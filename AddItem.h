#ifndef ADDITEM_H
#define ADDITEM_H

#pragma once

#include <QDialog>
#include <QMessageBox>
#include <QVariant>

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


public slots:

    void input();


private slots:
    void on_saveButton_clicked();

private:
    Ui::AddItem *ui;
};

#endif // ADDITEM_H
