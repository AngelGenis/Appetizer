/********************************************************************************
** Form generated from reading UI file 'menuplatillos.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUPLATILLOS_H
#define UI_MENUPLATILLOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuPlatillos
{
public:
    QLineEdit *buscador;
    QLabel *label;

    void setupUi(QWidget *MenuPlatillos)
    {
        if (MenuPlatillos->objectName().isEmpty())
            MenuPlatillos->setObjectName(QString::fromUtf8("MenuPlatillos"));
        MenuPlatillos->resize(482, 552);
        MenuPlatillos->setMaximumSize(QSize(482, 552));
        buscador = new QLineEdit(MenuPlatillos);
        buscador->setObjectName(QString::fromUtf8("buscador"));
        buscador->setGeometry(QRect(30, 30, 423, 34));
        buscador->setStyleSheet(QString::fromUtf8("background: #FFFFFF;\n"
"padding-left: 41px;\n"
"\n"
"border: 1px solid #C8CFE1;\n"
"border-radius: 4px;\n"
"\n"
"color: #A9AFC2;"));
        label = new QLabel(MenuPlatillos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(41, 33, 16, 29));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Img/lupa.png")));

        retranslateUi(MenuPlatillos);

        QMetaObject::connectSlotsByName(MenuPlatillos);
    } // setupUi

    void retranslateUi(QWidget *MenuPlatillos)
    {
        MenuPlatillos->setWindowTitle(QCoreApplication::translate("MenuPlatillos", "Form", nullptr));
        buscador->setText(QString());
        buscador->setPlaceholderText(QCoreApplication::translate("MenuPlatillos", "Buscar platillos...", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuPlatillos: public Ui_MenuPlatillos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPLATILLOS_H
