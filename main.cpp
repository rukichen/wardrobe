#include "MainWindow.h"
#include "dataaccess.h"
#include <QApplication>
#include <QWidget>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w ;

    w.show();
    Init();
    return a.exec();
}

