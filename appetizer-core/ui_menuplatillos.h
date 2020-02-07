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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;

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
        scrollArea = new QScrollArea(MenuPlatillos);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 70, 421, 41));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 568, 39));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(MenuPlatillos);

        QMetaObject::connectSlotsByName(MenuPlatillos);
    } // setupUi

    void retranslateUi(QWidget *MenuPlatillos)
    {
        MenuPlatillos->setWindowTitle(QCoreApplication::translate("MenuPlatillos", "Form", nullptr));
        buscador->setText(QString());
        buscador->setPlaceholderText(QCoreApplication::translate("MenuPlatillos", "Buscar platillos...", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MenuPlatillos", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MenuPlatillos", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MenuPlatillos", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MenuPlatillos", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MenuPlatillos", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuPlatillos: public Ui_MenuPlatillos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPLATILLOS_H
