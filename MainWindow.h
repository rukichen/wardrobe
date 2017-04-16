#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtWidgets>
#include <QSqlRelationalTableModel>


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

public slots:
    void addItemWindow();


private:
    void showError(const QSqlError &err);

    Ui::MainWindow *ui;
    QSqlRelationalTableModel *model;

    int typeIdx;

};

#endif // MAINWINDOW_H
