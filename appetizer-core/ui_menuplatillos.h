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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuPlatillos
{
public:
    QLineEdit *buscador;
    QLabel *lupa;
    QScrollArea *categorias;
    QWidget *categorias_content;
    QScrollArea *scroll_menu;
    QWidget *scroll_content_menu;
    QVBoxLayout *verticalLayout;
    QGridLayout *grid_menu;
    QLabel *label;

    void setupUi(QWidget *MenuPlatillos)
    {
        if (MenuPlatillos->objectName().isEmpty())
            MenuPlatillos->setObjectName(QString::fromUtf8("MenuPlatillos"));
        MenuPlatillos->resize(482, 552);
        MenuPlatillos->setMaximumSize(QSize(482, 552));
        MenuPlatillos->setStyleSheet(QString::fromUtf8("\n"
"#MenuPlatillos{\n"
"border: 2px solid rgba(0,0,0,0);\n"
"background: #F5F6FA;\n"
"}\n"
""));
        buscador = new QLineEdit(MenuPlatillos);
        buscador->setObjectName(QString::fromUtf8("buscador"));
        buscador->setGeometry(QRect(30, 0, 423, 34));
        buscador->setStyleSheet(QString::fromUtf8("background: #FFFFFF;\n"
"padding-left: 41px;\n"
"\n"
"border: 1px solid #C8CFE1;\n"
"border-radius: 4px;\n"
"\n"
"color: #A9AFC2;"));
        lupa = new QLabel(MenuPlatillos);
        lupa->setObjectName(QString::fromUtf8("lupa"));
        lupa->setGeometry(QRect(41, 3, 16, 29));
        lupa->setPixmap(QPixmap(QString::fromUtf8(":/Img/lupa.png")));
        categorias = new QScrollArea(MenuPlatillos);
        categorias->setObjectName(QString::fromUtf8("categorias"));
        categorias->setGeometry(QRect(30, 55, 421, 25));
        categorias->setStyleSheet(QString::fromUtf8("#categorias{\n"
"border: 2px solid rgba(0,0,0,0);\n"
"background: #F5F6FA;\n"
"}\n"
""));
        categorias->setWidgetResizable(true);
        categorias_content = new QWidget();
        categorias_content->setObjectName(QString::fromUtf8("categorias_content"));
        categorias_content->setGeometry(QRect(0, 0, 417, 21));
        categorias_content->setStyleSheet(QString::fromUtf8("#categorias_content{\n"
"border: 2px solid rgba(0,0,0,0);\n"
"background: #F5F6FA;\n"
"}\n"
""));
        categorias->setWidget(categorias_content);
        scroll_menu = new QScrollArea(MenuPlatillos);
        scroll_menu->setObjectName(QString::fromUtf8("scroll_menu"));
        scroll_menu->setGeometry(QRect(30, 100, 421, 455));
        scroll_menu->setStyleSheet(QString::fromUtf8("#scroll_menu{\n"
"border: 2px solid rgba(0,0,0,0);\n"
"background: #F5F6FA;\n"
"}\n"
""));
        scroll_menu->setWidgetResizable(true);
        scroll_content_menu = new QWidget();
        scroll_content_menu->setObjectName(QString::fromUtf8("scroll_content_menu"));
        scroll_content_menu->setGeometry(QRect(0, 0, 417, 451));
        scroll_content_menu->setStyleSheet(QString::fromUtf8("#scroll_content_menu{\n"
"border: 2px solid rgba(0,0,0,0);\n"
"background: #F5F6FA;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(scroll_content_menu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        grid_menu = new QGridLayout();
        grid_menu->setObjectName(QString::fromUtf8("grid_menu"));
        grid_menu->setSizeConstraint(QLayout::SetDefaultConstraint);
        grid_menu->setHorizontalSpacing(-1);

        verticalLayout->addLayout(grid_menu);

        scroll_menu->setWidget(scroll_content_menu);
        label = new QLabel(MenuPlatillos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 520, 481, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Img/sombra_scroll.png")));

        retranslateUi(MenuPlatillos);

        QMetaObject::connectSlotsByName(MenuPlatillos);
    } // setupUi

    void retranslateUi(QWidget *MenuPlatillos)
    {
        MenuPlatillos->setWindowTitle(QCoreApplication::translate("MenuPlatillos", "Form", nullptr));
        buscador->setText(QString());
        buscador->setPlaceholderText(QCoreApplication::translate("MenuPlatillos", "Buscar platillos...", nullptr));
        lupa->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuPlatillos: public Ui_MenuPlatillos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPLATILLOS_H
