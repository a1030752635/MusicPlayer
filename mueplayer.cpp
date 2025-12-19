#include "mueplayer.h"
#include "ui_mueplayer.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QList>
#include <QVector>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <cstdlib>
#include <QFileDialog>
#include <QDir>
#include <QUrl>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QMenu>
MuePlayer::MuePlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MuePlayer)
{
    ui->setupUi(this);

    initUi();

    initPlayer();
    initSQLite();
    initMusicList();
    connectSignalAndSlot();
}

MuePlayer::~MuePlayer()
{
    delete ui;
}

void MuePlayer::initUi()
{
    //设置窗口 没有默认的标题栏
    this->setWindowFlag(Qt::FramelessWindowHint);//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);//半透明
    this->setWindowIcon(QIcon(":/image/tubiao.png"));
    ui->max->setEnabled(false);
    //设置窗口的阴影效果
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0,0);
    effect->setColor("blue");//阴影的颜色
    effect->setBlurRadius(10);
    //在设置GraphicsEffect后，我发现，我原来设置的background-color，会被覆盖，于是
    //假设设置半透明和background，是什么样的,红色没了，只剩下了半透明效果
    //假设设置半透明和红色的effect，结果是毛玻璃效果
    //于是，得出结论，半透明和effect，会覆盖background-color的效果
    //想要设置毛玻璃效果，effect+半透明即可，不需要考虑backgroun-color的影响。
    this->setGraphicsEffect(effect);

    //添加托盘，创建托盘图标
    QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/image/tubiao.png"));
    //创建托盘菜单
    QMenu* trayMenu = new QMenu(this);
    trayMenu->addAction("窗口最大化",this,&QWidget::showNormal);
    trayMenu->addSeparator();
    trayMenu->addAction("退出程序",this,&MuePlayer::quitMuePlayer);

    //将托盘菜单和托盘图标关联
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();



    //8.8Update
    //设置图标
    ui->recomd->setIcon_Text(":/image/rec.png","推荐",0);
    ui->audio->setIcon_Text(":/image/radio.png","电台",1);
    ui->music->setIcon_Text(":/image/music.png","音乐",2);
    ui->like->setIcon_Text(":/image/like.png","喜欢",3);
    ui->localMusic->setIcon_Text(":/image/local.png","本地音乐",4);
    ui->recent->setIcon_Text(":/image/recent.png","最近播放",5);

    //只显示本地音乐的动画
    ui->stackedWidget->setCurrentIndex(4);
    currentPage = ui->loaclMusicPage;
    ui->localMusic->showImage();


    srand(time(nullptr));
    ui->todayBox->initRecBox(RandomFile(),1);
    ui->supplyBox->initRecBox(RandomFile(),2);


    //
    ui->likePage->setCommonPageUI("我喜欢",":/image/ilikebg.png");
    ui->loaclMusicPage->setCommonPageUI("本地音乐",":/image/localbg.png");
    ui->recentPage->setCommonPageUI("最近播放",":/image/recentbg.png");

    //
    volume = new VolumeTool(this);

    //设置commonPage的信息,由initMusicList完成
    //ui->likePage->setMusicListType(PageType::LIKE_PAGE);
    //ui->loaclMusicPage->setMusicListType(PageType::LOCAL_PAGE);
    //ui->recentPage->setMusicListType(PageType::HISTORY_PAGE);

    //
    ui->play->setIcon(QIcon(":/image/play_2.png"));
    ui->playMode->setIcon(QIcon(":/image/shuffle_2.png"));

    //
    lrcPage = new LrcPage(this);
    lrcPage->hide();

    lrcAnimation = new QPropertyAnimation(lrcPage,"geometry",this);//给谁设置动画，动画的形状
    lrcAnimation->setDuration(250);//单位ms
    lrcAnimation->setStartValue(QRect(10,lrcPage->height()+10,lrcPage->width(),lrcPage->height()));
    lrcAnimation->setEndValue(QRect(10,10,lrcPage->width(),lrcPage->height()));


}

