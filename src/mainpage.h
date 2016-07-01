#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <dailywidget.h>
#include <QPushButton>
#include "titlewidget.h"

namespace Ui {
class mainpage;
}

class mainpage : public QWidget
{
    Q_OBJECT

public:
    explicit mainpage(QWidget *parent = 0);
    ~mainpage();
     TitleWIdget *titleWidget;

public slots:



private:
    Ui::mainpage *ui;
    DailyWidget * dailyWidget;
    QVBoxLayout* vBoxLayout;
    QVBoxLayout* h1BoxLayout;
    QPushButton * button;

};

#endif // MAINPAGE_H
