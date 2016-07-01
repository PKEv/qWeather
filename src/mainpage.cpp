#include "mainpage.h"
#include "ui_mainpage.h"

#include <QPropertyAnimation>

mainpage::mainpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainpage)
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
    delete ui;
}
