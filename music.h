#ifndef MUSIC_H
#define MUSIC_H
#include <QUrl>
#include <QString>

class Music
{
public:
    Music();
    Music(const QUrl& url);

    void setMusicName(const QString& musicName);
    void setSingerName(const QString& singerName);
    void setAlbumName(const QString& albumName);
    void setDuration(const qint64& duration);
    void setMusicId(const QString& id);
    void setMusicUrl(const QUrl& url);
    void setIsLike(bool isLike);
    void setIsHistory(bool isHistory);

    QString getMusicName() const;
    QString getSingerName() const;
    QString getAlbumName() const;
    qint64 getDuration() const;
    QString getMusicId() const;
    QUrl getMusicUrl() const;
    bool getIsLike() const;
    bool getIsHistory() const;
    QString getLrcFilePath() const;
    void insertMusicToDB();
private:
    void parseMediaMetaData();
    bool isLike;
    bool isHistory;
    QString musicName;
    QString singerName;
    QString albumName;

    qint64 duration;//音乐的总时长。

    //为了标记歌曲的唯一性，设置歌曲Id
    QString musicId;

    QUrl musicUrl;//歌曲在磁盘中的位置
};

#endif // MUSIC_H
