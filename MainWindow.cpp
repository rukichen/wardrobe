#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "AddItem.h"

#include <QDebug>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QModelIndex>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




//    if (!QSqlDatabase::drivers().contains("QSQLITE"))
//            QMessageBox::critical(this, "Unable to load database",
//                                  "This demo needs the SQLITE driver");

//// -- DATABASE INIT --
//    QSqlError err = DatabaseInit();
//    if (err.type() != QSqlError::NoError) {
//        showError(err);
//        return;
//    }

////set database model
//    model = new QSqlRelationalTableModel(ui->tableView);
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->setTable("kimono");

////remember the indexes of the collums
//    typeIdx = model->fieldIndex("type");

////set relations
//    model->setRelation(typeIdx, QSqlRelation("type","id", "name"));

//    model->setHeaderData(model->fieldIndex("name"), Qt::Horizontal, tr("name"));
//    model->setHeaderData(typeIdx, Qt::Horizontal, tr("type"));

//    if (!model->select())
//    {
//        showError(model->lastError());
//        return;
//    }

//    ui->tableView->setModel(model);
//    ui->tableView->setColumnHidden(model->fieldIndex("id"),true);
//    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
//    ui->tableView->setCurrentIndex(model->index(0, 0));

//button
   connect(ui->AddItem, SIGNAL(clicked()),this, SLOT(addItemWindow()));

}


//void MainWindow::showError(const QSqlError &err)
//{
//    QMessageBox::critical(this, "Unable to initialize Database",
//                "Error initializing database: " + err.text());
//}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addItemWindow(){
    AddItem *winAdd = new AddItem();
    winAdd->show();
    winAdd->exec();
}

