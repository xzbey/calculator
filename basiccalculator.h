#ifndef BASICCALCULATOR_H
#define BASICCALCULATOR_H

#include <QDialog>

namespace Ui {
class BasicCalculator;
}

class BasicCalculator : public QDialog
{
    Q_OBJECT

public:
    explicit BasicCalculator(QWidget *parent = nullptr);
    ~BasicCalculator();

private slots:
    void on_rB_plus_clicked();

    void on_rB_minus_clicked();

    void on_rB_div_clicked();

    void on_rB_mult_clicked();

    void on_rB_sin_clicked();

    void on_rB_cos_clicked();

    void on_rB_tan_clicked();

    void on_rB_ctan_clicked();

    void on_rB_arcsin_clicked();

    void on_rB_arccos_clicked();

    void on_rB_arctan_clicked();

    void on_rB_arcctan_clicked();

    void on_pB_get_result_clicked();

private:
    Ui::BasicCalculator *ui;

    void checkType(int count);

    void setText(QString text);

    void printDegree(QString name, double num);
};

#endif // BASICCALCULATOR_H
