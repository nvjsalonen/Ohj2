#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(parent);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLcd);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopTimer);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetTimer);
    QPalette pal2 = QPalette();
    pal2.setColor(QPalette::Window,Qt::green);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    ui->lcdNumberMin->setAutoFillBackground(true);
    ui->lcdNumberMin->setPalette(pal);
    ui->lcdNumberMin->show();

    ui->lcdNumberSec->setAutoFillBackground(true);
    ui->lcdNumberSec->setPalette(pal2);
    ui->lcdNumberSec->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startTimer()
{
    if(timer->isActive())
    {

    }
    else
    {
    timer->start(1000);
    time = 0;
    }
}

void MainWindow::stopTimer()
{
    timer->stop();
}

void MainWindow::resetTimer()
{
  stopTimer();
  ui->lcdNumberMin->display(0);
  ui->lcdNumberSec->display(0);
  time = 0;

}

void MainWindow::updateLcd()
{
    time++;
    ui->lcdNumberMin->display(time/60);
    ui->lcdNumberSec->display(time%60);
}
