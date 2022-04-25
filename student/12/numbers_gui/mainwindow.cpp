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

void MainWindow::on_seedLineEdit_returnPressed()
{
    seed_ = ui->seedLineEdit->text();
    lauta_.init_empty();
    lauta_.fill(seed_.toInt());
    ruudut = lauta_.returnBoard();
    piirraRuutu();
    tulostaLabelit();
}

void MainWindow::piirraRuutu()
{
    QBrush  valkoinenBrush(Qt::white);
    QPen    blackpen(Qt::black);
    blackpen.setWidth(2);
    for(auto y : ruudut)
        for(auto x : y)
        {
            ruutu_ = pelikentta_->addRect(x->coords_.first * PRINT_WIDTH*10, x->coords_.second * PRINT_WIDTH*10,
                                          PRINT_WIDTH*10, PRINT_WIDTH*10, blackpen, valkoinenBrush);
            if(x->value_ == 2)
            {

            QLabel *text_ = new QLabel;
            text_->setText(QString::number(x->value_));
            pelikentta_->addWidget(text_);
            text_->setGeometry(x->coords_.second * PRINT_WIDTH*10, x->coords_.first* PRINT_WIDTH*10,
                               PRINT_WIDTH*10, PRINT_WIDTH*10);



            }

}
}






void MainWindow::tulostaLabelit()
{
    for(auto y : ruudut)
    {
        for(auto x : y )
        {
            QLabel *teksti = new QLabel(this);
            int arvo = x->value_;


        }
    }



}



