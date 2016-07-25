#ifndef SETTINGSWETHER_H
#define SETTINGSWETHER_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "locationedit.h"
#include "settings.h"

class SettingsWether : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWether(QWidget *parent = 0);


signals:

public slots:
    void Setup();
private:
    LocationEdit *locationEdit;
    QComboBox * dimBox;
    QLabel * locationLabel;
    QLabel * dimLabel;
    QVBoxLayout * vLayout;
    QPushButton * setupButton;
};

#endif // SETTINGSWETHER_H
