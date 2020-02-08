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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <components-mesero/menubutton.h>

QT_BEGIN_NAMESPACE

class Ui_MenuPlatillos
{
public:
    QLineEdit *buscador;
    QLabel *label;
    QScrollArea *scroll_platillos;
    QWidget *content_platillos;
    QGridLayout *gridLayout_2;
    QWidget *platillo_grid;
    QGridLayout *grid_platillos;
    QSpacerItem *verticalSpacer;
    QScrollArea *menu;
    QWidget *menu_contents;
    QGridLayout *gridLayout;
    QHBoxLayout *menu_layout;
    MenuButton *btnTest;

    void setupUi(QWidget *MenuPlatillos)
    {
        if (MenuPlatillos->objectName().isEmpty())
            MenuPlatillos->setObjectName(QString::fromUtf8("MenuPlatillos"));
        MenuPlatillos->resize(482, 581);
        MenuPlatillos->setMaximumSize(QSize(482, 581));
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
        scroll_platillos = new QScrollArea(MenuPlatillos);
        scroll_platillos->setObjectName(QString::fromUtf8("scroll_platillos"));
        scroll_platillos->setGeometry(QRect(26, 120, 421, 461));
        scroll_platillos->setStyleSheet(QString::fromUtf8("#scroll_platillos{\n"
"background: #F5F6FA;\n"
"border: none\n"
"}"));
        scroll_platillos->setWidgetResizable(true);
        content_platillos = new QWidget();
        content_platillos->setObjectName(QString::fromUtf8("content_platillos"));
        content_platillos->setGeometry(QRect(0, 0, 421, 461));
        content_platillos->setStyleSheet(QString::fromUtf8("#content_platillos{\n"
"background: #F5F6FA;\n"
"}"));
        gridLayout_2 = new QGridLayout(content_platillos);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 10);
        platillo_grid = new QWidget(content_platillos);
        platillo_grid->setObjectName(QString::fromUtf8("platillo_grid"));
        grid_platillos = new QGridLayout(platillo_grid);
        grid_platillos->setObjectName(QString::fromUtf8("grid_platillos"));
        grid_platillos->setSizeConstraint(QLayout::SetDefaultConstraint);
        grid_platillos->setHorizontalSpacing(5);
        grid_platillos->setContentsMargins(0, 0, 0, 0);

        gridLayout_2->addWidget(platillo_grid, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        scroll_platillos->setWidget(content_platillos);
        menu = new QScrollArea(MenuPlatillos);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(30, 70, 421, 41));
        menu->setStyleSheet(QString::fromUtf8("#menu{\n"
"border: none;\n"
"	background: #F5F6FA;\n"
"}"));
        menu->setWidgetResizable(true);
        menu_contents = new QWidget();
        menu_contents->setObjectName(QString::fromUtf8("menu_contents"));
        menu_contents->setGeometry(QRect(0, 0, 421, 41));
        menu_contents->setStyleSheet(QString::fromUtf8("#menu_contents{\n"
"border: none;\n"
"	background: #F5F6FA;\n"
"}"));
        gridLayout = new QGridLayout(menu_contents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        menu_layout = new QHBoxLayout();
        menu_layout->setSpacing(0);
        menu_layout->setObjectName(QString::fromUtf8("menu_layout"));
        btnTest = new MenuButton(menu_contents);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));

        menu_layout->addWidget(btnTest);


        gridLayout->addLayout(menu_layout, 0, 0, 1, 1);

        menu->setWidget(menu_contents);

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
