#include "geocalculator.h"
#include "ui_geocalculator.h"
#include <cmath>

GeoCalculator::GeoCalculator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GeoCalculator)
{
    ui->setupUi(this);

    ui->spinBox_xB->setVisible(0);
    ui->spinBox_yB->setVisible(0);
    ui->spinBox_S->setVisible(0);
    ui->spinBox_degrees->setVisible(0);
    ui->spinBox_min->setVisible(0);
    ui->spinBox_sec->setVisible(0);
    ui->spinBox_xA->setVisible(0);
    ui->spinBox_yA->setVisible(0);
}

GeoCalculator::~GeoCalculator()
{
    delete ui;
}

void GeoCalculator::updateVisible(bool checked) {
    ui->spinBox_xA->setVisible(1);
    ui->spinBox_yA->setVisible(1);
    ui->spinBox_xB->setVisible(!checked);
    ui->spinBox_yB->setVisible(!checked);
    ui->spinBox_S->setVisible(checked);
    ui->spinBox_degrees->setVisible(checked);
    ui->spinBox_min->setVisible(checked);
    ui->spinBox_sec->setVisible(checked);
}

QString GeoCalculator::basicRes() {
    double xA = ui->spinBox_xA->value(), yA = ui->spinBox_yA->value(), s = ui->spinBox_S->value(),
        alpha = ui->spinBox_degrees->value(), min = ui->spinBox_min->value(), sec = ui->spinBox_sec->value(),
        degree = (alpha + min / 60 + sec / 3600) * M_PI / 180;


    double res1 = xA + s * cos(degree), res2 = yA + s * sin(degree);

    return QString::number(res1, 'f', 4) + " | " + QString::number(res2, 'f', 4);
}

QString GeoCalculator::antiRes() {
    double xA = ui->spinBox_xA->value(), yA = ui->spinBox_yA->value(),
            xB = ui->spinBox_xA->value(), yB = ui->spinBox_yA->value(),
            degree = atan((yB - yA) / (xB - xA)) * 180 / M_PI;

    double alpha = int(degree), min = (degree - alpha) * 60, sec = (min - int(min)) * 60;
    min = int(min); sec = int(sec);

    double s = sqrt((xB - xA)*(xB - xA) + (yB - yA)*(yB - yA));

    return QString::number(s, 'f', 4) + "| Угол: " + QString::number(alpha) + "'" + QString::number(min) + "''" + QString::number(sec, 'f', 4);

}

void GeoCalculator::on_rB_1_toggled(bool checked)
{
    updateVisible(checked);
}


void GeoCalculator::on_rB_2_toggled(bool checked)
{
    updateVisible(!checked);
}


void GeoCalculator::on_pB_get_result_clicked()
{
    QString result;
    if (ui->rB_1->isChecked()) {
        result = basicRes();
    } else if (ui->rB_2->isChecked()) {
        result = antiRes();
    }

    ui->label->setText(result);
}

