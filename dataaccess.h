#pragma once

#include <iostream>
#include <fstream>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QVariantMap>
#include "MainWindow.h"

class dataaccess
{


public:
    explicit dataaccess();
    ~dataaccess();

    void Init();
    QJsonArray read(QString file_name, QString category);
    QJsonArray find(QString file_name, QString id);
    void edit(QString file_name, QString id);
    void addNewItem(QString name, QString typetmp);
};

