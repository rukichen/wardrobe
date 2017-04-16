
#include <QDebug>


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

        if (!q.prepare(QLatin1String("insert into types(name) values(?)")))
            return q.lastError();
        QVariant komon = addGenre(q, QLatin1String("Komon"));
        QVariant iromuji = addGenre(q, QLatin1String("Iromuji"));
        QVariant yukata = addGenre(q, QLatin1String("Yukata"));

        return QSqlError();
}



