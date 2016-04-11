#include "Task_1_4_1.h"

Task_1_4_1::Task_1_4_1(QWidget *parent)
    : QWidget(parent)
{
    //инициализация слоев всего виджета (не изменять)
    this->setLayout(new QHBoxLayout);
    this->layout()->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    this->setMinimumWidth(720);
    this->setMaximumWidth(760);

    QFont font;
    font.setBold(true);
    font.setPointSize(13);
    //инициализация слоя для виджетов ввода данных (не изменять)
    QVBoxLayout* input_layout = new QVBoxLayout;
    input_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    //инициализация слоя для виджетов вывода данных (не изменять)
    QVBoxLayout* output_layout = new QVBoxLayout;
    output_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    //выбор тестов
    QHBoxLayout* tests_layout = new QHBoxLayout;
    tests_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QLabel* tests_label = new QLabel("Tests  ", this);
    tests_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    tests_label->setFixedWidth(150);
    tests_label->setFixedHeight(40);
    tests_box = new QComboBox(this);
    tests_box->setFixedWidth(150);
    tests_box->addItem("Test1");
    tests_box->addItem("Test2");
    tests_box->addItem("Test3");
    tests_box->addItem("Test4");
    tests_layout->addWidget(tests_label);
    tests_layout->addWidget(tests_box);
    connect(tests_box, SIGNAL(activated(int)), this, SLOT(SetTest(int)));

    QHBoxLayout* edit_box1_layout = new QHBoxLayout;
    edit_box1_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box1_label = new QLabel("Success goal: ", this);
    edit_box1_label->setFixedWidth(200);
    edit_box1_label->setAlignment(Qt::AlignRight);
    edit_box1 = new QLineEdit(this);
    edit_box1->setFixedSize(100, 20);
    edit_box1_layout->addWidget(edit_box1_label);
    edit_box1_layout->addWidget(edit_box1);
    connect(edit_box1,SIGNAL(textChanged(QString)),this,SLOT(textChangedSlot(QString)));

    QHBoxLayout* edit_box2_layout = new QHBoxLayout;
    edit_box2_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box2_label = new QLabel("Fail goal: ", this);
    edit_box2_label->setFixedWidth(200);
    edit_box2_label->setAlignment(Qt::AlignRight);
    edit_box2 = new QLineEdit(this);
    edit_box2->setEnabled(false);
    edit_box2->setFixedSize(100, 20);
    edit_box2_layout->addWidget(edit_box2_label);
    edit_box2_layout->addWidget(edit_box2);

    QHBoxLayout* edit_box3_layout = new QHBoxLayout;
    edit_box3_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box3_label = new QLabel("Success touchdown: ", this);
    edit_box3_label->setFixedWidth(200);
    edit_box3_label->setAlignment(Qt::AlignRight);
    edit_box3 = new QLineEdit(this);
    edit_box3->setEnabled(false);
    edit_box3->setFixedSize(100, 20);
    edit_box3_layout->addWidget(edit_box3_label);
    edit_box3_layout->addWidget(edit_box3);

    QHBoxLayout* edit_box4_layout = new QHBoxLayout;
    edit_box4_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box4_label = new QLabel("Fail touchdown: ", this);
    edit_box4_label->setFixedWidth(200);
    edit_box4_label->setAlignment(Qt::AlignRight);
    edit_box4 = new QLineEdit(this);
    edit_box4->setEnabled(false);
    edit_box4->setFixedSize(100, 20);
    edit_box4_layout->addWidget(edit_box4_label);
    edit_box4_layout->addWidget(edit_box4);

    QHBoxLayout* edit_box5_layout = new QHBoxLayout;
    edit_box5_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box5_label = new QLabel("Drow chance: ", this);
    edit_box5_label->setFixedWidth(200);
    edit_box5_label->setAlignment(Qt::AlignRight);
    edit_box5 = new QLineEdit(this);
    edit_box5->setEnabled(false);
    edit_box5->setFixedSize(100, 20);
    edit_box5_layout->addWidget(edit_box5_label);
    edit_box5_layout->addWidget(edit_box5);

    QHBoxLayout* edit_box6_layout = new QHBoxLayout;
    edit_box6_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box6_label = new QLabel("Lose chance: ", this);
    edit_box6_label->setFixedWidth(200);
    edit_box6_label->setAlignment(Qt::AlignRight);
    edit_box6 = new QLineEdit(this);
    edit_box6->setEnabled(false);
    edit_box6->setFixedSize(100, 20);
    edit_box6_layout->addWidget(edit_box6_label);
    edit_box6_layout->addWidget(edit_box6);

    QHBoxLayout* edit_box7_layout = new QHBoxLayout;
    edit_box7_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box7_label = new QLabel("Win chance: ", this);
    edit_box7_label->setFixedWidth(200);
    edit_box7_label->setAlignment(Qt::AlignRight);
    edit_box7 = new QLineEdit(this);
    edit_box7->setEnabled(false);
    edit_box7->setFixedSize(100, 20);
    edit_box7_layout->addWidget(edit_box7_label);
    edit_box7_layout->addWidget(edit_box7);

    QHBoxLayout* edit_box8_layout = new QHBoxLayout;
    edit_box8_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box8_label = new QLabel("Trainer select goal: ", this);
    edit_box8_label->setFixedWidth(200);
    edit_box8_label->setAlignment(Qt::AlignRight);
    edit_box8 = new QLineEdit(this);
    edit_box8->setEnabled(true);
    edit_box8->setFixedSize(100, 20);
    edit_box8_layout->addWidget(edit_box8_label);
    edit_box8_layout->addWidget(edit_box8);
    connect(edit_box8,SIGNAL(textChanged(QString)),this,SLOT(trainerChangedSlot(QString)));

    QHBoxLayout* edit_box9_layout = new QHBoxLayout;
    edit_box9_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box9_label = new QLabel("Trainer select touchdown: ", this);
    edit_box9_label->setFixedWidth(200);
    edit_box9_label->setAlignment(Qt::AlignRight);
    edit_box9 = new QLineEdit(this);
    edit_box9->setEnabled(false);
    edit_box9->setFixedSize(100, 20);
    edit_box9_layout->addWidget(edit_box9_label);
    edit_box9_layout->addWidget(edit_box9);

    QHBoxLayout* edit_box10_layout = new QHBoxLayout;
    edit_box10_layout->setAlignment(Qt::AlignLeft);
    QLabel* edit_box10_label = new QLabel("Value v: ", this);
    edit_box10_label->setFixedWidth(200);
    edit_box10_label->setAlignment(Qt::AlignRight);
    edit_box10 = new QLineEdit(this);
    edit_box10->setEnabled(true);
    edit_box10->setFixedSize(100, 20);
    edit_box10_layout->addWidget(edit_box10_label);
    edit_box10_layout->addWidget(edit_box10);

    QLabel* input_label = new QLabel("Input", this);
    input_label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    input_label->setFont(font);
    input_label->setFixedHeight(30);

    QHBoxLayout* calculate_layout = new QHBoxLayout;
    QPushButton* calculate_btn = new QPushButton("Calculate", this);
    calculate_btn->setFixedSize(150,30);
    calculate_btn->setFont(font);
    calculate_layout->addWidget(calculate_btn);
    connect(calculate_btn, SIGNAL(clicked()), this, SLOT(Calcukate()));

    input_layout->addWidget(input_label);
    input_layout->addItem(tests_layout);
    input_layout->addItem(edit_box1_layout);
    input_layout->addItem(edit_box2_layout);
    input_layout->addItem(edit_box3_layout);
    input_layout->addItem(edit_box4_layout);
    input_layout->addItem(edit_box5_layout);
    input_layout->addItem(edit_box6_layout);
    input_layout->addItem(edit_box7_layout);
    input_layout->addItem(edit_box8_layout);
    input_layout->addItem(edit_box9_layout);
    input_layout->addItem(edit_box10_layout);
    input_layout->addItem(calculate_layout);

    QHBoxLayout* label1_layout = new QHBoxLayout;
    label1_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QLabel* output_label1 = new QLabel("Result for trainer:  ", this);
    output_label1->setAlignment(Qt::AlignRight);
    output_label1->setFixedSize(200,20);
    label1 = new QLabel("", this);
    label1->setFixedSize(200,20);
    label1->setAlignment(Qt::AlignLeft);
    label1_layout->addWidget(output_label1);
    label1_layout->addWidget(label1);

    QHBoxLayout* label2_layout = new QHBoxLayout;
    label2_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QLabel* output_label2 = new QLabel("Result for Nensy:  ", this);
    output_label2->setAlignment(Qt::AlignRight);
    output_label2->setFixedSize(200,20);
    label2 = new QLabel("", this);
    label2->setFixedSize(200,20);
    label2->setAlignment(Qt::AlignLeft);
    label2_layout->addWidget(output_label2);
    label2_layout->addWidget(label2);

    QHBoxLayout* label3_layout = new QHBoxLayout;
    label3_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QLabel* output_label3 = new QLabel("Result for Ron:  ", this);
    output_label3->setAlignment(Qt::AlignRight);
    output_label3->setFixedSize(200,20);
    label3 = new QLabel("", this);
    label3->setFixedSize(200,20);
    label3->setAlignment(Qt::AlignLeft);
    label3_layout->addWidget(output_label3);
    label3_layout->addWidget(label3);

    QHBoxLayout* label4_layout = new QHBoxLayout;
    label4_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QLabel* output_label4 = new QLabel("1) Result for Nansy before Trainer:  ", this);
    output_label4->setAlignment(Qt::AlignRight);
    output_label4->setFixedSize(200,20);
    label4 = new QLabel("", this);
    label4->setFixedSize(200,20);
    label4->setAlignment(Qt::AlignLeft);
    label4_layout->addWidget(output_label4);
    label4_layout->addWidget(label4);

    QHBoxLayout* label5_layout = new QHBoxLayout;
    label5_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QLabel* output_label5 = new QLabel("2) Result for Nansy before Trainer:  ", this);
    output_label5->setAlignment(Qt::AlignRight);
    output_label5->setFixedSize(200,20);
    label5 = new QLabel("", this);
    label5->setFixedSize(200,20);
    label5->setAlignment(Qt::AlignLeft);
    label5_layout->addWidget(output_label5);
    label5_layout->addWidget(label5);

    QHBoxLayout* label6_layout = new QHBoxLayout;
    label6_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QLabel* output_label6 = new QLabel("Result for Nansy with value v:  ", this);
    output_label6->setAlignment(Qt::AlignRight);
    output_label6->setFixedSize(200,20);
    label6 = new QLabel("", this);
    label6->setFixedSize(200,20);
    label6->setAlignment(Qt::AlignLeft);
    label6_layout->addWidget(output_label6);
    label6_layout->addWidget(label6);

    QLabel* output_label = new QLabel("Output", this);
    output_label->setFont(font);
    output_label->setFixedHeight(30);
    output_label->setAlignment(Qt::AlignHCenter);
    output_layout->addWidget(output_label);
    output_layout->addItem(label1_layout);
    output_layout->addItem(label2_layout);
    output_layout->addItem(label3_layout);
    output_layout->addItem(label4_layout);
    output_layout->addItem(label5_layout);
    output_layout->addItem(label6_layout);
    this->layout()->addItem(input_layout);
    this->layout()->addItem(output_layout);
}

