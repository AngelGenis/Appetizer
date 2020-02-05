#include "notificationdialog.h"
#include "ui_notificationdialog.h"
#include <QDesktopWidget>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>

NotificationDialog::NotificationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotificationDialog),
    animation_on(false),
    currentPos(Qt::AlignCenter)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Popup | Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground); 
    setModal(false);
    connect(this, &NotificationDialog::reverseAnimStarted,
            [this] {animation_on = true; });

    QGraphicsDropShadowEffect *dropshadow = new QGraphicsDropShadowEffect(this);
    dropshadow->setXOffset(0);
    dropshadow->setYOffset(0);
    dropshadow->setBlurRadius(10);
    dropshadow->setColor(QColor::fromRgb(0, 0, 0, 70));
    ui->container->setGraphicsEffect(dropshadow);
    setPosition(currentPos);

}

NotificationDialog::~NotificationDialog()
{
    delete ui;
}

void NotificationDialog::open()
{
    animate(false);
    QDialog::open();
}

void NotificationDialog::done(int r)
{
    if (!animation_on) {
        animate(true);
        setResult(r);
        if (r == QDialog::Accepted)
            emit accepted();
        else if (r == QDialog::Rejected)
            emit rejected();

        emit finished(r);
    }
}
void NotificationDialog::animate(bool reverse)
{
    auto animFade= new QPropertyAnimation(this, "windowOpacity", this);
    animFade->setDuration(400);
    animFade->setEasingCurve(QEasingCurve::Linear);

   

    auto animMove = new QPropertyAnimation(this, "pos", this);
    animMove->setDuration(250);
    animMove->setEasingCurve(QEasingCurve::OutQuad);

    if (!reverse) {
        animFade->setStartValue(0.0);
        animFade->setEndValue(1.0);
        animMove->setStartValue(pos2);
        animMove->setEndValue(pos1);

    } else {
        emit reverseAnimStarted();
        animFade->setStartValue(1.0);
        animFade->setEndValue(0.0);
        animMove->setStartValue(pos1);
        animMove->setEndValue(pos2);

        connect(animFade, &QPropertyAnimation::finished,
                [this] { QDialog::hide(); });
    }

    animFade->start(QAbstractAnimation::DeleteWhenStopped);
    animMove->start(QAbstractAnimation::DeleteWhenStopped);
}

void NotificationDialog::setMessage(const QString &message)
{
    ui->message->setText(message);
}

void NotificationDialog::setPosition(Qt::AlignmentFlag position)
{
    currentPos = position;
    int parentX;
    int parentY;
    int parentW;
    int parentH;

    if(parentWidget())
    {
        parentX = parentWidget()->pos().x();
        parentY = parentWidget()->pos().y();
        parentW = parentWidget()->width();
        parentH = parentWidget()->height();
    }
    else
    {
        parentX = qApp->desktop()->pos().x();
        parentY = qApp->desktop()->pos().y();
        parentW = qApp->desktop()->width();
        parentH = qApp->desktop()->height();
    }
    
    switch (currentPos) {
    case Qt::AlignTop: {
        pos1  = QPoint{ (parentX + parentW / 2 - width() / 2) + 15,
                        (parentY + 15 + height() / 2) / 2 };
        pos2  = QPoint{ (parentX + parentW / 2 - width() / 2) + 15,
                        (parentY + 15 + height() / 2) / 2 - 65 };
        break;
    }
    case Qt::AlignBottom: {
        pos1  = QPoint{ (parentX + parentW / 2 - width() / 2),
                        (parentY + parentH - height() / 2 - 15) };
        
        pos2  = QPoint{ (parentX + parentW / 2 - width() / 2),
                        (parentY + parentH + height() / 2 + 15) + 65 };
        break;
    }
    case Qt::AlignLeft: {
        pos1  = QPoint{ parentX + 15,
                        (parentY + parentH / 2) };
        
        pos2  = QPoint{ parentX - 15 - width() - 65,
                        (parentY + parentH / 2)};
        break;
    }
    case Qt::AlignRight: {
        pos1  = QPoint{ parentX + parentW -  width() - 15,
                        (parentY + parentH / 2) };
        
        pos2  = QPoint{ parentX + parentW + width() + 15 + 65,
                        (parentY + parentH / 2)};
        break;
    }
    default: {
        pos1 = QPoint{ (parentX + parentW / 2 - width() / 2),
                       (parentY + parentH + height()) / 2 + 15 };
        
        pos2 = QPoint{ (parentX + parentW / 2 - width() / 2),
                       (parentY + parentH + height()) / 2 - 65 - 15};
        break;        
    } 
    }
    move(pos1);
    
}
