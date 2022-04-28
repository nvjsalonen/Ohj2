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
        QGraphicsRectItem *ruutu_;

private slots:
    //Käyttäjä syöttää spinboxiin luvun, jonka
    //haluaa siemenluvuksi. Siemenluku tallennetaan
    //seed-muuttujaan.
    void on_seedSpinBox_valueChanged(int arg1);
    //Käyttäjä syöttää halutun pistemäärän ja
    //pistemäärä tallennetaan goal-muuttujaan.
    void on_goalSpinBox_valueChanged(int arg1);
    //
    void on_startButton_clicked();

    void on_vasenPushButton_clicked();

    void on_oikeaPushButton_clicked();

    void on_alasPushButton_clicked();

    void on_ylosPushButton_clicked();

    void on_resetPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *pelikentta_;
    QGraphicsTextItem * text_;
    void piirraRuutu();
;    GameBoard lauta_;
    std::vector<std::vector<NumberTile*>> ruudut;

    int seed_ = time(NULL);
    int goal_ = 2048;
    bool onkoVoitto = false;


    const Coords DEFAULT_DIR = {0, 0};
    const Coords LEFT = {0, -1};
    const Coords UP = {-1, 0};
    const Coords RIGHT = {0, 1};
    const Coords DOWN = {1, 0};
    void suljePushButtonit();
    void avaaPushButtonit();
    void piirraLuvut();

};
#endif // MAINWINDOW_HH
