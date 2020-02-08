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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <components-layout/navegador.h>
#include <components-mesero/menuplatillos.h>
#include <keypadwidget.h>
#include <orden.h>

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
    QWidget *ui_mesero;
    QStackedWidget *mesero_stacked;
    QWidget *mesas;
    QLabel *label_4;
    QWidget *orden;
    MenuPlatillos *widget;
    Orden *cuentaWidget;
    QLabel *label;
    Navegador *widget_2;
    QPushButton *pushButton;

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
"font: 15px \"SF Pro Text\";\n"
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
        ui_mesero = new QWidget();
        ui_mesero->setObjectName(QString::fromUtf8("ui_mesero"));
        ui_mesero->setStyleSheet(QString::fromUtf8("#ui_mesero{\n"
"background: #F5F6FA;\n"
"}"));
        mesero_stacked = new QStackedWidget(ui_mesero);
        mesero_stacked->setObjectName(QString::fromUtf8("mesero_stacked"));
        mesero_stacked->setGeometry(QRect(-1, 46, 901, 579));
        mesero_stacked->setStyleSheet(QString::fromUtf8("#mesero_stacked{\n"
"background: red;\n"
"}"));
        mesas = new QWidget();
        mesas->setObjectName(QString::fromUtf8("mesas"));
        mesas->setStyleSheet(QString::fromUtf8("#mesas{\n"
"background: #F5F6FA;\n"
"}"));
        label_4 = new QLabel(mesas);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(400, 160, 271, 91));
        QFont font;
        font.setPointSize(50);
        label_4->setFont(font);
        mesero_stacked->addWidget(mesas);
        orden = new QWidget();
        orden->setObjectName(QString::fromUtf8("orden"));
        orden->setStyleSheet(QString::fromUtf8("#orden{\n"
"background: #F5F6FA;\n"
"}"));
        widget = new MenuPlatillos(orden);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 482, 581));
        cuentaWidget = new Orden(orden);
        cuentaWidget->setObjectName(QString::fromUtf8("cuentaWidget"));
        cuentaWidget->setGeometry(QRect(480, 20, 381, 526));
        cuentaWidget->setStyleSheet(QString::fromUtf8("#cuentaWidget{\n"
"	background: white;\n"
"	border: 1px solid #C8CFE1;\n"
"	border-radius: 5px;\n"
"}"));
        label = new QLabel(orden);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(480, 0, 58, 16));
        label->setStyleSheet(QString::fromUtf8("color: blue;"));
        mesero_stacked->addWidget(orden);
        widget_2 = new Navegador(ui_mesero);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 895, 46));
        pushButton = new QPushButton(ui_mesero);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1220, 40, 75, 23));
        stackedWidget->addWidget(ui_mesero);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        mesero_stacked->setCurrentIndex(1);


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
        label_4->setText(QCoreApplication::translate("MainWindow", "MESAS", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "holfjfjf", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
