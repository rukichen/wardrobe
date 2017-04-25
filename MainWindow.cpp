#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "AddItem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//button
   connect(ui->AddItem, SIGNAL(clicked()),this, SLOT(addItemWindow()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addItemWindow(){
    AddItem *winAdd = new AddItem();
    winAdd->show();
    winAdd->exec();
}

