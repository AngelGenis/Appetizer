#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roles.h"
#include "rolesitemdelegate.h"
#include "services/authenticationservice.h"
#include "services/notificationservice.h"
#include "services/keyboardservice.h"

#include <QSqlRecord>
#include <QDebug>
#include <QStringListModel>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      usersModel(new QStringListModel(this)),
      authSrv(new AuthenticationService),
      notiService(new NotificationService(this))
      
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    ui->userListView->setModel(usersModel);
    ui->userListView->setItemDelegate(new RolesItemDelegate);
    ui->keypad->setEchoMode(QLineEdit::Password);
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    ui->lista_categorias->activated("Mesero");

    /*Dejarle a menuplatillos que conzca a Orden*/
    ui->menuPlatillos->setOrdenWidget(ui->orden);




    /*Asignar teclado en el servicio*/
    kbSrv = new KeyboardService;
    kbSrv->setTeclado(ui->teclado);
    kbSrv->hideTeclado();

    QList<QLineEdit*> list = this->findChildren<QLineEdit *>();
    foreach(QLineEdit *w, list) {
        connect(w, &QLineEdit::textChanged, kbSrv, &KeyboardService::showTecladoEdit);
        connect(w, &QLineEdit::returnPressed, kbSrv, &KeyboardService::hideTeclado);
    }

    /* Navegador menu popups*/
    ui->profileMenu->hide();
    ui->notificaciones->hide();
    ui->sideMenu->hide();
    ui->header->hide();

    ui->teclado->raise();
    ui->profileMenu->raise();
    ui->header->raise();
    ui->notificaciones->raise();
    ui->sideMenu->raise();
    /************************/

    connect(ui->header, &Navegador::profileBtnClicked, this, &MainWindow::on_profileBtnClicked);
    connect(ui->header, &Navegador::notificationBtnClicked, this, &MainWindow::on_notifBtnClicked);
    connect(ui->header, &Navegador::hamBtnClicked, this, &MainWindow::on_hamBtnClicked);
    connect(ui->header, &Navegador::btnAtrasMesasClicked, this, &MainWindow::on_btnAtrasMesaClicked);


    // editor y vista del mapa del restaurant
    ui->restaurantMapMesero->setMode(RestaurantMap::ViewMode);
    ui->restaurantMap->setMode(RestaurantMap::EditMode);
    ui->mesero_stacked->setCurrentWidget(ui->mesas);
    connect(ui->restaurantMapMesero, &RestaurantMap::mesaSelected, this, [=](int mesa) {

            ui->cuentaWidget->setMesa(mesa);
            ui->mesero_stacked->setCurrentWidget(ui->orden);
        });


}
MainWindow::~MainWindow()
{
    delete notiService;
    delete ui;
}

void MainWindow::on_lista_categorias_activated(QString category)
{
    ui->keypad->clear();
    if(category == "Manager" || category == "Cajero")
    {
        ui->keypad->setMode(KeypadWidget::Desktop);
    }
    else
    {
        ui->keypad->setMode(KeypadWidget::Touch);
    }
    auto empleados = authSrv->getEmpleados(category);
    usersModel->setStringList(empleados);
    currentUserName = "";


}
void MainWindow::on_keypad_enterPressed(QString text)
{


    if(currentUserName.isEmpty())
    {
        notiService->notify("Selecciona tu usuario desde la lista de usuarios",
                            Qt::AlignBottom,
                            4000);
            return;
    }
    

    if(authSrv->authenticate(currentUserName, text))
    {   

        ui->header->show();
        currentTipoUsuario = authSrv->getTipoDeUsuario(currentUserName);
        ui->stackedWidget->setCurrentIndex(currentTipoUsuario);

        usuario p1;
        p1 = authSrv->getDatosUsuario(currentUserName);
        ui->header->setDatosUsuario(p1.nombre, p1.cargo, p1.foto);

        ui->header->setEditorMode(currentTipoUsuario != manager);
        qDebug()<<"Curr use: "<<currentUserName;

        ui->menuPlatillos->setCurrentUser(p1.cargo);
        ui->menuPlatillos->llenarCatalogo();
    }
    else
    {

        ui->keypad->clear();
        ui->keypad->setInputFocus();
        notiService->notify(authSrv->lastErrorMessage(),
                            Qt::AlignBottom,
                            4000,
                            NotificationDialog::Error);
        return;
    }


}

void MainWindow::on_userListView_clicked(QModelIndex index)
{
    currentUserName = index.data().toString();
    ui->keypad->clear();
    ui->keypad->setInputFocus();
}

void MainWindow::on_profileBtnClicked(){
    if(ui->profileMenu->isVisible()) ui->profileMenu->hide();
    else ui->profileMenu->show();
}

void MainWindow::on_notifBtnClicked()
{
    if(ui->notificaciones->isVisible()) ui->notificaciones->hide();
    else ui->notificaciones->show();
}

void MainWindow::on_hamBtnClicked()
{
    if(ui->sideMenu->isVisible()) ui->sideMenu->hide();
    else ui->sideMenu->show();
}

void MainWindow::on_btnAtrasMesaClicked()
{
    ui->mesero_stacked->setCurrentWidget(ui->mesas);
}


void MainWindow::on_cerrarSesion_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->profileMenu->hide();
    ui->header->hide();
    ui->notificaciones->hide();
    ui->sideMenu->hide();
}

void MainWindow::on_ham_mesas_clicked()
{
    ui->manager_stacked->setCurrentWidget(ui->layout_editor);
    ui->sideMenu->hide();
}

void MainWindow::on_ham_menu_clicked()
{
    ui->manager_stacked->setCurrentWidget(ui->gestionar_menu);
    ui->sideMenu->hide();
    ui->editarMenu->setEditionMode();
}
