#include "settingswether.h"

SettingsWether::SettingsWether(QWidget *parent) : QWidget(parent)
{
    setGeometry(0,0,parent->width()/2,parent->height()/2);
resize(400,400);
    locationEdit = new LocationEdit;
    dimBox = new QComboBox;
    locationLabel = new QLabel;
    dimLabel = new QLabel;
    vLayout = new QVBoxLayout;

    locationLabel->setText(tr("Название города:"));
    dimLabel->setText(tr("Размерность показателей:"));

    dimBox->clear();
    dimBox->addItem("Цельсий");
    dimBox->addItem("Фаренгейт");
    dimBox->setCurrentIndex(0);

    vLayout->addWidget(locationLabel);
    vLayout->addWidget(locationEdit);
    vLayout->addWidget(dimLabel);
    vLayout->addWidget(dimBox);
    vLayout->setGeometry(QRect(0,0,this->width(), this->height()));

    setLayout(vLayout);


}

