#ifndef LISTITEMBOX_H
#define LISTITEMBOX_H

#include <QWidget>

namespace Ui {
class ListItemBox;
}

class ListItemBox : public QWidget
{
    Q_OBJECT

public:
    explicit ListItemBox(QWidget *parent = nullptr);
    ~ListItemBox();
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

    void setMusicName(const QString& name);
    void setSingerName(const QString& name);
    void setAlbumName(const QString& name);
    void setLike(bool like);
signals:
    void setIsLike(bool);//自定义信号，通知更新歌曲的喜欢信息
private slots:
    void on_likeBtn_clicked();

private:
    Ui::ListItemBox *ui;

    bool isLike;
};

#endif // LISTITEMBOX_H
