#include "creatdb.h"
#include "MainWindow.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>


void CreatDB::DatabaseConnect()
{
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName("./testdatabase.db");

        if(!db.open())
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}

void CreatDB::DatabaseInit()
{
    QSqlQuery query;
    QSqlQuery kimono("CREATE TABLE kimono (id INTEGER PRIMARY KEY, name TEXT)");
    QSqlQuery obi("CREATE TABLE obi (id INTEGER PRIMARY KEY, name TEXT)");

    if(!kimono.isActive())
         qWarning() << "CreateDB - kimono - ERROR: " << query.lastError().text();
    if(!obi.isActive())
         qWarning() << "CreateDB - obi - ERROR: " << query.lastError().text();
}

void CreatDB::DatabasePopulate()
{
    QSqlQuery query;

    if(!query.exec("INSERT INTO kimono(name) VALUES('green')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO kimono(name) VALUES('Gordon')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}

