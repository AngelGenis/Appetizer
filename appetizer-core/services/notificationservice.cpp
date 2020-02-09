#include "notificationservice.h"
#include "notificationdialog.h"


NotificationService::NotificationService(QWidget *parent) :
    parentWidget(parent)
{

}

void NotificationService::notify(const QString &message, Qt::AlignmentFlag position, int timeout)
{
    auto dialog = new NotificationDialog(parentWidget, timeout);
    dialog->setMessage(message);
    dialog->setPosition(position);
    dialog->open();
}
