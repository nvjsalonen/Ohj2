#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include "gameboard.hh"
const QString VOITTO = "Voitit pelin.";
const QString HAVIO = "Hävisit pelin.";
const QBrush HAVION_VARI = Qt::red;
const QBrush VOITON_VARI = Qt::green;
const QBrush NORMAALI_VARI =Qt::white;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:



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

    //Kutsuu kaikkia tarvittavia funktioita pelin aloittamiseksi.
    //Samalla vapauttaa suuntanuolet ja sulkee muut buttonit
    void on_startButton_clicked();

    //Kutsuu move-funktiota, joka siirtää numbertilen koordinaatteja vasemmalle.
    //Tarkastaa myös voitto ja häviö tilanteet sekä päivittää ruudukon.
    void on_vasenPushButton_clicked();

    //Kutsuu move-funktiota, joka siirtää numbertilen koordinaatteja oikealle.
    //Tarkastaa myös voitto ja häviö tilanteet sekä päivittää ruudukon.
    void on_oikeaPushButton_clicked();

    //Kutsuu move-funktiota, joka siirtää numbertilen koordinaatteja alas.
    //Tarkastaa myös voitto- ja häviötilanteet sekä päivittää ruudukon.
    void on_alasPushButton_clicked();

    //Kutsuu move-funktiota, joka siirtää numbertilen koordinaatteja ylös.
    //Tarkastaa myös voitto- ja häviötilanteet sekä päivittää ruudukon.
    void on_ylosPushButton_clicked();

    //Nollaa pisteet, avaa spinboxit sekä sulkee suuntanäppäimet.
    void on_resetPushButton_clicked();

    //Funktio asettaa laskurin pisteet labeliin aina kun nuolia painetaan.
    void naytaPisteet();

    //Palauttaa eri QColor värejä numbertilen arvon perusteella.
    //Parametrina on numbertilen value_.
    QColor vaihdaVari(int arvo);


    void on_actionKayttoohjeet_triggered();

    void on_actionPunainen_triggered();

    void on_actionValkoinen_triggered();

    void on_actionVihrea_triggered();

    void on_actionMusta_triggered();

private:
    Ui::MainWindow *ui;

    //Scene, jossa pelin toiminta tapahtuu.
    QGraphicsScene *pelikentta_;

    //Labelien tekstit, jotka tulevat laudan
    //laudan arvoista.
    QGraphicsTextItem * text_;

    //Funktiossa kutsutaan getCoords ja getValues funktioita, joiden arvojen
    //perusteella sceneen piirretään ruudut ja labelit.
    void piirraRuutu();

    //Sisältää pelilaudan rakenteen.
;    GameBoard lauta_;

    //Muutttuja johon talletetaan ruutujen sijainnit jota niitä voidaan
    //käsitellä.
    std::vector<std::vector<NumberTile*>> ruudut;
    int seed_ = time(NULL);

    int goal_ = 2048;

    const Coords DEFAULT_DIR = {0, 0};
    const Coords LEFT = {0, -1};
    const Coords UP = {-1, 0};
    const Coords RIGHT = {0, 1};
    const Coords DOWN = {1, 0};


    //Nuolinäppäinten aktivoimiseen ja sulkemiseen.
    void muutaNappaintenTilaa(bool onkoKaynnissa);
    //Tyhjentää laudan.
    void tyhjennaLauta();


    int laskuri = 0;


};
#endif // MAINWINDOW_HH
