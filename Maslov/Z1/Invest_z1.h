#ifndef INVEST_Z1_H
#define INVEST_Z1_H

#include <QMainWindow>
#include "alternative1.h"
#include "answer1.h"

namespace Ui {
class Invest_z1;
}

class Invest_z1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Invest_z1(QWidget *parent = 0);
    ~Invest_z1();

private:
    Ui::Invest_z1 *ui;
    //Байесовское решение
    Answer1 * calculateBayesianDecision(Alternative1 ** _alternatives);

    //Алтернатива Баесовскому решению, выбрать лучшее решение при худших обстаятельствах
    Answer1 * calculateMinMaxDecision(Alternative1 ** _alternatives);

    //Полезность точной информации
    Answer1 * calculateUsefulnessAccurateInformation(Alternative1 ** _alternatives);
private slots:
    void calculate();
    void setTest1();
    void setTest2();
    void setTest3();
};

#endif // MAINWINDOW_H
