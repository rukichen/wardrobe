﻿#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QStandardItemModel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QListView>
#include "dataaccess.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void load();
    QStandardItemModel *model;

public slots:
    void addItemWindow();
    void showItem();



private slots:
    //void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
