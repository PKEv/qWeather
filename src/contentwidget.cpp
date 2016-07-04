#include "contentwidget.h"

ContentWidget::ContentWidget(QWidget *parent) :
    QWidget(parent)
{
    horizonalSlider = new HorizonalSlider(this);
    horizonalSlider->setShowNumber(1);
    horizonalSlider->setGeometry(0,0,this->width(),this->height());
}

//void ContentWidget::wheelEvent(QWheelEvent *ev)
//{
//    if(ev->delta() > 0)
//    {
//        prevWidget();
//        emit prevWidgetSignal();
//    }
//    else
//    {
//        nextWidget();
//        emit nextWidgetSignal();
//    }
//}

void ContentWidget::nextWidget()
{
    if(horizonalSlider->currentIndex() == horizonalSlider->numberOfChildren() - 1)
        return;
    else
        horizonalSlider->scrollToIndex(horizonalSlider->currentIndex() + 1);
}

void ContentWidget::prevWidget()
{
    if(horizonalSlider->currentIndex() == 0)
        return;
    else
        horizonalSlider->scrollToIndex(horizonalSlider->currentIndex() - 1);
}

void ContentWidget::firstWidget()
{
    horizonalSlider->scrollToIndex(0);
    emit firstWidgetSignal();
}

void ContentWidget::setWidget(const QList<QWidget *> &widgetList)
{
    _widgets = widgetList;
    horizonalSlider->setChildren(_widgets);
    horizonalSlider->scrollToIndex(0);
}


void ContentWidget::resizeEvent(QResizeEvent *re)
{
    horizonalSlider->setGeometry(0,0,this->width(),this->height());
    QWidget::resizeEvent(re);
}
