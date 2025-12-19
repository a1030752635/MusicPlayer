#include "lrcpage.h"
#include "ui_lrcpage.h"
#include <QDebug>
LrcPage::LrcPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LrcPage)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);//去掉窗口标题栏

    ui->hideBtn->setIcon(QIcon(":/image/xiala.png"));

    lrcAnimation = new QPropertyAnimation(this,"geometry",this);
    lrcAnimation->setDuration(250);
    lrcAnimation->setStartValue(QRect(10,10,width(),height()));
    lrcAnimation->setEndValue(QRect(10,10+height(),width(),height()));


    connect(lrcAnimation,&QPropertyAnimation::finished,this,[=](){
       hide();
    });
}

LrcPage::~LrcPage()
{
    delete ui;
}

bool LrcPage::parseLrc(const QString &lrcPath)
{
    lyricLines.clear();
    //打开歌词文件
    QFile lrcFile(lrcPath);
    if(!lrcFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "打开文件失败：" << lrcPath;
        return false;
    }

    qDebug() << "------------\n";
    while(!lrcFile.atEnd())
    {
        QString lrcWord = lrcFile.readLine(1024);

        int left = lrcWord.indexOf('[');
        int right = lrcWord.indexOf(']');

        //解析时间
        qint64 lineTime = 0;
        int start = 0;
        int end = 0;
        QString time =lrcWord.mid(left,right-left+1);

        //用时间，解析出分钟、秒
        start = 1;
        end = time.indexOf(':',start);
        lineTime += time.mid(start,end-start).toInt()*60*1000;

        //解析秒，同样加到lineTime中
        start = end+1;
        end = time.indexOf('.',start);
        lineTime += time.mid(start,end-start).toInt()*1000;
        //解析毫秒
        start = end+1;
        end = time.indexOf('.',start);
        lineTime += time.mid(start,end-start).toInt();

        //解析歌词
        QString word = lrcWord.mid(right+1).trimmed();
        lyricLines.push_back(LyricLine(lineTime,word.trimmed()));
        qDebug() << "解析一行歌词完成";
    }

    for(auto word:lyricLines)
    {
        qDebug() << word.time << ":" << word.text;
    }
    return true;
}

int LrcPage::getLineLrcWordIndex(qint64 pos)
{
    //这个函数的目的是，通过MuePlayer中传进来的位置(是一个毫秒级的时间)
    //转换为歌词数组的下标
    if(lyricLines.isEmpty())
        return -1;
    if(lyricLines[0].time > pos)
        return 0;
    for(int i = 1;i < lyricLines.size();++i)
    {
        if(pos > lyricLines[i-1].time && pos <= lyricLines[i].time)
        {
            return i-1;
        }

    }
    return lyricLines.size()-1;
}

QString LrcPage::getLineLrcWord(int index)
{
    if(index < 0 || index >= lyricLines.size())
        return "";
    return lyricLines[index].text;
}

void LrcPage::showLrcWord(qint64 time)
{

    int index = getLineLrcWordIndex(time);

    if(-1 == index)
    {
        ui->line1->setText("");
        ui->line2->setText("");
        ui->line3->setText("");
        ui->line4->setText("");
        ui->line5->setText("");
        ui->line6->setText("");
        ui->lineCenter->setText("当前歌曲暂无歌词");
    }
    else
    {
        ui->line1->setText(getLineLrcWord(index-3));
        ui->line2->setText(getLineLrcWord(index-2));
        ui->line3->setText(getLineLrcWord(index-1));
        ui->lineCenter->setText(getLineLrcWord(index));
        ui->line4->setText(getLineLrcWord(index+1));
        ui->line5->setText(getLineLrcWord(index+2));
        ui->line6->setText(getLineLrcWord(index+3));

    }

    ui->musicName->setText("");
}

void LrcPage::on_hideBtn_clicked()
{
    lrcAnimation->start();
}
