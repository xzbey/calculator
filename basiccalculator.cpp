#include "basiccalculator.h"
#include "ui_basiccalculator.h"
#include <QMessageBox>
#include <cmath>

BasicCalculator::BasicCalculator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BasicCalculator)
{
    ui->setupUi(this);

    ui->doubleSpinBox->setVisible(0);
    ui->doubleSpinBox_2->setVisible(0);
    ui->label_info->setVisible(0);
    ui->label_num1->setVisible(0);
    ui->label_num2->setVisible(0);
    ui->pB_get_result->setVisible(0);
    ui->label_degree->setVisible(0);
}

BasicCalculator::~BasicCalculator()
{
    delete ui;
}


void BasicCalculator::checkType(int count) {
    ui->pB_get_result->setVisible(1);
    ui->label_info->setVisible(1);
    ui->label_num1->setVisible(1);

    ui->doubleSpinBox->setVisible(1);
    ui->doubleSpinBox->setValue(0);

    if (count == 2) {
        ui->doubleSpinBox_2->setVisible(1);
        ui->doubleSpinBox_2->setValue(0);
        ui->label_num2->setVisible(1);
    } else {
        ui->doubleSpinBox_2->setVisible(0);
        ui->label_num2->setVisible(0);
    }

    ui->label_degree->setVisible(0);
}

void BasicCalculator::setText(QString text) {
    ui->label_result->setText(text);
}

void BasicCalculator::printDegree(QString name, double num) {
    if (num > 360)
        QMessageBox::information(this, name, "Угол более 360 градусов\nБудет использован эквивалентный угол");
    else if (num < 0)
        QMessageBox::information(this, name, "Угол менее 360 градусов\nБудет использован эквивалентный угол");
}

void BasicCalculator::on_rB_plus_clicked()
{
    checkType(2);
}


void BasicCalculator::on_rB_minus_clicked()
{
    checkType(2);
}


void BasicCalculator::on_rB_div_clicked()
{
    checkType(2);
}


void BasicCalculator::on_rB_mult_clicked()
{
    checkType(2);
}


void BasicCalculator::on_rB_sin_clicked()
{
    checkType(1);
    ui->label_degree->setVisible(1);
}


void BasicCalculator::on_rB_cos_clicked()
{
    checkType(1);
    ui->label_degree->setVisible(1);
}


void BasicCalculator::on_rB_tan_clicked()
{
    checkType(1);
    ui->label_degree->setVisible(1);
}


void BasicCalculator::on_rB_ctan_clicked()
{
    checkType(1);
    ui->label_degree->setVisible(1);
}


void BasicCalculator::on_rB_arcsin_clicked()
{
    checkType(1);
}


void BasicCalculator::on_rB_arccos_clicked()
{
    checkType(1);
}


void BasicCalculator::on_rB_arctan_clicked()
{
    checkType(1);
}


void BasicCalculator::on_rB_arcctan_clicked()
{
    checkType(1);
}


void BasicCalculator::on_pB_get_result_clicked()
{
    double num1 = ui->doubleSpinBox->value(), num2 = ui->doubleSpinBox_2->value();

    if (ui->rB_plus->isChecked())
        setText(QString::number(num1 + num2, 'f', 4));

    else if (ui->rB_minus->isChecked())
        setText(QString::number(num1 - num2, 'f', 4));

    else if (ui->rB_mult->isChecked())
        setText(QString::number(num1 * num2, 'f', 4));

    else if (ui->rB_div->isChecked()) {
        if (num2 == 0)
            QMessageBox::warning(this, "Error", "Второе число равно нулю!");

        else setText(QString::number(num1 / num2, 'f', 4));
    }

    else if (ui->rB_sin->isChecked()) {
        printDegree("Синус", num1);

        setText(QString::number(sin(num1 * M_PI / 180), 'f', 4));
    }

    else if (ui->rB_cos->isChecked()) {
        printDegree("Косинус", num1);

        setText(QString::number(cos(num1 * M_PI / 180), 'f', 4));
    }

    else if (ui->rB_tan->isChecked()) {
        printDegree("Тангенс", num1);

        if (abs(fmod(abs(num1), 180) - 90) < 1e-6)
            setText("Не существует");
        else {
            double result = std::tan(num1 * M_PI / 180);
            if (std::isinf(result) || std::isnan(result))
                setText("Не существует");
            else
                setText(QString::number(result, 'f', 4));

        }
    }
    else if (ui->rB_ctan->isChecked()) {
        printDegree("Котангенс", num1);

        double x = fmod(abs(num1), 180);
        if (abs(x) < 1e-6 || abs(x - 180) < 1e-6)
            setText("Не существует");
        else {
            double tan1 = tan(num1 * M_PI / 180);
            if (abs(tan1) < 1e-10 || std::isinf(tan1) || std::isnan(tan1))
                setText("Не существует");
            else
                setText(QString::number(1 / tan1, 'f', 4));
        }
    }

    else if (ui->rB_arcsin->isChecked())
        if (abs(num1) > 1)
            QMessageBox::warning(this, "Error", "Аргумент вне области определения");
        else
            setText(QString::number(asin(num1), 'f', 4));

    else if (ui->rB_arccos->isChecked())
        if (abs(num1) > 1)
            QMessageBox::warning(this, "Error", "Аргумент вне области определения");
        else
            setText(QString::number(acos(num1), 'f', 4));

    else if (ui->rB_arctan->isChecked())
        setText(QString::number(atan(num1), 'f', 4));

    else if (ui->rB_arcctan->isChecked())
        setText(QString::number(M_PI / 2 - atan(num1), 'f', 4));
}

