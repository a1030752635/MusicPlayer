/********************************************************************************
** Form generated from reading UI file 'recbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECBOX_H
#define UI_RECBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecBox
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftPage;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *up;
    QWidget *content;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *recUp;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *upLayout;
    QWidget *recDown;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *downLayout;
    QWidget *rightPage;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *down;

    void setupUi(QWidget *RecBox)
    {
        if (RecBox->objectName().isEmpty())
            RecBox->setObjectName(QString::fromUtf8("RecBox"));
        RecBox->resize(950, 440);
        RecBox->setMinimumSize(QSize(950, 440));
        RecBox->setMaximumSize(QSize(950, 440));
        horizontalLayout = new QHBoxLayout(RecBox);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftPage = new QWidget(RecBox);
        leftPage->setObjectName(QString::fromUtf8("leftPage"));
        leftPage->setMinimumSize(QSize(30, 0));
        leftPage->setMaximumSize(QSize(30, 16777215));
        horizontalLayout_2 = new QHBoxLayout(leftPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        up = new QPushButton(leftPage);
        up->setObjectName(QString::fromUtf8("up"));
        up->setMinimumSize(QSize(25, 330));
        up->setMaximumSize(QSize(25, 330));
        up->setStyleSheet(QString::fromUtf8("#up\n"
"{\n"
"	border:none;\n"
"	background-image:url(:/image/up_page.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#1ECD97;\n"
"}"));

        horizontalLayout_2->addWidget(up);


        horizontalLayout->addWidget(leftPage);

        content = new QWidget(RecBox);
        content->setObjectName(QString::fromUtf8("content"));
        verticalLayout = new QVBoxLayout(content);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(content);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        recUp = new QWidget(widget);
        recUp->setObjectName(QString::fromUtf8("recUp"));
        verticalLayout_3 = new QVBoxLayout(recUp);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        upLayout = new QHBoxLayout();
        upLayout->setObjectName(QString::fromUtf8("upLayout"));

        verticalLayout_3->addLayout(upLayout);


        verticalLayout_2->addWidget(recUp);

        recDown = new QWidget(widget);
        recDown->setObjectName(QString::fromUtf8("recDown"));
        verticalLayout_4 = new QVBoxLayout(recDown);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        downLayout = new QHBoxLayout();
        downLayout->setObjectName(QString::fromUtf8("downLayout"));

        verticalLayout_4->addLayout(downLayout);


        verticalLayout_2->addWidget(recDown);


        verticalLayout->addWidget(widget);


        horizontalLayout->addWidget(content);

        rightPage = new QWidget(RecBox);
        rightPage->setObjectName(QString::fromUtf8("rightPage"));
        rightPage->setMinimumSize(QSize(30, 0));
        rightPage->setMaximumSize(QSize(30, 16777215));
        horizontalLayout_3 = new QHBoxLayout(rightPage);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        down = new QPushButton(rightPage);
        down->setObjectName(QString::fromUtf8("down"));
        down->setMinimumSize(QSize(25, 330));
        down->setMaximumSize(QSize(25, 330));
        down->setStyleSheet(QString::fromUtf8("#down\n"
"{\n"
"	border:none;\n"
"	background-image:url(:/image/down_page.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#1ECD97;\n"
"}"));

        horizontalLayout_3->addWidget(down);


        horizontalLayout->addWidget(rightPage);


        retranslateUi(RecBox);

        QMetaObject::connectSlotsByName(RecBox);
    } // setupUi

    void retranslateUi(QWidget *RecBox)
    {
        RecBox->setWindowTitle(QCoreApplication::translate("RecBox", "Form", nullptr));
        up->setText(QString());
        down->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecBox: public Ui_RecBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECBOX_H
