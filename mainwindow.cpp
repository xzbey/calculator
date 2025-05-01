#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "geocalculator.h"
#include "basiccalculator.h"

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


void MainWindow::on_pB_open_geocalculator_clicked()
{
    GeoCalculator geocalc(this);
    geocalc.exec();
}


void MainWindow::on_pB_open_calculator_clicked()
{
    BasicCalculator basiccalc(this);
    basiccalc.exec();
}

