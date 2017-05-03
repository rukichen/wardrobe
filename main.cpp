//used https://github.com/open-source-parsers/jsoncpp#generating-amalgamated-source-and-header for json

#include "dataaccess.h"
#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w ;

    w.show();

    dataaccess *data = new dataaccess();
    data->Init();
    w.load();

    return a.exec();
}


