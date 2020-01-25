#include "mainwindow.h"
#include "authenticationservice.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    AuthenticationService authSrv;
    authSrv.authenticate("foo", "1234");
    MainWindow w;
    w.show();
    
    return a.exec();
}
