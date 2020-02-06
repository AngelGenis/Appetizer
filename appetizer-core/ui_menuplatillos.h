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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuPlatillos
{
public:
    QLineEdit *lineEdit;

    void setupUi(QWidget *MenuPlatillos)
    {
        if (MenuPlatillos->objectName().isEmpty())
            MenuPlatillos->setObjectName(QString::fromUtf8("MenuPlatillos"));
        MenuPlatillos->resize(482, 552);
        MenuPlatillos->setMaximumSize(QSize(482, 552));
        lineEdit = new QLineEdit(MenuPlatillos);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 30, 113, 21));

        retranslateUi(MenuPlatillos);

        QMetaObject::connectSlotsByName(MenuPlatillos);
    } // setupUi

    void retranslateUi(QWidget *MenuPlatillos)
    {
        MenuPlatillos->setWindowTitle(QCoreApplication::translate("MenuPlatillos", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuPlatillos: public Ui_MenuPlatillos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPLATILLOS_H
