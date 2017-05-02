#include "dataaccess.h"
dataaccess::dataaccess()
{

}

void dataaccess::Init(){
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
    char filename[ ] = "data/data.txt";
    std::fstream appendFileToWorkWith;

    appendFileToWorkWith.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);

    // If file does not exist, Create new file
    if (!appendFileToWorkWith ) {
       std::cout << "Cannot open file, file does not exist. Creating new file..";
       appendFileToWorkWith <<"\n";
       appendFileToWorkWith.open(filename,  std::fstream::in | std::fstream::out | std::fstream::trunc);
       appendFileToWorkWith.close();
    }else{    // use existing file
        appendFileToWorkWith.close();
    }
    //datei einlesen

    //für die Datein jeweils eine exsistenzabfrage
    //
}

void dataaccess::read(){
    QString val;
    QFile file;
    file.setFileName("data/data.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Failed to open";
        exit(1);
    }

    QTextStream file_text(&file);
    QString json_string;
    json_string = file_text.readAll();
    //val = file.readAll();
    file.close();

    qWarning() << json_string;
    QByteArray json_bytes = json_string.toLocal8Bit();

    QJsonDocument json_doc = QJsonDocument::fromJson(json_bytes);

    if(json_doc.isNull()){
        qDebug()<<"failed to crete json doc";
        exit(2);
    }
    if(!json_doc.isObject()){
        qDebug()<<"Json is not an object";
        exit(3);
    }
    QJsonObject json_obj = json_doc.object();

    if(json_obj.isEmpty()){
    qDebug()<<"json is empty";
    exit(4);
    }

    QVariantMap json_map = json_obj.toVariantMap();
}

void dataaccess::addNewItem(QString name, QString typetmp)
{
    //read file
    QFile file ;
    file.setFileName("data/data.txt"); //set pfad
    file.open(QIODevice::ReadOnly | QIODevice::Text); //open file
    QString val = file.readAll();
    file.close();

    // parse to jsonDoc
    QJsonDocument jsonDoc = QJsonDocument::fromJson(val.toUtf8());
    //qWarning() << jsonDoc.isNull();

    QJsonObject jo = jsonDoc.object();

//get the array for kimono
    QJsonArray array = jo.value("Kimono").toArray();

//find highest id
    QString id = "0";
    int max = 0;

    QList<QString> myIdList = QList<QString>();

    if( jo.isEmpty()){
        id = "10001";
    }else{
        foreach (const QJsonValue & value, array) {
            QJsonObject obj = value.toObject();
            QString inner_id = obj["id"].toString();
            myIdList.append(inner_id);
            int temp = inner_id.toInt();
            if(max < temp){
                max = temp;
            }
        }
        max++;
        id = QString::number(max);
    }

    int place = myIdList.size();
    qDebug() << myIdList;

    QJsonObject newItem;
    newItem["id"] = id;
    newItem["kimono"] = name;
    newItem["type"] = typetmp;

    array.insert(place,newItem);
    jo.insert("Kimono",array);

    QJsonDocument saveDoc(jo);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write(saveDoc.toJson());
    file.close();

}


