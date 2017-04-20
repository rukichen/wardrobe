#include <QDir>

#include <iostream>
#include <fstream>

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/writer.h>



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

void addItem(QString name,QString type){
    std::string newname = name.toStdString();
    std::cout << type.toStdString() << std::endl;

    Json::Value root;   // will contains the root value after parsing.
    Json::Reader reader;
    Json::StyledStreamWriter writer;
    std::ifstream test("data/data.json");
    bool parsingSuccessful = reader.parse( test, root );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse configuration: "<< reader.getFormattedErrorMessages();
    }
    std::cout << root["kimono"] << std::endl;
    std::cout << root << std::endl;
    root["kimono"] = newname;
    test.close();
    std::ofstream test1("data/data.json");
    writer.write(test1,root);
    std::cout << root << std::endl;

}

