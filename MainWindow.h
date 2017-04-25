#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QWidget>

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


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
