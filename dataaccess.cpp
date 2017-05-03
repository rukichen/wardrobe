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
}

QJsonArray dataaccess::read(QString file_name, QString category){
    //read file
    QFile file ;
    file.setFileName("data/" + file_name + ".txt"); //set pfad
    file.open(QIODevice::ReadOnly | QIODevice::Text); //open file
    QString val = file.readAll();
    file.close();

    // parse to jsonDoc
    QJsonDocument jsonDoc = QJsonDocument::fromJson(val.toUtf8());
    //qWarning() << jsonDoc.isNull();

    QJsonObject jo = jsonDoc.object();
    //get the array for kimono
    QJsonArray array = jo.value(category).toArray();
    return array;
}

QJsonArray dataaccess::find(QString file_name, QString id){

}

void dataaccess::edit(QString file_name, QString id){

}

//in this method the wanted file is read and the new item is put
//at the end of the file with a new ID
void dataaccess::addNewItem(QString name, QString typetmp)
{
//read file
    QFile file ;
//set pfad
    file.setFileName("data/data.txt");
//open file
    file.open(QIODevice::ReadOnly | QIODevice::Text);
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


