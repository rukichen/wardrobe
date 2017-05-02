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

   QIcon icon (":/img/folder.png");
   QStringList list = load();

    ui->listWidget->setIconSize(QSize(100,100));
   for(int i = 0; i < list.size(); i++){
       QString name  = list[i];
       QListWidgetItem *item = new QListWidgetItem(icon,name);
       ui->listWidget->addItem(item);

   }

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
QStringList MainWindow::load(){
    //read file
    QFile file ;
    file.setFileName("data/data.txt"); //set pfad
    file.open(QIODevice::ReadOnly | QIODevice::Text); //open file
    QString val = file.readAll();
    file.close();

    QStringList myList ;

    // parse to jsonDoc
    QJsonDocument jsonDoc = QJsonDocument::fromJson(val.toUtf8());
    qWarning() << jsonDoc.isNull();

    QJsonObject json = jsonDoc.object();
    QJsonArray data = json.value("Kimono").toArray();

    foreach (const QJsonValue & value, data) {
        QJsonObject obj = value.toObject();
        QString name = obj["kimono"].toString();
        myList.append(name);

    }

 return myList;

}

//void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
//{

//}
