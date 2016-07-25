#include "settingswether.h"

SettingsWether::SettingsWether(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    vLayout = new QVBoxLayout();
    locationEdit = new LocationEdit;
    dimBox = new QComboBox;
    locationLabel = new QLabel;
    dimLabel = new QLabel;
    setupButton = new QPushButton;

    locationLabel->setText(tr("Название города:"));
    dimLabel->setText(tr("Размерность показателей:"));

    dimBox->clear();
    dimBox->addItem("Цельсий");
    dimBox->addItem("Фаренгейт");


    vLayout->addWidget(locationLabel);
    vLayout->addWidget(locationEdit);
    vLayout->addWidget(dimLabel);
    vLayout->addWidget(dimBox);
    vLayout->addWidget(setupButton);

    setLayout(vLayout);

    locationEdit->setText(Settings::getInstance().cityName);
    int index = Settings::getInstance().getDim();
    dimBox->setCurrentIndex(index);
    setupButton->setText(tr("Установить"));

    connect(setupButton, SIGNAL(clicked(bool)), this, SLOT(Setup()));
}

void SettingsWether::Setup()
{
    Settings::getInstance().cityName = locationEdit->text();
    Settings::getInstance().setDim(dimBox->currentIndex());
    Settings::getInstance().SaveSettings();
}

