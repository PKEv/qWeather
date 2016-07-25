#include "mainpage.h"

#include <QPropertyAnimation>

mainpage::mainpage(QWidget *parent) :
    QWidget(parent)
{
    resize(400, 400);
    setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    titleWidget = new TitleWIdget(this);
    QStringList titles;
    titles << tr("Текущее значение") << tr("Подробный прогноз") << tr("Прогноз по дням") << tr("Настройки") ;
    titleWidget->setGeometry(0, 0, this->width(), 50);
    titleWidget->setTitles(titles);

    contentWidget = new ContentWidget(this);

    dailyWidget = new DailyWidget(this);

    hourlyWidget = new HourlyWidget(this);
    settingsWether = new SettingsWether(this);

    QRect size = QRect(0,
                       titleWidget->y() + titleWidget->height(),
                       this->width(),
                       this->height() - titleWidget->y() - titleWidget->height());

    contentWidget->setGeometry(size);

    dailyWidget->setGeometry(size);
    hourlyWidget->setGeometry(size);
    settingsWether->setGeometry(size);

    widgetList  << dailyWidget << hourlyWidget << settingsWether;
    contentWidget->setWidget(widgetList);

    connect(titleWidget, SIGNAL(prevTitleSignal()), contentWidget, SLOT(prevWidget()));
    connect(titleWidget, SIGNAL(nextTitleSignal()), contentWidget, SLOT(nextWidget()));
    connect(titleWidget, SIGNAL(firstTitleSignal()), contentWidget, SLOT(firstWidget()));

    Settings::getInstance().ReadSettings();

    request = new WeatherRequest();
    request->setCityName(Settings::getInstance().cityName);

}
void mainpage::Button()
{
    setWindowTitle(QString:: number(dailyWidget->x())+"+"+QString:: number(dailyWidget->y()));
}

mainpage::~mainpage()
{
    Settings::getInstance().SaveSettings();
}
