/********************************************************************************
** Form generated from reading UI file 'roles.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLES_H
#define UI_ROLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Roles
{
public:
    QLabel *foto;
    QLabel *nombre;
    QLabel *label;
    QLabel *label_selected;
    QLabel *nombre_selected;

    void setupUi(QWidget *Roles)
    {
        if (Roles->objectName().isEmpty())
            Roles->setObjectName(QString::fromUtf8("Roles"));
        Roles->resize(345, 56);
        Roles->setCursor(QCursor(Qt::PointingHandCursor));
        Roles->setStyleSheet(QString::fromUtf8("background: #F5F6FA;\n"
"border: none;"));
        foto = new QLabel(Roles);
        foto->setObjectName(QString::fromUtf8("foto"));
        foto->setGeometry(QRect(20, 9, 37, 37));
        foto->setStyleSheet(QString::fromUtf8("background: #637283;\n"
"border: none;"));
        foto->setPixmap(QPixmap(QString::fromUtf8(":/Img/face.png")));
        foto->setAlignment(Qt::AlignCenter);
        nombre = new QLabel(Roles);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setGeometry(QRect(75, 10, 271, 41));
        nombre->setStyleSheet(QString::fromUtf8("color: #637283;\n"
"background: none;"));
        label = new QLabel(Roles);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(5, 0, 339, 55));
        label->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-radius: 8px;\n"
"background: #FFF;"));
        label_selected = new QLabel(Roles);
        label_selected->setObjectName(QString::fromUtf8("label_selected"));
        label_selected->setGeometry(QRect(5, 0, 339, 55));
        label_selected->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-radius: 8px;\n"
"background:#3C6AF1;;"));
        nombre_selected = new QLabel(Roles);
        nombre_selected->setObjectName(QString::fromUtf8("nombre_selected"));
        nombre_selected->setGeometry(QRect(75, 7, 261, 41));
        nombre_selected->setStyleSheet(QString::fromUtf8("color: rgba(255, 255, 255, 0.83);\n"
"background: none;"));
        label->raise();
        nombre->raise();
        label_selected->raise();
        nombre_selected->raise();
        foto->raise();

        retranslateUi(Roles);

        QMetaObject::connectSlotsByName(Roles);
    } // setupUi

    void retranslateUi(QWidget *Roles)
    {
        Roles->setWindowTitle(QCoreApplication::translate("Roles", "Form", nullptr));
        foto->setText(QString());
        nombre->setText(QCoreApplication::translate("Roles", "Mesero", nullptr));
        label->setText(QString());
        label_selected->setText(QString());
        nombre_selected->setText(QCoreApplication::translate("Roles", "Mesero", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Roles: public Ui_Roles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLES_H
