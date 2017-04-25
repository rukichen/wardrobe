#pragma once

#include <iostream>
#include <fstream>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>

#include "AddItem.h"

void Init(){
    QString path = "data";
    QDir dir(path);

    if (!dir.exists()) {
        dir.mkdir(path);
    }
    QDir dir2(path);

    if (!dir2.exists()) {
        dir2.mkpath("images");
    }
    //CREATE JSON FILE
    char filename[ ] = "data/data.json";
    std::fstream appendFileToWorkWith;

    appendFileToWorkWith.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);

    // If file does not exist, Create new file
    if (!appendFileToWorkWith ) {
       std::cout << "Cannot open file, file does not exist. Creating new file..";

        appendFileToWorkWith.open(filename,  std::fstream::in | std::fstream::out | std::fstream::trunc);
        appendFileToWorkWith <<"\n";
        appendFileToWorkWith.close();
    }else{    // use existing file
        appendFileToWorkWith << "Appending writing and working with existing file"<<"\n---\n";
        appendFileToWorkWith.close();
    }
    //datei einlesen

    //für die Datein jeweils eine exsistenzabfrage
    //
}

void read(){
    QString val;
    QFile file;
    file.setFileName("data/data.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("appName"));
    qWarning() << value;
    QJsonObject item = value.toObject();
    qWarning() << QObject::tr("QJsonObject of description: ") << item;

    /* in case of string value get value and convert into string*/
    qWarning() << QObject::tr("QJsonObject[appName] of description: ") << item["description"];
    QJsonValue subobj = item["description"];
    qWarning() << subobj.toString();

    /* in case of array get array and convert into string*/
    qWarning() << QObject::tr("QJsonObject[appName] of value: ") << item["imp"];
    QJsonArray test = item["imp"].toArray();
    qWarning() << test[1].toString();
}

void addNewItem(){
 AddItem *add = new AddItem();
 QString name = add->getName();
 QString typetmp = (add->getType()).toString();

QFile file ;
file.setFileName("data/data.json");
QString inputData;
bool updateVal;
if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
    inputData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(inputData.toUtf8());
    QJsonObject jo = jsonDoc.object();
    QJsonValue value = jo.value(QString());

    QJsonObject obj;
    QJsonArray itemArray;
     QJsonObject newItem;
    newItem["id"] = 1;
    newItem["kimono"] = name;
    newItem["type"] = typetmp;
    itemArray.append(newItem);
    obj["kimono"] = itemArray;

    file.write(jsonDoc.toJson());
    file.close();
}

}
