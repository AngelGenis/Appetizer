#include "databaseconnection.h"
#include <QtTest>


// add necessary includes here

class TestDatabaseConnection : public QObject
{
    Q_OBJECT

public:
    TestDatabaseConnection();
    ~TestDatabaseConnection();

private slots: 

    void conexionExitosa();
};

TestDatabaseConnection::TestDatabaseConnection()
{

}

TestDatabaseConnection::~TestDatabaseConnection()
{

}




void TestDatabaseConnection::conexionExitosa()
{
    try {
        QSqlDatabase &db = DatabaseConnection::connect();
        QVERIFY(db.isValid() && db.isOpen());
    } catch (DatabaseException &e) {
        qCritical() << e.what();
    }

        
}
QTEST_MAIN(TestDatabaseConnection)

#include "tst_databaseconnection.moc"

