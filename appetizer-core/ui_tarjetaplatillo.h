/********************************************************************************
** Form generated from reading UI file 'tarjetaplatillo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARJETAPLATILLO_H
#define UI_TARJETAPLATILLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TarjetaPlatillo
{
public:
    QLabel *mask;
    QLabel *nombre;
    QLabel *img;
    QLabel *bg;

    void setupUi(QWidget *TarjetaPlatillo)
    {
        if (TarjetaPlatillo->objectName().isEmpty())
            TarjetaPlatillo->setObjectName(QString::fromUtf8("TarjetaPlatillo"));
        TarjetaPlatillo->resize(98, 101);
        TarjetaPlatillo->setMinimumSize(QSize(98, 101));
        TarjetaPlatillo->setMaximumSize(QSize(98, 101));
        TarjetaPlatillo->setStyleSheet(QString::fromUtf8("#TarjetaPlatillo{\n"
"border: 1px solid white;\n"
"	background: white;\n"
"}"));
        mask = new QLabel(TarjetaPlatillo);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setGeometry(QRect(0, 0, 98, 101));
        mask->setPixmap(QPixmap(QString::fromUtf8(":/Img/mascara.png")));
        nombre = new QLabel(TarjetaPlatillo);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setGeometry(QRect(10, 58, 80, 35));
        nombre->setStyleSheet(QString::fromUtf8("font: 9px \"SF Pro Text\";\n"
"\n"
"/* negro - neutral */\n"
"\n"
"color: #3E5066;"));
        nombre->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        img = new QLabel(TarjetaPlatillo);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 1, 101, 49));
        img->setPixmap(QPixmap(QString::fromUtf8(":/Img/hamburguesa.png")));
        bg = new QLabel(TarjetaPlatillo);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(-3, -5, 111, 111));
        bg->setStyleSheet(QString::fromUtf8("border: 1px solid white;\n"
"	background: white;"));
        bg->raise();
        nombre->raise();
        img->raise();
        mask->raise();

        retranslateUi(TarjetaPlatillo);

        QMetaObject::connectSlotsByName(TarjetaPlatillo);
    } // setupUi

    void retranslateUi(QWidget *TarjetaPlatillo)
    {
        TarjetaPlatillo->setWindowTitle(QCoreApplication::translate("TarjetaPlatillo", "Form", nullptr));
        mask->setText(QString());
        nombre->setText(QCoreApplication::translate("TarjetaPlatillo", "Hamburguesa", nullptr));
        img->setText(QString());
        bg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TarjetaPlatillo: public Ui_TarjetaPlatillo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARJETAPLATILLO_H
