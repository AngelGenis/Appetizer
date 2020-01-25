#include "databaseconnection.h"
#include <QSettings>
#include <QDebug>
#include <QSqlError>
#include <QApplication>

QSqlDatabase DatabaseConnection::db = QSqlDatabase();

DatabaseConnection::DatabaseConnection()
{

}
/*
 * Método estático que conecta a la base de datos.
 * Regresa un objeto QSqlDatabase que representa la
 * conección gestionada por QT
 */
QSqlDatabase &DatabaseConnection::connect()
{
    if(db.isValid())
        return db;
    QString settingsFile = QApplication::applicationDirPath() + "/db.conf";

    QSettings settings(settingsFile, QSettings::NativeFormat);
    settings.beginGroup("connection");
    QString dbname = settings.value("dbname", "Appetizer").toString();
    QString host = settings.value("host", "localhost").toString();
    QString user = settings.value("user", "root").toString();
    QString password = settings.value("password", "").toString();
    settings.endGroup();

#ifdef Q_OS_WIN
    db = QSqlDatabase::addDatabase("QODBC");
#else
    db = QSqlDatabase::addDatabase("QMYSQL");
#endif
    db.setDatabaseName(dbname);
    db.setHostName(host);
    db.setUserName(user);
    db.setPassword(password);

    if(db.open())
        qInfo() << "Conexión con la base de datos establecida éxitosamente";
    else
        qCritical() << "Error de conexión a la base de datos: " << db.lastError().text();

    return db;
}
