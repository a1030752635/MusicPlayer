#include "listitembox.h"
#include "ui_listitembox.h"

ListItemBox::ListItemBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListItemBox),
    isLike(false)
{
    ui->setupUi(this);
}

ListItemBox::~ListItemBox()
{
    delete ui;
}

void ListItemBox::enterEvent(QEvent *event)
{
    (void)event;
    setStyleSheet("background-color:#EFEFEF");
}

void ListItemBox::leaveEvent(QEvent *event)
{
    (void)event;
    setStyleSheet("");
}

void ListItemBox::setMusicName(const QString &name)
{
    ui->musicNameLabel->setText(name);
}

void ListItemBox::setSingerName(const QString &name)
{
    ui->musicSingerLabel->setText(name);
}

void ListItemBox::setAlbumName(const QString &name)
{
    ui->musicAlbumLabel->setText(name);
}

void ListItemBox::setLike(bool like)
{
    isLike = like;
    if(isLike)
    {
        ui->likeBtn->setIcon(QIcon(":/image/like_2.png"));
    }
    else
    {
        ui->likeBtn->setIcon(QIcon(":/image/like_3.png"));
    }
}

void ListItemBox::on_likeBtn_clicked()
{
    isLike = !isLike;
    setLike(isLike);
    emit setIsLike(isLike);
}
