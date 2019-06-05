/********************************************************************************
** Form generated from reading UI file 'frm_Update.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_UPDATE_H
#define UI_FRM_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frm_Update
{
public:
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLabel *label_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *frm_Update)
    {
        if (frm_Update->objectName().isEmpty())
            frm_Update->setObjectName(QStringLiteral("frm_Update"));
        frm_Update->resize(400, 300);
        frm_Update->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        label_3 = new QLabel(frm_Update);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 92, 140, 52));
        lineEdit_4 = new QLineEdit(frm_Update);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(172, 163, 191, 34));
        lineEdit_4->setMaxLength(30);
        lineEdit_4->setEchoMode(QLineEdit::Normal);
        label_4 = new QLabel(frm_Update);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 154, 140, 53));
        label_2 = new QLabel(frm_Update);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 40, 140, 53));
        comboBox = new QComboBox(frm_Update);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 40, 190, 37));
        comboBox_2 = new QComboBox(frm_Update);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(170, 100, 190, 37));
        buttonBox = new QDialogButtonBox(frm_Update);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(130, 240, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(frm_Update);

        QMetaObject::connectSlotsByName(frm_Update);
    } // setupUi

    void retranslateUi(QWidget *frm_Update)
    {
        frm_Update->setWindowTitle(QApplication::translate("frm_Update", "\347\263\273\347\273\237\345\215\207\347\272\247", 0));
        label_3->setText(QApplication::translate("frm_Update", "\345\215\207\347\272\247\346\226\271\345\274\217", 0));
        lineEdit_4->setText(QString());
        label_4->setText(QApplication::translate("frm_Update", "\345\215\207\347\272\247\346\226\207\344\273\266\350\267\257\345\276\204", 0));
        label_2->setText(QApplication::translate("frm_Update", "\345\215\207\347\272\247\347\261\273\345\236\213", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("frm_Update", "\346\211\200\346\234\211", 0)
         << QApplication::translate("frm_Update", "\345\272\224\347\224\250", 0)
         << QApplication::translate("frm_Update", "\345\206\205\346\240\270", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("frm_Update", "U\347\233\230", 0)
         << QApplication::translate("frm_Update", "SD\345\215\2411", 0)
         << QApplication::translate("frm_Update", "SD\345\215\2412", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class frm_Update: public Ui_frm_Update {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_UPDATE_H
