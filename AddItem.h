#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QMessageBox>
#include "creatdb.h"

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(int row = -1, QWidget *parent = 0);
    ~AddItem();
signals:
    void signalReady();

    QString getName();
    QVariant getType();

private:
    Ui::AddItem *ui;
    QSqlRelationalTableModel *model;
    QDataWidgetMapper *mapper;

    void setupModel();
    void createUI();
    void accept();
};

#endif // ADDITEM_H
