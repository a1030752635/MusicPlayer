#ifndef COMMONPAGE_H
#define COMMONPAGE_H

#include <QWidget>
#include <QVector>
#include "musiclist.h"
#include "music.h"
#include <QMediaPlaylist>
namespace Ui {
class commonPage;
}
enum PageType//区分CommonPage是哪个页面
{
    LIKE_PAGE,//
    LOCAL_PAGE,
    HISTORY_PAGE
};

class commonPage : public QWidget
{
    Q_OBJECT

public:
    explicit commonPage(QWidget *parent = nullptr);
    ~commonPage();

    void setCommonPageUI(const QString& title,const QString& image);
    void setMusicListType(PageType pageType);
    void addMusicToMusicPage(MusicList& List);
    void reFresh(MusicList& musicList);
    void addMusicToPlayer(MusicList& musicList,QMediaPlaylist* playList);
    const QString getMusicIdByIndex(int index) const;
signals:
    void updateLikeMusic(bool isLike,QString musicId);
    void playAll(PageType pageType);
    void playMusicByIndex(commonPage*,int);
private slots:
    void on_playAllBtn_clicked();

private:
    Ui::commonPage *ui;
    PageType pageType;
    QVector<QString> musicListOfPage;//每一个页面特定的musicList
};

#endif // COMMONPAGE_H
