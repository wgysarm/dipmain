/********************************************************************************
** Form generated from reading UI file 'frm_restore.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_RESTORE_H
#define UI_FRM_RESTORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lb1_info;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::WindowModal);
        Dialog->resize(390, 137);
        Dialog->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        Dialog->setModal(true);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 80, 341, 51));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lb1_info = new QLabel(Dialog);
        lb1_info->setObjectName(QStringLiteral("lb1_info"));
        lb1_info->setGeometry(QRect(50, 30, 281, 24));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\346\201\242\345\244\215\345\207\272\345\216\202\350\256\276\347\275\256", 0));
        lb1_info->setText(QApplication::translate("Dialog", "\346\230\257\345\220\246\347\241\256\345\256\232\346\201\242\345\244\215\345\207\272\345\216\202\350\256\276\347\275\256\357\274\237", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_RESTORE_H
