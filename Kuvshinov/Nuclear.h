#ifndef Nuclear_H
#define Nuclear_H

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
 * Кто выполнял
 * Название и номер задачи
 */
class Nuclear : public QWidget
{
    Q_OBJECT

    QComboBox* tests_box; //список с выбором тестов

    //Примеры того, как создавать необходимые элементы см. в констркуторе
    QLabel* edit_box1; //поле ввода
    QSpinBox* spin_box1;  //поле выбора чисел
    QListWidget* list1;   //список
    QLabel* label1;       //метка для выводов результатов
    QTableWidget* table1; //таблица
    QCustomPlot* plot1;   //график
    QCheckBox* check_box1;//чек бокс
    QTextBlock *res;

public:
    Nuclear(QWidget *parent = 0);
    ~Nuclear();
    float get(int x, int y);
    void set(int x, int y, float mean);
    void init();
    void set(int x, int y, QString mean);
public slots:
    void OpenTest(QModelIndex ind);
	void Calculate(); //функция выполняющая считывания из полей ввода, вычисления, и последующее заполнение полей вывода
};

#endif // EXAMPLE_TASK_NUMBER_H
