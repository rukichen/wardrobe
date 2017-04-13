#include "MainWindow.h"
#include "creatdb.h"
#include "ui_mainwindow.h"

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

    if (!QSqlDatabase::drivers().contains("QSQLITE"))
            QMessageBox::critical(this, "Unable to load database",
                                  "This demo needs the SQLITE driver");

    // -- DATABASE INIT --
    QSqlError err = DatabaseInit();
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    QSqlTableModel *model = new QSqlTableModel(ui->tableView);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("kimono");

    if (!model->select()) {
        showError(model->lastError());
        return;
    }

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(model->fieldIndex("id"),true);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);


    ui->tableView->setCurrentIndex(model->index(0, 0));
}
void MainWindow::createTableView(){
    QTableView *view = new QTableView;

}

void MainWindow::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
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

