#ifndef DATAACCESS
#define DATAACCESS

#include <QDir>
#include <QString>
#include

void Init(){
    QString path = "/data";
    QDir dir(path);

    if (!dir.exists()) {
        dir.mkdir(path);
    }


    if (!dir.exists()) {
        dir.mkpath("images");
    }
    //datei items.json
    //datei einlesen

    //für die Datein jeweils eine exsistenzabfrage
    //
}

void addItem(){

}

#endif // DATAACCESS

