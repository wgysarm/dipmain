/********************************************************************************
** Form generated from reading UI file 'CPlayWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPLAYWINDOW_H
#define UI_CPLAYWINDOW_H

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

class Ui_CPlayWindow
{
public:
    QPushButton *pushButton_preview;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_switch;
    QPushButton *pushButton_cam2;
    QPushButton *pushButton_cam1;
    QPushButton *pushButton_return;
    QPushButton *pushButton_rtsp1;
    QPushButton *pushButton_rtsp2;
    QPushButton *pushButton_rtspsw;
    QLabel *label_logo;
    QLabel *label_info;
    QPushButton *pushButton;
    QPushButton *pushButton_brightset;
    QSlider *horizontalSlider_bn;
    QSlider *horizontalSlider_contrast;
    QSlider *horizontalSlider_saturation;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *CPlayWindow)
    {
        if (CPlayWindow->objectName().isEmpty())
            CPlayWindow->setObjectName(QStringLiteral("CPlayWindow"));
        CPlayWindow->resize(1024, 580);
        pushButton_preview = new QPushButton(CPlayWindow);
        pushButton_preview->setObjectName(QStringLiteral("pushButton_preview"));
        pushButton_preview->setGeometry(QRect(270, 540, 80, 23));
        pushButton_stop = new QPushButton(CPlayWindow);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(620, 540, 80, 23));
        pushButton_switch = new QPushButton(CPlayWindow);
        pushButton_switch->setObjectName(QStringLiteral("pushButton_switch"));
        pushButton_switch->setGeometry(QRect(530, 540, 80, 23));
        pushButton_cam2 = new QPushButton(CPlayWindow);
        pushButton_cam2->setObjectName(QStringLiteral("pushButton_cam2"));
        pushButton_cam2->setGeometry(QRect(450, 540, 80, 23));
        pushButton_cam1 = new QPushButton(CPlayWindow);
        pushButton_cam1->setObjectName(QStringLiteral("pushButton_cam1"));
        pushButton_cam1->setGeometry(QRect(370, 540, 80, 23));
        pushButton_return = new QPushButton(CPlayWindow);
        pushButton_return->setObjectName(QStringLiteral("pushButton_return"));
        pushButton_return->setGeometry(QRect(710, 540, 80, 23));
        pushButton_rtsp1 = new QPushButton(CPlayWindow);
        pushButton_rtsp1->setObjectName(QStringLiteral("pushButton_rtsp1"));
        pushButton_rtsp1->setGeometry(QRect(100, 540, 80, 23));
        pushButton_rtsp2 = new QPushButton(CPlayWindow);
        pushButton_rtsp2->setObjectName(QStringLiteral("pushButton_rtsp2"));
        pushButton_rtsp2->setGeometry(QRect(180, 540, 80, 23));
        pushButton_rtspsw = new QPushButton(CPlayWindow);
        pushButton_rtspsw->setObjectName(QStringLiteral("pushButton_rtspsw"));
        pushButton_rtspsw->setGeometry(QRect(20, 540, 80, 23));
        label_logo = new QLabel(CPlayWindow);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(0, 0, 111, 131));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/images/image/res/camera.ico")));
        label_info = new QLabel(CPlayWindow);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setGeometry(QRect(120, 10, 59, 15));
        pushButton = new QPushButton(CPlayWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(820, 140, 80, 23));
        pushButton_brightset = new QPushButton(CPlayWindow);
        pushButton_brightset->setObjectName(QStringLiteral("pushButton_brightset"));
        pushButton_brightset->setGeometry(QRect(820, 270, 80, 23));
        horizontalSlider_bn = new QSlider(CPlayWindow);
        horizontalSlider_bn->setObjectName(QStringLiteral("horizontalSlider_bn"));
        horizontalSlider_bn->setGeometry(QRect(820, 180, 160, 16));
        horizontalSlider_bn->setMinimum(1);
        horizontalSlider_bn->setMaximum(9);
        horizontalSlider_bn->setOrientation(Qt::Horizontal);
        horizontalSlider_contrast = new QSlider(CPlayWindow);
        horizontalSlider_contrast->setObjectName(QStringLiteral("horizontalSlider_contrast"));
        horizontalSlider_contrast->setGeometry(QRect(820, 210, 160, 16));
        horizontalSlider_contrast->setMinimum(1);
        horizontalSlider_contrast->setMaximum(5);
        horizontalSlider_contrast->setOrientation(Qt::Horizontal);
        horizontalSlider_saturation = new QSlider(CPlayWindow);
        horizontalSlider_saturation->setObjectName(QStringLiteral("horizontalSlider_saturation"));
        horizontalSlider_saturation->setGeometry(QRect(820, 240, 160, 16));
        horizontalSlider_saturation->setMinimum(1);
        horizontalSlider_saturation->setMaximum(5);
        horizontalSlider_saturation->setOrientation(Qt::Horizontal);
        label = new QLabel(CPlayWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(930, 160, 59, 15));
        label_2 = new QLabel(CPlayWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(930, 200, 59, 15));
        label_3 = new QLabel(CPlayWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(930, 230, 59, 15));

        retranslateUi(CPlayWindow);

        QMetaObject::connectSlotsByName(CPlayWindow);
    } // setupUi

    void retranslateUi(QWidget *CPlayWindow)
    {
        CPlayWindow->setWindowTitle(QApplication::translate("CPlayWindow", "PlayWindow", 0));
        pushButton_preview->setText(QApplication::translate("CPlayWindow", "\351\242\204\350\247\210", 0));
        pushButton_stop->setText(QApplication::translate("CPlayWindow", "\345\205\263\351\227\255\347\233\270\346\234\272", 0));
        pushButton_switch->setText(QApplication::translate("CPlayWindow", "\345\220\214\345\261\217\345\210\207\346\215\242", 0));
        pushButton_cam2->setText(QApplication::translate("CPlayWindow", "\347\233\270\346\234\2722", 0));
        pushButton_cam1->setText(QApplication::translate("CPlayWindow", "\347\233\270\346\234\2721", 0));
        pushButton_return->setText(QApplication::translate("CPlayWindow", "\350\277\224\345\233\236", 0));
        pushButton_rtsp1->setText(QApplication::translate("CPlayWindow", "RTSP1", 0));
        pushButton_rtsp2->setText(QApplication::translate("CPlayWindow", "RTSP2", 0));
        pushButton_rtspsw->setText(QApplication::translate("CPlayWindow", "RTSPSW", 0));
        label_logo->setText(QString());
        label_info->setText(QApplication::translate("CPlayWindow", "TextLabel", 0));
        pushButton->setText(QApplication::translate("CPlayWindow", "TEST", 0));
        pushButton_brightset->setText(QApplication::translate("CPlayWindow", "camerset", 0));
        label->setText(QApplication::translate("CPlayWindow", "bright", 0));
        label_2->setText(QApplication::translate("CPlayWindow", "contrast", 0));
        label_3->setText(QApplication::translate("CPlayWindow", "saturation", 0));
    } // retranslateUi

};

namespace Ui {
    class CPlayWindow: public Ui_CPlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPLAYWINDOW_H
