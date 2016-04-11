#include "Nuclear.h"
#include <QWidgetData>
#include <QListWidget>
#include <QDebug>
#include <QtMath>
#include <QPalette>

float func(float r, float b);
void max(float r1, float r2, float rs1, float rs2, float coef,
         float &res1, float &res2, bool &conf);


Nuclear::Nuclear(QWidget *parent)
    : QWidget(parent)
{
    //инициализация слоев всего виджета (не изменять)
    this->setLayout(new QVBoxLayout);
    this->layout()->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    this->setMinimumWidth(800);
	this->setMinimumHeight(480);

    QHBoxLayout* other = new QHBoxLayout;
    edit_box1 = new QLabel();
    QPalette pl;
    pl.setColor(QPalette::Text,Qt::red);
    edit_box1->setPalette(pl);
    this->layout()->addWidget(edit_box1);

    QFont font;
//    font.setBold(true);
    font.setPointSize(12);
    //инициализация слоя для виджетов ввода данных (не изменять)
    QVBoxLayout* input_layout = new QVBoxLayout;
    input_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    //инициализация слоя для виджетов вывода данных (не изменять)
    QVBoxLayout* output_layout = new QVBoxLayout;
    output_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    //выбор тестов

    QPushButton* calculate_btn = new QPushButton("Calculate", this);
    calculate_btn->setFixedSize(150,80);
	calculate_btn->setFont(font);
	connect(calculate_btn, SIGNAL(clicked()), this, SLOT(Calculate()));
    other->addWidget(calculate_btn);

    list1 = new QListWidget;
    list1->addItem("1");
    list1->addItem("2");
    list1->addItem("3");

    list1->setMaximumHeight(30);
    QObject::connect(list1, &QListWidget::clicked,
                     this, &Nuclear::OpenTest);
    QObject::connect(list1, &QListWidget::activated,
                     this, &Nuclear::OpenTest);


    this->layout()->addWidget(list1);


	//layout для table
	QVBoxLayout* table1_layout = new QVBoxLayout;
	table1_layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
	QLabel* table1_name_label = new QLabel("Table example", this); //название таблицы
    table1_name_label->setAlignment(Qt::AlignHCenter);
    table1_name_label->setVisible(false);
    table1 = new QTableWidget(this);
//    table1->setMinimumSize(700,560);
//    table1_layout->addWidget(table1_name_label);
//    table1_layout->addWidget(table1);
    other->addWidget(table1_name_label);
    other->addWidget(table1);


	table1->setRowCount(22);//кол-во строк
    table1->setColumnCount(7);//кол-во столбцов
	//задание название строкам (аналогично стобцам)
	QStringList lst;
	lst << "Node" <<
		   "Chance of branch" <<
		   "Cost of branch" <<
           "EIN" <<
           "Params" <<
           "Death" <<
           "Action";
	table1->setHorizontalHeaderLabels(lst);
	lst.clear();
    table1->setVerticalHeaderLabels(lst);
	table1->setItem(0,0, new QTableWidgetItem("1"));
	table1->setItem(2,0, new QTableWidgetItem("2"));
	table1->setItem(4,0, new QTableWidgetItem("3"));
	table1->setItem(9,0, new QTableWidgetItem("4"));
	table1->setItem(15,0, new QTableWidgetItem("5"));
	table1->setItem(21,0, new QTableWidgetItem("6"));

    //заполенения output layout
    QLabel* output_label = new QLabel("Output", this);
    output_label->setFont(font);
    output_label->setFixedHeight(30);
    output_label->setAlignment(Qt::AlignHCenter);
    output_layout->addWidget(output_label);
    output_label->setVisible(false);
    //добавление необходимых виджетов для вывода данных
//    output_layout->addItem(label1_layout);
    output_layout->addItem(table1_layout);
//	output_layout->addItem(plot1_layout);
    //=====

    this->layout()->addItem(other);
    this->layout()->addItem(input_layout);
	this->layout()->addItem(output_layout);

    init();

}



