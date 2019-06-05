/********************************************************************************
** Form generated from reading UI file 'frm_excepthandle.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_EXCEPTHANDLE_H
#define UI_FRM_EXCEPTHANDLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frm_excepthandle
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QComboBox *comboBox;

    void setupUi(QWidget *frm_excepthandle)
    {
        if (frm_excepthandle->objectName().isEmpty())
            frm_excepthandle->setObjectName(QStringLiteral("frm_excepthandle"));
        frm_excepthandle->setWindowModality(Qt::WindowModal);
        frm_excepthandle->resize(447, 207);
        frm_excepthandle->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        buttonBox = new QDialogButtonBox(frm_excepthandle);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(140, 140, 189, 34));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(frm_excepthandle);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 36, 91, 24));
        checkBox = new QCheckBox(frm_excepthandle);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(0, 90, 151, 30));
        checkBox->setLayoutDirection(Qt::RightToLeft);
        checkBox_2 = new QCheckBox(frm_excepthandle);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(180, 90, 161, 30));
        checkBox_2->setLayoutDirection(Qt::RightToLeft);
        comboBox = new QComboBox(frm_excepthandle);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 30, 251, 37));

        retranslateUi(frm_excepthandle);

        QMetaObject::connectSlotsByName(frm_excepthandle);
    } // setupUi

    void retranslateUi(QWidget *frm_excepthandle)
    {
        frm_excepthandle->setWindowTitle(QApplication::translate("frm_excepthandle", "\345\274\202\345\270\270\345\244\204\347\220\206", 0));
        label->setText(QApplication::translate("frm_excepthandle", "\345\274\202\345\270\270\347\261\273\345\236\213", 0));
        checkBox->setText(QApplication::translate("frm_excepthandle", "\345\243\260\351\237\263\346\212\245\350\255\246", 0));
        checkBox_2->setText(QApplication::translate("frm_excepthandle", "\350\247\246\345\217\221\346\212\245\350\255\246\350\276\223\345\207\272", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("frm_excepthandle", "IP\345\234\260\345\235\200\345\206\262\347\252\201", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class frm_excepthandle: public Ui_frm_excepthandle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_EXCEPTHANDLE_H
