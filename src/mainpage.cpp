#include "mainpage.h"

#include <QPropertyAnimation>

mainpage::mainpage(QWidget *parent) :
    QWidget(parent)
{
    resize(400, 400);
    setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    //vBoxLayout = new QVBoxLayout(this);


    titleWidget = new TitleWIdget(this);
    QStringList titles;
    titles << tr("Текущее значение") << "Почасовой прогноз" << "Прогноз по дням" << "Настройки" ;
    titleWidget->setGeometry(0, 0, this->width(), 50);
    titleWidget->setTitles(titles);
    //titleWidget->setGeometry(0,0,this->width(),200);
    //titleWidget->res


    contentWidget = new ContentWidget(this);

    dailyWidget = new DailyWidget(this);
    /*
    hourlyWidget = new HourlyWidget(this);*/
    settingsWether = new SettingsWether(this);

    //SettingsWether *settings2Wether = new SettingsWether(this);

    QRect size = QRect(0,
                       titleWidget->y() + titleWidget->height(),
                       this->width(),
                       this->height() - titleWidget->y() - titleWidget->height());

    contentWidget->setGeometry(size);

    dailyWidget->setGeometry(size);
    /*
    hourlyWidget->setGeometry(size);*/
    settingsWether->setGeometry(size);/*
    settings2Wether->setGeometry(size);*/

    //contentWidget->setContentsMargins(0,0,0,0);

    widgetList  << dailyWidget /*<< hourlyWidget*/ << settingsWether /*<< settings2Wether*/;
    contentWidget->setWidget(widgetList);

    connect(titleWidget, SIGNAL(prevTitleSignal()), contentWidget, SLOT(prevWidget()));
    connect(titleWidget, SIGNAL(nextTitleSignal()), contentWidget, SLOT(nextWidget()));
    connect(titleWidget, SIGNAL(firstTitleSignal()), contentWidget, SLOT(firstWidget()));

    //vBoxLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    //vBoxLayout->addWidget(titleWidget);
    //vBoxLayout->addWidget(contentWidget);
    //vBoxLayout->setAlignment(titleWidget,Qt::AlignTop);
    //setLayout(vBoxLayout);

    request = new WeatherRequest();
    request->setCityName("Moscow");


    QPushButton *push = new QPushButton(this);
    push->setText("Проверка");
    push->setGeometry(0,700,100,20);
    push->setVisible(true);
    connect (push, SIGNAL(clicked(bool)),this, SLOT(Button()));

    //int a, b,c,d;
    //getContentsMargins(&a,&b,&c,&d);
    //setWindowTitle(QString:: number(a)+QString:: number(b)+QString:: number(c)+QString:: number(d));

}
void mainpage::Button()
{

    setWindowTitle(QString:: number(dailyWidget->x())+"+"+QString:: number(dailyWidget->y()));
}

mainpage::~mainpage()
{

}
