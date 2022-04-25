#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <gameboard.hh>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pelikentta_ = new QGraphicsScene(this);
    ui->graphicsView->setScene(pelikentta_);





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
    for (int row = 0; row < SIZE; row++) {
        for (int column = 0; column < SIZE; column++){

            ruutu_ = pelikentta_->addRect(column * PRINT_WIDTH*10, row * PRINT_WIDTH*10,
                                          PRINT_WIDTH*10, PRINT_WIDTH*10, blackpen, valkoinenBrush);
        }
    }
}


void MainWindow::on_seedLineEdit_returnPressed()
{
    seed_ = ui->seedLineEdit->text();
    lauta_.init_empty();
    lauta_.fill(seed_.toInt());
    piirraRuutu();
    tulostaLabelit();


}
void MainWindow::tulostaLabelit()
{
    for(auto y : ruudut)
    {
        for(auto x : y )
        {
            QLabel *teksti = new QLabel(this);
            int arvo = x->value_;

            teksti->setText(sto_string

        }
    }


}



