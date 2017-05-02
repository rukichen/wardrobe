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
    QStringList headers = QStringList() << "Name" << "Type";
        model.setHorizontalHeaderLabels(headers);
        model.setColumnCount(headers.size());
        const int rowCount = 5;
        for (int row = 0; row < rowCount; row++) {
            QList <QStandardItem *> rowItems;

            for (int column = 0; column < model.columnCount(); column++) {
                QStandardItem* item = new QStandardItem(QString("%1_%2x%3").arg(headers[column]).arg(row).arg(column));
                rowItems.append(item);
            }

            model.appendRow(rowItems);
        }
        ui->tableView->setModel(&model);
}
void MainWindow::load(QStandardItemModel& model){
    QFile file ;
    file.setFileName("data/data.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
    }
    QList<QString> myIdList = QList<QString>();

    QByteArray saveData = file.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);
    QJsonObject json = loadDoc.object();
    QJsonArray data = json["Kimono"].toArray();
    while (model.rowCount() > 0) {
        model.invisibleRootItem()->removeRow(0);
    }
    const int rowCount = 2;
    foreach (const QJsonValue & value, data) {
        QJsonObject obj = value.toObject();
        QString inner_id = obj["id"].toString();
        myIdList.append(inner_id);
        const int columnCount = myIdList.size();


    model.setRowCount(rowCount);
    model.setColumnCount(columnCount);
}
