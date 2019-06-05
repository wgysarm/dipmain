/********************************************************************************
** Form generated from reading UI file 'frm_alarmsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_ALARMSETTINGS_H
#define UI_FRM_ALARMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frm_alarmsettings
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QSpinBox *spinBox_4;
    QPushButton *pushButton;
    QFrame *frame_2;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *spinBox;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_2;
    QComboBox *comboBox_3;
    QPushButton *pushButton_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *frm_alarmsettings)
    {
        if (frm_alarmsettings->objectName().isEmpty())
            frm_alarmsettings->setObjectName(QStringLiteral("frm_alarmsettings"));
        frm_alarmsettings->setWindowModality(Qt::WindowModal);
        frm_alarmsettings->resize(642, 405);
        frm_alarmsettings->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        frame = new QFrame(frm_alarmsettings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 20, 601, 161));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 131, 24));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 20, 111, 24));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 91, 24));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 103, 131, 24));
        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(145, 100, 111, 34));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(16);
        spinBox_2->setValue(2);
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(480, 14, 111, 37));
        comboBox_2 = new QComboBox(frame);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(145, 50, 111, 37));
        spinBox_4 = new QSpinBox(frame);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(145, 10, 111, 34));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 100, 81, 36));
        frame_2 = new QFrame(frm_alarmsettings);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(20, 180, 601, 161));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 91, 24));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 110, 70, 24));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 60, 131, 24));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(350, 20, 111, 24));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(350, 60, 91, 24));
        spinBox = new QSpinBox(frame_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(150, 110, 101, 34));
        spinBox->setMinimum(1);
        spinBox->setMaximum(16);
        spinBox->setValue(2);
        spinBox_3 = new QSpinBox(frame_2);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(470, 60, 111, 34));
        spinBox_5 = new QSpinBox(frame_2);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setGeometry(QRect(150, 10, 101, 34));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 110, 81, 36));
        comboBox_3 = new QComboBox(frame_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(470, 10, 111, 37));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 60, 100, 36));
        buttonBox = new QDialogButtonBox(frm_alarmsettings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(210, 350, 189, 34));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(frm_alarmsettings);

        QMetaObject::connectSlotsByName(frm_alarmsettings);
    } // setupUi

    void retranslateUi(QWidget *frm_alarmsettings)
    {
        frm_alarmsettings->setWindowTitle(QApplication::translate("frm_alarmsettings", "\346\212\245\350\255\246\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("frm_alarmsettings", "\351\200\211\346\213\251\346\212\245\350\255\246\350\276\223\345\205\245", 0));
        label_3->setText(QApplication::translate("frm_alarmsettings", "\346\212\245\350\255\246\345\231\250\347\261\273\345\236\213", 0));
        label_4->setText(QApplication::translate("frm_alarmsettings", "\346\212\245\350\255\246\350\276\223\345\205\245", 0));
        label_5->setText(QApplication::translate("frm_alarmsettings", "\345\244\215\345\210\266\345\210\260\346\212\245\350\255\246\351\207\217", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("frm_alarmsettings", "\344\275\216\347\224\265\345\271\263", 0)
         << QApplication::translate("frm_alarmsettings", "\351\253\230\347\224\265\345\271\263", 0)
         << QApplication::translate("frm_alarmsettings", "\345\270\270\351\227\255", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("frm_alarmsettings", "\344\270\215\345\244\204\347\220\206", 0)
         << QApplication::translate("frm_alarmsettings", "\346\212\245\350\255\246", 0)
        );
        pushButton->setText(QApplication::translate("frm_alarmsettings", "\345\244\215\345\210\266", 0));
        label_2->setText(QApplication::translate("frm_alarmsettings", "\346\212\245\350\255\246\350\276\223\345\207\272", 0));
        label_6->setText(QApplication::translate("frm_alarmsettings", "\345\244\215\345\210\266\345\210\260", 0));
        label_7->setText(QApplication::translate("frm_alarmsettings", "\346\212\245\350\255\246\350\276\223\345\207\272\346\227\266\351\227\264", 0));
        label_8->setText(QApplication::translate("frm_alarmsettings", "\346\212\245\350\255\246\345\231\250\347\261\273\345\236\213", 0));
        label_9->setText(QApplication::translate("frm_alarmsettings", "\350\276\223\345\207\272\345\273\266\346\227\266", 0));
        spinBox_3->setSuffix(QApplication::translate("frm_alarmsettings", "\347\247\222", 0));
        pushButton_2->setText(QApplication::translate("frm_alarmsettings", "\345\244\215\345\210\266", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("frm_alarmsettings", "\344\275\216\347\224\265\345\271\263", 0)
         << QApplication::translate("frm_alarmsettings", "\351\253\230\347\224\265\345\271\263", 0)
         << QApplication::translate("frm_alarmsettings", "\345\270\270\351\227\255", 0)
        );
        pushButton_3->setText(QApplication::translate("frm_alarmsettings", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class frm_alarmsettings: public Ui_frm_alarmsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_ALARMSETTINGS_H
