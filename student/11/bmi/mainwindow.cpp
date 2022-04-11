#include "mainwindow.hh"
#include "ui_mainwindow.h"
const QString UNDERWEIGHT = "You are underweight.";
const QString OVERRWEIGHT = "You are overweight.";
const QString NORMAL = "Your weight is normal.";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_weightLineEdit_editingFinished()
{
    weight_ = ui->weightLineEdit->text();
}


void MainWindow::on_heightLineEdit_editingFinished()
{
    height_ = ui->heightLineEdit->text();


}

double MainWindow::calculateBmi()
{
    if(height_.toDouble() == 0 || height_.isEmpty())
    {
        return 0;
    }
    else{
        double meter_height = height_.toDouble()/100;
        double bmi = weight_.toDouble()/(meter_height*meter_height);
        return bmi;
    }
}




void MainWindow::on_countButton_clicked()
{

    if(calculateBmi() == 0)
    {
        ui->resultLabel->setText("Cannot count.");
    }
    else{
        QString bmi = QString::number(calculateBmi());

        ui->resultLabel->setText(bmi);
        if(bmi.toDouble() < 18.5)
        {
            ui->infotextBrowser->setText(UNDERWEIGHT);
        }
        if(bmi.toDouble()> 25)
        {
            ui->infotextBrowser->setText(OVERRWEIGHT);
        }
    }
}

