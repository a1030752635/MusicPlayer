#ifndef MUEPLAYER_H
#define MUEPLAYER_H

#include <QWidget>
#include <QJsonArray>
#include "volumetool.h"
#include "musiclist.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "commonpage.h"
#include "lrcpage.h"
#include <QPropertyAnimation>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MuePlayer; }
QT_END_NAMESPACE


class MuePlayer : public QWidget
{
    Q_OBJECT

public:
    MuePlayer(QWidget *parent = nullptr);
    ~MuePlayer();
    void initUi();
    void connectSignalAndSlot();

    QJsonArray RandomFile();

    void initPlayer();
    void onUpdateLikeMusic(bool isLike,QString musicId);

    void initSQLite();
    void initMusicList();
    void updateBtformAnima();
    void quitMuePlayer();
private slots:
    void on_quit_clicked();
    void onBtClick(int id);
    void on_volume_clicked();

    void on_addLocal_clicked();

    void on_play_clicked();
    void onPlayStateChanged();
    void on_playUp_clicked();

    void on_playDown_clicked();

    void on_playMode_clicked();

    void onPlaybackModeChanged(QMediaPlaylist::PlaybackMode playbackMode);
    void onPlayAll(PageType pageType);
    void playAllOfPage(commonPage* page,int index);

    void playMusicByIndex(commonPage* page,int index);

    void onCurrentIndexChanged(int index);
    void onSetSilence(bool);
    void setPlayerVolume(int volume);

    void onDurationChanged(qint64 duration);

    void onPostionChanged(qint64 duration);
    void onMusicSliderChanged(float value);
    void onMetaDataAvailableChanged(bool available);
    void on_word_clicked();

    void on_skin_clicked();

    void on_min_clicked();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::MuePlayer *ui;
    QPoint line;
    VolumeTool* volume;
    MusicList musicList;
    QMediaPlayer* player;
    QMediaPlaylist* playList;

    commonPage* currentPage;
    int curIndex;//当前正在播放的歌曲，在PageList中的Index
    LrcPage* lrcPage;

    QPropertyAnimation* lrcAnimation;
    QSqlDatabase sqlite;

    bool isDrag;//为true时窗口才能拖拽
};
#endif // MUEPLAYER_H
