#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QVector>
#include <QList>
#include <QUrl>
#include "music.h"
#include <QSet>

class MusicList
{
public:
    typedef typename QVector<Music>::iterator iterator;
    MusicList();
    void addMusicByUrl(const QList<QUrl>& urls);

    iterator begin();
    iterator end();
    QVector<Music> musicList;

    iterator findMusicById(const QString& musicId);
    void writeToDB();
    void readFromDB();
    QSet<QString> musicPaths;
};

#endif // MUSICLIST_H
