#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <gameboard.hh>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <cmath>

/* Numbers_gui
 *
 * Kuvaus:
 * Ohjelma luo graafisen käyttöliittymän 2048-pelille. Pelin
 * back end on toteutettu gameboard.cpp ja numbertile.cpp-
 * tiedostoissa. Pelissä pelaajalta kysytään ensin siemenlukua, jonka
 * perusteella luodaan satunnainen kenttä. Pelaaja antaa sitten
 * kakkosen potenssin, jonka haluaa tavoiteluvuksi. Aloita peli
 * näppäimestä voi aloittaa pelin, jolloin nuolinäppäimet vapautuvat
 * ja spinboxien, sekä aloitusnäppäimen, käyttö on estetty. Pelin
 * voi halutessaan resetoida milloin tahansa, jolloin aiemmin
 * mainitut näppäimet vapautuvat taas käytettäväksi. Nuolinäppäimistä
 * pelaaja voi valita mihin suuntaan tiiliä liikutetaan. Aina kun tiiliä
 * liikutetaan, satunnaiseen vapaaseen ruuutuun ilmestyy kakkonen. Vierekkäiset
 * ruudut, joissa on sama luku, lisätään yhteen. Tarkoituksena on saada ruutuun
 * tavoiteluvun summa, jolloin pelaaja on voittanut. Jos lauta täyttyy niin
 * pelaaja on hävinnyt. Pelissä on myös pistelaskuri, joka laskee käytetyt
 * siirrot.
 *
 *
 * Ohjelman kirjoittaja
 * Nimi: Nikolas Salonen
 * Opiskelijanumero: 050158931
 * Käyttäjätunnus: chnisa ( Git-repositorion hakemistonimi. )
 * E-Mail: nikolas.salonen@tuni.fi
 *
 * Huomioita ohjelmasta ja sen toteutuksesta:
 *
 * */


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pelikentta_ = new QGraphicsScene(this);
    ui->graphicsView->setScene(pelikentta_);




    ui->seedSpinBox->setRange(0,99999);
    ui->goalSpinBox->setRange(2, 30);
    ui->alasPushButton->setDisabled(true);
    ui->ylosPushButton->setDisabled(true);
    ui->vasenPushButton->setDisabled(true);
    ui->oikeaPushButton->setDisabled(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::piirraRuutu()
{
    QBrush  valkoinenBrush(Qt::white);
    QPen    blackpen(Qt::black);
    blackpen.setWidth(2);
    for(auto y : lauta_.returnBoard())
    {
        for(auto x : y)
        {

            ruutu_ = pelikentta_->addRect(x->returnCoords().second * PRINT_WIDTH*10, x->returnCoords().first * PRINT_WIDTH*10,
                                          PRINT_WIDTH*10, PRINT_WIDTH*10, blackpen, valkoinenBrush);

            if(x->returnValue() != 0)
            {

                QLabel *text_ = new QLabel(this,Qt::Window | Qt::WindowStaysOnTopHint);
                text_->setStyleSheet("color:darkRed;");
                text_->setText(QString::number(x->returnValue()));
                pelikentta_->addWidget(text_);
                text_->setGeometry(x->returnCoords().second * PRINT_WIDTH*10, x->returnCoords().first* PRINT_WIDTH*10,
                                   PRINT_WIDTH*10, PRINT_WIDTH*10);
                text_->setAlignment(Qt::AlignCenter);
                text_->setAttribute(Qt::WA_TranslucentBackground);
            }

        }
    }
}



void MainWindow::muutaNappaintenTilaa(bool onkoKaynnissa)
{
    ui->alasPushButton->setEnabled(onkoKaynnissa);
    ui->ylosPushButton->setEnabled(onkoKaynnissa);
    ui->vasenPushButton->setEnabled(onkoKaynnissa);
    ui->oikeaPushButton->setEnabled(onkoKaynnissa);
}





void MainWindow::on_seedSpinBox_valueChanged(int arg1)
{
    seed_ = arg1;
}

void MainWindow::on_goalSpinBox_valueChanged(int arg1)
{
    goal_ = pow(2, arg1);
    ui->tavoiteLabel->setText(QString::number(goal_));
}


void MainWindow::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    muutaNappaintenTilaa(true);
    lauta_.init_empty();
    lauta_.fill(seed_);
    piirraRuutu();
    ui->seedSpinBox->setDisabled(true);
    ui->goalSpinBox->setDisabled(true);

}


void MainWindow::on_vasenPushButton_clicked()
{
    if(lauta_.move(LEFT, goal_))
    {
        QMessageBox::about(this,"Voitto", VOITTO);
        muutaNappaintenTilaa(false);
    }
    else if(lauta_.is_full())
    {
        QMessageBox::about(this,"Häviö", HAVIO);
        muutaNappaintenTilaa(false);
    }
    else
    {
        lauta_.new_value(false);
        piirraRuutu();
        laskuri++;
        naytaPisteet();
    }
}


void MainWindow::on_oikeaPushButton_clicked()
{
    if(lauta_.move(RIGHT, goal_))
    {
        QMessageBox::about(this,"Voitto", VOITTO);
        muutaNappaintenTilaa(false);
    }
    else if(lauta_.is_full())
    {
        QMessageBox::about(this,"Häviö", HAVIO);
        muutaNappaintenTilaa(false);
    }
    else
    {

        lauta_.new_value(false);
        piirraRuutu();
        laskuri++;
        naytaPisteet();
    }
}


void MainWindow::on_alasPushButton_clicked()
{
    if(lauta_.move(DOWN, goal_))
    {
        QMessageBox::about(this,"Voitto", VOITTO);
        muutaNappaintenTilaa(false);
    }
    else if(lauta_.is_full())
    {
        QMessageBox::about(this,"Häviö", HAVIO);
        muutaNappaintenTilaa(false);
    }
    else
    {

        lauta_.new_value(false);
        piirraRuutu();
        laskuri++;
        naytaPisteet();
    }
}


void MainWindow::on_ylosPushButton_clicked()
{
    if(lauta_.move(UP, goal_))
    {
        QMessageBox::about(this,"Voitto", VOITTO);
        muutaNappaintenTilaa(false);
    }
    else if(lauta_.is_full())
    {
        QMessageBox::about(this,"Häviö", HAVIO);
        muutaNappaintenTilaa(false);
    }
    else
    {
        lauta_.new_value(false);
        piirraRuutu();
        laskuri++;
        naytaPisteet();
    }

}
void MainWindow::on_resetPushButton_clicked()
{
    laskuri = 0;
    ui->pisteetLabel->clear();
    ui->startButton->setDisabled(false);
    ui->seedSpinBox->setDisabled(false);
    ui->goalSpinBox->setDisabled(false);
    pelikentta_->clear();
    tyhjennaLauta();
    lauta_.emptyBoard();
    muutaNappaintenTilaa(false);

}


void MainWindow::naytaPisteet()
{
    ui->pisteetLabel->setText(QString::number(laskuri));
}

void MainWindow::tyhjennaLauta()
{
    for(auto y : lauta_.returnBoard())
    {
        for(auto x : y)
        {
            delete x;
            x = nullptr;
        }

}
}


