#ifndef INVEST_Z2_H
#define INVEST_Z2_H

#include <QMainWindow>
#include "alternative2.h"
#include "answer2.h"

namespace Ui {
class Invest_z2;
}

class Invest_z2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Invest_z2(QWidget *parent = 0);
    ~Invest_z2();

private:
    Ui::Invest_z2 *ui;
    //Байесовское решение
    Answer2 * calculateBayesianDecision(Alternative2 ** _alternatives);

    //Алтернатива Баесовскому решению, выбрать лучшее решение при худших обстаятельствах
    Answer2 * calculateMinMaxDecision(Alternative2 ** _alternatives);

private slots:
    void calculate();
    void setTest1();
    void setTest2();
    void setTest3();
};

#endif // MAINWINDOW_H
