/********************************************************************************
** Form generated from reading UI file 'frm_driveSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_DRIVESETTINGS_H
#define UI_FRM_DRIVESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frm_driver
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *edt_capacity;
    QLineEdit *edt_remain;
    QLineEdit *edt_format;
    QFrame *line;
    QSplitter *splitter;
    QPushButton *pbtn_ok;
    QPushButton *pushButton;
    QPushButton *pbtn_close;

    void setupUi(QWidget *frm_driver)
    {
        if (frm_driver->objectName().isEmpty())
            frm_driver->setObjectName(QStringLiteral("frm_driver"));
        frm_driver->setWindowModality(Qt::WindowModal);
        frm_driver->resize(522, 229);
        frm_driver->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        label = new QLabel(frm_driver);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 91, 24));
        label_2 = new QLabel(frm_driver);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 110, 91, 24));
        label_3 = new QLabel(frm_driver);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 80, 70, 24));
        comboBox = new QComboBox(frm_driver);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 30, 291, 37));
        label_5 = new QLabel(frm_driver);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 80, 101, 24));
        label_7 = new QLabel(frm_driver);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(400, 80, 70, 24));
        edt_capacity = new QLineEdit(frm_driver);
        edt_capacity->setObjectName(QStringLiteral("edt_capacity"));
        edt_capacity->setGeometry(QRect(120, 110, 113, 34));
        edt_capacity->setAlignment(Qt::AlignCenter);
        edt_capacity->setReadOnly(true);
        edt_remain = new QLineEdit(frm_driver);
        edt_remain->setObjectName(QStringLiteral("edt_remain"));
        edt_remain->setGeometry(QRect(250, 110, 113, 34));
        edt_remain->setAlignment(Qt::AlignCenter);
        edt_remain->setReadOnly(true);
        edt_format = new QLineEdit(frm_driver);
        edt_format->setObjectName(QStringLiteral("edt_format"));
        edt_format->setGeometry(QRect(380, 110, 113, 34));
        edt_format->setAlignment(Qt::AlignCenter);
        edt_format->setReadOnly(true);
        line = new QFrame(frm_driver);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 160, 491, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        splitter = new QSplitter(frm_driver);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(100, 180, 341, 31));
        splitter->setOrientation(Qt::Horizontal);
        pbtn_ok = new QPushButton(splitter);
        pbtn_ok->setObjectName(QStringLiteral("pbtn_ok"));
        QFont font;
        font.setFamily(QStringLiteral("WenQuanYi Zen Hei"));
        font.setPointSize(12);
        pbtn_ok->setFont(font);
        splitter->addWidget(pbtn_ok);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        splitter->addWidget(pushButton);
        pbtn_close = new QPushButton(splitter);
        pbtn_close->setObjectName(QStringLiteral("pbtn_close"));
        pbtn_close->setFont(font);
        splitter->addWidget(pbtn_close);

        retranslateUi(frm_driver);
        QObject::connect(pbtn_close, SIGNAL(clicked()), frm_driver, SLOT(close()));
        QObject::connect(pbtn_ok, SIGNAL(clicked()), frm_driver, SLOT(close()));

        QMetaObject::connectSlotsByName(frm_driver);
    } // setupUi

    void retranslateUi(QWidget *frm_driver)
    {
        frm_driver->setWindowTitle(QApplication::translate("frm_driver", "\347\243\201\347\233\230\347\256\241\347\220\206", 0));
        label->setText(QApplication::translate("frm_driver", "\347\243\201\347\233\230\351\200\211\346\213\251", 0));
        label_2->setText(QApplication::translate("frm_driver", "\347\243\201\347\233\230\344\277\241\346\201\257", 0));
        label_3->setText(QApplication::translate("frm_driver", "\345\256\271\351\207\217", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("frm_driver", "\345\206\205\351\203\250flash", 0)
         << QApplication::translate("frm_driver", "\345\244\226\351\203\250SD1", 0)
         << QApplication::translate("frm_driver", "\345\244\226\351\203\250SD2", 0)
        );
        label_5->setText(QApplication::translate("frm_driver", "\345\211\251\344\275\231\347\251\272\351\227\264", 0));
        label_7->setText(QApplication::translate("frm_driver", "\346\240\274\345\274\217\345\214\226", 0));
        edt_capacity->setText(QApplication::translate("frm_driver", "0M", 0));
        edt_remain->setText(QApplication::translate("frm_driver", "0M", 0));
        edt_format->setText(QApplication::translate("frm_driver", "\346\230\257", 0));
        pbtn_ok->setText(QApplication::translate("frm_driver", "\346\240\274\345\274\217\345\214\226", 0));
        pushButton->setText(QApplication::translate("frm_driver", "\347\241\256\345\256\232", 0));
        pbtn_close->setText(QApplication::translate("frm_driver", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class frm_driver: public Ui_frm_driver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_DRIVESETTINGS_H
