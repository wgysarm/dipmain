/********************************************************************************
** Form generated from reading UI file 'IVFDUiDesign.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IVFDUIDESIGN_H
#define UI_IVFDUIDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IVFDUiDesignClass
{
public:
    QWidget *centralWidget;
    QSplitter *splitter;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_devinfo;
    QPushButton *pushButton;
    QTextBrowser *textBrowser_devinfo;
    QWidget *page_sysinfo;
    QPushButton *pushButton_sysinfo;
    QTextBrowser *textBrowser_sysinfo;
    QWidget *page_hwinfo;
    QPushButton *pushButton_hwinfo;
    QTextBrowser *textBrowser_hwinfo;
    QWidget *page_netinfo;
    QPushButton *pushButton_netread;
    QPushButton *pushButton_netwrite;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_addr;
    QLineEdit *lineEdit_mask;
    QLineEdit *lineEdit_netgate;
    QWidget *page_video;
    QTextBrowser *textBrowser_videoinfo;
    QCheckBox *checkBox_osd;
    QCheckBox *checkBox_detect;
    QPushButton *pushButton_preview;
    QPushButton *pushButton_stopvideo;
    QWidget *page_file;
    QPushButton *pushButton_fileread;
    QPushButton *pushButton_fileupdate;
    QWidget *page_camset;
    QPushButton *pushButton_camset;
    QWidget *page_io;
    QPushButton *pushButton_ioset;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_ioset_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_capture;
    QPushButton *pushButton_close;
    QPushButton *pushButton_uartserv;
    QPushButton *pushButton_mainthread;
    QPushButton *pushButton_test;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IVFDUiDesignClass)
    {
        if (IVFDUiDesignClass->objectName().isEmpty())
            IVFDUiDesignClass->setObjectName(QStringLiteral("IVFDUiDesignClass"));
        IVFDUiDesignClass->resize(1024, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/IMAGES/Image/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        IVFDUiDesignClass->setWindowIcon(icon);
        IVFDUiDesignClass->setStyleSheet(QStringLiteral("background-color: rgb(192, 237, 255);"));
        centralWidget = new QWidget(IVFDUiDesignClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(11);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 20, 1024, 400));
        splitter->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(splitter);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/IMAGES/Image/xray.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/IMAGES/Image/linkurl.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/IMAGES/Image/thurdbird.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/IMAGES/Image/dashcode.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/IMAGES/Image/spaces.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/IMAGES/Image/alertstop2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget);
        __qlistwidgetitem5->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/IMAGES/Image/pages.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget);
        __qlistwidgetitem6->setIcon(icon7);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/IMAGES/Image/stacks.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(listWidget);
        __qlistwidgetitem7->setIcon(icon8);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(100, 192));
        listWidget->setMaximumSize(QSize(131, 400));
        listWidget->setFrameShape(QFrame::HLine);
        listWidget->setLineWidth(0);
        listWidget->setMidLineWidth(1);
        splitter->addWidget(listWidget);
        stackedWidget = new QStackedWidget(splitter);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        page_devinfo = new QWidget();
        page_devinfo->setObjectName(QStringLiteral("page_devinfo"));
        pushButton = new QPushButton(page_devinfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(520, 290, 121, 23));
        textBrowser_devinfo = new QTextBrowser(page_devinfo);
        textBrowser_devinfo->setObjectName(QStringLiteral("textBrowser_devinfo"));
        textBrowser_devinfo->setGeometry(QRect(20, 10, 781, 271));
        stackedWidget->addWidget(page_devinfo);
        page_sysinfo = new QWidget();
        page_sysinfo->setObjectName(QStringLiteral("page_sysinfo"));
        pushButton_sysinfo = new QPushButton(page_sysinfo);
        pushButton_sysinfo->setObjectName(QStringLiteral("pushButton_sysinfo"));
        pushButton_sysinfo->setGeometry(QRect(560, 340, 121, 23));
        textBrowser_sysinfo = new QTextBrowser(page_sysinfo);
        textBrowser_sysinfo->setObjectName(QStringLiteral("textBrowser_sysinfo"));
        textBrowser_sysinfo->setGeometry(QRect(30, 20, 681, 281));
        stackedWidget->addWidget(page_sysinfo);
        page_hwinfo = new QWidget();
        page_hwinfo->setObjectName(QStringLiteral("page_hwinfo"));
        pushButton_hwinfo = new QPushButton(page_hwinfo);
        pushButton_hwinfo->setObjectName(QStringLiteral("pushButton_hwinfo"));
        pushButton_hwinfo->setGeometry(QRect(470, 220, 101, 23));
        textBrowser_hwinfo = new QTextBrowser(page_hwinfo);
        textBrowser_hwinfo->setObjectName(QStringLiteral("textBrowser_hwinfo"));
        textBrowser_hwinfo->setGeometry(QRect(20, 20, 571, 192));
        stackedWidget->addWidget(page_hwinfo);
        page_netinfo = new QWidget();
        page_netinfo->setObjectName(QStringLiteral("page_netinfo"));
        pushButton_netread = new QPushButton(page_netinfo);
        pushButton_netread->setObjectName(QStringLiteral("pushButton_netread"));
        pushButton_netread->setGeometry(QRect(410, 60, 141, 23));
        pushButton_netwrite = new QPushButton(page_netinfo);
        pushButton_netwrite->setObjectName(QStringLiteral("pushButton_netwrite"));
        pushButton_netwrite->setGeometry(QRect(410, 90, 141, 23));
        label_2 = new QLabel(page_netinfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 40, 54, 12));
        label_3 = new QLabel(page_netinfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 70, 54, 16));
        label_4 = new QLabel(page_netinfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 100, 54, 12));
        lineEdit_addr = new QLineEdit(page_netinfo);
        lineEdit_addr->setObjectName(QStringLiteral("lineEdit_addr"));
        lineEdit_addr->setGeometry(QRect(170, 40, 191, 20));
        lineEdit_mask = new QLineEdit(page_netinfo);
        lineEdit_mask->setObjectName(QStringLiteral("lineEdit_mask"));
        lineEdit_mask->setGeometry(QRect(170, 70, 191, 20));
        lineEdit_netgate = new QLineEdit(page_netinfo);
        lineEdit_netgate->setObjectName(QStringLiteral("lineEdit_netgate"));
        lineEdit_netgate->setGeometry(QRect(170, 100, 191, 20));
        stackedWidget->addWidget(page_netinfo);
        page_video = new QWidget();
        page_video->setObjectName(QStringLiteral("page_video"));
        textBrowser_videoinfo = new QTextBrowser(page_video);
        textBrowser_videoinfo->setObjectName(QStringLiteral("textBrowser_videoinfo"));
        textBrowser_videoinfo->setGeometry(QRect(500, 50, 361, 311));
        checkBox_osd = new QCheckBox(page_video);
        checkBox_osd->setObjectName(QStringLiteral("checkBox_osd"));
        checkBox_osd->setGeometry(QRect(300, 360, 71, 16));
        checkBox_detect = new QCheckBox(page_video);
        checkBox_detect->setObjectName(QStringLiteral("checkBox_detect"));
        checkBox_detect->setGeometry(QRect(370, 360, 71, 16));
        pushButton_preview = new QPushButton(page_video);
        pushButton_preview->setObjectName(QStringLiteral("pushButton_preview"));
        pushButton_preview->setGeometry(QRect(180, 360, 80, 23));
        pushButton_stopvideo = new QPushButton(page_video);
        pushButton_stopvideo->setObjectName(QStringLiteral("pushButton_stopvideo"));
        pushButton_stopvideo->setGeometry(QRect(90, 360, 75, 23));
        stackedWidget->addWidget(page_video);
        page_file = new QWidget();
        page_file->setObjectName(QStringLiteral("page_file"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(page_file->sizePolicy().hasHeightForWidth());
        page_file->setSizePolicy(sizePolicy3);
        pushButton_fileread = new QPushButton(page_file);
        pushButton_fileread->setObjectName(QStringLiteral("pushButton_fileread"));
        pushButton_fileread->setGeometry(QRect(60, 150, 75, 23));
        pushButton_fileupdate = new QPushButton(page_file);
        pushButton_fileupdate->setObjectName(QStringLiteral("pushButton_fileupdate"));
        pushButton_fileupdate->setGeometry(QRect(60, 180, 75, 23));
        stackedWidget->addWidget(page_file);
        page_camset = new QWidget();
        page_camset->setObjectName(QStringLiteral("page_camset"));
        pushButton_camset = new QPushButton(page_camset);
        pushButton_camset->setObjectName(QStringLiteral("pushButton_camset"));
        pushButton_camset->setGeometry(QRect(180, 140, 75, 23));
        stackedWidget->addWidget(page_camset);
        page_io = new QWidget();
        page_io->setObjectName(QStringLiteral("page_io"));
        pushButton_ioset = new QPushButton(page_io);
        pushButton_ioset->setObjectName(QStringLiteral("pushButton_ioset"));
        pushButton_ioset->setGeometry(QRect(60, 20, 75, 23));
        pushButton_2 = new QPushButton(page_io);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 90, 80, 23));
        pushButton_3 = new QPushButton(page_io);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 150, 80, 23));
        pushButton_4 = new QPushButton(page_io);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 220, 80, 23));
        pushButton_5 = new QPushButton(page_io);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 280, 80, 23));
        pushButton_6 = new QPushButton(page_io);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(180, 150, 80, 23));
        pushButton_ioset_2 = new QPushButton(page_io);
        pushButton_ioset_2->setObjectName(QStringLiteral("pushButton_ioset_2"));
        pushButton_ioset_2->setGeometry(QRect(180, 20, 75, 23));
        pushButton_9 = new QPushButton(page_io);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(180, 90, 80, 23));
        pushButton_8 = new QPushButton(page_io);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(180, 220, 80, 23));
        pushButton_7 = new QPushButton(page_io);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(180, 280, 80, 23));
        stackedWidget->addWidget(page_io);
        splitter->addWidget(stackedWidget);
        pushButton_capture = new QPushButton(centralWidget);
        pushButton_capture->setObjectName(QStringLiteral("pushButton_capture"));
        pushButton_capture->setGeometry(QRect(350, 480, 80, 23));
        pushButton_close = new QPushButton(centralWidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(460, 480, 101, 23));
        pushButton_uartserv = new QPushButton(centralWidget);
        pushButton_uartserv->setObjectName(QStringLiteral("pushButton_uartserv"));
        pushButton_uartserv->setGeometry(QRect(250, 480, 80, 23));
        pushButton_mainthread = new QPushButton(centralWidget);
        pushButton_mainthread->setObjectName(QStringLiteral("pushButton_mainthread"));
        pushButton_mainthread->setGeometry(QRect(160, 480, 80, 23));
        pushButton_test = new QPushButton(centralWidget);
        pushButton_test->setObjectName(QStringLiteral("pushButton_test"));
        pushButton_test->setGeometry(QRect(160, 440, 80, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(260, 440, 113, 23));
        IVFDUiDesignClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IVFDUiDesignClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 20));
        IVFDUiDesignClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IVFDUiDesignClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        IVFDUiDesignClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(IVFDUiDesignClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IVFDUiDesignClass->setStatusBar(statusBar);

        retranslateUi(IVFDUiDesignClass);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(IVFDUiDesignClass);
    } // setupUi

    void retranslateUi(QMainWindow *IVFDUiDesignClass)
    {
        IVFDUiDesignClass->setWindowTitle(QApplication::translate("IVFDUiDesignClass", "IVFDUiDesign", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("IVFDUiDesignClass", "DEVINFO", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("IVFDUiDesignClass", "SYSINFO", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("IVFDUiDesignClass", "HARDIFO", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("IVFDUiDesignClass", "NETSET", 0));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("IVFDUiDesignClass", "VIDEOCAPTURE", 0));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("IVFDUiDesignClass", "CAMSET", 0));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("IVFDUiDesignClass", "IO TEST", 0));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("IVFDUiDesignClass", "HELP", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("IVFDUiDesignClass", "RESET", 0));
        pushButton_sysinfo->setText(QApplication::translate("IVFDUiDesignClass", "GET SYSTEM INFO", 0));
        pushButton_hwinfo->setText(QApplication::translate("IVFDUiDesignClass", "GET HARD INFO", 0));
        pushButton_netread->setText(QApplication::translate("IVFDUiDesignClass", "READ THE NET", 0));
        pushButton_netwrite->setText(QApplication::translate("IVFDUiDesignClass", "CONFIG NET", 0));
        label_2->setText(QApplication::translate("IVFDUiDesignClass", "ADDRESS", 0));
        label_3->setText(QApplication::translate("IVFDUiDesignClass", "MASK", 0));
        label_4->setText(QApplication::translate("IVFDUiDesignClass", "NETGATE", 0));
        checkBox_osd->setText(QApplication::translate("IVFDUiDesignClass", "OSD", 0));
        checkBox_detect->setText(QApplication::translate("IVFDUiDesignClass", "DETECT", 0));
        pushButton_preview->setText(QApplication::translate("IVFDUiDesignClass", "PREVIEW", 0));
        pushButton_stopvideo->setText(QApplication::translate("IVFDUiDesignClass", "STOP", 0));
        pushButton_fileread->setText(QApplication::translate("IVFDUiDesignClass", "\346\226\207\344\273\266\350\257\273\345\207\272", 0));
        pushButton_fileupdate->setText(QApplication::translate("IVFDUiDesignClass", "\346\226\207\344\273\266\344\270\212\344\274\240", 0));
        pushButton_camset->setText(QApplication::translate("IVFDUiDesignClass", "6", 0));
        pushButton_ioset->setText(QApplication::translate("IVFDUiDesignClass", "LED1 ON", 0));
        pushButton_2->setText(QApplication::translate("IVFDUiDesignClass", "LED2 ON", 0));
        pushButton_3->setText(QApplication::translate("IVFDUiDesignClass", "LED3 ON", 0));
        pushButton_4->setText(QApplication::translate("IVFDUiDesignClass", "RL1 OPEN", 0));
        pushButton_5->setText(QApplication::translate("IVFDUiDesignClass", "RL2 OPEN", 0));
        pushButton_6->setText(QApplication::translate("IVFDUiDesignClass", "LED3 OFF", 0));
        pushButton_ioset_2->setText(QApplication::translate("IVFDUiDesignClass", "LED1 OFF", 0));
        pushButton_9->setText(QApplication::translate("IVFDUiDesignClass", "LED2 OFF", 0));
        pushButton_8->setText(QApplication::translate("IVFDUiDesignClass", "RL1 CLOSE", 0));
        pushButton_7->setText(QApplication::translate("IVFDUiDesignClass", "RL2 CLOSE", 0));
        pushButton_capture->setText(QApplication::translate("IVFDUiDesignClass", "VIDEO CAP", 0));
        pushButton_close->setText(QApplication::translate("IVFDUiDesignClass", "CLOSE", 0));
        pushButton_uartserv->setText(QApplication::translate("IVFDUiDesignClass", "UART SERV", 0));
        pushButton_mainthread->setText(QApplication::translate("IVFDUiDesignClass", "main thread", 0));
        pushButton_test->setText(QApplication::translate("IVFDUiDesignClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class IVFDUiDesignClass: public Ui_IVFDUiDesignClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IVFDUIDESIGN_H
