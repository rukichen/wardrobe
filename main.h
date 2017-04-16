#include <QMainWindow>

namespace ui {
class main;
}

class main : public QMainWindow
{
    Q_OBJECT

public:
    explicit main(QWidget *parent = 0);
    ~main();

private:
    Ui::MainWindow *ui;
};
