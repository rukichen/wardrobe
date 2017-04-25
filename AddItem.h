#ifndef ADDITEM_H
#define ADDITEM_H

#pragma once

#include <QDialog>
#include <QMessageBox>
#include <QVariant>

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


private:
    Ui::AddItem *ui;
};

#endif // ADDITEM_H