Nuclear::~Nuclear()
{

}

float Nuclear::get(int x, int y) {
    if(table1->item(x, y)->text().isEmpty()) {
        set(x, y, 0.0);
    }
    return table1->item(x, y)->text().toFloat();
}

void Nuclear::set(int x, int y, float mean) {
    QString str;
    str.setNum(mean);
    if(table1->item(x,y) == NULL)
        table1->setItem(x,y, new QTableWidgetItem(str));
    else
        table1->item(x,y)->setText(str);
}

void Nuclear::set(int x, int y, QString mean) {
    if(table1->item(x,y) == NULL)
        table1->setItem(x,y, new QTableWidgetItem(mean));
    else
        table1->item(x,y)->setText(mean);
    table1->item(x,y)->setTextColor(Qt::red);
}

void Nuclear::OpenTest(QModelIndex ind)
{
    qDebug() << ind.data().toString();
    if(ind.data().toString() == "1") {
        init();
        set(9,1,0.6);
        set(10,1,0.4);
        set(9,2,14.0);
        set(10,2,-2.0);

        set(15,1,0.6);
        set(16,1,0.3);
        set(17,1,0.10);

        set(18,1,0.8);
        set(19,1,0.2);
        set(20,1,0.0);

        set(15,2,8.0);
        set(16,2,2.0);
        set(17,2,-4.0);

        //death
        set(9,5,4);
        set(10,5,4);

    }
    else if(ind.data().toString() == "2") {
        init();
    }
    else if(ind.data().toString() == "3") {
        init();
        set(16,5,8);
        //death
        set(9,5,4);
        set(10,5,4);
    }
}

void Nuclear::init() {
    qDebug() << "init";

    set(9,1,0.98);
    set(10,1,0.02);
    set(9,2,10.0);
    set(10,2,-2.0);

    set(15,1,0.4);
    set(16,1,0.46);
    set(17,1,0.14);

    set(18,1,0.9);
    set(19,1,0.06);
    set(20,1,0.04);

    set(15,2,16.0);
    set(16,2,-2.0);
    set(17,2,-6.0);

    set(4,3,-2.0);
    set(5,3,-2.0);
    set(6,3,-4.0);
    set(7,3,-2.0);
    set(8,3,-4.0);

    set(2,1,0.6);
    set(3,1,0.4);

    set(0,4,2.0);
    set(1,4,2.0);

    //death
    set(9,5,0);
    set(10,5,-4);

    set(15,5,1);
    set(16,5,2);
    set(17,5,3);

    set(18,5,1);
    set(19,5,2);
    set(20,5,3);


//    float x1=0.5,x2=0.8,
//            x3=0.2, x4=0.6,
//            res1, res2;
//    bool conf = false;
//    max(x1,x2,x3,x4,get(1,4),res1,res2,conf);
//    qDebug() << "test";
//    qDebug() << res1 << " " << res2 << " " << conf;
}

float func(float r, float b) {
    float res = (b/(b-1))*(1-pow(b,-(r+11)/22));
    return res;
}

void max(float r1, float r2, float rs1, float rs2, float coef,
         float &res1, float &res2, bool &conf)
{
    res1 = (r1>rs1)? r1:rs1;
    res2 = (r2<rs2)? r2:rs2;

    if(coef != 0) {
        float x1 = r1-r2*coef,
              x2 = rs1-rs2*coef;
        res1 = (x1>x2)? r1:rs1;
        res2 = (x1>x2)? r2:rs2;
        qDebug() << "end";
        return;
    }

    if( ((r1>rs1) && (r2<rs2)) ||
            (!(r1>rs1) && !(r2<rs2)) ) {}
    else conf = true;
}

