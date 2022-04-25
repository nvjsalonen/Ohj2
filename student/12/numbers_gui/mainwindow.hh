#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include "gameboard.hh"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:



private slots:
    void on_seedLineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *pelikentta_;
    QGraphicsRectItem *ruutu_;
    void piirraRuutu();
    void tulostaLabelit();
    QString seed_;
    std::vector<std::vector<NumberTile*>> lauta;

};
#endif // MAINWINDOW_HH
