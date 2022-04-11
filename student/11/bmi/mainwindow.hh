#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_weightLineEdit_editingFinished();

    void on_heightLineEdit_editingFinished();

    double calculateBmi();

    void on_countButton_clicked();

private:
    Ui::MainWindow *ui;
    QString weight_ = "<weight>";
    QString height_ = "<Height";
    double bmi_ = 0;
};
#endif // MAINWINDOW_HH
