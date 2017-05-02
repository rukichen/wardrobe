#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addItemWindow();
    void showItem();
    void load(QStandardItemModel& model);


private:
    Ui::MainWindow *ui;
    QTableView view;
    QStandardItemModel model;

};

#endif // MAINWINDOW_H
