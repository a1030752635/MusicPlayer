#ifndef VOLUMETOOL_H
#define VOLUMETOOL_H

#include <QWidget>

namespace Ui {
class VolumeTool;
}

class VolumeTool : public QWidget
{
    Q_OBJECT

public:
    explicit VolumeTool(QWidget *parent = nullptr);
    ~VolumeTool();
    void paintEvent(QPaintEvent* event);
    bool eventFilter(QObject* object,QEvent* event);
    void setVolume();
signals:
    void setSilence(bool);
    void setMusicVolume(int);
private slots:
    void on_silenceBtn_clicked();

private:
    Ui::VolumeTool *ui;
    bool isMuted;//是否静音
    int volumeRatio;//音量大小
};

#endif // VOLUMETOOL_H
