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
    char filename[ ] = "data/data.json";
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
    file.setFileName("data/data.json");
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

void dataaccess::addNewItem(QString name, QString typetmp){

QFile file ;
file.setFileName("data/data.json"); //set pfad

file.open(QIODevice::ReadWrite | QIODevice::Text); //open file
QString val = file.readAll(); //read file

QJsonDocument jsonDoc = QJsonDocument::fromJson(val.toUtf8());
QJsonObject jo = jsonDoc.object();
QJsonArray array = jo.value(QString()).toArray();

//find highest id

QJsonValue value =jo.value("id");
QJsonArray arr = value.toArray();

for( int i = 0, i)

 QJsonArray itemArray;
    QJsonObject newItem;
    newItem["id"] = 1;
    newItem["kimono"] = name;
    newItem["type"] = typetmp;
    itemArray.append(newItem);
   // obj["kimono"] = itemArray;
    array.append(itemArray);

    QJsonDocument saveDoc(newItem);
    file.write(saveDoc.toJson());
    file.close();

    //Edit
//    QJsonObject RootObject = JsonDocument.object();
//    QJsonValueRef ArrayRef = RootObject.find("array").value();
//    QJsonArray Array = ArrayRef.toArray();

//    QJsonArray::iterator ArrayIterator = Array.begin();
//    QJsonValueRef ElementOneValueRef = ArrayIterator[0];

//    QJsonObject ElementOneObject = ElementOneValueRef.toObject();

//    // Make modifications to ElementOneObject

//    ElementOneValueRef = ElementOneObject;
//    ArrayRef = Array;
//    JsonDocument.setObject(RootObject);


}
