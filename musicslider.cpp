#include "musicslider.h"
#include "ui_musicslider.h"

MusicSlider::MusicSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicSlider)
{
    ui->setupUi(this);

    currentPos = 0;
    maxWidth = width();
    moveSlider();
}

MusicSlider::~MusicSlider()
{
    delete ui;
}

void MusicSlider::mousePressEvent(QMouseEvent *event)
{
    currentPos = event->pos().x();
    moveSlider();
}

void MusicSlider::mouseMoveEvent(QMouseEvent *event)
{
    //如果鼠标不在outline，则不移动
    QRect rect = QRect(0,0,width(),height());
    QPoint point = event->pos();
    if(!rect.contains(point))
    {
        return;
    }

    if(event->buttons() == Qt::LeftButton)
    {
        currentPos = event->pos().x();

        if(currentPos < 0)
        {
            currentPos = 0;
        }
        if(currentPos>maxWidth)
        {
            currentPos = maxWidth;
        }

        moveSlider();
    }
}

void MusicSlider::mouseReleaseEvent(QMouseEvent *event)
{
    currentPos = event->pos().x();
    moveSlider();

    emit setMusicSliderPos((float)currentPos/(float)maxWidth);
}

void MusicSlider::moveSlider()
{
    ui->outLine->setMaximumWidth(currentPos);
    ui->outLine->setGeometry(0,8,currentPos,4);
}

void MusicSlider::setStep(float bf)
{
    currentPos = maxWidth * bf;
    moveSlider();
}
