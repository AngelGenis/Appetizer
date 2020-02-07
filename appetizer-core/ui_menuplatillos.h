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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuPlatillos
{
public:
    QLineEdit *buscador;
    QLabel *label;
    QScrollArea *scroll_platillos;
    QWidget *content_platillos;
    QGridLayout *gridLayout_2;
    QGridLayout *grid_platillos;
    QScrollArea *menu;
    QWidget *menu_contents;
    QGridLayout *gridLayout;
    QHBoxLayout *menu_layout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

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
        scroll_platillos->setGeometry(QRect(26, 120, 431, 461));
        scroll_platillos->setStyleSheet(QString::fromUtf8("#scroll_platillos{\n"
"background: #F5F6FA;\n"
"border: none\n"
"}"));
        scroll_platillos->setWidgetResizable(true);
        content_platillos = new QWidget();
        content_platillos->setObjectName(QString::fromUtf8("content_platillos"));
        content_platillos->setGeometry(QRect(0, 0, 431, 461));
        content_platillos->setStyleSheet(QString::fromUtf8("#content_platillos{\n"
"background: #F5F6FA;\n"
"}"));
        gridLayout_2 = new QGridLayout(content_platillos);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        grid_platillos = new QGridLayout();
        grid_platillos->setObjectName(QString::fromUtf8("grid_platillos"));

        gridLayout_2->addLayout(grid_platillos, 0, 0, 1, 1);

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
        pushButton = new QPushButton(menu_contents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("color: #3C6AF1;\n"
"font: 12x \"SF Pro Text\";\n"
"border: 2px solid rgba(0,0,0,0);\n"
"padding-bottom: 11px;\n"
"border-bottom: 2px solid #3C6AF1;\n"
""));

        menu_layout->addWidget(pushButton);

        pushButton_2 = new QPushButton(menu_contents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #C8CFE1;\n"
"	font: 12x \"SF Pro Text\";\n"
"	border: 2px solid rgba(0,0,0,0);\n"
"	padding-bottom: 11px;\n"
"	border-bottom: 2px solid #C8CFE1;\n"
"}\n"
"QPushButton:hover{\n"
"	color: #89ACFA;\n"
"border-bottom: 2px solid #89ACFA;\n"
"}"));

        menu_layout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(menu_contents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #C8CFE1;\n"
"	font: 12x \"SF Pro Text\";\n"
"	border: 2px solid rgba(0,0,0,0);\n"
"	padding-bottom: 11px;\n"
"	border-bottom: 2px solid #C8CFE1;\n"
"}\n"
"QPushButton:hover{\n"
"	color: #89ACFA;\n"
"border-bottom: 2px solid #89ACFA;\n"
"}"));

        menu_layout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(menu_contents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #C8CFE1;\n"
"	font: 12x \"SF Pro Text\";\n"
"	border: 2px solid rgba(0,0,0,0);\n"
"	padding-bottom: 11px;\n"
"	border-bottom: 2px solid #C8CFE1;\n"
"}\n"
"QPushButton:hover{\n"
"	color: #89ACFA;\n"
"border-bottom: 2px solid #89ACFA;\n"
"}"));

        menu_layout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(menu_contents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #C8CFE1;\n"
"	font: 12x \"SF Pro Text\";\n"
"	border: 2px solid rgba(0,0,0,0);\n"
"	padding-bottom: 11px;\n"
"	border-bottom: 2px solid #C8CFE1;\n"
"}\n"
"QPushButton:hover{\n"
"	color: #89ACFA;\n"
"border-bottom: 2px solid #89ACFA;\n"
"}"));

        menu_layout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(menu_contents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #C8CFE1;\n"
"	font: 12x \"SF Pro Text\";\n"
"	border: 2px solid rgba(0,0,0,0);\n"
"	padding-bottom: 11px;\n"
"	border-bottom: 2px solid #C8CFE1;\n"
"}\n"
"QPushButton:hover{\n"
"	color: #89ACFA;\n"
"border-bottom: 2px solid #89ACFA;\n"
"}"));

        menu_layout->addWidget(pushButton_6);


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
        pushButton->setText(QCoreApplication::translate("MenuPlatillos", "Todo", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MenuPlatillos", "Hambur..", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MenuPlatillos", "Pizzas", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MenuPlatillos", "Tacos", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MenuPlatillos", "Tacos", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MenuPlatillos", "Ensaladas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuPlatillos: public Ui_MenuPlatillos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPLATILLOS_H
