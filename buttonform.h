#ifndef BUTTONFORM_H
#define BUTTONFORM_H

#include <QWidget>
#include <QPropertyAnimation>
namespace Ui {
class ButtonForm;
}

class ButtonForm : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonForm(QWidget *parent = nullptr);
    ~ButtonForm();


    void setIcon_Text(const QString& btIcon,const QString& btText,int pageID);
    int getID();
    void clearBackground();
    void showImage(bool isShow = true);
signals:
    //点击信号
    void BtClick(int id);
protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    Ui::ButtonForm *ui;
    int PageId;

    QPropertyAnimation* line1_anima;
    QPropertyAnimation* line2_anima;
    QPropertyAnimation* line3_anima;
    QPropertyAnimation* line4_anima;

};

#endif // BUTTONFORM_H
