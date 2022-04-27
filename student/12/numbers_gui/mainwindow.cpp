#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <gameboard.hh>
#include <string>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pelikentta_ = new QGraphicsScene(this);
    ui->graphicsView->setScene(pelikentta_);

    ui->seedSpinBox->setRange(0,99999);
    ui->goalSpinBox->setRange(0, 999999);





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
            ruutu_ = pelikentta_->addRect(x->coords_.second * PRINT_WIDTH*10, x->coords_.first * PRINT_WIDTH*10,
                                          PRINT_WIDTH*10, PRINT_WIDTH*10, blackpen, valkoinenBrush);

            if(x->value_ != 0)
            {

                QLabel *text_ = new QLabel(this,Qt::Window | Qt::WindowStaysOnTopHint);
                text_->setText(QString::number(x->value_));
                pelikentta_->addWidget(text_);
                text_->setGeometry(x->coords_.second * PRINT_WIDTH*10, x->coords_.first* PRINT_WIDTH*10,
                                   PRINT_WIDTH*10, PRINT_WIDTH*10);
                text_->setAlignment(Qt::AlignCenter);




            }

        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        lauta_.move(UP, 2048);
    }
    if(event->key() == Qt::Key_S)
    {
        lauta_.move(DOWN, 2048);
    }
    if(event->key() == Qt::Key_A)
    {
        lauta_.move(LEFT, 2048);
    }
    if(event->key() == Qt::Key_D)
    {
        lauta_.move(RIGHT, 2048);
    }
    lauta_.new_value(false);
    piirraRuutu();
}

void MainWindow::on_seedSpinBox_valueChanged(int arg1)
{
    seed_ = arg1;
}





void MainWindow::on_goalSpinBox_valueChanged(int arg1)
{
    goal_ = arg1;
}




void MainWindow::on_startButton_clicked()
{
    lauta_.init_empty();
    lauta_.fill(seed_);
    piirraRuutu();
}

