#include <QtTest>

#include <QSignalSpy>
// add necessary includes here

#include "notificationdialog.h"

class TestNotifications : public QObject
{
    Q_OBJECT

public:
    TestNotifications();
    ~TestNotifications();

private slots:
    void testNotification();

};

TestNotifications::TestNotifications()
{

}

TestNotifications::~TestNotifications()
{

}

void TestNotifications::testNotification()
{
    NotificationDialog dialog;
    QSignalSpy spy(&dialog, &NotificationDialog::finished);
    dialog.setPosition(Qt::AlignCenter);
    dialog.exec();
    QCOMPARE(spy.count(), 1);
    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).toInt(), dialog.result());
}

QTEST_MAIN(TestNotifications)

#include "tst_testnotifications.moc"
