#ifndef CREATDB_H
#define CREATDB_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include "MainWindow.h"

QVariant addType(QSqlQuery &query, const QString &name)
{
    query.addBindValue(name);
    query.exec();
    return query.lastInsertId();
}

void addKimono(QSqlQuery &q, const QString &name, const QVariant &typeId)
{
    q.addBindValue(name);
    q.addBindValue(typeId);

    q.exec();
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
    if(!query.exec(QLatin1String("create table type( id INTEGER PRIMARY KEY, name varchar)")));
        return query.lastError();

        if (!query.prepare(QLatin1String("insert into types(name) values(?)")))
            return query.lastError();


        QVariant komon = addType(query, QLatin1String("Komon"));
        QVariant iromuji = addType(query, QLatin1String("Iromuji"));
        QVariant yukata = addType(query, QLatin1String("Yukata"));

        return QSqlError();
}


#endif // CREATDB_H
