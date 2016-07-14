#include "settingswether.h"

SettingsWether::SettingsWether(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vLayout = new QVBoxLayout(this);
    locationEdit = new LocationEdit;
    dimBox = new QComboBox;
    locationLabel = new QLabel;
    dimLabel = new QLabel;

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

    setLayout(vLayout);

}

