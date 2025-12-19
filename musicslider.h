#ifndef MUSICSLIDER_H
#define MUSICSLIDER_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class MusicSlider;
}

class MusicSlider : public QWidget
{
    Q_OBJECT

public:
    explicit MusicSlider(QWidget *parent = nullptr);
    ~MusicSlider();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void moveSlider();

    void setStep(float bf);
signals:
    void setMusicSliderPos(float);
private:
    Ui::MusicSlider *ui;
    int currentPos;
    int maxWidth;
};

#endif // MUSICSLIDER_H
