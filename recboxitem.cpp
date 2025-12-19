#include "recboxitem.h"
#include "ui_recboxitem.h"
#include <QPropertyAnimation>
#include <QDebug>
RecBoxItem::RecBoxItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecBoxItem)
{
    ui->setupUi(this);

    ui->image->installEventFilter(this);
}

RecBoxItem::~RecBoxItem()
{
    delete ui;
}

bool RecBoxItem::eventFilter(QObject *watched, QEvent *event)
{
    if(ui->image == watched)
    {
        if(QEvent::Enter == event->type())
        {
            QPropertyAnimation* anima = new QPropertyAnimation(ui->image,"geometry");
            anima->setDuration(150);
            anima->setStartValue(QRect(0,9,ui->image->width(),ui->image->height()));
            anima->setEndValue(QRect(0,0,ui->image->width(),ui->image->height()));
            anima->start();

            connect(anima,&QPropertyAnimation::finished,this,[=](){
                delete anima;
            });
        }
        else if(QEvent::Leave == event->type())
        {
            QPropertyAnimation* anima = new QPropertyAnimation(ui->image,"geometry");
            anima->setDuration(150);
            anima->setStartValue(QRect(0,0,ui->image->width(),ui->image->height()));
            anima->setEndValue(QRect(0,9,ui->image->width(),ui->image->height()));
            anima->start();

            connect(anima,&QPropertyAnimation::finished,this,[=](){
                delete anima;
            });
        }
        else{
            return false;
        }
    }
    return QObject::eventFilter(watched,event);
}

void RecBoxItem::setText(const QString &text)
{
    ui->label->setText(text);
}

void RecBoxItem::setImage(const QString &path)
{
    QString style = "background-image:url(" + path+");";
    ui->image->setStyleSheet(style);
}

