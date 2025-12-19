#include "commonpage.h"
#include "ui_commonpage.h"
#include "listitembox.h"

commonPage::commonPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::commonPage)
{
    ui->setupUi(this);

    ui->pageMusicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(ui->pageMusicList,&QListWidget::doubleClicked,this,[=](const QModelIndex& index){
       emit playMusicByIndex(this,index.row());
    });
}

commonPage::~commonPage()
{
    delete ui;
}

void commonPage::setCommonPageUI(const QString &title, const QString &image)
{
    ui->pageTittle->setText(title);

    ui->musicImageLabel->setPixmap(QPixmap(image));
    ui->musicImageLabel->setScaledContents(true);

}

void commonPage::setMusicListType(PageType pageType)
{
    this->pageType = pageType;
}

void commonPage::addMusicToMusicPage(MusicList &List)
{

    musicListOfPage.clear();
    //在MusicList中定义了迭代器，所以支持了范围for
    for(auto& music: List)
    {
           switch(pageType)
           {
            case LOCAL_PAGE:
               musicListOfPage.push_back(music.getMusicId());
                break;
            case LIKE_PAGE:
           {
               if(music.getIsLike())
               {
                   musicListOfPage.push_back(music.getMusicId());
               }
               break;
           }
            case HISTORY_PAGE:
           {
               if(music.getIsHistory())
               {
                   musicListOfPage.push_back(music.getMusicId());
               }
               break;
           }
           default:
               break;
           }
    }
}

void commonPage::reFresh(MusicList &musicList)
{
    ui->pageMusicList->clear();
    //从musicList中分离出当前页面的音乐
    addMusicToMusicPage(musicList);

    //遍历这些音乐，显示到界面
    for(auto& id : musicListOfPage)
    {
        auto it = musicList.findMusicById(id);
        if(it == musicList.end())
            continue;

        ListItemBox* box = new ListItemBox(ui->pageMusicList);
        box->setMusicName(it->getMusicName());
        box->setSingerName(it->getSingerName());
        box->setAlbumName(it->getAlbumName());
        box->setLike(it->getIsLike());


        //如果listWidget的IteM是自定义的，就用这种方法添加一行item
        QListWidgetItem* item = new QListWidgetItem(ui->pageMusicList);
        item->setSizeHint(QSize(ui->pageMusicList->width(),45));
        ui->pageMusicList->setItemWidget(item,box);

        //在这个地方接收ListItemBox的信号
        connect(box,&ListItemBox::setIsLike,this,[=](bool isLike){
            emit updateLikeMusic(isLike,it->getMusicId());
        });
    }
    ui->pageMusicList->repaint();



}

void commonPage::addMusicToPlayer(MusicList &musicList, QMediaPlaylist *playList)
{
 //根据musicList，添加到playList
    for(auto& music: musicList)
    {
        switch(pageType)
        {
        case LOCAL_PAGE:
        {
            playList->addMedia(music.getMusicUrl());
            break;
        }
        case LIKE_PAGE:
        {
            if(music.getIsLike())
            {
                playList->addMedia(music.getMusicUrl());
            }
            break;
        }
        case HISTORY_PAGE:
        {
            if(music.getIsHistory())
            {
                playList->addMedia(music.getMusicUrl());
            }
            break;
        }
        default:
            break;
        }
    }
}

const QString commonPage::getMusicIdByIndex(int index) const
{
    if(index >= musicListOfPage.size())
    {
        qDebug() << "无此歌曲";
        return"";
    }
    return musicListOfPage[index];
}

void commonPage::on_playAllBtn_clicked()
{
    emit playAll(pageType);
}
