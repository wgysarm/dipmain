/********************************************************************************
** Form generated from reading UI file 'frm_sysinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_SYSINFO_H
#define UI_FRM_SYSINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frm_sysinfo
{
public:
    QPushButton *pbtn_ok;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *frm_sysinfo)
    {
        if (frm_sysinfo->objectName().isEmpty())
            frm_sysinfo->setObjectName(QStringLiteral("frm_sysinfo"));
        frm_sysinfo->resize(545, 308);
        frm_sysinfo->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        pbtn_ok = new QPushButton(frm_sysinfo);
        pbtn_ok->setObjectName(QStringLiteral("pbtn_ok"));
        pbtn_ok->setGeometry(QRect(230, 240, 100, 36));
        label_2 = new QLabel(frm_sysinfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 180, 90, 24));
        label = new QLabel(frm_sysinfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 130, 90, 24));
        label_3 = new QLabel(frm_sysinfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 70, 90, 24));
        lineEdit = new QLineEdit(frm_sysinfo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 70, 330, 34));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(frm_sysinfo);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 120, 330, 34));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(frm_sysinfo);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 180, 330, 34));
        lineEdit_3->setDragEnabled(false);
        lineEdit_3->setReadOnly(true);

        retranslateUi(frm_sysinfo);

        QMetaObject::connectSlotsByName(frm_sysinfo);
    } // setupUi

    void retranslateUi(QWidget *frm_sysinfo)
    {
        frm_sysinfo->setWindowTitle(QApplication::translate("frm_sysinfo", "\347\263\273\347\273\237\344\277\241\346\201\257", 0));
        pbtn_ok->setText(QApplication::translate("frm_sysinfo", "\347\241\256\345\256\232", 0));
        label_2->setText(QApplication::translate("frm_sysinfo", "\347\211\210\346\234\254\345\217\267", 0));
        label->setText(QApplication::translate("frm_sysinfo", "\345\236\213\345\217\267", 0));
        label_3->setText(QApplication::translate("frm_sysinfo", "\350\256\276\345\244\207\345\220\215\347\247\260", 0));
    } // retranslateUi

};

namespace Ui {
    class frm_sysinfo: public Ui_frm_sysinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_SYSINFO_H
