#ifndef CREATDB_H
#define CREATDB_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>

#include "creatdb.h"
#include "MainWindow.h"

QVariant addGenre(QSqlQuery &query, const QString &name)
{
    query.addBindValue(name);
    query.exec();
    return query.lastInsertId();
}


QSqlError DatabaseInit()
{
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("./testdatabase.db");

    if(!db.open())
        return db.lastError();

    QStringList tables = db.tables();
    if(tables.contains("kimono", Qt::CaseInsensitive)&& tables.contains("obi", Qt::CaseInsensitive))
        return QSqlError();

    QSqlQuery query;
    if(!query.exec(QLatin1String("CREATE TABLE kimono (id INTEGER PRIMARY KEY, name varchar, type integer )")))
        return query.lastError();
    if(!query.exec(QLatin1String("CREATE TABLE obi (id INTEGER PRIMARY KEY, name varchar, type integer )")))
        return query.lastError();
    if(!query.exec(QLatin1String("create table type( id interger primary key, name varchar)")));
        return query.lastError();

        if (!query.prepare(QLatin1String("insert into types(name) values(?)")))
            return query.lastError();
        QVariant komon = addGenre(query, QLatin1String("Komon"));
        QVariant iromuji = addGenre(query, QLatin1String("Iromuji"));
        QVariant yukata = addGenre(query, QLatin1String("Yukata"));

        return QSqlError();
}


#endif // CREATDB_H
