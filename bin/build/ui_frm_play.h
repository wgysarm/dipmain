/********************************************************************************
** Form generated from reading UI file 'frm_play.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_PLAY_H
#define UI_FRM_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Play
{
public:
    QWidget *widget;
    QPushButton *pushButton_tackpic;
    QPushButton *pushButton_play;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_home;
    QSlider *horizontalSlider_4;
    QLabel *label;
    QPushButton *pushButton_switchC;

    void setupUi(QWidget *Play)
    {
        if (Play->objectName().isEmpty())
            Play->setObjectName(QStringLiteral("Play"));
        Play->resize(1024, 600);
        Play->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(Play);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 540, 800, 60));
        widget->setStyleSheet(QStringLiteral(""));
        pushButton_tackpic = new QPushButton(widget);
        pushButton_tackpic->setObjectName(QStringLiteral("pushButton_tackpic"));
        pushButton_tackpic->setGeometry(QRect(50, 10, 71, 31));
        pushButton_tackpic->setAutoFillBackground(false);
        pushButton_tackpic->setStyleSheet(QStringLiteral(""));
        pushButton_play = new QPushButton(widget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        pushButton_play->setGeometry(QRect(140, 10, 71, 31));
        pushButton_play->setStyleSheet(QStringLiteral(""));
        pushButton_stop = new QPushButton(widget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(370, 10, 71, 31));
        pushButton_stop->setStyleSheet(QStringLiteral(""));
        pushButton_home = new QPushButton(widget);
        pushButton_home->setObjectName(QStringLiteral("pushButton_home"));
        pushButton_home->setGeometry(QRect(480, 10, 71, 31));
        pushButton_home->setStyleSheet(QStringLiteral(""));
        horizontalSlider_4 = new QSlider(widget);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(620, 10, 141, 20));
        horizontalSlider_4->setMinimum(1);
        horizontalSlider_4->setMaximum(10);
        horizontalSlider_4->setPageStep(5);
        horizontalSlider_4->setValue(1);
        horizontalSlider_4->setSliderPosition(1);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(580, 10, 31, 29));
        pushButton_switchC = new QPushButton(widget);
        pushButton_switchC->setObjectName(QStringLiteral("pushButton_switchC"));
        pushButton_switchC->setGeometry(QRect(260, 10, 61, 31));
        pushButton_switchC->setStyleSheet(QStringLiteral(""));

        retranslateUi(Play);

        QMetaObject::connectSlotsByName(Play);
    } // setupUi

    void retranslateUi(QWidget *Play)
    {
        Play->setWindowTitle(QApplication::translate("Play", "Form", 0));
        pushButton_tackpic->setText(QApplication::translate("Play", "picture", 0));
        pushButton_play->setText(QApplication::translate("Play", "capture", 0));
        pushButton_stop->setText(QApplication::translate("Play", "stop", 0));
        pushButton_home->setText(QApplication::translate("Play", "return", 0));
        label->setText(QApplication::translate("Play", "X1", 0));
        pushButton_switchC->setText(QApplication::translate("Play", "switch", 0));
    } // retranslateUi

};

namespace Ui {
    class Play: public Ui_Play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_PLAY_H
