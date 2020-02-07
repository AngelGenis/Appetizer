/********************************************************************************
** Form generated from reading UI file 'keypadwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYPADWIDGET_H
#define UI_KEYPADWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeypadWidget
{
public:
    QWidget *numpad;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_0;
    QPushButton *btn_entrar;
    QLineEdit *line_numeros_ingresados;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *KeypadWidget)
    {
        if (KeypadWidget->objectName().isEmpty())
            KeypadWidget->setObjectName(QString::fromUtf8("KeypadWidget"));
        KeypadWidget->resize(280, 332);
        KeypadWidget->setMinimumSize(QSize(0, 0));
        KeypadWidget->setStyleSheet(QString::fromUtf8(""));
        numpad = new QWidget(KeypadWidget);
        numpad->setObjectName(QString::fromUtf8("numpad"));
        numpad->setGeometry(QRect(10, 90, 261, 231));
        numpad->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8(".SF Compact Text"));
        font.setPointSize(17);
        numpad->setFont(font);
        btn_1 = new QPushButton(numpad);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(0, 0, 80, 51));
        btn_1->setMinimumSize(QSize(80, 51));
        btn_1->setMaximumSize(QSize(128, 64));
        QFont font1;
        font1.setFamily(QString::fromUtf8("SF Pro Text"));
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        btn_1->setFont(font1);
        btn_1->setCursor(QCursor(Qt::PointingHandCursor));
        btn_1->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_2 = new QPushButton(numpad);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(90, 0, 80, 51));
        btn_2->setMinimumSize(QSize(80, 51));
        btn_2->setMaximumSize(QSize(128, 64));
        btn_2->setFont(font1);
        btn_2->setCursor(QCursor(Qt::PointingHandCursor));
        btn_2->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_3 = new QPushButton(numpad);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(180, 0, 80, 51));
        btn_3->setMinimumSize(QSize(80, 51));
        btn_3->setMaximumSize(QSize(128, 64));
        btn_3->setFont(font1);
        btn_3->setCursor(QCursor(Qt::PointingHandCursor));
        btn_3->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_4 = new QPushButton(numpad);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(0, 60, 80, 51));
        btn_4->setMinimumSize(QSize(80, 51));
        btn_4->setMaximumSize(QSize(128, 64));
        btn_4->setFont(font1);
        btn_4->setCursor(QCursor(Qt::PointingHandCursor));
        btn_4->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_5 = new QPushButton(numpad);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(90, 60, 80, 51));
        btn_5->setMinimumSize(QSize(80, 51));
        btn_5->setMaximumSize(QSize(128, 64));
        btn_5->setFont(font1);
        btn_5->setCursor(QCursor(Qt::PointingHandCursor));
        btn_5->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_6 = new QPushButton(numpad);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(180, 60, 80, 51));
        btn_6->setMinimumSize(QSize(80, 51));
        btn_6->setMaximumSize(QSize(128, 64));
        btn_6->setFont(font1);
        btn_6->setCursor(QCursor(Qt::PointingHandCursor));
        btn_6->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_7 = new QPushButton(numpad);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(0, 120, 80, 51));
        btn_7->setMinimumSize(QSize(80, 51));
        btn_7->setMaximumSize(QSize(128, 64));
        btn_7->setFont(font1);
        btn_7->setCursor(QCursor(Qt::PointingHandCursor));
        btn_7->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_8 = new QPushButton(numpad);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(90, 120, 80, 51));
        btn_8->setMinimumSize(QSize(80, 51));
        btn_8->setMaximumSize(QSize(128, 64));
        btn_8->setFont(font1);
        btn_8->setCursor(QCursor(Qt::PointingHandCursor));
        btn_8->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_9 = new QPushButton(numpad);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(180, 120, 80, 51));
        btn_9->setMinimumSize(QSize(80, 51));
        btn_9->setMaximumSize(QSize(128, 64));
        btn_9->setFont(font1);
        btn_9->setCursor(QCursor(Qt::PointingHandCursor));
        btn_9->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_0 = new QPushButton(numpad);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(0, 180, 166, 51));
        btn_0->setMinimumSize(QSize(166, 51));
        btn_0->setMaximumSize(QSize(128, 64));
        btn_0->setFont(font1);
        btn_0->setCursor(QCursor(Qt::PointingHandCursor));
        btn_0->setStyleSheet(QString::fromUtf8("background-color: #C8CFE1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: #525252;"));
        btn_entrar = new QPushButton(numpad);
        btn_entrar->setObjectName(QString::fromUtf8("btn_entrar"));
        btn_entrar->setGeometry(QRect(180, 180, 80, 51));
        btn_entrar->setMinimumSize(QSize(80, 51));
        btn_entrar->setMaximumSize(QSize(128, 64));
        btn_entrar->setCursor(QCursor(Qt::PointingHandCursor));
        btn_entrar->setStyleSheet(QString::fromUtf8("background-color: #3C6AF1;\n"
"border-radius: 6px;\n"
"\n"
"font: 17px \"SF Pro Text\";\n"
"line-height: 22px;\n"
"color: white;"));
        line_numeros_ingresados = new QLineEdit(KeypadWidget);
        line_numeros_ingresados->setObjectName(QString::fromUtf8("line_numeros_ingresados"));
        line_numeros_ingresados->setGeometry(QRect(10, 30, 261, 51));
        line_numeros_ingresados->setMinimumSize(QSize(0, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("SF Pro Display"));
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        line_numeros_ingresados->setFont(font2);
        line_numeros_ingresados->setStyleSheet(QString::fromUtf8("background: #3E5066;\n"
"border-radius: 6px;\n"
"\n"
"font: 25px \"SF Pro Display\";\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"padding-left: 25px;\n"
"\n"
"color: #FFFFFF;"));
        line_numeros_ingresados->setEchoMode(QLineEdit::Normal);
        line_numeros_ingresados->setAlignment(Qt::AlignCenter);
        line_numeros_ingresados->setClearButtonEnabled(true);
        label = new QLabel(KeypadWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 5, 251, 21));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font: 12px \"SF Pro Text\";\n"
"color: #8E98A5;\n"
"background: none;\n"
"border: none;\n"
""));
        label_2 = new QLabel(KeypadWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 280, 332));
        label_2->setStyleSheet(QString::fromUtf8("background: #F5F6FA"));
        label_2->raise();
        numpad->raise();
        line_numeros_ingresados->raise();
        label->raise();
        QWidget::setTabOrder(btn_1, btn_2);
        QWidget::setTabOrder(btn_2, btn_3);
        QWidget::setTabOrder(btn_3, btn_4);
        QWidget::setTabOrder(btn_4, btn_5);
        QWidget::setTabOrder(btn_5, btn_6);
        QWidget::setTabOrder(btn_6, btn_7);
        QWidget::setTabOrder(btn_7, btn_8);
        QWidget::setTabOrder(btn_8, btn_9);
        QWidget::setTabOrder(btn_9, btn_entrar);

        retranslateUi(KeypadWidget);

        QMetaObject::connectSlotsByName(KeypadWidget);
    } // setupUi

    void retranslateUi(QWidget *KeypadWidget)
    {
        KeypadWidget->setWindowTitle(QCoreApplication::translate("KeypadWidget", "Form", nullptr));
        btn_1->setText(QCoreApplication::translate("KeypadWidget", "1", nullptr));
        btn_2->setText(QCoreApplication::translate("KeypadWidget", "2", nullptr));
        btn_3->setText(QCoreApplication::translate("KeypadWidget", "3", nullptr));
        btn_4->setText(QCoreApplication::translate("KeypadWidget", "4", nullptr));
        btn_5->setText(QCoreApplication::translate("KeypadWidget", "5", nullptr));
        btn_6->setText(QCoreApplication::translate("KeypadWidget", "6", nullptr));
        btn_7->setText(QCoreApplication::translate("KeypadWidget", "7", nullptr));
        btn_8->setText(QCoreApplication::translate("KeypadWidget", "8", nullptr));
        btn_9->setText(QCoreApplication::translate("KeypadWidget", "9", nullptr));
        btn_0->setText(QCoreApplication::translate("KeypadWidget", "0", nullptr));
        btn_entrar->setText(QCoreApplication::translate("KeypadWidget", "Ir", nullptr));
        line_numeros_ingresados->setText(QString());
        label->setText(QCoreApplication::translate("KeypadWidget", "Ingrese su clave PIN", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KeypadWidget: public Ui_KeypadWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYPADWIDGET_H
