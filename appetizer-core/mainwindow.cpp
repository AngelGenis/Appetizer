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
    ui->header->hide();

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

    connect(ui->header, &Navegador::profileBtnClicked, this, &MainWindow::on_profileBtnClicked);
    connect(ui->header, &Navegador::notificationBtnClicked, this, &MainWindow::on_notifBtnClicked);

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


void MainWindow::on_cerrarSesion_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->profileMenu->hide();
    ui->header->hide();
    ui->notificaciones->hide();
}
