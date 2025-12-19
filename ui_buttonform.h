/********************************************************************************
** Form generated from reading UI file 'buttonform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONFORM_H
#define UI_BUTTONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ButtonForm
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *ButtonStyle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Icon;
    QLabel *Text;
    QWidget *Line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *ButtonForm)
    {
        if (ButtonForm->objectName().isEmpty())
            ButtonForm->setObjectName(QString::fromUtf8("ButtonForm"));
        ButtonForm->resize(180, 36);
        ButtonForm->setStyleSheet(QString::fromUtf8("#ButtonStyle:hover\n"
"{\n"
"	background-color:#D8D8D8;\n"
"}"));
        horizontalLayout = new QHBoxLayout(ButtonForm);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ButtonStyle = new QWidget(ButtonForm);
        ButtonStyle->setObjectName(QString::fromUtf8("ButtonStyle"));
        ButtonStyle->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(ButtonStyle);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Icon = new QLabel(ButtonStyle);
        Icon->setObjectName(QString::fromUtf8("Icon"));
        Icon->setMinimumSize(QSize(30, 30));
        Icon->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(Icon);

        Text = new QLabel(ButtonStyle);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setMinimumSize(QSize(90, 30));
        Text->setMaximumSize(QSize(90, 30));

        horizontalLayout_2->addWidget(Text);

        Line = new QWidget(ButtonStyle);
        Line->setObjectName(QString::fromUtf8("Line"));
        Line->setMinimumSize(QSize(30, 30));
        Line->setMaximumSize(QSize(30, 30));
        Line->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color:rgb(85, 255, 127);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(Line);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Line);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(2, 0));
        label->setMaximumSize(QSize(2, 16777215));

        horizontalLayout_3->addWidget(label);

        label_2 = new QLabel(Line);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(2, 0));
        label_2->setMaximumSize(QSize(2, 16777215));

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(Line);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(2, 0));
        label_3->setMaximumSize(QSize(2, 16777215));

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(Line);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(2, 0));
        label_4->setMaximumSize(QSize(2, 16777215));

        horizontalLayout_3->addWidget(label_4);


        horizontalLayout_2->addWidget(Line);


        horizontalLayout->addWidget(ButtonStyle);


        retranslateUi(ButtonForm);

        QMetaObject::connectSlotsByName(ButtonForm);
    } // setupUi

    void retranslateUi(QWidget *ButtonForm)
    {
        ButtonForm->setWindowTitle(QCoreApplication::translate("ButtonForm", "Form", nullptr));
        Icon->setText(QCoreApplication::translate("ButtonForm", "\345\233\276", nullptr));
        Text->setText(QCoreApplication::translate("ButtonForm", "\346\234\254\345\234\260\346\255\214\346\233\262", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ButtonForm: public Ui_ButtonForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONFORM_H
