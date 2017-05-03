#pragma once

#include "ui_AddItem.h"
#include "AddItem.h"

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(input()));


 }

AddItem::~AddItem()
{
    delete ui;
}
QString AddItem::getName(){
    return ui->name->text();
}

QVariant AddItem::getType(){
   return ui->comboBox->itemText(ui->comboBox->currentIndex());
}

void AddItem::input(){

}

void AddItem::on_saveButton_clicked()
{
    QString name = getName();
    QString typetmp = (getType()).toString();
    dataaccess *data = new dataaccess();

    data->addNewItem(name, typetmp);
    this->close();
    MainWindow *main = new MainWindow();
    main->load();
}
