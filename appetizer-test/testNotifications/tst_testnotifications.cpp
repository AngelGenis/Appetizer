#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "notificationdialog.h"

class TestNotifications : public QObject
{
    Q_OBJECT

public:
    TestNotifications();
    ~TestNotifications();

private slots:
    void test_case1();

};

TestNotifications::TestNotifications()
{

}

TestNotifications::~TestNotifications()
{

}

void TestNotifications::test_case1()
{
    NotificationDialog dialog;
    dialog.exec();
}

QTEST_MAIN(TestNotifications)

#include "tst_testnotifications.moc"
