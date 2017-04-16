#include "AddItem.h"
#include "ui_additem.h"

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);

    setupModel();

    if(row == -1){
        model->insertRow(model->rowCount(QModelIndex()));
        mapper->toLast();
    }else{
        mapper->setCurrentIndex(model->index(row,0));;
    }

    createUI();

    connect(ui->cancleButton,SIGNAL(clicked()), this, SLOT(close()));

}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::setupModel(){
    model = new QSqlRelationalTableModel(this);
    model->setTable(DEVICE);
    model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model->select();


}

void AddItem::accept(){
    QSqlQuery query;
    QString str = QString().arg(ui->HostnameLineEdit->text(),
                 ui->name->text(),
                 model->data(model->index(mapper->currentIndex(),0), Qt::DisplayRole).toString());

    query.prepare(str);
    query.exec();
}

