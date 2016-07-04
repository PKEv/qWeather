#include "hourlywidget.h"

HourlyWidget::HourlyWidget(QWidget *parent) : QWidget(parent)
{
    vLayout = new QVBoxLayout;
    scrollArea = new QScrollArea(this);
    solitaryWidgetList.clear();
    SolitaryWidget *sololit = new SolitaryWidget();
    solitaryWidgetList.append(sololit);

    vLayout->addWidget(sololit);
    scrollArea->setLayout(vLayout);


}

