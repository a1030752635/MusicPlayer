#include "buttonform.h"
#include "ui_buttonform.h"

ButtonForm::ButtonForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonForm)
{
    ui->setupUi(this);

    ui->Line->hide();
    //设置Line1的动画效果
    line1_anima = new QPropertyAnimation(ui->label,"geometry",this);

    line1_anima->setDuration(1500);
    line1_anima->setKeyValueAt(0,QRect(2,27,2,0));
    line1_anima->setKeyValueAt(0.5,QRect(2,3,2,24));
    line1_anima->setKeyValueAt(1,QRect(2,27,2,0));

    line1_anima->setLoopCount(-1);
    line1_anima->start();

    //设置Line2的动画效果
    line2_anima = new QPropertyAnimation(ui->label_2,"geometry",this);

    line2_anima->setDuration(1600);
    line2_anima->setKeyValueAt(0,QRect(9,27,2,0));
    line2_anima->setKeyValueAt(0.5,QRect(9,3,2,24));
    line2_anima->setKeyValueAt(1,QRect(9,27,2,0));

    line2_anima->setLoopCount(-1);
    line2_anima->start();

    //设置动画3的效果
    line3_anima = new QPropertyAnimation(ui->label_3,"geometry",this);

    line3_anima->setDuration(1700);
    line3_anima->setKeyValueAt(0,QRect(16,27,2,0));
    line3_anima->setKeyValueAt(0.5,QRect(16,3,2,24));
    line3_anima->setKeyValueAt(1,QRect(16,27,2,0));

    line3_anima->setLoopCount(-1);
    line3_anima->start();
    //设置动画4的效果
    line4_anima = new QPropertyAnimation(ui->label_4,"geometry",this);

    line4_anima->setDuration(1800);
    line4_anima->setKeyValueAt(0,QRect(23,27,2,0));
    line4_anima->setKeyValueAt(0.5,QRect(23,3,2,24));
    line4_anima->setKeyValueAt(1,QRect(23,27,2,0));

    line4_anima->setLoopCount(-1);
    line4_anima->start();

}

ButtonForm::~ButtonForm()
{
    delete ui;
}

void ButtonForm::setIcon_Text(const QString &btIcon, const QString &btText,int pageId)
{
    ui->Icon->setPixmap(QPixmap(btIcon));

    ui->Text->setText(btText);

    //在给BT按钮设置图片、文本的同时，关联层叠窗口的对对应页面

    this->PageId = pageId;
}

int ButtonForm::getID()
{
    return PageId;
}

void ButtonForm::clearBackground()
{
    ui->ButtonStyle->setStyleSheet("#ButtonStyle:hover{background-color:#D8D8D8;}");
}

void ButtonForm::showImage(bool isShow)
{
    if(isShow)
    {
        ui->Line->show();
    }
    else
    {
        ui->Line->hide();
    }
}

void ButtonForm::mousePressEvent(QMouseEvent *event)
{
    //鼠标按下后，要做两件事

    //1.修改背景颜色
    ui->ButtonStyle->setStyleSheet("#ButtonStyle{background:rgb(30,206,154);}");
    //2.切换BodyRight的Page
    emit BtClick(PageId);

}