void MuePlayer::connectSignalAndSlot()
{
    connect(ui->recomd,&ButtonForm::BtClick,this,&MuePlayer::onBtClick);
    connect(ui->audio,&ButtonForm::BtClick,this,&MuePlayer::onBtClick);
    connect(ui->music,&ButtonForm::BtClick,this,&MuePlayer::onBtClick);
    connect(ui->like,&ButtonForm::BtClick,this,&MuePlayer::onBtClick);
    connect(ui->localMusic,&ButtonForm::BtClick,this,&MuePlayer::onBtClick);
    connect(ui->recent,&ButtonForm::BtClick,this,&MuePlayer::onBtClick);

    //
    connect(ui->likePage,&commonPage::updateLikeMusic,this,&MuePlayer::onUpdateLikeMusic);
    connect(ui->loaclMusicPage,&commonPage::updateLikeMusic,this,&MuePlayer::onUpdateLikeMusic);
    connect(ui->recentPage,&commonPage::updateLikeMusic,this,&MuePlayer::onUpdateLikeMusic);

    //
    connect(player,&QMediaPlayer::stateChanged,this,&MuePlayer::onPlayStateChanged);

    //
    connect(playList,&QMediaPlaylist::playbackModeChanged,this,&MuePlayer::onPlaybackModeChanged);

    //
    connect(ui->likePage,&commonPage::playAll,this,&MuePlayer::onPlayAll);
    connect(ui->loaclMusicPage,&commonPage::playAll,this,&MuePlayer::onPlayAll);
    connect(ui->recentPage,&commonPage::playAll,this,&MuePlayer::onPlayAll);

    //
    connect(ui->likePage,&commonPage::playMusicByIndex,this,&MuePlayer::playMusicByIndex);
    connect(ui->loaclMusicPage,&commonPage::playMusicByIndex,this,&MuePlayer::playMusicByIndex);
    connect(ui->recentPage,&commonPage::playMusicByIndex,this,&MuePlayer::playMusicByIndex);

    //
    connect(playList,&QMediaPlaylist::currentIndexChanged,this,&MuePlayer::onCurrentIndexChanged);

    //
    connect(volume,&VolumeTool::setSilence,this,&MuePlayer::onSetSilence);

    //
    connect(volume,&VolumeTool::setMusicVolume,this,&MuePlayer::setPlayerVolume);
    //
    connect(player,&QMediaPlayer::durationChanged,this,&MuePlayer::onDurationChanged);
    //
    connect(player,&QMediaPlayer::positionChanged,this,&MuePlayer::onPostionChanged);
    //
    connect(ui->progressBar,&MusicSlider::setMusicSliderPos,this,&MuePlayer::onMusicSliderChanged);

    connect(player,&QMediaPlayer::metaDataAvailableChanged,this,&MuePlayer::onMetaDataAvailableChanged);
}

QJsonArray MuePlayer::RandomFile()
{
      QVector<QString> imageName;
      imageName<<"001.png"<<"003.png"<<"004.png"<<
                          "005.png"<<"006.png"<<"007.png"<<"008.png"<<
                          "009.png"<<"010.png"<<"011.png"<<"012.png"<<
                          "013.png"<<"014.png"<<"015.png"<<"016.png"<<
                          "017.png"<<"018.png"<<"019.png"<<"020.png"<<
                          "021.png"<<"022.png"<<"023.png"<<"024.png"<<
                          "025.png"<<"026.png"<<"027.png"<<"028.png"<<
                          "029.png"<<"030.png"<<"031.png"<<"032.png"<<
                          "033.png"<<"034.png"<<"035.png"<<"036.png"<<
                          "037.png"<<"038.png"<<"039.png"<<"040.png";

      std::random_shuffle(imageName.begin(),imageName.end());

      //"path":":/image/rec/001.png"
      //"text":"推荐-001"
      QJsonArray ojbArray;
      for(int i = 0;i < imageName.size();++i)
      {
          QJsonObject ojb;
          QString path = ":/image/rec/"+imageName[i];
          ojb.insert("path",path);

          QString text = QString("推荐-%1").arg(i,3,10,QChar('0'));
          ojb.insert("text",text);

          ojbArray.append(ojb);
      }
      return ojbArray;
}

