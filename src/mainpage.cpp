#include "mainpage.h"

#include <QPropertyAnimation>

mainpage::mainpage(QWidget *parent) :
    QWidget(parent)
{
    resize(400,400);
    vBoxLayout = new QVBoxLayout;

    titleWidget = new TitleWIdget(this);
    QStringList titles;
    titles << tr("Текущее значение") << "Почасовой прогноз" << "Прогноз по дням" << "Настройки" ;
    titleWidget->setTitles(titles);

    vBoxLayout->addWidget(titleWidget);


    dailyWidget = new DailyWidget(this);
    //dailyWidget->show();

    vBoxLayout->addWidget(dailyWidget);


    setLayout(vBoxLayout);
}

mainpage::~mainpage()
{

}
