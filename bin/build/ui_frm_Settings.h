/********************************************************************************
** Form generated from reading UI file 'frm_Settings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_SETTINGS_H
#define UI_FRM_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frm_imageSettings
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_14;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QFrame *line;
    QComboBox *comboBox_6;
    QLabel *label_11;
    QComboBox *comboBox_7;
    QLabel *label_12;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *frm_imageSettings)
    {
        if (frm_imageSettings->objectName().isEmpty())
            frm_imageSettings->setObjectName(QStringLiteral("frm_imageSettings"));
        frm_imageSettings->setWindowModality(Qt::WindowModal);
        frm_imageSettings->resize(1024, 600);
        frm_imageSettings->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        buttonBox = new QDialogButtonBox(frm_imageSettings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(250, 410, 189, 34));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_3 = new QLabel(frm_imageSettings);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(412, 81, 80, 29));
        label_4 = new QLabel(frm_imageSettings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(412, 116, 80, 29));
        label_6 = new QLabel(frm_imageSettings);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(110, 150, 100, 24));
        label_9 = new QLabel(frm_imageSettings);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(110, 100, 100, 24));
        label_10 = new QLabel(frm_imageSettings);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(110, 205, 100, 24));
        label_13 = new QLabel(frm_imageSettings);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(412, 152, 80, 29));
        label_14 = new QLabel(frm_imageSettings);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(412, 188, 80, 29));
        horizontalSlider = new QSlider(frm_imageSettings);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(510, 85, 179, 17));
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(frm_imageSettings);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(510, 120, 179, 17));
        horizontalSlider_2->setValue(50);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(frm_imageSettings);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(510, 155, 179, 17));
        horizontalSlider_3->setValue(50);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_4 = new QSlider(frm_imageSettings);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(510, 190, 179, 17));
        horizontalSlider_4->setValue(50);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        comboBox_3 = new QComboBox(frm_imageSettings);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(210, 90, 140, 37));
        comboBox_3->setLayoutDirection(Qt::LeftToRight);
        comboBox_4 = new QComboBox(frm_imageSettings);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(210, 140, 140, 37));
        comboBox_4->setLayoutDirection(Qt::LeftToRight);
        comboBox_5 = new QComboBox(frm_imageSettings);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(210, 200, 140, 37));
        comboBox_5->setLayoutDirection(Qt::LeftToRight);
        line = new QFrame(frm_imageSettings);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(100, 380, 561, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        comboBox_6 = new QComboBox(frm_imageSettings);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));
        comboBox_6->setGeometry(QRect(210, 255, 140, 37));
        comboBox_6->setLayoutDirection(Qt::LeftToRight);
        label_11 = new QLabel(frm_imageSettings);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(110, 260, 100, 24));
        comboBox_7 = new QComboBox(frm_imageSettings);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));
        comboBox_7->setGeometry(QRect(520, 250, 271, 37));
        comboBox_7->setLayoutDirection(Qt::LeftToRight);
        label_12 = new QLabel(frm_imageSettings);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(410, 260, 100, 24));
        lineEdit_3 = new QLineEdit(frm_imageSettings);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(210, 320, 330, 34));
        lineEdit_3->setDragEnabled(false);
        lineEdit_3->setReadOnly(true);
        label_2 = new QLabel(frm_imageSettings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 330, 90, 24));
        pushButton = new QPushButton(frm_imageSettings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 322, 75, 31));

        retranslateUi(frm_imageSettings);

        comboBox_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(frm_imageSettings);
    } // setupUi

    void retranslateUi(QWidget *frm_imageSettings)
    {
        frm_imageSettings->setWindowTitle(QApplication::translate("frm_imageSettings", "\345\233\276\345\203\217\350\256\276\347\275\256", 0));
        label_3->setText(QApplication::translate("frm_imageSettings", "\344\272\256\345\272\246", 0));
        label_4->setText(QApplication::translate("frm_imageSettings", "\350\211\262\345\272\246", 0));
        label_6->setText(QApplication::translate("frm_imageSettings", "\345\275\225\345\203\217\351\227\264\351\232\224", 0));
        label_9->setText(QApplication::translate("frm_imageSettings", "\345\274\200\346\234\272\345\275\225\345\203\217", 0));
        label_10->setText(QApplication::translate("frm_imageSettings", "ADAS", 0));
        label_13->setText(QApplication::translate("frm_imageSettings", "\345\257\271\346\257\224\345\272\246", 0));
        label_14->setText(QApplication::translate("frm_imageSettings", "\351\245\261\345\222\214\345\272\246", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("frm_imageSettings", "\345\205\263\351\227\255", 0)
         << QApplication::translate("frm_imageSettings", "\345\220\257\345\212\250", 0)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("frm_imageSettings", "1\345\210\206\351\222\237", 0)
         << QApplication::translate("frm_imageSettings", "3\345\210\206\351\222\237", 0)
         << QApplication::translate("frm_imageSettings", "5\345\210\206\351\222\237", 0)
        );
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("frm_imageSettings", "\345\205\263\351\227\255", 0)
         << QApplication::translate("frm_imageSettings", "\345\220\257\345\212\250", 0)
        );
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("frm_imageSettings", "1280x720", 0)
         << QApplication::translate("frm_imageSettings", "640x480", 0)
        );
        label_11->setText(QApplication::translate("frm_imageSettings", "\345\275\225\345\203\217\345\210\206\350\276\250\347\216\207", 0));
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("frm_imageSettings", "\345\205\263\351\227\255", 0)
         << QApplication::translate("frm_imageSettings", "HDMI_1080P60Hz", 0)
         << QApplication::translate("frm_imageSettings", "HDMI_1080P50Hz", 0)
         << QApplication::translate("frm_imageSettings", "HDMI_720P60Hz", 0)
         << QApplication::translate("frm_imageSettings", "HDMI_720P50Hz", 0)
         << QApplication::translate("frm_imageSettings", "VGA", 0)
         << QApplication::translate("frm_imageSettings", "TV_NTSC", 0)
         << QApplication::translate("frm_imageSettings", "TV_PAL", 0)
        );
        label_12->setText(QApplication::translate("frm_imageSettings", "VGA/TV\350\276\223\345\207\272", 0));
        label_2->setText(QApplication::translate("frm_imageSettings", "\345\255\230\345\202\250\350\267\257\345\276\204", 0));
        pushButton->setText(QApplication::translate("frm_imageSettings", "\346\265\217\350\247\210", 0));
    } // retranslateUi

};

namespace Ui {
    class frm_imageSettings: public Ui_frm_imageSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_SETTINGS_H
