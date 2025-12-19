/********************************************************************************
** Form generated from reading UI file 'musicslider.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICSLIDER_H
#define UI_MUSICSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicSlider
{
public:
    QFrame *inLine;
    QFrame *outLine;

    void setupUi(QWidget *MusicSlider)
    {
        if (MusicSlider->objectName().isEmpty())
            MusicSlider->setObjectName(QString::fromUtf8("MusicSlider"));
        MusicSlider->resize(960, 20);
        MusicSlider->setMinimumSize(QSize(960, 0));
        inLine = new QFrame(MusicSlider);
        inLine->setObjectName(QString::fromUtf8("inLine"));
        inLine->setGeometry(QRect(0, 8, 960, 4));
        inLine->setStyleSheet(QString::fromUtf8("#inLine\n"
"{\n"
"	background-color:#EBEEF5;\n"
"}"));
        inLine->setFrameShape(QFrame::StyledPanel);
        inLine->setFrameShadow(QFrame::Raised);
        outLine = new QFrame(MusicSlider);
        outLine->setObjectName(QString::fromUtf8("outLine"));
        outLine->setGeometry(QRect(0, 8, 400, 4));
        outLine->setStyleSheet(QString::fromUtf8("#outLine\n"
"{\n"
"	background-color:#1ECC94;\n"
"\n"
"}"));
        outLine->setFrameShape(QFrame::StyledPanel);
        outLine->setFrameShadow(QFrame::Raised);

        retranslateUi(MusicSlider);

        QMetaObject::connectSlotsByName(MusicSlider);
    } // setupUi

    void retranslateUi(QWidget *MusicSlider)
    {
        MusicSlider->setWindowTitle(QCoreApplication::translate("MusicSlider", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicSlider: public Ui_MusicSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICSLIDER_H