void MuePlayer::initPlayer()
{
    //创建播放器
    player = new QMediaPlayer(this);

    //创建播放列表
    playList = new QMediaPlaylist(this);

    //设置播放器模式
    playList->setPlaybackMode(QMediaPlaylist::Loop);

    //将播放列表设置给播放器
    player->setPlaylist(playList);

    //默认音量大小设置为20
    player->setVolume(20);

}

void MuePlayer::onUpdateLikeMusic(bool isLike, QString musicId)
{
    //找到该歌曲，并更新对应的Music信息
    auto it = musicList.findMusicById(musicId);
    if(it != musicList.end())
    {
        it->setIsLike(isLike);
    }

    //通知三个页面更新自己的数据
    ui->likePage->reFresh(musicList);
    ui->loaclMusicPage->reFresh(musicList);
    ui->recentPage->reFresh(musicList);
}

void MuePlayer::initSQLite()
{
    //1.创建数据库连接
    sqlite = QSqlDatabase::addDatabase("QSQLITE");
    //2.设置数据库名称
    sqlite.setDatabaseName("MuePlayer.db");
    //3.打开数据库
    if(!sqlite.open())
    {
        QMessageBox::critical(this,"打开MuePlayer.DB失败",sqlite.lastError().text());
        return;
    }
    qDebug() << "SQLite创建成功,【MuePlayer.db】数据库创建成功";
    //4.创建数据库表
    QString sql = ("CREATE TABLE IF NOT EXISTS musicInfo(\
                    id INTEGER PRIMARY KEY AUTOINCREMENT,\
                    musicId varchar(200) UNIQUE,\
                    musicName varchar(50),\
                    musicSinger varchar(50),\
                    albumName varchar(50),\
                    duration BIGINT,\
                    musicUrl varchar(256),\
                    isLike INTEGER,\
                    isHistory INTEGER)");
    QSqlQuery query;
    if(!query.exec(sql))
    {
        QMessageBox::critical(this,"创建数据库表失败",query.lastError().text());
        return;
    }
    qDebug() << "创建【musicInfo】表成功！";
}

void MuePlayer::initMusicList()
{
    //从数据库中取歌曲信息
    musicList.readFromDB();
    //更新CommonPage页面
    ui->likePage->setMusicListType(PageType::LIKE_PAGE);
    ui->likePage->reFresh(musicList);

    ui->loaclMusicPage->setMusicListType(PageType::LOCAL_PAGE);
    ui->loaclMusicPage->reFresh(musicList);

    ui->recentPage->setMusicListType(PageType::HISTORY_PAGE);
    ui->recentPage->reFresh(musicList);
}

void MuePlayer::updateBtformAnima()
{
    int index = ui->stackedWidget->indexOf(currentPage);
    if(-1 == index)
    {
        qDebug() << "页面不存在";
        return;
    }
    QList<ButtonForm*> btForm = this->findChildren<ButtonForm*>();
    for(auto bf:btForm)
    {
        if(bf->getID() == index)
        {
            bf->showImage(true);
        }
        else
            bf->showImage(false);
    }
}

void MuePlayer::quitMuePlayer()
{
    musicList.writeToDB();
    sqlite.close();
    close();
}

void MuePlayer::on_quit_clicked()
{
    musicList.writeToDB();

    sqlite.close();

    close();
}

void MuePlayer::onBtClick(int id)
{
    //在点击的槽函数中，1.清除其他ButtonForm按钮的颜色
    //获取到MuePlayer所有BT的子控件，除去当前控件，其他全部恢复原状态
    QList<ButtonForm*> BTList =  this->findChildren<ButtonForm*>();
    for(auto BT : BTList)
    {
        if(BT->getID() != id)
        {
            BT->clearBackground();
            BT->showImage(false);
        }
        else
            BT->showImage(true);
    }

    //2
    ui->stackedWidget->setCurrentIndex(id);
    isDrag = false;

}

void MuePlayer::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isDrag=true;
        //如果按下的是左键，就计算出鼠标位置相对窗口左上角的距离
        line = event->globalPos() - geometry().topLeft();
    }
    //对于不是左键的按下，同样也是按下，也需要处理
    QWidget::mousePressEvent(event);
}

