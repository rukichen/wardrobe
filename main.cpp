#include "MainWindow.h"
#include <QApplication>
#include <QtWidgets/QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTableView tableView;
    MainWindow w;
    //tableView.setModel( &w);
    w.show();

    return a.exec();
}
