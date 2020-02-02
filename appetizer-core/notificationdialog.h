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
    explicit NotificationDialog(QWidget *parent = nullptr);
    ~NotificationDialog();
    void done(int r) override;
    void open() override;
    void setMessage(const QString &message);
    void animate(bool reverse = false);
    void setPosition(Qt::AlignmentFlag position);

signals:
    void reverseAnimStarted();
private:
    Ui::NotificationDialog *ui;
    bool animation_on;
    Qt::AlignmentFlag currentPos;
    QPoint pos1;
    QPoint pos2;
};

#endif // NOTIFICATIONDIALOG_H
