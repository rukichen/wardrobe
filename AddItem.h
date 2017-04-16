#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QMessageBox>


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
    QSqlRelationalTableModel *model;
    QDataWidgetMapper *mapper;
    QString name;
    QVariant type;
};

#endif // ADDITEM_H
