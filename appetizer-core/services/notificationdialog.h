#ifndef NOTIFICATIONDIALOG_H
#define NOTIFICATIONDIALOG_H

#include <QDialog>

namespace Ui {
class NotificationDialog;
}


class NotificationDialog : public QDialog
{
    Q_OBJECT

public:
    enum Icon {Information, Warning, Error, Succes};
    explicit NotificationDialog(QWidget *parent = nullptr, int timeout = 0, Icon icon = Information);
    ~NotificationDialog();
    void done(int r) override;
    void open() override;
    void setMessage(const QString &message);
    void animate(bool reverse = false);
    void setPosition(Qt::AlignmentFlag position);
    void setMessageIcon(Icon icon);
    // si ms <= 0, se desactiva el auto cerrado
    void setTimeOut(int ms);
private:
    void autoClose();
    
signals:
    void reverseAnimStarted();
private:
    Ui::NotificationDialog *ui;
    bool animation_on;
    Qt::AlignmentFlag currentPos;
    QPoint pos1;
    QPoint pos2;
    // si timeout <= 0, se desactiva el auto cerrado
    int timeOut;
    
};

#endif // NOTIFICATIONDIALOG_H
