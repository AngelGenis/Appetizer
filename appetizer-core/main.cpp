#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //    Añadir fuentes
    QFontDatabase::addApplicationFont(":/fonts/fonts/SF-Pro-Display-Bold.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/SF-Pro-Display-Medium.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/SF-Pro-Display-Regular.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/SF-Pro-Text-Bold.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/SF-Pro-Text-Light.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/SF-Pro-Text-Medium.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/SF-Pro-Text-Regular.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/BalooChettan-Regular.ttf");

    //    Debug Fonts
    //    QFontDatabase fontDb;
    //    for(int i=0; i<fontDb.families().size(); i++){
    //        qDebug() << fontDb.families().at(i);
    //    }

    MainWindow w;
    w.show();
    
    return a.exec();
}
