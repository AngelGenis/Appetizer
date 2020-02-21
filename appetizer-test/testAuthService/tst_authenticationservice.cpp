#include "services/authenticationservice.h"
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
    void loginIncorrecto();
    void crearNotificacion();

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
    QVERIFY(authSrv.authenticate("Jesus Morales", "1234"));
        
}
void TestAuthenticationService::loginIncorrecto()
{
    AuthenticationService authSrv;
    bool r = authSrv.authenticate("No existe", "no valido");
    qCritical() << authSrv.lastErrorMessage();
    QCOMPARE(r, false);
}

void TestAuthenticationService::crearNotificacion()
{

}

QTEST_MAIN(TestAuthenticationService)

#include "tst_authenticationservice.moc"

