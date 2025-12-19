#include "volumetool.h"
#include "ui_volumetool.h"
#include <QGraphicsDropShadowEffect>
#include <QPainter>
VolumeTool::VolumeTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VolumeTool),
    isMuted(false),//默认非静音
    volumeRatio(20)
{
    ui->setupUi(this);

    //设置窗口为无边框窗口,在windows上，设置Popup为弹窗窗口后，要设置FramelessWindowHint
    //否则没有控件的位置是黑色背景
    //还要去掉默认阴影NoDropShadowWindowHint
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);

    //设置半透明效果
    setAttribute(Qt::WA_TranslucentBackground);

    //自定义阴影效果
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0,0);
    effect->setColor("#646464");
    effect->setBlurRadius(10);
    setGraphicsEffect(effect);

    //
    ui->silenceBtn->setIcon(QIcon(":/image/volumn.png"));
    ui->volumeRatio->setText("20%");

    ui->outSlider->setGeometry(ui->outSlider->x(),ui->outSlider->y()+(ui->outSlider->height()*0.8),ui->outSlider->width(),36);

    ui->sliderBtn->move(ui->sliderBtn->x(),ui->outSlider->y()-ui->sliderBtn->height()/2);


    ui->sliderBox->installEventFilter(this);
}

VolumeTool::~VolumeTool()
{
    delete ui;
}

void VolumeTool::paintEvent(QPaintEvent *event)
{
    (void)event;

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);

    //创建一个三角形
    QPolygon polygon;
    polygon.append(QPoint(30,300));
    polygon.append(QPoint(70,300));
    polygon.append(QPoint(50,320));

    painter.drawPolygon(polygon);


}

bool VolumeTool::eventFilter(QObject *object, QEvent *event)
{
       //过滤volumeBox上的事件
    if(object == ui->sliderBox)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            setVolume();
        }
        else if(event->type() == QEvent::MouseMove)
        {
            setVolume();
            emit setMusicVolume(volumeRatio);
        }
        else if(event->type() == QEvent::MouseButtonRelease)
        {
            emit setMusicVolume(volumeRatio);
        }
        return true;
    }
    return QObject::eventFilter(object,event);
}

void VolumeTool::setVolume()
{
    int height = ui->sliderBox->mapFromGlobal(QCursor().pos()).y();

    //鼠标的可移动范围在25-205之间
    height=height<25?25:height;
    height=height>205?205:height;


    //计算SliderBtn
    ui->sliderBtn->move(ui->sliderBtn->x(),height-ui->sliderBtn->height()/2);

    //计算OutSlider
    ui->outSlider->setGeometry(ui->outSlider->x(),height,ui->outSlider->width(),205-height);

    //计算音量比率
    volumeRatio = (int)(((double)ui->outSlider->height() / (double)180)*100);
    //
    ui->volumeRatio->setText(QString::number(volumeRatio) +"%" );

}

void VolumeTool::on_silenceBtn_clicked()
{
    isMuted = !isMuted;
    if(isMuted)
    {
        ui->silenceBtn->setIcon(QIcon(":/image/silent.png"));
    }
    else
    {
        ui->silenceBtn->setIcon(QIcon(":/image/volumn.png"));
    }

    emit setSilence(isMuted);
}
