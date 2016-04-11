#include "titlewidget.h"

TitleWidget::TitleWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(450, 500);
    this->setLayout(new QVBoxLayout);
    this->layout()->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    task_list = new QComboBox(this);
    /*task_list->setMinimumWidth(200);
    task_list->setMaximumWidth(400);*/
    task_list->addItem("Задача об инвестировании средств");
    task_list->addItem("Задача об американском футболе");
    task_list->addItem("Задача о ядерном реакторе");

    QFont font;
    font.setFamily("Arial");
    font.setPointSize(11);

    descript_label = new QLabel(this);
    descript_label->setFixedSize(400, 400);
    descript_label->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    descript_label->setWordWrap(true);
    descript_label->setFont(font);

    btn_layout = new QHBoxLayout();
    btn_maslov_1 = new QPushButton("Запустить Вариант №1", this);
    btn_maslov_2 = new QPushButton("Запустить Вариант №2", this);
    btn_martinov = new QPushButton("Запустить", this);
    btn_kuvshinov = new QPushButton("Запустить", this);
    ClearWidget();
    btn_layout->addWidget(btn_maslov_1);
    btn_layout->addWidget(btn_maslov_2);
    btn_layout->addWidget(btn_martinov);
    btn_layout->addWidget(btn_kuvshinov);

    this->layout()->addWidget(task_list);
    this->layout()->addWidget(descript_label);
    this->layout()->addItem(btn_layout);


    connect(task_list, SIGNAL(activated(int)), this, SLOT(ChangeTaks(int)));
    connect(btn_maslov_1, SIGNAL(clicked(bool)), this, SLOT(StartMaslovZ1()));
    connect(btn_maslov_2, SIGNAL(clicked(bool)), this, SLOT(StartMaslovZ2()));
    connect(btn_martinov, SIGNAL(clicked(bool)), this, SLOT(StartMartinov()));
    connect(btn_kuvshinov, SIGNAL(clicked(bool)), this, SLOT(StartKuvshinov()));
}

TitleWidget::~TitleWidget()
{

}

void TitleWidget::ChangeTaks(int i)
{
    switch (i) {
    case 0:
        InitMaslov();
        break;
    case 1:
        InitMartinov();
        break;
    case 2:
        InitKuvshinov();
        break;
    default:
        break;
    }
}

void TitleWidget::InitKuvshinov()
{
    descript_label->setText("Имеется обыный ядерный реактор и нового типа. Для исользования нового реактора нужно проводить тест. Тест не бесплатный и может показать с заданными вероятностями разный результат. Программа должна решить стоит ли провидить тест и какие действия предпринять для различных вариантах теста. Программа проводит анализ текущего состояния среды(вероятностей результатов, стоимости переходов, функци полезности) и решает задачу проведения постройки реактора. На вход программе подается таблица с вероятностями исходов, ожидаемыми полезностями от коненых испходов и ожидаемыми смертями. На выход программа выдает ответы на вопросы: ""Стоит ли проводить тест?"", ""Что делать в различных варинтах теста"".");
    ClearWidget();
    btn_kuvshinov->show();
}

void TitleWidget::InitMartinov()
{
    descript_label->setText("Пусть тренер со своей командой принимает участие в чемпионате по американскому футболу. В очень важной игре до конца матча остается меньше минуты. Команда совершила тачдаун. При этом проигрывает со счетом 16:17. По правилам, после тачдауна команда может заработать дополнительные очки, тренеру предоставляется выбор: попробовать забить гол, заработав 1 очко, и тем самым сравнять счет (при этом времени на победу уже не останется), либо попытаться совершить еще один тачдаун, заработав 2 очка, и, возможно, выиграть матч. Будем считать, что вероятность забить гол гораздо выше, чем сделать еще один тачдаун.");
    ClearWidget();
    btn_martinov->show();
}

void TitleWidget::InitMaslov()
{
    descript_label->setText("Пусть некий начинающий инвестор, имеющий в своем распоряжении небольшую сумму денег и большое желание преумножить имеющийся капитал, рассматривает два варианта вложения средств – в акции и в облигации с купонным доходом. Вариант вложения в облигации является надежным, однако имеет достаточно низкую доходность. При вложении средств в акции в связи с непредсказуемостью поведения рынка существует вероятность потерять вложенные средства. Задача сводится к выбору наилучшего варианта из двух рассматриваемых. Для оценки ка- чества принимаемого решения будем использовать математическое ожидание получаемого инвестором дохода");
    ClearWidget();
    btn_maslov_1->show();
    btn_maslov_2->show();
}

void TitleWidget::ClearWidget()
{
    btn_maslov_1->hide();
    btn_maslov_2->hide();
    btn_kuvshinov->hide();
    btn_martinov->hide();
}

void TitleWidget::StartKuvshinov()
{
    Nuclear* w = new Nuclear();
    w->show();
}

void TitleWidget::StartMartinov()
{
    Task_1_4_1* w = new Task_1_4_1();
    w->show();
}

void TitleWidget::StartMaslovZ1()
{
    Invest_z1* w = new Invest_z1();
    w->show();
}

void TitleWidget::StartMaslovZ2()
{
    Invest_z2* w = new Invest_z2();
    w->show();
}
