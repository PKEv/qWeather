#include "hourlywidget.h"

HourlyWidget::HourlyWidget(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    vLayout = new QVBoxLayout(this);
    scrollArea = new QScrollArea(this);
    solitaryWidgetList.clear();
    SolitaryWidget *sololit = new SolitaryWidget();
    solitaryWidgetList.append(sololit);

    vLayout->addWidget(sololit);
    scrollArea->setLayout(vLayout);
}

