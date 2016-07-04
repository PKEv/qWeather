#include "solitarywidget.h"

SolitaryWidget::SolitaryWidget(QWidget *parent) : QWidget(parent)
{

    hLayout = new QHBoxLayout(this);
    textLabel = new QLabel(this);
    iconLebel = new QLabel(this);;
    vLayout = new QVBoxLayout(this);;
    maxValLabel = new QLabel(this);;
    minValLabel = new QLabel(this);;
    lineLabel = new QLabel(this);;


    vLayout->addWidget(maxValLabel);
    vLayout->addWidget(lineLabel);
    vLayout->addWidget(minValLabel);

    hLayout->addWidget(textLabel);
    hLayout->addWidget(iconLebel);
    hLayout->addLayout(vLayout);

}

