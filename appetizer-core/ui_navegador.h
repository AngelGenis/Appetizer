/********************************************************************************
** Form generated from reading UI file 'navegador.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
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
    QPushButton *btn_goMesas;
    QLabel *cargo;

    void setupUi(QWidget *Navegador)
    {
        if (Navegador->objectName().isEmpty())
            Navegador->setObjectName(QStringLiteral("Navegador"));
        Navegador->resize(895, 46);
        notificacion = new QLabel(Navegador);
        notificacion->setObjectName(QStringLiteral("notificacion"));
        notificacion->setGeometry(QRect(837, 12, 20, 20));
        notificacion->setPixmap(QPixmap(QString::fromUtf8(":/Img/notificationBell.png")));
        notificacion->setScaledContents(true);
        notificacion->setAlignment(Qt::AlignCenter);
        imgHeader = new QLabel(Navegador);
        imgHeader->setObjectName(QStringLiteral("imgHeader"));
        imgHeader->setGeometry(QRect(690, 12, 30, 30));
        imgHeader->setPixmap(QPixmap(QString::fromUtf8(":/Img/face.png")));
        imgHeader->setScaledContents(true);
        imgHeader->setAlignment(Qt::AlignCenter);
        label = new QLabel(Navegador);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 895, 46));
        label->setStyleSheet(QLatin1String("background: white;\n"
"border: none;"));
        logo = new QLabel(Navegador);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(0, 0, 45, 45));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/Img/Logo.png")));
        logo->setAlignment(Qt::AlignCenter);
        nombre = new QLabel(Navegador);
        nombre->setObjectName(QStringLiteral("nombre"));
        nombre->setGeometry(QRect(730, 12, 91, 16));
        nombre->setStyleSheet(QLatin1String("font: 75 8pt \"SF Pro Text\";\n"
"font-weight: 500;\n"
"color: #3E5066;"));
        btn_goMesas = new QPushButton(Navegador);
        btn_goMesas->setObjectName(QStringLiteral("btn_goMesas"));
        btn_goMesas->setGeometry(QRect(90, 10, 75, 23));
        btn_goMesas->setStyleSheet(QLatin1String("font-family: \"SF Pro Text\";\n"
"font-style: normal;\n"
"font-weight: 500;\n"
"border: none;\n"
"background: none;\n"
"font-size: 11px;\n"
"color: #3C6AF1;"));
        cargo = new QLabel(Navegador);
        cargo->setObjectName(QStringLiteral("cargo"));
        cargo->setGeometry(QRect(730, 22, 81, 16));
        cargo->setStyleSheet(QLatin1String("font: 75 8pt \"SF Pro Text\";\n"
"font-weight: 500;\n"
"color: #A9AFC2;\n"
""));
        label->raise();
        notificacion->raise();
        imgHeader->raise();
        logo->raise();
        nombre->raise();
        btn_goMesas->raise();
        cargo->raise();

        retranslateUi(Navegador);

        QMetaObject::connectSlotsByName(Navegador);
    } // setupUi

    void retranslateUi(QWidget *Navegador)
    {
        Navegador->setWindowTitle(QApplication::translate("Navegador", "Form", nullptr));
        notificacion->setText(QString());
        imgHeader->setText(QString());
        label->setText(QString());
        logo->setText(QString());
        nombre->setText(QApplication::translate("Navegador", "Jorge Espinoza", nullptr));
        btn_goMesas->setText(QApplication::translate("Navegador", "Mesas", nullptr));
        cargo->setText(QApplication::translate("Navegador", "Mesero", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Navegador: public Ui_Navegador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVEGADOR_H
