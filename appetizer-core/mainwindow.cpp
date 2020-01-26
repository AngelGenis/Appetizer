#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roles.h"
#include "rolesitemdelegate.h"

#include <QSqlRecord>
#include <QDebug>
#include <QStringListModel>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      usersModel(new QStringListModel(this))
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    ui->userListView->setModel(usersModel);
    ui->userListView->setItemDelegate(new RolesItemDelegate);
    ui->keypad->setEchoMode(QLineEdit::Password);
    ui->stackedWidget->setCurrentWidget(ui->loginPage);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lista_categorias_currentIndexChanged(QString category)
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
    auto empleados = authSrv.getEmpleados(category);
    usersModel->setStringList(empleados);
    currentUserName = "";


}
void MainWindow::on_keypad_enterPressed(QString text)
{
    if(currentUserName.isEmpty())
    {
        QMessageBox::information(ui->loginPage, "Usuario no seleccionado", "Selecciona tu usuario desde la lista de usuarios");
        return;
    }
    
    try {
        if(authSrv.authenticate(currentUserName, text))
        {
            ui->stackedWidget->setCurrentWidget(ui->welcomePage);
        }
    } catch (AuthenticationException &e) {
        QMessageBox::critical(ui->loginPage, "Error de Autenticación", e.what());
        ui->keypad->clear();
        ui->keypad->setInputFocus();
    }

}

void MainWindow::on_userListView_clicked(QModelIndex index)
{
    currentUserName = index.data().toString();
    ui->keypad->clear();
    ui->keypad->setInputFocus();
}
