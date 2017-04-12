#include "MainWindow.h"
#include <QApplication>
#include <QtWidgets/QTableView>
#include "ui_layout.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTableView tableView;
    QWidget *widget = new QWidget;
    Ui::MainWindow w;
    w.setupUi(widget);

    //tableView.setModel( &w);
    widget->show();


    return a.exec();
}
