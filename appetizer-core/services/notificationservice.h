#ifndef NOTIFICATIONSERVICE_H
#define NOTIFICATIONSERVICE_H
#include <QWidget>

#include "notificationdialog.h"

class NotificationService
{
public:

    NotificationService(QWidget *parent);
  void notify(const QString &message,              
              Qt::AlignmentFlag position = Qt::AlignBottom, int timeOut = 0,
              NotificationDialog::Icon icon = NotificationDialog::Information);
private:
    QWidget *parentWidget;
};

#endif // NOTIFICATIONSERVICE_H
