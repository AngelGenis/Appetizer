#include "notificationservice.h"


NotificationService::NotificationService(QWidget *parent) :
    parentWidget(parent)
{

}

void NotificationService::notify(const QString &message,                          
                                 Qt::AlignmentFlag position, int timeout,
                                 NotificationDialog::Icon icon)
{
    
    auto dialog = new NotificationDialog(parentWidget, timeout, icon);
    dialog->setMessage(message);
    dialog->setPosition(position);
    dialog->open();
}
