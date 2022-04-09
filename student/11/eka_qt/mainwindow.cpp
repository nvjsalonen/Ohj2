#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator*ival = new QIntValidator(0, 125, this);
    ui->ageLineEdit->setValidator(ival);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_nameLineEdit_returnPressed()
{
    name_ = ui->nameLineEdit->text();
    printWholeText();

}


void MainWindow::on_ageLineEdit_returnPressed()
{
    age_ = ui->ageLineEdit->text();
    printWholeText();
}

void MainWindow::printWholeText()
{
    QString str = "";
    str.append(name_);
    str.append(" on ");
    str.append(age_);
    str.append(" vuotta vanha.");

    ui->textBrowser->setText(str);
}

