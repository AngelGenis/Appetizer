/********************************************************************************
** Form generated from reading UI file 'navegador.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVEGADOR_H
#define UI_NAVEGADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Navegador
{
public:
    QLabel *notificacion;
    QLabel *imgHeader;
    QLabel *label;
    QLabel *logo;
    QLabel *nombre;
    QPushButton *pushButton;
    QLabel *cargo;

    void setupUi(QWidget *Navegador)
    {
        if (Navegador->objectName().isEmpty())
            Navegador->setObjectName(QString::fromUtf8("Navegador"));
        Navegador->resize(895, 46);
        notificacion = new QLabel(Navegador);
        notificacion->setObjectName(QString::fromUtf8("notificacion"));
        notificacion->setGeometry(QRect(837, 12, 20, 20));
        notificacion->setPixmap(QPixmap(QString::fromUtf8(":/Img/notificationBell.png")));
        notificacion->setScaledContents(true);
        notificacion->setAlignment(Qt::AlignCenter);
        imgHeader = new QLabel(Navegador);
        imgHeader->setObjectName(QString::fromUtf8("imgHeader"));
        imgHeader->setGeometry(QRect(690, 12, 30, 30));
        imgHeader->setPixmap(QPixmap(QString::fromUtf8(":/Img/face.png")));
        imgHeader->setScaledContents(true);
        imgHeader->setAlignment(Qt::AlignCenter);
        label = new QLabel(Navegador);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 895, 46));
        label->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: none;"));
        logo = new QLabel(Navegador);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(0, 0, 45, 45));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/Img/Logo.png")));
        logo->setAlignment(Qt::AlignCenter);
        nombre = new QLabel(Navegador);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setGeometry(QRect(730, 12, 91, 16));
        pushButton = new QPushButton(Navegador);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 10, 75, 23));
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: none;\n"
"color: #3C6AF1;"));
        cargo = new QLabel(Navegador);
        cargo->setObjectName(QString::fromUtf8("cargo"));
        cargo->setGeometry(QRect(730, 22, 81, 16));
        label->raise();
        notificacion->raise();
        imgHeader->raise();
        logo->raise();
        nombre->raise();
        pushButton->raise();
        cargo->raise();

        retranslateUi(Navegador);

        QMetaObject::connectSlotsByName(Navegador);
    } // setupUi

    void retranslateUi(QWidget *Navegador)
    {
        Navegador->setWindowTitle(QCoreApplication::translate("Navegador", "Form", nullptr));
        notificacion->setText(QString());
        imgHeader->setText(QString());
        label->setText(QString());
        logo->setText(QString());
        nombre->setText(QCoreApplication::translate("Navegador", "Jorje Espinoza", nullptr));
        pushButton->setText(QCoreApplication::translate("Navegador", "Mesas", nullptr));
        cargo->setText(QCoreApplication::translate("Navegador", "Mesero", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Navegador: public Ui_Navegador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVEGADOR_H
