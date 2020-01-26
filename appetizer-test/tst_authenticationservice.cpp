#include "authenticationservice.h"
#include <QtTest>


// add necessary includes here

class TestAuthenticationService : public QObject
{
    Q_OBJECT

public:
    TestAuthenticationService();
    ~TestAuthenticationService();

private slots:
    void loginCorrecto();

};

TestAuthenticationService::TestAuthenticationService()
{

}

TestAuthenticationService::~TestAuthenticationService()
{

}

void TestAuthenticationService::loginCorrecto()
{

    AuthenticationService authSrv;
    try {
        QVERIFY(authSrv.authenticate("testUser", "testUser"));
    } catch (AuthenticationException &e) {
        qCritical() << e.what();
    }
}

QTEST_APPLESS_MAIN(TestAuthenticationService)

#include "tst_authenticationservice.moc"

