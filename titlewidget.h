#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayoutItem>
#include <QFont>

#include "Kuvshinov/Nuclear.h"
#include "Martinov/Task_1_4_1.h"
#include "Maslov/Z2/Invest_z2.h"
#include "Maslov/Z1/Invest_z1.h"


class TitleWidget : public QWidget
{
    Q_OBJECT

    QComboBox* task_list;
    QHBoxLayout* btn_layout;
    QLabel* descript_label;

    QPushButton* btn_maslov_1;
    QPushButton* btn_maslov_2;
    QPushButton* btn_kuvshinov;
    QPushButton* btn_martinov;

public:
    TitleWidget(QWidget *parent = 0);
    ~TitleWidget();

public slots:
    void ChangeTaks(int i);
    void InitKuvshinov();
    void InitMartinov();
    void InitMaslov();
    void ClearWidget();
    void StartKuvshinov();
    void StartMartinov();
    void StartMaslovZ1();
    void StartMaslovZ2();
};

#endif // TITLEWIDGET_H
