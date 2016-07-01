#include <QDate>
#include "dailywidget.h"

#define temp 1
DailyWidget::DailyWidget(QWidget *parent) : QWidget(parent)
{
    setGeometry(0,0,parent->width()/2,parent->height()/2);
    //setStyleSheet("background-color:rgba(255,255,255,0);border:none");
    vBoxLayout = new QVBoxLayout;
    sityLabel = new QLabel;
    dateLabel = new QLabel;
#ifdef temp
    sityLabel->setText("Санкт Петербург");
    dateLabel->setText(QDate::currentDate().toString("ddd MMMM d yy"));
#endif
    vBoxLayout->addWidget(sityLabel);
    vBoxLayout->addWidget(dateLabel);

    setupH1Layout();
    vBoxLayout->addLayout(h1BoxLayout);


    setLayout(vBoxLayout);

    show();

}

void DailyWidget::setupH1Layout()
{
    h1BoxLayout = new QHBoxLayout;
    tempFrame = new QFrame;
    tempLabel = new QLabel;
    tempDimLabel = new QLabel;
    maxTempLabel = new QLabel;
    minTempLabel = new QLabel;
    picLabel = new QLabel;

    tempFrame->setGeometry(QRect(0,0,185,185));
    tempFrame->setStyleSheet("border-radius:15px;"
                             "background-color: rgba(255, 255, 255, 0);"
                             "border-style:inset;"
                             "border-width:2px;"
                             "border-color:rgba(255, 255, 255, 180);"
                             "color:white\n");

    tempFrame->set

    h1BoxLayout->addWidget(tempFrame);
    h1BoxLayout->addWidget(picLabel);

}
