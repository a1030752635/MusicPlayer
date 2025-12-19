/********************************************************************************
** Form generated from reading UI file 'commonpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONPAGE_H
#define UI_COMMONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_commonPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *pageTittle;
    QWidget *musicplayBox;
    QHBoxLayout *horizontalLayout;
    QLabel *musicImageLabel;
    QWidget *playAll;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *playAllBtn;
    QSpacerItem *horizontalSpacer;
    QWidget *listLabelBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *musicName;
    QLabel *musicSinger;
    QLabel *musicAlbum;
    QListWidget *pageMusicList;

    void setupUi(QWidget *commonPage)
    {
        if (commonPage->objectName().isEmpty())
            commonPage->setObjectName(QString::fromUtf8("commonPage"));
        commonPage->resize(800, 500);
        verticalLayout = new QVBoxLayout(commonPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pageTittle = new QLabel(commonPage);
        pageTittle->setObjectName(QString::fromUtf8("pageTittle"));
        pageTittle->setMinimumSize(QSize(0, 30));
        pageTittle->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(pageTittle);

        musicplayBox = new QWidget(commonPage);
        musicplayBox->setObjectName(QString::fromUtf8("musicplayBox"));
        musicplayBox->setMinimumSize(QSize(0, 150));
        musicplayBox->setMaximumSize(QSize(16777215, 150));
        horizontalLayout = new QHBoxLayout(musicplayBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        musicImageLabel = new QLabel(musicplayBox);
        musicImageLabel->setObjectName(QString::fromUtf8("musicImageLabel"));
        musicImageLabel->setMinimumSize(QSize(150, 0));
        musicImageLabel->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(musicImageLabel);

        playAll = new QWidget(musicplayBox);
        playAll->setObjectName(QString::fromUtf8("playAll"));
        playAll->setMinimumSize(QSize(150, 0));
        playAll->setMaximumSize(QSize(150, 16777215));
        verticalLayout_2 = new QVBoxLayout(playAll);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 93, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        playAllBtn = new QPushButton(playAll);
        playAllBtn->setObjectName(QString::fromUtf8("playAllBtn"));
        playAllBtn->setMinimumSize(QSize(100, 30));
        playAllBtn->setMaximumSize(QSize(100, 30));
        playAllBtn->setStyleSheet(QString::fromUtf8("#playAllBtn\n"
"{\n"
"	background-color:#e3e3e3;\n"
"	border-radius:10px;\n"
"}\n"
"#playAllBtn::hover\n"
"{\n"
"	background-color:#1ECD97;\n"
"}"));

        verticalLayout_2->addWidget(playAllBtn);


        horizontalLayout->addWidget(playAll);

        horizontalSpacer = new QSpacerItem(479, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(musicplayBox);

        listLabelBox = new QWidget(commonPage);
        listLabelBox->setObjectName(QString::fromUtf8("listLabelBox"));
        listLabelBox->setMinimumSize(QSize(0, 40));
        listLabelBox->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(listLabelBox);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        musicName = new QLabel(listLabelBox);
        musicName->setObjectName(QString::fromUtf8("musicName"));

        horizontalLayout_2->addWidget(musicName);

        musicSinger = new QLabel(listLabelBox);
        musicSinger->setObjectName(QString::fromUtf8("musicSinger"));

        horizontalLayout_2->addWidget(musicSinger);

        musicAlbum = new QLabel(listLabelBox);
        musicAlbum->setObjectName(QString::fromUtf8("musicAlbum"));

        horizontalLayout_2->addWidget(musicAlbum);


        verticalLayout->addWidget(listLabelBox);

        pageMusicList = new QListWidget(commonPage);
        pageMusicList->setObjectName(QString::fromUtf8("pageMusicList"));
        pageMusicList->setStyleSheet(QString::fromUtf8("#pageMusicList::item:selected\n"
"{\n"
"	background-color:#EFEFEF;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"	border:none;\n"
"	width:10px;\n"
"	background-color:#FFFFFF;\n"
"	margin:0px,0px,0px,0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"	width:10px;\n"
"	background-color:#EFEFEF;\n"
"	border-radius:5px;\n"
"	min-height:20px;\n"
"}"));

        verticalLayout->addWidget(pageMusicList);


        retranslateUi(commonPage);

        QMetaObject::connectSlotsByName(commonPage);
    } // setupUi

    void retranslateUi(QWidget *commonPage)
    {
        commonPage->setWindowTitle(QCoreApplication::translate("commonPage", "Form", nullptr));
        pageTittle->setText(QCoreApplication::translate("commonPage", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        musicImageLabel->setText(QCoreApplication::translate("commonPage", "TextLabel", nullptr));
        playAllBtn->setText(QCoreApplication::translate("commonPage", "\346\222\255\346\224\276\345\205\250\351\203\250", nullptr));
        musicName->setText(QCoreApplication::translate("commonPage", "\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        musicSinger->setText(QCoreApplication::translate("commonPage", "\346\255\214\346\211\213\345\220\215\347\247\260", nullptr));
        musicAlbum->setText(QCoreApplication::translate("commonPage", "\344\270\223\350\276\221\345\220\215\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class commonPage: public Ui_commonPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONPAGE_H
