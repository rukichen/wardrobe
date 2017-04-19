#include <QDir>
#include <QString>
#include <iostream>
#include <fstream>
#include <json/json.h>



void Init(){
    QString path = "data";
    QDir dir(path);

    if (!dir.exists()) {
        dir.mkdir(path);
    }
    path = "data/images";
    QDir dir2(path);

    if (!dir2.exists()) {
        dir2.mkpath("images");
    }

//    char filename[ ] = "data.txt";
//    std::fstream appendFileToWorkWith;

//    appendFileToWorkWith.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);


//    // If file does not exist, Create new file
//    if (!appendFileToWorkWith ) {
//        std::cout << "Cannot open file, file does not exist. Creating new file..";

//        appendFileToWorkWith.open(filename,  std::fstream::in | std::fstream::out | std::fstream::trunc);
//        appendFileToWorkWith <<"\n";
//        appendFileToWorkWith.close();
//    }else{    // use existing file
//        std::cout<<"success "<<filename <<" found. \n";
//        std::cout<<"\nAppending writing and working with existing file"<<"\n---\n";

//        appendFileToWorkWith << "Appending writing and working with existing file"<<"\n---\n";
//        appendFileToWorkWith.close();
//        std::cout<<"\n";
//    }
    //datei items.json
    //datei einlesen

    //für die Datein jeweils eine exsistenzabfrage
    //
}

void addItem(){

}

