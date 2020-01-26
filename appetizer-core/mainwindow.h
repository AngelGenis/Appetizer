#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "authenticationservice.h"
#include <QMainWindow>
#include <QModelIndex>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QStringListModel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
                 
private slots:
    void on_lista_categorias_currentIndexChanged(QString category);
    void on_keypad_enterPressed(QString text);
    void on_userListView_clicked(QModelIndex index);
private:
    Ui::MainWindow *ui;
    AuthenticationService authSrv;
    QString currentUserName;
    QStringListModel *usersModel;
};
#endif // MAINWINDOW_H
