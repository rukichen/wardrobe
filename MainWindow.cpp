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

void MainWindow::showItem(){


}
void MainWindow::load(){

    model = new QStandardItemModel(this);

    QList<QStandardItem*> *items = new QList<QStandardItem*> ();


    QString category = "Kimono";
    QString file = "data";
    dataaccess *reading = new dataaccess();
    QJsonArray array = reading->read(file, category);

    QList<QString> myList = QList<QString>();
    foreach (const QJsonValue & value, array) {
        QJsonObject obj = value.toObject();
        QString name = obj["kimono"].toString();
        myList.append(name);
;

    }

    QIcon icon (":/img/folder.png");

    for(int i = 0; i < myList.size(); i++){
        QString name  = myList[i];
        QListWidgetItem *item = new QListWidgetItem(icon,name);

        QStandardItem * lItem = new QStandardItem (icon, name);
        model->appendRow(lItem);

        ui->listWidget->addItem(item);

    }

    ui->listView->setIconSize(QSize(100,100));
    ui->listWidget->setIconSize(QSize(100,100));
    ui->listView->setModel(model);
}

//void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
//{

//}
