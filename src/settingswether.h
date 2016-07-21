#ifndef SETTINGSWETHER_H
#define SETTINGSWETHER_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include "locationedit.h"

class SettingsWether : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWether(QWidget *parent = 0);


signals:

public slots:
private:
    LocationEdit *locationEdit;
    QComboBox * dimBox;
    QLabel * locationLabel;
    QLabel * dimLabel;
    QVBoxLayout * vLayout;
};

#endif // SETTINGSWETHER_H