void MuePlayer::mouseMoveEvent(QMouseEvent *event)
{
    //如果移动的同时按住左键
    if(event->buttons() == Qt::LeftButton && isDrag)
    {
        move(event->globalPos() - line);
    }
    QWidget::mouseMoveEvent(event);
}

void MuePlayer::on_volume_clicked()
{

    //调整音量条的显示位置
    //获取到volume的全局坐标的方式
    QPoint newpoint = ui->volume->mapToGlobal(QPoint(0,0));
    QPoint VolumeLeftTop = newpoint - QPoint(volume->width()/2,volume->height());

    VolumeLeftTop.setX(VolumeLeftTop.x()+15);
    VolumeLeftTop.setY(VolumeLeftTop.y()+30);

    volume->move(VolumeLeftTop);
    volume->show();
}

void MuePlayer::on_addLocal_clicked()
{
    //1.创建一个文件对话框
    QFileDialog fileDialog(this);

    fileDialog.setWindowTitle("添加本地音乐");
    //设置文件对话框是用来打开文件的
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    //设置对话框模式,只能选择文件，并且可以选择多个文件
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    //设置对话框的MIME过滤器
    QStringList mimeList;
    mimeList << "application/octet-stream";
    fileDialog.setMimeTypeFilters(mimeList);
    //设置对话框的打开路径
    QDir dir(QDir::currentPath());
    dir.cdUp();
    QString musicPath = dir.path() + "/MuePlayer/musics/";
    fileDialog.setDirectory(musicPath);

    //显示对话框
    if(QFileDialog::Accepted == fileDialog.exec())
    {
        ui->stackedWidget->setCurrentIndex(4);
        //获取对话框的返回值
        QList<QUrl> urls = fileDialog.selectedUrls();
        //将歌曲文件交给musicList
        musicList.addMusicByUrl(urls);
        //更新到本地音乐列表
        ui->loaclMusicPage->reFresh(musicList);
    }

}

void MuePlayer::on_play_clicked()
{
    qDebug() << "播放按钮点击";

    if(player->state() == QMediaPlayer::PlayingState)
    {
        player->pause();
    }
    else if(player->state() == QMediaPlayer::PausedState)
    {
        player->play();
    }
    else if(player->state() == QMediaPlayer::StoppedState)
    {
        player->play();
    }
    else
    {}
}

void MuePlayer::onPlayStateChanged()
{
    qDebug() << "播放状态改变";
    if(player->state() == QMediaPlayer::PlayingState)
    {
        ui->play->setIcon(QIcon(":/image/play_on.png"));
    }
    else
    {
        ui->play->setIcon(QIcon(":/image/play3.png"));
    }
}



void MuePlayer::on_playUp_clicked()
{
    playList->previous();
}

void MuePlayer::on_playDown_clicked()
{
    playList->next();
}

