/********************************************************************************
** Form generated from reading UI file 'recboxitem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECBOXITEM_H
#define UI_RECBOXITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecBoxItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *image;
    QPushButton *btn;
    QLabel *label;

    void setupUi(QWidget *RecBoxItem)
    {
        if (RecBoxItem->objectName().isEmpty())
            RecBoxItem->setObjectName(QString::fromUtf8("RecBoxItem"));
        RecBoxItem->resize(150, 200);
        verticalLayout = new QVBoxLayout(RecBoxItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(RecBoxItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 150));
        widget->setMaximumSize(QSize(16777215, 150));
        image = new QLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, 9, 150, 150));
        image->setStyleSheet(QString::fromUtf8(""));
        btn = new QPushButton(widget);
        btn->setObjectName(QString::fromUtf8("btn"));
        btn->setGeometry(QRect(20, 20, 111, 111));
        btn->setCursor(QCursor(Qt::PointingHandCursor));
        btn->setStyleSheet(QString::fromUtf8("#btn\n"
"{\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(widget);

        label = new QLabel(RecBoxItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(150, 30));
        label->setMaximumSize(QSize(150, 30));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(RecBoxItem);

        QMetaObject::connectSlotsByName(RecBoxItem);
    } // setupUi

    void retranslateUi(QWidget *RecBoxItem)
    {
        RecBoxItem->setWindowTitle(QCoreApplication::translate("RecBoxItem", "Form", nullptr));
        image->setText(QString());
        btn->setText(QString());
        label->setText(QCoreApplication::translate("RecBoxItem", "\346\255\214\346\233\262\346\216\250\350\215\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecBoxItem: public Ui_RecBoxItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECBOXITEM_H
