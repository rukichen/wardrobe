#pragma once

#include <iostream>
#include <fstream>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QVariantMap>


class dataaccess
{


public:
    explicit dataaccess();
    ~dataaccess();

    void Init();
    void read();
    void addNewItem(QString name, QString typetmp);
};