void MuePlayer::on_playMode_clicked()
{
    //播放模式
    if(playList->playbackMode() == QMediaPlaylist::Loop)
    {
        //如果当前模式是列表循环，就切换为随机播放
        ui->playMode->setToolTip("随机播放");
        playList->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if(playList->playbackMode() == QMediaPlaylist::Random)
    {
        //如果当前模式是随机播放模式
        ui->playMode->setToolTip("单曲循环");
        playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
    else if(playList->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
    {
        //如果当前是单曲循环就切换为列表循环
        ui->playMode->setToolTip("列表循环");
        playList->setPlaybackMode(QMediaPlaylist::Loop);
    }
    else
    {
        qDebug() << "播放模式错误";
    }
}

void MuePlayer::onPlaybackModeChanged(QMediaPlaylist::PlaybackMode playbackMode)
{
    if(playbackMode == QMediaPlaylist::Loop)
    {
        ui->playMode->setIcon(QIcon(":/image/list_play.png"));
    }
    else if(playbackMode == QMediaPlaylist::Random)
    {
        ui->playMode->setIcon(QIcon(":/image/shuffle_2.png"));
    }
    else if(playbackMode == QMediaPlaylist::CurrentItemInLoop)
    {
        ui->playMode->setIcon(QIcon(":/image/single_play.png"));
    }
    else
    {
        qDebug()<<"切换播放模式图片，未知模式";
    }
}

void MuePlayer::onPlayAll(PageType pageType)
{
    commonPage* page = nullptr;
    switch(pageType)
    {
    case PageType::LIKE_PAGE:
    {
        page = ui->likePage;
        break;
    }
    case PageType::LOCAL_PAGE:
    {
        page = ui->loaclMusicPage;
        break;
    }
    case PageType::HISTORY_PAGE:
    {
        page = ui->recentPage;
        break;
    }
    default:
        break;
    }
    playAllOfPage(page,0);
}

void MuePlayer::playAllOfPage(commonPage *page, int index)
{
    currentPage = page;
    updateBtformAnima();
    //清空播放列表
    playList->clear();
    //
    page->addMusicToPlayer(musicList,playList);

    //设置播放列表的索引
    playList->setCurrentIndex(index);
    player->play();
}

void MuePlayer::playMusicByIndex(commonPage *page, int index)
{
    playAllOfPage(page,index);
}

void MuePlayer::onCurrentIndexChanged(int index)
{
    curIndex = index;
    //切换了播放歌曲
   const QString& musicId = currentPage->getMusicIdByIndex(index);
   //
   auto it = musicList.findMusicById(musicId);
   if(it != musicList.end())
   {
       it->setIsHistory(true);
   }
   ui->recentPage->reFresh(musicList);
}

void MuePlayer::onSetSilence(bool isMuted)
{
    player->setMuted(isMuted);
}

void MuePlayer::setPlayerVolume(int volume)
{
    player->setVolume(volume);
}

void MuePlayer::onDurationChanged(qint64 duration)
{
    ui->totalTime->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60,2,10,QChar('0')));

}

void MuePlayer::onPostionChanged(qint64 duration)
{
    ui->currentTime->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60,2,10,QChar('0')));

    ui->progressBar->setStep((float)duration/(float)player->duration());
    if(playList->currentIndex() >= 0)
    {
        lrcPage->showLrcWord(duration);
    }
}

void MuePlayer::onMusicSliderChanged(float value)
{
    //计算当前seek位置的时长
    qint64 duration = (qint64)(player->duration()*value);
    //转换为百分制
    ui->currentTime->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60,2,10,QChar('0')));
    //
    player->setPosition(duration);
}

void MuePlayer::onMetaDataAvailableChanged(bool available)
{
    qDebug() << "歌曲切换";

    //从player中获取歌曲信息
   QString singer= player->metaData("Author").toStringList().join(",");
   QString musicName = player->metaData("Title").toString();

   if(musicName.isEmpty())
   {
       auto it = musicList.findMusicById(currentPage->getMusicIdByIndex(curIndex));
       if(it != musicList.end())
       {
           musicName = it->getMusicName();
           singer = it->getSingerName();
       }
   }
   //解析歌词的逻辑
   //同时解析歌词
   auto it = musicList.findMusicById(currentPage->getMusicIdByIndex(curIndex));
   lrcPage->parseLrc(it->getLrcFilePath());

   //设置歌手
   ui->musicName->setText(musicName);
   ui->musicSinger->setText(singer);

   //获取封面图片
   QVariant coverImage = player->metaData("ThumbnailImage");
   if(coverImage.isValid())
   {
       QImage image = coverImage.value<QImage>();

       ui->musicCover->setPixmap(QPixmap::fromImage(image));

       ui->musicCover->setScaledContents(true);
   }
   else
   {
       qDebug() << "歌曲没有封面图片";
       QString path = ":/image/rec/001.png";
       ui->musicCover->setPixmap(path);
       ui->musicCover->setScaledContents(true);
   }
}

void MuePlayer::on_word_clicked()
{
    lrcPage->show();

    lrcAnimation->start();
}

void MuePlayer::on_skin_clicked()
{
    QMessageBox::information(this,"温馨提升","敬请期待");
}

void MuePlayer::on_min_clicked()
{
    showMinimized();
}

