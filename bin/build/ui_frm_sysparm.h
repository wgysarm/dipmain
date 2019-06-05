/********************************************************************************
** Form generated from reading UI file 'frm_sysparm.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_SYSPARM_H
#define UI_FRM_SYSPARM_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pbtn_ok;
    QPushButton *pbtn_close;
    QFrame *line;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *edt_num;
    QLineEdit *edt_name;
    QComboBox *cb_timeout;
    QComboBox *cb_videoMode;
    QComboBox *cb_VGArate;
    QComboBox *cb_language;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_10;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->setWindowModality(Qt::WindowModal);
        Form->resize(431, 480);
        QFont font;
        font.setFamily(QStringLiteral("WenQuanYi Zen Hei"));
        font.setPointSize(12);
        Form->setFont(font);
        Form->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        pbtn_ok = new QPushButton(Form);
        pbtn_ok->setObjectName(QStringLiteral("pbtn_ok"));
        pbtn_ok->setGeometry(QRect(120, 430, 100, 36));
        pbtn_ok->setFont(font);
        pbtn_close = new QPushButton(Form);
        pbtn_close->setObjectName(QStringLiteral("pbtn_close"));
        pbtn_close->setGeometry(QRect(250, 430, 100, 36));
        pbtn_close->setFont(font);
        line = new QFrame(Form);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 410, 381, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 30, 241, 340));
        layoutWidget->setFont(font);
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        edt_num = new QLineEdit(layoutWidget);
        edt_num->setObjectName(QStringLiteral("edt_num"));
        edt_num->setFont(font);

        verticalLayout->addWidget(edt_num);

        edt_name = new QLineEdit(layoutWidget);
        edt_name->setObjectName(QStringLiteral("edt_name"));
        edt_name->setFont(font);

        verticalLayout->addWidget(edt_name);

        cb_timeout = new QComboBox(layoutWidget);
        cb_timeout->setObjectName(QStringLiteral("cb_timeout"));
        cb_timeout->setFont(font);
        cb_timeout->setMouseTracking(true);
        cb_timeout->setAcceptDrops(true);

        verticalLayout->addWidget(cb_timeout);

        cb_videoMode = new QComboBox(layoutWidget);
        cb_videoMode->setObjectName(QStringLiteral("cb_videoMode"));
        cb_videoMode->setFont(font);

        verticalLayout->addWidget(cb_videoMode);

        cb_VGArate = new QComboBox(layoutWidget);
        cb_VGArate->setObjectName(QStringLiteral("cb_VGArate"));
        cb_VGArate->setFont(font);

        verticalLayout->addWidget(cb_VGArate);

        cb_language = new QComboBox(layoutWidget);
        cb_language->setObjectName(QStringLiteral("cb_language"));
        cb_language->setFont(font);

        verticalLayout->addWidget(cb_language);

        layoutWidget1 = new QWidget(Form);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 40, 121, 311));
        layoutWidget1->setFont(font);
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout_2->addWidget(label_7);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        verticalLayout_2->addWidget(label_10);


        retranslateUi(Form);
        QObject::connect(pbtn_close, SIGNAL(clicked()), Form, SLOT(close()));
        QObject::connect(pbtn_ok, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "\347\263\273\347\273\237\345\217\202\346\225\260", 0));
        pbtn_ok->setText(QApplication::translate("Form", "\347\241\256\345\256\232", 0));
        pbtn_close->setText(QApplication::translate("Form", "\345\217\226\346\266\210", 0));
        edt_name->setText(QString());
        cb_timeout->clear();
        cb_timeout->insertItems(0, QStringList()
         << QApplication::translate("Form", "\350\246\206\347\233\226", 0)
         << QApplication::translate("Form", "\345\201\234\346\255\242", 0)
        );
        cb_videoMode->clear();
        cb_videoMode->insertItems(0, QStringList()
         << QApplication::translate("Form", "PAL", 0)
         << QApplication::translate("Form", "NTSC", 0)
        );
        cb_VGArate->clear();
        cb_VGArate->insertItems(0, QStringList()
         << QApplication::translate("Form", "1024X768/60HZ", 0)
         << QApplication::translate("Form", "800X480/60HZ", 0)
        );
        cb_language->clear();
        cb_language->insertItems(0, QStringList()
         << QApplication::translate("Form", "\347\256\200\344\275\223\344\270\255\346\226\207", 0)
        );
        label->setText(QApplication::translate("Form", "\350\256\276\345\244\207\345\217\267", 0));
        label_2->setText(QApplication::translate("Form", "\350\256\276\345\244\207\345\220\215\347\247\260", 0));
        label_3->setText(QApplication::translate("Form", "\350\256\276\345\244\207\346\273\241\346\227\266", 0));
        label_6->setText(QApplication::translate("Form", "\350\247\206\351\242\221\345\210\266\345\274\217", 0));
        label_7->setText(QApplication::translate("Form", "VGA\345\210\206\350\276\250\347\216\207", 0));
        label_10->setText(QApplication::translate("Form", "\350\257\255\350\250\200", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_SYSPARM_H
