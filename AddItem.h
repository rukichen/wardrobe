#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include <QMessageBox>
#include "dataaccess.h"


namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = 0);
    ~AddItem();

    QString getName();
    QVariant getType();


private slots:
    void addedItem();


private:
    Ui::AddItem *ui;
    QString name;
    QVariant type;
    QString typetmp;
};

#endif // ADDITEM_H
