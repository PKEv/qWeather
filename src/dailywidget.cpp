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
    setupH2Layout();

    vBoxLayout->addLayout(h1BoxLayout);
    vBoxLayout->addLayout(h2BoxLayout);

    setLayout(vBoxLayout);

    show();

}

void DailyWidget::setupH1Layout()
{
    h1BoxLayout = new QHBoxLayout;
    tempFrame = new QFrame;
    tempFrameLayout = new QGridLayout(tempFrame);

    tempLabel = new QLabel(tempFrame);
    tempDimLabel = new QLabel(tempFrame);
    maxTempLabel = new QLabel(tempFrame);
    minTempLabel = new QLabel(tempFrame);
    lineLabel = new QLabel(tempFrame);
    picLabel = new QLabel;

    tempFrameLayout->addWidget(tempLabel, 0, 0, 2, 2);
    tempFrameLayout->addWidget(tempDimLabel, 0, 3);
    tempFrameLayout->addWidget(lineLabel, 3, 0, 1, 0, 0 );
    tempFrameLayout->addWidget(maxTempLabel, 4, 0);
    tempFrameLayout->addWidget(minTempLabel, 4, 2);

    tempFrameLayout->setSpacing(1);

#ifdef temp
    tempLabel->setText("27");
    tempDimLabel->setText("C");
    maxTempLabel->setText("27");
    minTempLabel->setText("-2");
#endif

    lineLabel->setMaximumHeight(3);
    lineLabel->setStyleSheet("border-width:5px;"
                             "border-style:solid;"
                             "border-radius:0px;"
                             "border-color:rgb(255, 255, 255)");

    minTempLabel->setFont(QFont("Arial", 18));
    minTempLabel->setStyleSheet("border-width:0px");

    maxTempLabel->setFont(QFont("Arial", 18));
    maxTempLabel->setStyleSheet("border-width:0px");

    tempDimLabel->setFont(QFont("Arial", 20));
    tempDimLabel->setStyleSheet("border-width:0px");

    tempLabel->setFont(QFont("Arial", 72));
    tempLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                             "border-width:0px");

    tempFrame->setGeometry(QRect(0, 0, 185, 185));
    tempFrame->setStyleSheet("border-radius:15px;"
                             "background-color: rgba(255, 255, 255, 0);"
                             "border-style:inset;"
                             "border-width:2px;"
                             "border-color:rgba(255, 255, 255, 180);"
                             "color:white\n");

    picLabel->setStyleSheet("border-radius:15px;"
                            "background-color: rgba(255, 255, 255, 0);"
                            "border-style:inset;"
                            "border-width:2px;"
                            "border-color:rgba(255, 255, 255, 180);"
                            "color:white;"
                            "background-position:center center;");



    h1BoxLayout->addWidget(tempFrame);
    h1BoxLayout->addWidget(picLabel);

}

void DailyWidget::setupH2Layout()
{
    h2BoxLayout = new QHBoxLayout;

    humidityFrame = new QFrame;
    humidityLayout = new QVBoxLayout(humidityFrame);

    humidityLabel = new QLabel;
    humidityValueLabel = new QLabel;
    humidityDimLabel = new QLabel;

    fin1LineLabel = new QLabel;
    fin2LineLabel = new QLabel;

    setupSmallW(humidityFrame, humidityLayout, humidityLabel, humidityValueLabel, humidityDimLabel, fin1LineLabel, fin2LineLabel );

    windFrame = new QFrame;
    windLayout = new QVBoxLayout(windFrame);

    windLabel = new QLabel;
    windValueLabel = new QLabel;
    windDimLabel = new QLabel;

    fin3LineLabel = new QLabel;
    fin4LineLabel = new QLabel;

    setupSmallW(windFrame, windLayout, windLabel, windValueLabel, windDimLabel, fin3LineLabel, fin4LineLabel );

    presFrame = new QFrame;
    presLayout = new QVBoxLayout(presFrame);

    presLabel = new QLabel;
    presValueLabel = new QLabel;
    presDimLabel = new QLabel;

    fin5LineLabel = new QLabel;
    fin6LineLabel = new QLabel;

    setupSmallW(presFrame, presLayout, presLabel, presValueLabel, presDimLabel, fin5LineLabel, fin6LineLabel );

    precipitationFrame = new QFrame;
    precipitationLayout = new QVBoxLayout(precipitationFrame);

    precipitationLabel = new QLabel;
    precipitationValueLabel = new QLabel;
    precipitationDimLabel = new QLabel;

    fin7LineLabel = new QLabel;
    fin8LineLabel = new QLabel;

    setupSmallW(precipitationFrame, precipitationLayout, precipitationLabel, precipitationValueLabel, precipitationDimLabel, fin7LineLabel, fin8LineLabel );

#ifdef temp
    windLabel->setText("Ветер");
    windValueLabel->setText("мало");
    windDimLabel->setText("%%%");

    humidityLabel->setText("Влажность");
    humidityValueLabel->setText("мало");
    humidityDimLabel->setText("%%%");

    presLabel->setText("Давл");
    presValueLabel->setText("мало");
    presDimLabel->setText("%%%");

    precipitationLabel->setText("Осад");
    precipitationValueLabel->setText("мало");
    precipitationDimLabel->setText("%%%");
#endif

    h2BoxLayout->addWidget(humidityFrame);
    h2BoxLayout->addWidget(windFrame);
    h2BoxLayout->addWidget(presFrame);
    h2BoxLayout->addWidget(precipitationFrame);
}

void DailyWidget::setupSmallW(QFrame * parentw,QVBoxLayout * layout, QLabel* laybel, QLabel* value, QLabel* dim, QLabel* line1, QLabel *line2 )
{
    laybel->setParent(parentw);
    value->setParent(parentw);
    dim->setParent(parentw);
    line1->setParent(parentw);
    line2->setParent(parentw);

    layout->addWidget(laybel);
    layout->addWidget(line1);
    layout->addWidget(value);
    layout->addWidget(line2);
    layout->addWidget(dim);

    line1->setStyleSheet("border-width:5px;"
                             "border-style:solid;"
                             "border-radius:0px;"
                             "border-color:rgb(255, 255, 255)");

    line2->setStyleSheet("border-width:5px;"
                             "border-style:solid;"
                             "border-radius:0px;"
                             "border-color:rgb(255, 255, 255)");

    line1->setMaximumHeight(1);
    line2->setMaximumHeight(1);

    laybel->setFont(QFont("Arial", 9));
    laybel->setStyleSheet("border-width:0px");

    value->setFont(QFont("Arial", 24));
    value->setStyleSheet("border-width:0px");

    dim->setFont(QFont("Arial", 9));
    dim->setStyleSheet("border-width:0px");

    parentw->setStyleSheet("border-radius:10px;"
                           "background-color: rgba(255, 255, 255, 0);"
                           "border-style:inset;"
                           "border-width:1px;"
                           "border-color:rgba(255, 255, 255, 180);"
                           "color:white");
}
