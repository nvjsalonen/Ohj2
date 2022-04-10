#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gradecounter.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBoxG->setRange(0, 120);
    ui->spinBoxN->setRange(0, 760);
    ui->spinBoxP->setRange(0, 250);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_spinBoxN_valueChanged(int arg1)
{
    n_ = arg1;
}


void MainWindow::on_spinBoxG_valueChanged(int arg1)
{
    g_ = arg1;
}


void MainWindow::on_spinBoxP_valueChanged(int arg1)
{
    p_ = arg1;
}


void MainWindow::on_spinBoxE_valueChanged(int arg1)
{
    exam_grade_ = arg1;
}




void MainWindow::on_countPushButton_clicked()
{
    grade_ = count_final_grade(n_, g_, p_, exam_grade_);
    QString grade = QVariant(grade_).toString();
    QString str = "";
    str.append("Total grade: ");
    str.append(grade);
    ui->textBrowser->setText(str);

}

