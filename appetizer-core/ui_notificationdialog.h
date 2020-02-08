/********************************************************************************
** Form generated from reading UI file 'notificationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATIONDIALOG_H
#define UI_NOTIFICATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotificationDialog
{
public:
    QGridLayout *gridLayout;
    QWidget *container;
    QHBoxLayout *horizontalLayout;
    QLabel *message;
    QPushButton *pushButton;

    void setupUi(QDialog *NotificationDialog)
    {
        if (NotificationDialog->objectName().isEmpty())
            NotificationDialog->setObjectName(QString::fromUtf8("NotificationDialog"));
        NotificationDialog->resize(484, 108);
        NotificationDialog->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(NotificationDialog);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        container = new QWidget(NotificationDialog);
        container->setObjectName(QString::fromUtf8("container"));
        container->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-radius: 8px;\n"
"background: #FFF;\n"
"\n"
"QLabel#message, QPushButton#pushButton, QWidget#widget {\n"
"border: none;\n"
"border-radius: 0px;\n"
"background: none\n"
"}"));
        horizontalLayout = new QHBoxLayout(container);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        message = new QLabel(container);
        message->setObjectName(QString::fromUtf8("message"));
        message->setAlignment(Qt::AlignCenter);
        message->setWordWrap(true);

        horizontalLayout->addWidget(message);

        pushButton = new QPushButton(container);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(32, 32));
        QFont font;
        font.setPointSize(24);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);

        gridLayout->addWidget(container, 0, 0, 1, 1);


        retranslateUi(NotificationDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), NotificationDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(NotificationDialog);
    } // setupUi

    void retranslateUi(QDialog *NotificationDialog)
    {
        NotificationDialog->setWindowTitle(QCoreApplication::translate("NotificationDialog", "Dialog", nullptr));
        message->setText(QCoreApplication::translate("NotificationDialog", "_message_", nullptr));
        pushButton->setText(QCoreApplication::translate("NotificationDialog", "\303\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotificationDialog: public Ui_NotificationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATIONDIALOG_H
