/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <keypadwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QComboBox *lista_categorias;
    KeypadWidget *keypad;
    QListView *userListView;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *welcomePage;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(895, 625);
        MainWindow->setMaximumSize(QSize(895, 625));
        MainWindow->setStyleSheet(QString::fromUtf8("QListView,\n"
"QTableView {\n"
"    show-decoration-selected: 0; /* make the selection span the entire width of the view */\n"
"    selection-background-color:  none;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 895, 625));
        stackedWidget->setMaximumSize(QSize(895, 625));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        lista_categorias = new QComboBox(loginPage);
        lista_categorias->addItem(QString());
        lista_categorias->addItem(QString());
        lista_categorias->addItem(QString());
        lista_categorias->addItem(QString());
        lista_categorias->addItem(QString());
        lista_categorias->setObjectName(QString::fromUtf8("lista_categorias"));
        lista_categorias->setGeometry(QRect(70, 89, 339, 55));
        lista_categorias->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 15pt \"SF Pro Text\";\n"
"padding-left: 75px;\n"
"\n"
"color: #637283;"));
        keypad = new KeypadWidget(loginPage);
        keypad->setObjectName(QString::fromUtf8("keypad"));
        keypad->setGeometry(QRect(540, 147, 280, 332));
        keypad->setMinimumSize(QSize(253, 40));
        userListView = new QListView(loginPage);
        userListView->setObjectName(QString::fromUtf8("userListView"));
        userListView->setGeometry(QRect(60, 168, 361, 361));
        userListView->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: #F5F6FA;"));
        userListView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        userListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userListView->setSpacing(6);
        label_2 = new QLabel(loginPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 1361, 767));
        label_2->setStyleSheet(QString::fromUtf8("background: #F5F6FA;"));
        label_3 = new QLabel(loginPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(470, 96, 1, 400));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"\n"
"border: 0.749581px solid #A9AFC2;\n"
""));
        stackedWidget->addWidget(loginPage);
        label_2->raise();
        lista_categorias->raise();
        keypad->raise();
        userListView->raise();
        label_3->raise();
        welcomePage = new QWidget();
        welcomePage->setObjectName(QString::fromUtf8("welcomePage"));
        label = new QLabel(welcomePage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 210, 253, 109));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        stackedWidget->addWidget(welcomePage);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Appetizer", nullptr));
        lista_categorias->setItemText(0, QCoreApplication::translate("MainWindow", "Mesero", nullptr));
        lista_categorias->setItemText(1, QCoreApplication::translate("MainWindow", "Host", nullptr));
        lista_categorias->setItemText(2, QCoreApplication::translate("MainWindow", "Cocinero", nullptr));
        lista_categorias->setItemText(3, QCoreApplication::translate("MainWindow", "Manager", nullptr));
        lista_categorias->setItemText(4, QCoreApplication::translate("MainWindow", "Cajero", nullptr));

        label_2->setText(QString());
        label_3->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Bienvenido!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
