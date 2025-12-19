#include "music.h"
#include <QUuid>
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlError>
Music::Music():isLike(false),isHistory(false)
{

}

Music::Music(const QUrl &url):isLike(false),isHistory(false)
  ,musicUrl(url)
{
    musicId = QUuid::createUuid().toString();
    parseMediaMetaData();
}

void Music::setMusicName(const QString &Name)
{
    this->musicName = Name;
}

void Music::setSingerName(const QString &singerName)
{
    this->singerName = singerName;
}

void Music::setAlbumName(const QString &albumName)
{
    this->albumName =  albumName;
}

void Music::setDuration(const qint64 &duration)
{
    this->duration = duration;
}

void Music::setMusicId(const QString &id)
{
    this->musicId = id;
}

void Music::setMusicUrl(const QUrl &url)
{
    this->musicUrl = url;
}

void Music::setIsLike(bool isLike)
{
    this->isLike = isLike;
}

void Music::setIsHistory(bool isHistory)
{
    this->isHistory = isHistory;
}

QString Music::getMusicName() const
{
    return musicName;
}

QString Music::getSingerName() const
{
    return singerName;
}

QString Music::getAlbumName() const
{
    return albumName;
}

qint64 Music::getDuration() const
{
    return duration;
}

QString Music::getMusicId() const
{
    return musicId;
}

QUrl Music::getMusicUrl() const
{
    return musicUrl;
}

bool Music::getIsLike() const
{
    return isLike;
}

bool Music::getIsHistory() const
{
    return isHistory;
}

QString Music::getLrcFilePath() const
{
    QString path  = musicUrl.toLocalFile();
    path.replace(".mp3",".lrc");
    path.replace(".flac","lrc");
    path.replace(".mpga","lrc");
    return path;
}

void Music::insertMusicToDB()
{
    //1.检测Music是否在数据库中存在
    QSqlQuery query;
    query.prepare("SELECT EXISTS (SELECT 1 FROM musicInfo WHERE musicId = ?)");
    query.addBindValue(musicId);
    if(!query.exec())
    {
        qDebug() << "查询失败:"<< query.lastError().text();
        return;
    }
    if(query.next())
    {
        bool isExists = query.value(0).toBool();
        if(isExists)
        {
            //歌曲已经存在,则更新歌曲的喜欢、历史播放
            query.prepare("UPDATE musicInfo SET isLike=?,isHistory=? WHERE musicId = ?");
            query.addBindValue(isLike?1:0);
            query.addBindValue(isHistory?1:0);
            query.addBindValue(musicId);
            if(!query.exec())
            {
                qDebug() << "更新信息失败"<<query.lastError().text();
                return;
            }
            qDebug() << "更新信息成功" << musicName<<":" << musicId;
        }
        else
        {
            //歌曲不存在
            query.prepare("INSERT INTO musicInfo(musicId,musicName,musicSinger,albumName,musicUrl,\
                            duration,isLike,isHistory)VALUES(?,?,?,?,?,?,?,?)");
            query.addBindValue(musicId);
            query.addBindValue(musicName);
            query.addBindValue(singerName);
            query.addBindValue(albumName);
            query.addBindValue(musicUrl.toLocalFile());
            query.addBindValue(duration);
            query.addBindValue(isLike);
            query.addBindValue(isHistory);
            if(!query.exec())
            {
                qDebug() << "插入歌曲失败" << query.lastError().text();
                return;
            }
            else
            {
                qDebug() << "插入歌曲成功" << musicName<<":" << musicId;
            }
        }
    }
}

void Music::parseMediaMetaData()
{
    //读取歌曲数据，用QMediaPlayer
    QMediaPlayer player;
    player.setMedia(musicUrl);

    //player会解析媒体数据，这个过程需要时间
    //循环等待解析，在循环等待时，主界面消息循环就无法处理了，因此
    //要在等待期间，让消息循环继续处理
    while(!player.isMetaDataAvailable())
    {
        QCoreApplication::processEvents();
    }

    //解析媒体元数据结束，提取元数据信息
    if(player.isMetaDataAvailable())
    {

        musicName = player.metaData("Title").toString();
        singerName = player.metaData("Author").toString();
        albumName = player.metaData("AlbumTitle").toString();
        duration = player.metaData("Duration").toLongLong();

        QString filename = musicUrl.fileName();
        int index = filename.indexOf('-');
        if(musicName.isEmpty())
        {
            if(index != -1)
            {
            musicName = filename.mid(0,index).trimmed();
            }
            else
            {
                musicName = filename.mid(0,filename.indexOf('.')).trimmed();
            }
        }
        if(singerName.isEmpty())
        {
            if(index != -1)
            {
                singerName = filename.mid(index+1,filename.indexOf('.')-index-1).trimmed();
            }
            else
            {
                singerName = "未知歌手";
            }

        }
        if(albumName.isEmpty())
        {
            albumName = "未知专辑";
        }

    }
}
