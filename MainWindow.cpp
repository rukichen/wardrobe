#include "MainWindow.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

#include "creatdb.h"

MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
{
    // window title
    setWindowTitle("Qt SQL and SQLite");

    // -- set fixed size --
    const int WIN_W = 320;
    const int WIN_H = 320;
    setMinimumSize(WIN_W, WIN_H);
    setMaximumSize(WIN_W, WIN_H);

    // create GUI
    BuildWindow();

    // -- DATABASE INIT --
    CreatDB * db = new CreatDB;
    db->DatabaseConnect();
    db->DatabaseInit();
    db->DatabasePopulate();

    QAction *quit = new QAction("&Quit", this);
    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

// ===== PRIVATE =====
void MainWindow::BuildWindow()
{
    QWidget * content = new QWidget;
    setCentralWidget(content);

    // main layout
    QVBoxLayout * layoutMain = new QVBoxLayout;
    content->setLayout(layoutMain);

    // -- VERT SPACER --
    layoutMain->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));

    // -- INPUT ROW --
    QHBoxLayout * layoutRow = new QHBoxLayout;
    layoutMain->addLayout(layoutRow);

    // input field
    mInputText = new QLineEdit;
    mInputText->setValidator(new QIntValidator(mInputText));

    connect(mInputText, &QLineEdit::textChanged, this, &MainWindow::OnInput);

    layoutRow->addWidget(mInputText);

    // search button
    mButtonSearch = new QPushButton("SEARCH");
    mButtonSearch->setEnabled(false);

    connect(mButtonSearch, &QPushButton::clicked, this, &MainWindow::OnSearchClicked);

    layoutRow->addWidget(mButtonSearch);

    // -- OUTPUT ROW --
    mOutputText = new QLabel("...");
    mOutputText->setAlignment(Qt::AlignCenter);
    layoutMain->addWidget(mOutputText);

    // -- VERT SPACER --
    layoutMain->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));
}



//void MainWindow::createActions()
//{
//    newAction = new QAction(tr("&New"), this);
//    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));
//}
//void MainWindow::createMenus()
//{

//    fileMenu = menuBar()->addMenu(tr("&File"));
//    fileMenu->addAction(newAction);
//}



// ===== PRIVATE SLOTS =====
void MainWindow::OnInput()
{
    if(mInputText->text().length() > 0)
        mButtonSearch->setEnabled(true);
    else
        mButtonSearch->setEnabled(false);
}

void MainWindow::OnSearchClicked()
{
    QSqlQuery query;
    query.prepare("SELECT name FROM people WHERE id = ?");
    query.addBindValue(mInputText->text().toInt());

    if(!query.exec())
        qWarning() << "MainWindow::OnSearchClicked - ERROR: " << query.lastError().text();

    if(query.first())
        mOutputText->setText(query.value(0).toString());
    else
        mOutputText->setText("person not found");
}
