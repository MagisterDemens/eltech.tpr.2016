#ifndef Task_1_4_1_H
#define Task_1_4_1_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QPushButton>
#include <QTableWidget>
#include <QList>
#include <qcustomplot.h>
#include <QSizePolicy>
#include <QFont>
#include <QComboBox>
#include <QCheckBox>
#include <QStringList>


/*
 * Заполнить:
 * Мартынов & Лапкина
 * 1.4.1. Решение тренера о стратегии проведения игры
 */
class Task_1_4_1 : public QWidget
{
    Q_OBJECT

    QComboBox* tests_box; //список с выбором тестов

    //Примеры того, как создавать необходимые элементы см. в констркуторе
    QLineEdit* edit_box1; //поле ввода
    QLineEdit* edit_box2;
    QLineEdit* edit_box3;
    QLineEdit* edit_box4;
    QLineEdit* edit_box5;
    QLineEdit* edit_box6;
    QLineEdit* edit_box7;
    QLineEdit* edit_box8;
    QLineEdit* edit_box9;
    QLineEdit* edit_box10;

    QLabel* label1;       //метка для выводов результатов
    QLabel* label2;       //метка для выводов результатов для второй задачи
    QLabel* label3;
    QLabel* label4;
    QLabel* label5;
    QLabel* label6;

public:
    Task_1_4_1(QWidget *parent = 0);
    ~Task_1_4_1();
public slots:
    void Calcukate(); //функция выполняющая считывания из полей ввода, вычисления, и последующее заполнение полей вывода
    void SetTest(int i); //слот выборов тестов
    void textChangedSlot(QString text);
    void trainerChangedSlot(QString text);
};

#endif // Task_1_4_1_H