void Nuclear::Calculate()
{
    qDebug() << get(2,0);
    edit_box1->setText("");

    float c11=get(9,1), c12=get(10,1),
          c21=get(9,2), c22=get(10,2);
    float b11=get(15,1), b12=get(16,1), b13=get(17,1),
          b21=get(18,1), b22=get(19,1), b23=get(20,1),
          bp1=get(15,2), bp2=get(16,2), bp3=get(17,2);

    float r41=0, cr41=get(4,3),
        r42=0, cr42=get(5,3),
        r53=0, cr53=get(6,3),
        r44=0, cr44=get(7,3),
        r55=0, cr55=get(8,3);

    float res31=0, res32=0, res33=0;
    float rT, rTs;


    float T=-1, N=0;
    float p=get(2,1), n=get(3,1);

    /*------------------------------------*/

    float _r41, _r42,
           _r43, _r44,
           _r51, _r52,_r53,
           _r45, _r46,
           _r54, _r55,_r56;
    float b = get(0,4);
    if(b < 1.5) {
        b = 1.5;
        set(0,4,b);
    }

    /*----count death--------------------------------*/


    float cs11=get(9,5), cs12=get(10,5);
    float bs11=get(15,5), bs12=get(16,5), bs13=get(17,5),
          bs21=get(18,5), bs22=get(19,5), bs23=get(20,5);
    float rs41=0,
        rs42=0,
        rs53=0,
        rs44=0,
        rs55=0;
    float reses31=0, reses32=0, reses33=0;
    float coefs = get(1,4);
    qDebug() << coefs;

    bool conf=false;
    float ans,anses;


    /*------------------------------------*/
       _r41 = func(N + cr41 + c21, b);
       _r42 = func(N + cr41 + c22, b);

       _r43 = func(T + cr42 + c21, b);
       _r44 = func(T + cr42 + c22, b);

       _r51 = func(T + cr53 + bp1, b);
       _r52 = func(T + cr53 + bp2, b);
       _r53 = func(T + cr53 + bp3, b);

       _r45 = func(T + cr44 + c21, b);
       _r46 = func(T + cr44 + c22, b);

       _r54 = func(T + cr55 + bp1, b);
       _r55 = func(T + cr55 + bp2, b);
       _r56 = func(T + cr55 + bp3, b);

       r41 = _r41*c11 + _r42*c12;
       r42 = _r43*c11 + _r44*c12;
       r53 = _r51*b11 + _r52*b12 + _r53*b13;
       r44 = _r45*c11 + _r46*c12;
       r55 = _r54*b21 + _r55*b22 + _r56*b23;

       qDebug() << "count polsa";
       qDebug() << r41 << " " << r42 << " " << r53;
       qDebug() << r44 << " " << r55;

       /*----count death--------------------------------*/

       rs41 = cs11*c11 + cs12*c12;
       rs42 = rs41;
       rs53 = bs11*b11 + bs12*b12 + bs13*b13;
       rs44 = rs41;
       rs55 = bs21*b21 + bs22*b22 + bs23*b23;

       qDebug() << "count death";
       qDebug() << rs41 << " " << rs42 << " " << rs53;
       qDebug() << rs44 << " " << rs55;

       /*------------------------------------*/
       res31 = r41;
       reses31 = rs41;
       max(r42, rs42, r53, rs53, coefs ,res32, reses32, conf);
       max(r44, rs44, r55, rs55, coefs, res33, reses33, conf);

       rT = res32*p + res33*n;
       rTs = reses32*p + reses33*n;
       qDebug() << "test: " << rT << " no test: " << res31;
       qDebug() << "end";
       max(res31, reses31, rT, rTs, coefs, ans, anses, conf);

       if( conf && (coefs == 0) ) {
           edit_box1->setText("Input coefficient");
           return;
       }

       if(ans == rT) {
           set(0,6, "Test");
       }
       else {
           set(0,6, "No Test");
       }

       if( r42 == res32 ) {
           set(5,6,"Old");
       }
       else {
           set(5,6,"New");
       }

       if( (r44 == res33) && (rs44 == reses33) ) {
           set(7,6,"Old");
       }
       else {
           set(7,6,"New");
       }
}

