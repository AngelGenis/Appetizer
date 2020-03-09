#include <QtTest>
#include "services/mesasservice.h"
// add necessary includes here

class testMesaService : public QObject
{
    Q_OBJECT

public:
    testMesaService();
    ~testMesaService();

private slots:
    void test_case1();

};

testMesaService::testMesaService()
{

}

testMesaService::~testMesaService()
{

}

void testMesaService::test_case1()
{
    MesasService srv;
    srv.createMesa(4,100,100);
}

QTEST_APPLESS_MAIN(testMesaService)

#include "tst_testmesaservice.moc"
