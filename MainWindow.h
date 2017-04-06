#pragma once

#include <QMainWindow>
#include <QApplication>

class QLabel;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget * parent = 0);

private:
    void BuildWindow();


private slots:
    void OnInput();
    void OnSearchClicked();

private:
    QLineEdit * mInputText;
    QPushButton * mButtonSearch;
    QLabel * mOutputText;
};

