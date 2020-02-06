#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roles.h"
#include "rolesitemdelegate.h"
#include "services/authenticationservice.h"
#include "services/notificationservice.h"

#include <QSqlRecord>
#include <QDebug>
#include <QStringListModel>
#include <QMessageBox>


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
        ui->stackedWidget->setCurrentWidget(ui->ui_mesero);
        ui->mesero_stacked->setCurrentWidget(ui->orden);
    }
    else
    {

        ui->keypad->clear();
        ui->keypad->setInputFocus();
        notiService->notify(authSrv->lastErrorMessage(),
                            Qt::AlignBottom,
                            4000);
        return;
    }


}

void MainWindow::on_userListView_clicked(QModelIndex index)
{
    currentUserName = index.data().toString();
    ui->keypad->clear();
    ui->keypad->setInputFocus();
}
