/********************************************************************************
** Form generated from reading UI file 'frm_managetools.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_MANAGETOOLS_H
#define UI_FRM_MANAGETOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frm_managetools
{
public:
    QFrame *line;
    QToolButton *tbtn_Close;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *tbtn_restore;
    QToolButton *tbtn_systime;
    QToolButton *tbtn_Update;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tbtn_sysparm;
    QToolButton *tbtn_hardmanage;
    QToolButton *tbtn_sysinfo;

    void setupUi(QWidget *frm_managetools)
    {
        if (frm_managetools->objectName().isEmpty())
            frm_managetools->setObjectName(QStringLiteral("frm_managetools"));
        frm_managetools->setWindowModality(Qt::WindowModal);
        frm_managetools->resize(1024, 600);
        frm_managetools->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        line = new QFrame(frm_managetools);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(70, 60, 651, 16));
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::HLine);
        tbtn_Close = new QToolButton(frm_managetools);
        tbtn_Close->setObjectName(QStringLiteral("tbtn_Close"));
        tbtn_Close->setGeometry(QRect(360, 10, 81, 51));
        tbtn_Close->setAutoRaise(true);
        layoutWidget = new QWidget(frm_managetools);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 270, 611, 159));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tbtn_restore = new QToolButton(layoutWidget);
        tbtn_restore->setObjectName(QStringLiteral("tbtn_restore"));
        QFont font;
        font.setFamily(QStringLiteral("WenQuanYi Zen Hei"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tbtn_restore->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/image/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_restore->setIcon(icon);
        tbtn_restore->setIconSize(QSize(128, 128));
        tbtn_restore->setAutoExclusive(false);
        tbtn_restore->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbtn_restore->setAutoRaise(true);

        horizontalLayout->addWidget(tbtn_restore);

        tbtn_systime = new QToolButton(layoutWidget);
        tbtn_systime->setObjectName(QStringLiteral("tbtn_systime"));
        tbtn_systime->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/manangertools/image/navigationmap.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_systime->setIcon(icon1);
        tbtn_systime->setIconSize(QSize(128, 128));
        tbtn_systime->setAutoExclusive(false);
        tbtn_systime->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbtn_systime->setAutoRaise(true);

        horizontalLayout->addWidget(tbtn_systime);

        tbtn_Update = new QToolButton(layoutWidget);
        tbtn_Update->setObjectName(QStringLiteral("tbtn_Update"));
        tbtn_Update->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/manangertools/image/tooldownboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_Update->setIcon(icon2);
        tbtn_Update->setIconSize(QSize(128, 128));
        tbtn_Update->setAutoExclusive(false);
        tbtn_Update->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbtn_Update->setAutoRaise(true);

        horizontalLayout->addWidget(tbtn_Update);

        layoutWidget1 = new QWidget(frm_managetools);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 80, 611, 159));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tbtn_sysparm = new QToolButton(layoutWidget1);
        tbtn_sysparm->setObjectName(QStringLiteral("tbtn_sysparm"));
        tbtn_sysparm->setFont(font);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/manangertools/image/dashcode.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_sysparm->setIcon(icon3);
        tbtn_sysparm->setIconSize(QSize(128, 128));
        tbtn_sysparm->setAutoExclusive(false);
        tbtn_sysparm->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbtn_sysparm->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbtn_sysparm);

        tbtn_hardmanage = new QToolButton(layoutWidget1);
        tbtn_hardmanage->setObjectName(QStringLiteral("tbtn_hardmanage"));
        tbtn_hardmanage->setFont(font);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/manangertools/image/installdrive.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_hardmanage->setIcon(icon4);
        tbtn_hardmanage->setIconSize(QSize(128, 128));
        tbtn_hardmanage->setAutoExclusive(false);
        tbtn_hardmanage->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbtn_hardmanage->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbtn_hardmanage);

        tbtn_sysinfo = new QToolButton(layoutWidget1);
        tbtn_sysinfo->setObjectName(QStringLiteral("tbtn_sysinfo"));
        tbtn_sysinfo->setFont(font);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/manangertools/image/alternote.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_sysinfo->setIcon(icon5);
        tbtn_sysinfo->setIconSize(QSize(128, 128));
        tbtn_sysinfo->setAutoExclusive(false);
        tbtn_sysinfo->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tbtn_sysinfo->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbtn_sysinfo);


        retranslateUi(frm_managetools);
        QObject::connect(tbtn_Close, SIGNAL(clicked()), frm_managetools, SLOT(close()));

        QMetaObject::connectSlotsByName(frm_managetools);
    } // setupUi

    void retranslateUi(QWidget *frm_managetools)
    {
        frm_managetools->setWindowTitle(QApplication::translate("frm_managetools", "\347\256\241\347\220\206\345\267\245\345\205\267", 0));
        tbtn_Close->setText(QApplication::translate("frm_managetools", "\345\205\263\351\227\255", 0));
        tbtn_restore->setText(QApplication::translate("frm_managetools", "\346\201\242\345\244\215\350\256\276\347\275\256", 0));
        tbtn_systime->setText(QApplication::translate("frm_managetools", "\347\263\273\347\273\237\346\227\266\351\227\264", 0));
        tbtn_Update->setText(QApplication::translate("frm_managetools", "\350\275\257\344\273\266\345\215\207\347\272\247", 0));
        tbtn_sysparm->setText(QApplication::translate("frm_managetools", "\347\263\273\347\273\237\345\217\202\346\225\260", 0));
        tbtn_hardmanage->setText(QApplication::translate("frm_managetools", "\347\241\254\347\233\230\347\256\241\347\220\206", 0));
        tbtn_sysinfo->setText(QApplication::translate("frm_managetools", "\347\263\273\347\273\237\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class frm_managetools: public Ui_frm_managetools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_MANAGETOOLS_H
