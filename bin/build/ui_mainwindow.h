/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tbtn_querylog;
    QToolButton *tbtn_Settings;
    QToolButton *tbtn_moveSettings;
    QHBoxLayout *horizontalLayout;
    QToolButton *tbtn_netSettings;
    QToolButton *tbtn_imageSettings;
    QToolButton *tbtn_managetools;
    QPushButton *pushButton_ledAlarm;
    QPushButton *pushButton_ledRunning;
    QPushButton *pushButton_ledError;
    QPushButton *pushButton_setRelay1;
    QPushButton *pushButton_setRelay2;
    QLineEdit *lineEdit_setRelay1;
    QLineEdit *lineEdit_setRelay2;
    QPushButton *pushButton_readRelay1;
    QPushButton *pushButton_readRelay2;
    QLabel *label_relay2;
    QLabel *label_relay1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 600);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(112, 200, 11, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(147, 255, 225, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(113, 227, 195, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(40, 100, 83, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(53, 133, 111, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(167, 227, 210, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush9(QColor(80, 200, 166, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        MainWindow->setMouseTracking(true);
        MainWindow->setFocusPolicy(Qt::WheelFocus);
        MainWindow->setStyleSheet(QLatin1String("font: 12pt \"WenQuanYi Zen Hei\";\n"
"background-color: rgb(112, 200, 11);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush10(QColor(83, 238, 240, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush11(QColor(240, 240, 240, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush11);
        centralwidget->setPalette(palette1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 761, 431));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tbtn_querylog = new QToolButton(layoutWidget);
        tbtn_querylog->setObjectName(QStringLiteral("tbtn_querylog"));
        QFont font;
        font.setFamily(QStringLiteral("WenQuanYi Zen Hei"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setKerning(true);
        tbtn_querylog->setFont(font);
        tbtn_querylog->setCursor(QCursor(Qt::BlankCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/manangertools/image/foudergroup.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_querylog->setIcon(icon);
        tbtn_querylog->setIconSize(QSize(96, 96));
        tbtn_querylog->setAutoExclusive(false);
        tbtn_querylog->setToolButtonStyle(Qt::ToolButtonTextOnly);
        tbtn_querylog->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbtn_querylog);

        tbtn_Settings = new QToolButton(layoutWidget);
        tbtn_Settings->setObjectName(QStringLiteral("tbtn_Settings"));
        QFont font1;
        font1.setFamily(QStringLiteral("WenQuanYi Zen Hei"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        tbtn_Settings->setFont(font1);
        tbtn_Settings->setCursor(QCursor(Qt::BlankCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/image/linkurl.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_Settings->setIcon(icon1);
        tbtn_Settings->setIconSize(QSize(96, 96));
        tbtn_Settings->setAutoExclusive(false);
        tbtn_Settings->setToolButtonStyle(Qt::ToolButtonTextOnly);
        tbtn_Settings->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbtn_Settings);

        tbtn_moveSettings = new QToolButton(layoutWidget);
        tbtn_moveSettings->setObjectName(QStringLiteral("tbtn_moveSettings"));
        QFont font2;
        font2.setFamily(QStringLiteral("WenQuanYi Zen Hei"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        font2.setKerning(false);
        tbtn_moveSettings->setFont(font2);
        tbtn_moveSettings->setCursor(QCursor(Qt::BlankCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/image/imovie.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_moveSettings->setIcon(icon2);
        tbtn_moveSettings->setIconSize(QSize(96, 96));
        tbtn_moveSettings->setAutoExclusive(false);
        tbtn_moveSettings->setToolButtonStyle(Qt::ToolButtonTextOnly);
        tbtn_moveSettings->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbtn_moveSettings);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tbtn_netSettings = new QToolButton(layoutWidget);
        tbtn_netSettings->setObjectName(QStringLiteral("tbtn_netSettings"));
        tbtn_netSettings->setFont(font1);
        tbtn_netSettings->setCursor(QCursor(Qt::BlankCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/image/thurdbird.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_netSettings->setIcon(icon3);
        tbtn_netSettings->setIconSize(QSize(96, 96));
        tbtn_netSettings->setAutoExclusive(false);
        tbtn_netSettings->setToolButtonStyle(Qt::ToolButtonTextOnly);
        tbtn_netSettings->setAutoRaise(true);

        horizontalLayout->addWidget(tbtn_netSettings);

        tbtn_imageSettings = new QToolButton(layoutWidget);
        tbtn_imageSettings->setObjectName(QStringLiteral("tbtn_imageSettings"));
        tbtn_imageSettings->setFont(font1);
        tbtn_imageSettings->setCursor(QCursor(Qt::BlankCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/image/preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_imageSettings->setIcon(icon4);
        tbtn_imageSettings->setIconSize(QSize(96, 96));
        tbtn_imageSettings->setAutoExclusive(false);
        tbtn_imageSettings->setToolButtonStyle(Qt::ToolButtonTextOnly);
        tbtn_imageSettings->setAutoRaise(true);

        horizontalLayout->addWidget(tbtn_imageSettings);

        tbtn_managetools = new QToolButton(layoutWidget);
        tbtn_managetools->setObjectName(QStringLiteral("tbtn_managetools"));
        tbtn_managetools->setFont(font1);
        tbtn_managetools->setCursor(QCursor(Qt::BlankCursor));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/manangertools/image/spaces.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtn_managetools->setIcon(icon5);
        tbtn_managetools->setIconSize(QSize(96, 96));
        tbtn_managetools->setAutoExclusive(false);
        tbtn_managetools->setToolButtonStyle(Qt::ToolButtonTextOnly);
        tbtn_managetools->setAutoRaise(true);

        horizontalLayout->addWidget(tbtn_managetools);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_ledAlarm = new QPushButton(centralwidget);
        pushButton_ledAlarm->setObjectName(QStringLiteral("pushButton_ledAlarm"));
        pushButton_ledAlarm->setGeometry(QRect(808, 20, 111, 27));
        pushButton_ledRunning = new QPushButton(centralwidget);
        pushButton_ledRunning->setObjectName(QStringLiteral("pushButton_ledRunning"));
        pushButton_ledRunning->setGeometry(QRect(810, 70, 111, 27));
        pushButton_ledError = new QPushButton(centralwidget);
        pushButton_ledError->setObjectName(QStringLiteral("pushButton_ledError"));
        pushButton_ledError->setGeometry(QRect(810, 120, 111, 27));
        pushButton_setRelay1 = new QPushButton(centralwidget);
        pushButton_setRelay1->setObjectName(QStringLiteral("pushButton_setRelay1"));
        pushButton_setRelay1->setGeometry(QRect(810, 170, 111, 27));
        pushButton_setRelay2 = new QPushButton(centralwidget);
        pushButton_setRelay2->setObjectName(QStringLiteral("pushButton_setRelay2"));
        pushButton_setRelay2->setGeometry(QRect(810, 220, 111, 27));
        lineEdit_setRelay1 = new QLineEdit(centralwidget);
        lineEdit_setRelay1->setObjectName(QStringLiteral("lineEdit_setRelay1"));
        lineEdit_setRelay1->setGeometry(QRect(930, 170, 61, 27));
        lineEdit_setRelay1->setAutoFillBackground(false);
        lineEdit_setRelay1->setStyleSheet(QStringLiteral("background-color: rgb(234, 234, 234);"));
        lineEdit_setRelay2 = new QLineEdit(centralwidget);
        lineEdit_setRelay2->setObjectName(QStringLiteral("lineEdit_setRelay2"));
        lineEdit_setRelay2->setGeometry(QRect(930, 220, 61, 27));
        lineEdit_setRelay2->setAutoFillBackground(false);
        lineEdit_setRelay2->setStyleSheet(QStringLiteral("background-color: rgb(234, 234, 234);"));
        pushButton_readRelay1 = new QPushButton(centralwidget);
        pushButton_readRelay1->setObjectName(QStringLiteral("pushButton_readRelay1"));
        pushButton_readRelay1->setGeometry(QRect(810, 270, 111, 27));
        pushButton_readRelay2 = new QPushButton(centralwidget);
        pushButton_readRelay2->setObjectName(QStringLiteral("pushButton_readRelay2"));
        pushButton_readRelay2->setGeometry(QRect(810, 310, 111, 27));
        label_relay2 = new QLabel(centralwidget);
        label_relay2->setObjectName(QStringLiteral("label_relay2"));
        label_relay2->setGeometry(QRect(930, 310, 67, 21));
        label_relay2->setStyleSheet(QStringLiteral("background-color: rgb(254, 228, 228);"));
        label_relay1 = new QLabel(centralwidget);
        label_relay1->setObjectName(QStringLiteral("label_relay1"));
        label_relay1->setGeometry(QRect(930, 270, 67, 21));
        label_relay1->setStyleSheet(QStringLiteral("background-color: rgb(254, 228, 228);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DVR\347\256\241\347\220\206", 0));
        tbtn_querylog->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\347\256\241\347\220\206", 0));
        tbtn_Settings->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        tbtn_moveSettings->setText(QApplication::translate("MainWindow", "\345\252\222\344\275\223\346\222\255\346\224\276", 0));
        tbtn_netSettings->setText(QApplication::translate("MainWindow", "\347\275\221\347\273\234\350\256\276\347\275\256", 0));
        tbtn_imageSettings->setText(QApplication::translate("MainWindow", "capture", 0));
        tbtn_managetools->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\267\245\345\205\267", 0));
        pushButton_ledAlarm->setText(QApplication::translate("MainWindow", "\345\252\222\344\275\223\346\222\255\346\224\276", 0));
        pushButton_ledRunning->setText(QApplication::translate("MainWindow", "LED \347\201\257", 0));
        pushButton_ledError->setText(QApplication::translate("MainWindow", "LED ERROR", 0));
        pushButton_setRelay1->setText(QApplication::translate("MainWindow", "SET RELAY1", 0));
        pushButton_setRelay2->setText(QApplication::translate("MainWindow", "SET RELAY2", 0));
        lineEdit_setRelay2->setText(QString());
        pushButton_readRelay1->setText(QApplication::translate("MainWindow", "Read RELAY1", 0));
        pushButton_readRelay2->setText(QApplication::translate("MainWindow", "Read RELAY2", 0));
        label_relay2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_relay1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
