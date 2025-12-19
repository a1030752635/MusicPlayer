#include "musiclist.h"
#include <QMimeDatabase>
#include <QMimeType>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
MusicList::MusicList()
{

}

void MusicList::addMusicByUrl(const QList<QUrl> &urls)
{
    for(auto musicUrl : urls)
    {
        qDebug() << "我是观察者" << musicUrl;
        QString musicPath = musicUrl.toLocalFile();
        if(musicPaths.contains(musicPath))
            continue;
        musicPaths.insert(musicPath);
        //判断文件是不是音乐文件
        QMimeDatabase db;
        QMimeType type = db.mimeTypeForFile(musicUrl.toLocalFile());
        if(type.name() != "audio/mpeg"
              && type.name() != "audio/flac"
              && type.name() != "audio/wav")
        {
            continue;
        }


        musicList.push_back(Music(musicUrl));
    }
}

MusicList::iterator MusicList::begin()
{
    return musicList.begin();
}

MusicList::iterator MusicList::end()
{
    return musicList.end();
}

MusicList::iterator MusicList::findMusicById(const QString &musicId)
{
    for(iterator it = begin();it !=  end();++it)
    {
        if(it->getMusicId() == musicId)
        {
            return it;
        }
    }
    return end();
}

void MusicList::writeToDB()
{
    for(auto music:musicList)
    {
        music.insertMusicToDB();
    }
}

void MusicList::readFromDB()
{
    QString sql("SELECT musicId,musicName,musicSinger,albumName,\
                 duration,musicUrl,isLike,isHistory \
    FROM musicInfo");

    QSqlQuery query;
    query.prepare(sql);
    if(!query.exec())
    {
        QSqlError error = query.lastError();
        return;
    }
    while(query.next())
    {
        Music music;
        music.setMusicId(query.value(0).toString());
        music.setMusicName(query.value(1).toString());
        music.setSingerName(query.value(2).toString());
        music.setAlbumName(query.value(3).toString());
        music.setDuration(query.value(4).toLongLong());
        music.setMusicUrl("file:///"+query.value(5).toString());
        music.setIsLike(query.value(6).toBool());
        music.setIsHistory(query.value(7).toBool());
        musicList.push_back(music);

        musicPaths.insert(music.getMusicUrl().toLocalFile());
    }
}
