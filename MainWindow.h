#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtWidgets>
#include <QSqlRelationalDelegate>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createTableView();

private:
    void showError(const QSqlError &err);
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
