#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <gameboard.hh>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pelikentta_ = new QGraphicsScene(this);
    ui->graphicsView->setScene(pelikentta_);

    QBrush  valkoinenBrush(Qt::white);
    QPen    blackpen(Qt::black);
    blackpen.setWidth(2);

    ruutu_ = pelikentta_->addRect(5, 5, 100, 100, blackpen, valkoinenBrush);
}

MainWindow::~MainWindow()
{
    delete ui;
}

