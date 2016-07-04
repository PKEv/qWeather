#include "titlewidget.h"
#include <QLabel>
#include <QFont>
#include <QDebug>
const QString HIGHTLIGHT_STYLE = "font-size:25px;font-style:bold;color:black";
const QString DARK_STYLE = "font-size:20px;font-style:normal; color:darkgrey";

TitleWIdget::TitleWIdget(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("background-color:transparent");
    horizonalSlider = new HorizonalSlider(this);
    horizonalSlider->setGeometry(0,0,this->width(),this->height());
    horizonalSlider->setShowNumber(2);
}

void TitleWIdget::wheelEvent(QWheelEvent *ev)
{
    if(ev->delta() > 0)
    {
        prevTitle();
        emit prevTitleSignal();
    }
    else
    {
        nextTitle();
        emit nextTitleSignal();
    }
}


void TitleWIdget::nextTitle()
{
    if(horizonalSlider->currentIndex() == horizonalSlider->numberOfChildren() - 1)
        return;
    horizonalSlider->scrollToIndex(horizonalSlider->currentIndex() + 1);
    horizonalSlider->currentWidget()->setStyleSheet(HIGHTLIGHT_STYLE);
    horizonalSlider->preWidget()->setStyleSheet(DARK_STYLE);
    if(horizonalSlider->nextWidget())
        horizonalSlider->nextWidget()->setStyleSheet(DARK_STYLE);
}

void TitleWIdget::prevTitle()
{
    if(horizonalSlider->currentIndex() == 0)
        return;
    horizonalSlider->scrollToIndex(horizonalSlider->currentIndex() - 1);
    horizonalSlider->currentWidget()->setStyleSheet(HIGHTLIGHT_STYLE);
    horizonalSlider->nextWidget()->setStyleSheet(DARK_STYLE);
    if(horizonalSlider->preWidget())
        horizonalSlider->preWidget()->setStyleSheet(DARK_STYLE);
}

void TitleWIdget::firstTitle()
{
    horizonalSlider->scrollToIndex(0);
    horizonalSlider->currentWidget()->setStyleSheet(HIGHTLIGHT_STYLE);
    horizonalSlider->nextWidget()->setStyleSheet(DARK_STYLE);
    emit firstTitleSignal();
}


void TitleWIdget::setTitles(const QStringList &titles)
{
    _titles = titles;
    int currentIndex = 0;
    QList<QWidget* > labelList;
    foreach (QString title, _titles) {
        QLabel *label = new QLabel(title,horizonalSlider);
        label->setStyleSheet(DARK_STYLE);
        label->resize(horizonalSlider->width(),horizonalSlider->height());
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QFont font("Tahoma",20);
        label->setFont(font);
        labelList.append(label);
    }
    horizonalSlider->setChildren(labelList);
    horizonalSlider->scrollToIndex(currentIndex);
}

void TitleWIdget::resizeEvent(QResizeEvent *re)
{

    horizonalSlider->setGeometry(0,0,this->width(),this->height());
    horizonalSlider->currentWidget()->setStyleSheet(HIGHTLIGHT_STYLE);
    QWidget::resizeEvent(re);
}
