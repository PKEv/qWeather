#include "mainpage.h"

#include <QPropertyAnimation>

mainpage::mainpage(QWidget *parent) :
    QWidget(parent)
{
    resize(400,400);
    //vBoxLayout = new QVBoxLayout;

    titleWidget = new TitleWIdget(this);
    QStringList titles;
    titles << tr("Текущее значение") << "Почасовой прогноз" << "Прогноз по дням" << "Настройки" ;
    titleWidget->setTitles(titles);
    //titleWidget->setGeometry(0,0,this->width(),200);
    //titleWidget->res

    contentWidget = new ContentWidget(this);
    dailyWidget = new DailyWidget(this);
    hourlyWidget = new HourlyWidget(this);
    settingsWether = new SettingsWether(this);

    widgetList << dailyWidget << hourlyWidget << settingsWether;
    contentWidget->setWidget(widgetList);

    connect(titleWidget, SIGNAL(prevTitleSignal()), contentWidget, SLOT(prevWidget()));
    connect(titleWidget, SIGNAL(nextTitleSignal()), contentWidget, SLOT(nextWidget()));
    connect(titleWidget, SIGNAL(firstTitleSignal()), contentWidget, SLOT(firstWidget()));

    //vBoxLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    titleWidget->setGeometry(0,0,this->width(),50);
    contentWidget->setGeometry(0,
                               titleWidget->y() + titleWidget->height(),
                               this->width(),
                               this->height() - titleWidget->height());
    //vBoxLayout->addWidget(titleWidget);
    //vBoxLayout->addWidget(contentWidget);
    //vBoxLayout->setAlignment(titleWidget,Qt::AlignTop);
    
    //setLayout(vBoxLayout);

    request = new WeatherRequest();
    request->setCityName("Moscow");

}

mainpage::~mainpage()
{

}
