#ifndef LRCPAGE_H
#define LRCPAGE_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QVector>
#include <QFile>
namespace Ui {
class LrcPage;
}
class LyricLine;
class LrcPage : public QWidget
{
    Q_OBJECT

public:
    explicit LrcPage(QWidget *parent = nullptr);
    ~LrcPage();
    bool parseLrc(const QString& lrcPath);
    int getLineLrcWordIndex(qint64 pos);
    QString getLineLrcWord(int index);
    void showLrcWord(qint64 time);

private slots:
    void on_hideBtn_clicked();

private:
    Ui::LrcPage *ui;
    QPropertyAnimation* lrcAnimation;
    QVector<LyricLine> lyricLines;
};
class LyricLine
{
public:
    qint64 time;
    QString text;
    LyricLine(qint64 qtime,QString qtext):time(qtime),text(qtext)
    {
    }
};

#endif // LRCPAGE_H
