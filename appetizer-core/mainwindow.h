#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>

#include <components-mesero/tarjetaplatillo.h>
#include <services/authenticationservice.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QStringListModel;
class AuthenticationService;
class NotificationService;
class KeyboardService;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
                 
private slots:
    void on_lista_categorias_activated(QString category);
    void on_keypad_enterPressed(QString text);
    void on_userListView_clicked(QModelIndex index);
    void on_profileBtnClicked();
    void on_notifBtnClicked();
    void on_hamBtnClicked();
    void on_btnAtrasMesaClicked();

    void on_cerrarSesion_Btn_clicked();

    void on_ham_mesas_clicked();

    void on_ham_menu_clicked();

private:
    Ui::MainWindow *ui;
    QString currentUserName;
    tipoUsuario currentTipoUsuario;
    QStringListModel *usersModel;
    AuthenticationService *authSrv;
    NotificationService *notiService;
    KeyboardService *kbSrv;
};
#endif // MAINWINDOW_H
