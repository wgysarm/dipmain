/********************************************************************************
** Form generated from reading UI file 'frm_autplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_AUTPLAYER_H
#define UI_FRM_AUTPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutPlayer
{
public:
    QWidget *widget;
    QPushButton *pushButton_openfile;
    QPushButton *pushButton_play;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_home;

    void setupUi(QWidget *AutPlayer)
    {
        if (AutPlayer->objectName().isEmpty())
            AutPlayer->setObjectName(QStringLiteral("AutPlayer"));
        AutPlayer->resize(1024, 600);
        AutPlayer->setStyleSheet(QStringLiteral("background-color: rgb(112, 200, 0);"));
        widget = new QWidget(AutPlayer);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 420, 800, 60));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(112, 200, 11);"));
        pushButton_openfile = new QPushButton(widget);
        pushButton_openfile->setObjectName(QStringLiteral("pushButton_openfile"));
        pushButton_openfile->setGeometry(QRect(20, 10, 51, 51));
        pushButton_openfile->setStyleSheet(QStringLiteral("border-image: url(:/images/image/res/openfile_unsel.png);"));
        pushButton_play = new QPushButton(widget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        pushButton_play->setGeometry(QRect(150, 10, 51, 51));
        pushButton_play->setStyleSheet(QStringLiteral("border-image: url(:/images/image/res/play_unsel.png);"));
        pushButton_stop = new QPushButton(widget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(280, 10, 51, 51));
        pushButton_stop->setStyleSheet(QStringLiteral("border-image: url(:/images/image/res/stop_unsel.png);"));
        pushButton_home = new QPushButton(widget);
        pushButton_home->setObjectName(QStringLiteral("pushButton_home"));
        pushButton_home->setGeometry(QRect(730, 10, 51, 51));
        pushButton_home->setStyleSheet(QStringLiteral("border-image: url(:/images/image/res/up-arrow_unsel.png);"));

        retranslateUi(AutPlayer);

        QMetaObject::connectSlotsByName(AutPlayer);
    } // setupUi

    void retranslateUi(QWidget *AutPlayer)
    {
        AutPlayer->setWindowTitle(QApplication::translate("AutPlayer", "Form", 0));
        pushButton_openfile->setText(QString());
        pushButton_play->setText(QString());
        pushButton_stop->setText(QString());
        pushButton_home->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AutPlayer: public Ui_AutPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_AUTPLAYER_H
