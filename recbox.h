#ifndef RECBOX_H
#define RECBOX_H

#include <QWidget>
#include "recboxitem.h"
#include <QJsonArray>
namespace Ui {
class RecBox;
}

class RecBox : public QWidget
{
    Q_OBJECT

public:
    explicit RecBox(QWidget *parent = nullptr);
    ~RecBox();
    void initRecBox(QJsonArray data,int row);
private slots:
    void on_down_clicked();

    void on_up_clicked();

private:
    void createRecboxItem();
private:
    Ui::RecBox *ui;

    int row;
    int col;
    QJsonArray imageList;

    //上下页内容的切换
    int currentIndex;//当前是第几组
    int count;//总共有几组
};

#endif // RECBOX_H
