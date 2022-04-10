#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <QDebug>
#include <QFile>

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


void MainWindow::on_fileLineEdit_editingFinished()
{
    etsittava_tiedosto_ = ui->fileLineEdit->text();
}


void MainWindow::on_keyLineEdit_editingFinished()
{
    etsittava_sana_ = ui->keyLineEdit->text();


}




void MainWindow::on_findPushButton_clicked()
{
    QString tiedosto = etsittava_tiedosto_;

    if(!ui->matchCheckBox->isChecked())
    {
        tiedosto = etsittava_tiedosto_.toLower();
    }
    QFile input (tiedosto);
    if(!input.exists())
    {
        QString str = "File not found";
        ui->textBrowser->setText(str);
    }
    if(input.exists())
    {
        if(etsittava_sana_ == "<word>")
        {
            QString str = "File found";
            ui->textBrowser->setText(str);
        }
        else
        {
            input.open(QIODevice::ReadOnly);
            QString str = input.readAll();
            if(!ui->matchCheckBox->isChecked())
            {
                if(str.contains(etsittava_sana_, Qt::CaseInsensitive))
                {
                    QString str = "Word found";
                    ui->textBrowser->setText(str);
                }
                else
                {
                    QString str = "Word not found";
                    ui->textBrowser->setText(str);

                }
            }
            else
            {
                if(str.contains(etsittava_sana_))
                {
                    QString str = "Word found";
                    ui->textBrowser->setText(str);
                }
                else
                {
                    QString str = "Word not found";
                    ui->textBrowser->setText(str);


                }

            }
        }

    }
}


void MainWindow::tulostaTeksti()
{
    QString str = "";
    str.append(etsittava_tiedosto_);
    str.append("\n");
    str.append(etsittava_sana_);
    ui->textBrowser->setText(str);
}

