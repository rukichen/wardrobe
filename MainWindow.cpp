#include "MainWindow.h"
#include "creatdb.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // -- DATABASE INIT --
    CreatDB * db = new CreatDB;
    db->DatabaseConnect();
    db->DatabaseInit();
    db->DatabasePopulate();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::OnSearchClicked()
//{
//    QSqlQuery query;
//    query.prepare("SELECT name FROM people WHERE id = ?");
//    query.addBindValue(mInputText->text().toInt());

//    if(!query.exec())
//        qWarning() << "MainWindow::OnSearchClicked - ERROR: " << query.lastError().text();

//    if(query.first())
//        mOutputText->setText(query.value(0).toString());
//    else
//        mOutputText->setText("person not found");
//}