void Task_1_4_1::trainerChangedSlot(QString text)
{
    if(text.toDouble() > 1)
    {
        edit_box8->setText("1");
        text = "1";
    }

    if(text.toDouble() < 0)
    {
        edit_box8->setText("0");
        text = "0";
    }

    edit_box9->setText(QString::number(1 - text.toDouble()));
}

void Task_1_4_1::textChangedSlot(QString text)
{
    if(text.toDouble() > 1)
    {
        edit_box1->setText("1");
        text = "1";
    }

    if(text.toDouble() < 0)
    {
        edit_box1->setText("0");
        text = "0";
    }

    int k = 2;
    edit_box2->setText(QString::number(1 - text.toDouble()));
    edit_box3->setText(QString::number(text.toDouble()/k));
    edit_box4->setText(QString::number(1 - text.toDouble()/k));

    edit_box5->setText(QString::number(text.toDouble()/2));
    edit_box6->setText(QString::number(1/2 - text.toDouble()/2 + 1 - text.toDouble()/(k*2)));
    edit_box7->setText(QString::number(text.toDouble()/(k*2)));
}

Task_1_4_1::~Task_1_4_1()
{

}

void Task_1_4_1::Calcukate()
{
    if (edit_box1->text().isEmpty()) {
        return;
    }

    double p11 = edit_box1->text().toDouble();
    double p12 = edit_box2->text().toDouble();
    double p21 = edit_box3->text().toDouble();
    double p22 = edit_box4->text().toDouble();

    double r1 = edit_box5->text().toDouble();
    double r2 = edit_box6->text().toDouble();
    double r3 = edit_box7->text().toDouble();

    double pk = edit_box8->text().toDouble();
    double pk2 = edit_box9->text().toDouble();

    double v = edit_box10->text().toDouble();

    double res = (p11*r1 + p21*r2) / (p12*r3 + p22*r2);

    if(res >= 1)
    {
        label1->setText("Goal!");
        if (p11 > 0.8) {
            label2->setText("Make a bet at goal!");
            label3->setText("Doesn't make a bet at goal!");
        } else {
            label2->setText("Doesn't make a bet at goal!");
            label3->setText("Make a bet at goal!");
        }
    }
    else
    {
        label1->setText("Tochdown!");
        if (p21 > 0.33) {
            label2->setText("Make a bet at tochdown!");
            label3->setText("Doesn't make a bet at tochdown!");
        } else {
            label2->setText("Doesn't make a bet at tochdown!");
            label3->setText("Make a bet at tochdown!");
        }
    }


    if (edit_box8->text().isEmpty()) {
        return;
    }

    double trainerChance = pk*(1.25*p11 -1)+(1-pk)*(3*p21-1);

    if(trainerChance > 0)
    {
        label4->setText("Make a bet on goal!");
    }
    else
    {
        label4->setText("Make a bet on tochdown!");
    }

    double trainerChance2 = 5*p11/12;

    if (trainerChance2 < p21)
    {
        label5->setText("Make a bet on goal!");
    }
    else
    {
        label5->setText("Make a bet on tochdown!"); // Вообще не достижимый случай
    }

    if (edit_box10->text().isEmpty()) {
        return;
    }

     double betAndV = pk*((1+v)*p11 -1)+(1-pk)*(3*p21-1);

     if(betAndV > 0)
     {
         label6->setText("Make a bet!");
     }
     else
     {
         label6->setText("Doesn't make a bet!");
     }
}

void Task_1_4_1::SetTest(int i)
{
    switch (i) {
    case 0:
        edit_box1->setText("0.85");
        edit_box8->setText("0.7");
        edit_box10->setText("1.3");
        break;
    case 1:
        edit_box1->setText("0.7");
        edit_box8->setText("0.14");
        edit_box10->setText("0.4");
        break;
    case 2:
        edit_box1->setText("0.665");
        edit_box8->setText("0.33");
        edit_box10->setText("0.9");
        break;
    case 3:
        edit_box1->setText("0.13");
        edit_box8->setText("0.7");
        edit_box10->setText("0.5");
        break;
    default:
        break;
    }
}
