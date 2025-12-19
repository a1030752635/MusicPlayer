/********************************************************************************
** Form generated from reading UI file 'mueplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUEPLAYER_H
#define UI_MUEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <buttonform.h>
#include <commonpage.h>
#include <musicslider.h>
#include <recbox.h>

QT_BEGIN_NAMESPACE

class Ui_MuePlayer
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *background;
    QVBoxLayout *verticalLayout_2;
    QWidget *head;
    QHBoxLayout *horizontalLayout;
    QWidget *headLeft;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logo;
    QWidget *headRight;
    QHBoxLayout *horizontalLayout_3;
    QWidget *searchBox;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit;
    QWidget *settingBox;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *skin;
    QPushButton *min;
    QPushButton *max;
    QPushButton *quit;
    QWidget *body;
    QHBoxLayout *horizontalLayout_4;
    QWidget *bodyLeft;
    QVBoxLayout *verticalLayout_4;
    QWidget *leftBox;
    QVBoxLayout *verticalLayout_5;
    QWidget *online;
    QVBoxLayout *verticalLayout_6;
    QLabel *onlineMusic;
    ButtonForm *recomd;
    ButtonForm *audio;
    ButtonForm *music;
    QWidget *local;
    QVBoxLayout *verticalLayout_7;
    QLabel *myMusic;
    ButtonForm *like;
    ButtonForm *localMusic;
    ButtonForm *recent;
    QSpacerItem *verticalSpacer;
    QWidget *bodyRight;
    QVBoxLayout *verticalLayout_8;
    QStackedWidget *stackedWidget;
    QWidget *recomdPage;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_9;
    QLabel *rec;
    QLabel *todayRec;
    RecBox *todayBox;
    QLabel *supplyRec;
    RecBox *supplyBox;
    QWidget *audioPage;
    QLabel *label_2;
    QWidget *musicPage;
    QLabel *label_3;
    commonPage *likePage;
    commonPage *loaclMusicPage;
    commonPage *recentPage;
    MusicSlider *progressBar;
    QWidget *control;
    QHBoxLayout *horizontalLayout_7;
    QWidget *play_1;
    QGridLayout *gridLayout;
    QLabel *musicCover;
    QLabel *musicName;
    QLabel *musicSinger;
    QWidget *play_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *playMode;
    QPushButton *playUp;
    QPushButton *play;
    QPushButton *playDown;
    QPushButton *volume;
    QPushButton *addLocal;
    QWidget *play_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *nullLabel;
    QLabel *currentTime;
    QLabel *line;
    QLabel *totalTime;
    QPushButton *word;

    void setupUi(QWidget *MuePlayer)
    {
        if (MuePlayer->objectName().isEmpty())
            MuePlayer->setObjectName(QString::fromUtf8("MuePlayer"));
        MuePlayer->resize(1180, 840);
        MuePlayer->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(MuePlayer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        background = new QWidget(MuePlayer);
        background->setObjectName(QString::fromUtf8("background"));
        background->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(background);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        head = new QWidget(background);
        head->setObjectName(QString::fromUtf8("head"));
        head->setMinimumSize(QSize(0, 90));
        head->setMaximumSize(QSize(16777215, 90));
        head->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(head);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        headLeft = new QWidget(head);
        headLeft->setObjectName(QString::fromUtf8("headLeft"));
        headLeft->setMinimumSize(QSize(180, 0));
        headLeft->setMaximumSize(QSize(180, 16777215));
        headLeft->setStyleSheet(QString::fromUtf8("#headLeft\n"
"{\n"
"	background-color:#F0F0F0 /*\350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(headLeft);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, -1, 0);
        logo = new QLabel(headLeft);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setMinimumSize(QSize(180, 0));
        logo->setMaximumSize(QSize(180, 16777215));
        logo->setStyleSheet(QString::fromUtf8("#logo\n"
"{\n"
"	background-image:url(:/image/Logo.jpg);\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}"));

        horizontalLayout_2->addWidget(logo);


        horizontalLayout->addWidget(headLeft);

        headRight = new QWidget(head);
        headRight->setObjectName(QString::fromUtf8("headRight"));
        headRight->setStyleSheet(QString::fromUtf8("#headRight\n"
"{\n"
"	background-color:#F5F5F5;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(headRight);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchBox = new QWidget(headRight);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        searchBox->setMinimumSize(QSize(280, 0));
        searchBox->setMaximumSize(QSize(280, 16777215));
        searchBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(searchBox);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 0, 5, 0);
        lineEdit = new QLineEdit(searchBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 35));
        lineEdit->setMaximumSize(QSize(16777215, 35));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit\n"
"{\n"
"	background-color:#e3e3e3;\n"
"	border:none;\n"
"	border-radius:17px;\n"
"	padding-left:17px;\n"
"}"));

        verticalLayout_3->addWidget(lineEdit);


        horizontalLayout_3->addWidget(searchBox);

        settingBox = new QWidget(headRight);
        settingBox->setObjectName(QString::fromUtf8("settingBox"));
        settingBox->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255,0,0,0.5);\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(settingBox);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, 0, 5, 0);
        horizontalSpacer = new QSpacerItem(290, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        skin = new QPushButton(settingBox);
        skin->setObjectName(QString::fromUtf8("skin"));
        skin->setMinimumSize(QSize(30, 30));
        skin->setMaximumSize(QSize(30, 30));
        skin->setStyleSheet(QString::fromUtf8("#skin\n"
"{\n"
"	background-image:url(\":/image/skin.png\");\n"
"}"));

        horizontalLayout_5->addWidget(skin);

        min = new QPushButton(settingBox);
        min->setObjectName(QString::fromUtf8("min"));
        min->setMinimumSize(QSize(30, 30));
        min->setMaximumSize(QSize(30, 30));
        min->setStyleSheet(QString::fromUtf8("#min\n"
"{\n"
"	background-image:url(\":/image/min.png\");\n"
"}"));

        horizontalLayout_5->addWidget(min);

        max = new QPushButton(settingBox);
        max->setObjectName(QString::fromUtf8("max"));
        max->setMinimumSize(QSize(30, 30));
        max->setMaximumSize(QSize(30, 30));
        max->setStyleSheet(QString::fromUtf8("#max\n"
"{\n"
"	background-image:url(\":/image/max.png\");\n"
"}"));

        horizontalLayout_5->addWidget(max);

        quit = new QPushButton(settingBox);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setMinimumSize(QSize(30, 30));
        quit->setMaximumSize(QSize(30, 30));
        quit->setStyleSheet(QString::fromUtf8("#quit\n"
"{\n"
"	background-image:url(\":/image/quit.png\");\n"
"}"));

        horizontalLayout_5->addWidget(quit);


        horizontalLayout_3->addWidget(settingBox);


        horizontalLayout->addWidget(headRight);


        verticalLayout_2->addWidget(head);

        body = new QWidget(background);
        body->setObjectName(QString::fromUtf8("body"));
        body->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(body);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        bodyLeft = new QWidget(body);
        bodyLeft->setObjectName(QString::fromUtf8("bodyLeft"));
        bodyLeft->setMinimumSize(QSize(180, 0));
        bodyLeft->setMaximumSize(QSize(180, 16777215));
        bodyLeft->setStyleSheet(QString::fromUtf8("#bodyLeft\n"
"{\n"
"	background-color:#f0f0f0;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(bodyLeft);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        leftBox = new QWidget(bodyLeft);
        leftBox->setObjectName(QString::fromUtf8("leftBox"));
        leftBox->setMinimumSize(QSize(180, 360));
        leftBox->setMaximumSize(QSize(180, 360));
        leftBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(leftBox);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        online = new QWidget(leftBox);
        online->setObjectName(QString::fromUtf8("online"));
        online->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_6 = new QVBoxLayout(online);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        onlineMusic = new QLabel(online);
        onlineMusic->setObjectName(QString::fromUtf8("onlineMusic"));

        verticalLayout_6->addWidget(onlineMusic);

        recomd = new ButtonForm(online);
        recomd->setObjectName(QString::fromUtf8("recomd"));
        recomd->setStyleSheet(QString::fromUtf8("background-color:#f0f0f0;"));

        verticalLayout_6->addWidget(recomd);

        audio = new ButtonForm(online);
        audio->setObjectName(QString::fromUtf8("audio"));
        audio->setStyleSheet(QString::fromUtf8("background-color:#f0f0f0;"));

        verticalLayout_6->addWidget(audio);

        music = new ButtonForm(online);
        music->setObjectName(QString::fromUtf8("music"));
        music->setStyleSheet(QString::fromUtf8("background-color:#f0f0f0;"));

        verticalLayout_6->addWidget(music);


        verticalLayout_5->addWidget(online);

        local = new QWidget(leftBox);
        local->setObjectName(QString::fromUtf8("local"));
        local->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_7 = new QVBoxLayout(local);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        myMusic = new QLabel(local);
        myMusic->setObjectName(QString::fromUtf8("myMusic"));

        verticalLayout_7->addWidget(myMusic);

        like = new ButtonForm(local);
        like->setObjectName(QString::fromUtf8("like"));
        like->setStyleSheet(QString::fromUtf8("background-color:#f0f0f0;"));

        verticalLayout_7->addWidget(like);

        localMusic = new ButtonForm(local);
        localMusic->setObjectName(QString::fromUtf8("localMusic"));
        localMusic->setStyleSheet(QString::fromUtf8("background-color:#f0f0f0;"));

        verticalLayout_7->addWidget(localMusic);

        recent = new ButtonForm(local);
        recent->setObjectName(QString::fromUtf8("recent"));
        recent->setStyleSheet(QString::fromUtf8("background-color:#f0f0f0;"));

        verticalLayout_7->addWidget(recent);


        verticalLayout_5->addWidget(local);


        verticalLayout_4->addWidget(leftBox);

        verticalSpacer = new QSpacerItem(20, 189, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(bodyLeft);

        bodyRight = new QWidget(body);
        bodyRight->setObjectName(QString::fromUtf8("bodyRight"));
        bodyRight->setStyleSheet(QString::fromUtf8("#bodyRight\n"
"{\n"
"	background-color:#f5f5f5;\n"
"	\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(bodyRight);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(bodyRight);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        recomdPage = new QWidget();
        recomdPage->setObjectName(QString::fromUtf8("recomdPage"));
        recomdPage->setMinimumSize(QSize(980, 0));
        recomdPage->setMaximumSize(QSize(980, 16777215));
        scrollArea = new QScrollArea(recomdPage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 975, 650));
        scrollArea->setMinimumSize(QSize(975, 650));
        scrollArea->setMaximumSize(QSize(975, 650));
        scrollArea->setStyleSheet(QString::fromUtf8("#scrollArea:vertical\n"
"{\n"
"	width:10px;\n"
"	background-color:#F0F0F0;\n"
"	margin:0px 0px 0px 0px;\n"
"}\n"
"#scrollArea::handle:vertical\n"
"{\n"
"	width:10px;\n"
"	background-color:#E3E3E3;\n"
"	border-radius:5px;\n"
"	min-height:20px;\n"
"}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 950, 648));
        scrollAreaWidgetContents->setMinimumSize(QSize(950, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(950, 16777215));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(-1, -1, 2, -1);
        rec = new QLabel(scrollAreaWidgetContents);
        rec->setObjectName(QString::fromUtf8("rec"));
        rec->setMinimumSize(QSize(0, 50));
        rec->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(24);
        rec->setFont(font);

        verticalLayout_9->addWidget(rec);

        todayRec = new QLabel(scrollAreaWidgetContents);
        todayRec->setObjectName(QString::fromUtf8("todayRec"));
        todayRec->setMinimumSize(QSize(0, 30));
        todayRec->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(18);
        todayRec->setFont(font1);

        verticalLayout_9->addWidget(todayRec);

        todayBox = new RecBox(scrollAreaWidgetContents);
        todayBox->setObjectName(QString::fromUtf8("todayBox"));

        verticalLayout_9->addWidget(todayBox);

        supplyRec = new QLabel(scrollAreaWidgetContents);
        supplyRec->setObjectName(QString::fromUtf8("supplyRec"));
        supplyRec->setMinimumSize(QSize(0, 30));
        supplyRec->setMaximumSize(QSize(16777215, 30));
        supplyRec->setFont(font1);

        verticalLayout_9->addWidget(supplyRec);

        supplyBox = new RecBox(scrollAreaWidgetContents);
        supplyBox->setObjectName(QString::fromUtf8("supplyBox"));

        verticalLayout_9->addWidget(supplyBox);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(recomdPage);
        audioPage = new QWidget();
        audioPage->setObjectName(QString::fromUtf8("audioPage"));
        label_2 = new QLabel(audioPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 290, 72, 15));
        stackedWidget->addWidget(audioPage);
        musicPage = new QWidget();
        musicPage->setObjectName(QString::fromUtf8("musicPage"));
        label_3 = new QLabel(musicPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 280, 72, 15));
        stackedWidget->addWidget(musicPage);
        likePage = new commonPage();
        likePage->setObjectName(QString::fromUtf8("likePage"));
        stackedWidget->addWidget(likePage);
        loaclMusicPage = new commonPage();
        loaclMusicPage->setObjectName(QString::fromUtf8("loaclMusicPage"));
        stackedWidget->addWidget(loaclMusicPage);
        recentPage = new commonPage();
        recentPage->setObjectName(QString::fromUtf8("recentPage"));
        stackedWidget->addWidget(recentPage);

        verticalLayout_8->addWidget(stackedWidget);

        progressBar = new MusicSlider(bodyRight);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(970, 20));
        progressBar->setMaximumSize(QSize(970, 20));
        progressBar->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_8->addWidget(progressBar);

        control = new QWidget(bodyRight);
        control->setObjectName(QString::fromUtf8("control"));
        control->setMinimumSize(QSize(970, 60));
        control->setMaximumSize(QSize(970, 60));
        control->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_7 = new QHBoxLayout(control);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        play_1 = new QWidget(control);
        play_1->setObjectName(QString::fromUtf8("play_1"));
        play_1->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(play_1);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        musicCover = new QLabel(play_1);
        musicCover->setObjectName(QString::fromUtf8("musicCover"));
        musicCover->setMinimumSize(QSize(90, 60));
        musicCover->setMaximumSize(QSize(90, 60));

        gridLayout->addWidget(musicCover, 0, 0, 1, 1);

        musicName = new QLabel(play_1);
        musicName->setObjectName(QString::fromUtf8("musicName"));

        gridLayout->addWidget(musicName, 0, 1, 1, 1);

        musicSinger = new QLabel(play_1);
        musicSinger->setObjectName(QString::fromUtf8("musicSinger"));

        gridLayout->addWidget(musicSinger, 1, 1, 1, 1);


        horizontalLayout_7->addWidget(play_1);

        play_2 = new QWidget(control);
        play_2->setObjectName(QString::fromUtf8("play_2"));
        play_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-repeat:no-repeat;\n"
"	background-position: center center;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255,0,0,0.5);\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(play_2);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        playMode = new QPushButton(play_2);
        playMode->setObjectName(QString::fromUtf8("playMode"));
        playMode->setMinimumSize(QSize(30, 30));
        playMode->setMaximumSize(QSize(30, 30));
        playMode->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_8->addWidget(playMode);

        playUp = new QPushButton(play_2);
        playUp->setObjectName(QString::fromUtf8("playUp"));
        playUp->setMinimumSize(QSize(30, 30));
        playUp->setMaximumSize(QSize(30, 30));
        playUp->setStyleSheet(QString::fromUtf8("#playUp\n"
"{\n"
"	background-image:url(\":/image/up.png\");\n"
"}"));

        horizontalLayout_8->addWidget(playUp);

        play = new QPushButton(play_2);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMinimumSize(QSize(30, 30));
        play->setMaximumSize(QSize(30, 30));
        play->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_8->addWidget(play);

        playDown = new QPushButton(play_2);
        playDown->setObjectName(QString::fromUtf8("playDown"));
        playDown->setMinimumSize(QSize(30, 30));
        playDown->setMaximumSize(QSize(30, 30));
        playDown->setStyleSheet(QString::fromUtf8("#playDown\n"
"{\n"
"	background-image:url(\":/image/down.png\");\n"
"\n"
"}"));

        horizontalLayout_8->addWidget(playDown);

        volume = new QPushButton(play_2);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setMinimumSize(QSize(30, 30));
        volume->setMaximumSize(QSize(30, 30));
        volume->setStyleSheet(QString::fromUtf8("#volume\n"
"{\n"
"	background-image:url(\":/image/volumn.png\");\n"
"}"));

        horizontalLayout_8->addWidget(volume);

        addLocal = new QPushButton(play_2);
        addLocal->setObjectName(QString::fromUtf8("addLocal"));
        addLocal->setMinimumSize(QSize(30, 30));
        addLocal->setMaximumSize(QSize(30, 30));
        addLocal->setStyleSheet(QString::fromUtf8("#addLocal\n"
"{\n"
"	background-image:url(\":/image/add.png\");\n"
"\n"
"}"));

        horizontalLayout_8->addWidget(addLocal);


        horizontalLayout_7->addWidget(play_2);

        play_3 = new QWidget(control);
        play_3->setObjectName(QString::fromUtf8("play_3"));
        play_3->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_9 = new QHBoxLayout(play_3);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        nullLabel = new QLabel(play_3);
        nullLabel->setObjectName(QString::fromUtf8("nullLabel"));

        horizontalLayout_9->addWidget(nullLabel);

        currentTime = new QLabel(play_3);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));
        currentTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(currentTime);

        line = new QLabel(play_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(30, 0));
        line->setMaximumSize(QSize(30, 16777215));
        line->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(line);

        totalTime = new QLabel(play_3);
        totalTime->setObjectName(QString::fromUtf8("totalTime"));
        totalTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(totalTime);

        word = new QPushButton(play_3);
        word->setObjectName(QString::fromUtf8("word"));
        word->setMinimumSize(QSize(30, 30));
        word->setMaximumSize(QSize(30, 30));
        word->setStyleSheet(QString::fromUtf8("#word\n"
"{\n"
"	border:none;\n"
"	background-image:url(\":/image/ci.png\");\n"
"	background-repeat:no-reapeat;\n"
"	background-position:center center;\n"
"\n"
"}\n"
"#word:hover\n"
"{\n"
"	background-color:rgba(220,220,220,0.5);\n"
"}"));

        horizontalLayout_9->addWidget(word);


        horizontalLayout_7->addWidget(play_3);


        verticalLayout_8->addWidget(control);


        horizontalLayout_4->addWidget(bodyRight);


        verticalLayout_2->addWidget(body);


        verticalLayout->addWidget(background);


        retranslateUi(MuePlayer);

        QMetaObject::connectSlotsByName(MuePlayer);
    } // setupUi

    void retranslateUi(QWidget *MuePlayer)
    {
        MuePlayer->setWindowTitle(QCoreApplication::translate("MuePlayer", "MuePlayer", nullptr));
        logo->setText(QString());
        skin->setText(QString());
        min->setText(QString());
        max->setText(QString());
        quit->setText(QString());
        onlineMusic->setText(QCoreApplication::translate("MuePlayer", "\345\234\250\347\272\277\351\237\263\344\271\220", nullptr));
        myMusic->setText(QCoreApplication::translate("MuePlayer", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        rec->setText(QCoreApplication::translate("MuePlayer", "\346\216\250\350\215\220", nullptr));
        todayRec->setText(QCoreApplication::translate("MuePlayer", "\344\273\212\346\227\245\346\216\250\350\215\220", nullptr));
        supplyRec->setText(QCoreApplication::translate("MuePlayer", "\346\216\250\350\215\220\346\255\214\345\215\225", nullptr));
        label_2->setText(QCoreApplication::translate("MuePlayer", "\346\225\254\350\257\267\346\234\237\345\276\205", nullptr));
        label_3->setText(QCoreApplication::translate("MuePlayer", "\346\225\254\350\257\267\346\234\237\345\276\205", nullptr));
        musicCover->setText(QCoreApplication::translate("MuePlayer", "\345\233\276\347\211\207", nullptr));
        musicName->setText(QCoreApplication::translate("MuePlayer", "\346\255\214\345\220\215", nullptr));
        musicSinger->setText(QCoreApplication::translate("MuePlayer", "\346\255\214\346\211\213", nullptr));
        playMode->setText(QString());
        playUp->setText(QString());
        play->setText(QString());
        playDown->setText(QString());
        volume->setText(QString());
        addLocal->setText(QString());
        nullLabel->setText(QString());
        currentTime->setText(QCoreApplication::translate("MuePlayer", "2:27", nullptr));
        line->setText(QCoreApplication::translate("MuePlayer", "/", nullptr));
        totalTime->setText(QCoreApplication::translate("MuePlayer", "3:30", nullptr));
        word->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MuePlayer: public Ui_MuePlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUEPLAYER_H
