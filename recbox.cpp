#include "recbox.h"
#include "ui_recbox.h"
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <cmath>
RecBox::RecBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecBox),
    row(1),col(4)
{
    ui->setupUi(this);

}

RecBox::~RecBox()
{
    delete ui;
}

void RecBox::initRecBox(QJsonArray data, int row)
{
    if(row == 2)
    {
        this->row = row;
        col = 8;
    }
    else
    {
        ui->recDown->hide();
    }

    imageList = data;

    currentIndex = 0;
    count = ceil(imageList.size() / col);
    createRecboxItem();
}

void RecBox::createRecboxItem()
{
    //清除原来已有的元素
    QList<RecBoxItem*> upList = ui->recUp->findChildren<RecBoxItem*>();
    for(auto& e : upList)
    {
        ui->upLayout->removeWidget(e);
        delete e;
    }

    QList<RecBoxItem*> downList = ui->recDown->findChildren<RecBoxItem*>();
    for(auto&e : downList)
    {
        ui->downLayout->removeWidget(e);
        delete e;
    }
    //col = 8

    int index = 0;
    for(int i = currentIndex*col;i < col+currentIndex*col;++i)
    {
        RecBoxItem* item = new RecBoxItem();

        QJsonObject obj = imageList[i].toObject();

        item->setText(obj.value("text").toString());
        item->setImage(obj.value("path").toString());
        if( index>= col / 2&& row == 2)
        {
            ui->downLayout->addWidget(item);
        }
        else
        {
            ui->upLayout->addWidget(item);

        }
        ++index;
    }

}

void RecBox::on_down_clicked()
{
    currentIndex++;
    if(currentIndex >= count)
    {
        currentIndex=0;
    }
    createRecboxItem();
}

void RecBox::on_up_clicked()
{
    currentIndex--;
    if(currentIndex < 0)
    {
        currentIndex = count - 1;
    }
    createRecboxItem();
}
