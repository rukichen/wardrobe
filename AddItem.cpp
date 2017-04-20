#include "ui_AddItem.h"
#include "AddItem.h"

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);

   // connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(addedItem()));
    connect(ui->cancleButton,SIGNAL(clicked()), this, SLOT(close()));

 }

AddItem::~AddItem()
{
    delete ui;
}
QString AddItem::getName(){
    return ui->name->text();

}

QVariant AddItem::getType(){
   return ui->comboBox->itemData(ui->comboBox->currentIndex());


}

void AddItem::addedItem()
{
    name = getName();
    type = getType();
    QString typetmp = type.toString();
    addItem(name,typetmp);

}
