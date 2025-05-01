#ifndef GEOCALCULATOR_H
#define GEOCALCULATOR_H

#include <QDialog>

namespace Ui {
class GeoCalculator;
}

class GeoCalculator : public QDialog
{
    Q_OBJECT

public:
    explicit GeoCalculator(QWidget *parent = nullptr);
    ~GeoCalculator();

private slots:
    void on_rB_1_toggled(bool checked);

    void on_rB_2_toggled(bool checked);

    void on_pB_get_result_clicked();

private:
    Ui::GeoCalculator *ui;

    void updateVisible(bool checked);

    QString basicRes();

    QString antiRes();
};

#endif // GEOCALCULATOR_H
