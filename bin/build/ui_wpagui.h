/********************************************************************************
** Form generated from reading UI file 'wpagui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WPAGUI_H
#define UI_WPAGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <QtCore/QSocketNotifier>
#include <QtCore/QTimer>
#include "eventhistory.h"
#include "peers.h"
#include "scanresults.h"
#include "wpamsg.h"

QT_BEGIN_NAMESPACE

class Ui_WpaGui
{
public:
    QAction *fileEventHistoryAction;
    QAction *fileSaveConfigAction;
    QAction *networkAddAction;
    QAction *networkEditAction;
    QAction *networkRemoveAction;
    QAction *networkEnableAllAction;
    QAction *networkDisableAllAction;
    QAction *networkRemoveAllAction;
    QAction *helpContentsAction;
    QAction *helpIndexAction;
    QAction *helpAboutAction;
    QAction *actionWPS;
    QAction *actionPeers;
    QAction *actionExit;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *adapterLabel;
    QComboBox *adapterSelect;
    QLabel *networkLabel;
    QComboBox *networkSelect;
    QTabWidget *wpaguiTab;
    QWidget *statusTab;
    QGridLayout *gridLayout1;
    QFrame *frame3;
    QGridLayout *gridLayout2;
    QLabel *statusLabel;
    QLabel *lastMessageLabel;
    QLabel *authenticationLabel;
    QLabel *encryptionLabel;
    QLabel *ssidLabel;
    QLabel *bssidLabel;
    QLabel *ipAddressLabel;
    QLabel *textStatus;
    QLabel *textLastMessage;
    QLabel *textAuthentication;
    QLabel *textEncryption;
    QLabel *textSsid;
    QLabel *textBssid;
    QLabel *textIpAddress;
    QSpacerItem *spacerItem;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QPushButton *scanButton;
    QSpacerItem *spacerItem1;
    QWidget *networkconfigTab;
    QGridLayout *gridLayout3;
    QListWidget *networkList;
    QSpacerItem *spacerItem2;
    QRadioButton *enableRadioButton;
    QPushButton *editNetworkButton;
    QPushButton *removeNetworkButton;
    QSpacerItem *spacerItem3;
    QRadioButton *disableRadioButton;
    QPushButton *addNetworkButton;
    QPushButton *scanNetworkButton;
    QWidget *wpsTab;
    QGridLayout *wpsGridLayout;
    QLabel *label_2;
    QLabel *wpsStatusText;
    QPushButton *wpsPbcButton;
    QPushButton *wpsPinButton;
    QLabel *label;
    QLineEdit *wpsPinEdit;
    QPushButton *wpsApPinButton;
    QLabel *label_3;
    QLineEdit *wpsApPinEdit;
    QTextEdit *wpsInstructions;
    QMenuBar *MenuBar;
    QMenu *fileMenu;
    QMenu *networkMenu;
    QMenu *helpMenu;

    void setupUi(QMainWindow *WpaGui)
    {
        if (WpaGui->objectName().isEmpty())
            WpaGui->setObjectName(QStringLiteral("WpaGui"));
        WpaGui->resize(800, 480);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/wpa_gui.svg"), QSize(), QIcon::Normal, QIcon::Off);
        WpaGui->setWindowIcon(icon);
        WpaGui->setStyleSheet(QStringLiteral("background-color: rgb(112, 200, 11);"));
        fileEventHistoryAction = new QAction(WpaGui);
        fileEventHistoryAction->setObjectName(QStringLiteral("fileEventHistoryAction"));
        fileSaveConfigAction = new QAction(WpaGui);
        fileSaveConfigAction->setObjectName(QStringLiteral("fileSaveConfigAction"));
        networkAddAction = new QAction(WpaGui);
        networkAddAction->setObjectName(QStringLiteral("networkAddAction"));
        networkEditAction = new QAction(WpaGui);
        networkEditAction->setObjectName(QStringLiteral("networkEditAction"));
        networkRemoveAction = new QAction(WpaGui);
        networkRemoveAction->setObjectName(QStringLiteral("networkRemoveAction"));
        networkEnableAllAction = new QAction(WpaGui);
        networkEnableAllAction->setObjectName(QStringLiteral("networkEnableAllAction"));
        networkDisableAllAction = new QAction(WpaGui);
        networkDisableAllAction->setObjectName(QStringLiteral("networkDisableAllAction"));
        networkRemoveAllAction = new QAction(WpaGui);
        networkRemoveAllAction->setObjectName(QStringLiteral("networkRemoveAllAction"));
        helpContentsAction = new QAction(WpaGui);
        helpContentsAction->setObjectName(QStringLiteral("helpContentsAction"));
        helpContentsAction->setEnabled(false);
        helpIndexAction = new QAction(WpaGui);
        helpIndexAction->setObjectName(QStringLiteral("helpIndexAction"));
        helpIndexAction->setEnabled(false);
        helpAboutAction = new QAction(WpaGui);
        helpAboutAction->setObjectName(QStringLiteral("helpAboutAction"));
        actionWPS = new QAction(WpaGui);
        actionWPS->setObjectName(QStringLiteral("actionWPS"));
        actionWPS->setEnabled(false);
        actionPeers = new QAction(WpaGui);
        actionPeers->setObjectName(QStringLiteral("actionPeers"));
        actionExit = new QAction(WpaGui);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        widget = new QWidget(WpaGui);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        adapterLabel = new QLabel(widget);
        adapterLabel->setObjectName(QStringLiteral("adapterLabel"));

        gridLayout->addWidget(adapterLabel, 0, 0, 1, 1);

        adapterSelect = new QComboBox(widget);
        adapterSelect->setObjectName(QStringLiteral("adapterSelect"));

        gridLayout->addWidget(adapterSelect, 0, 1, 1, 1);

        networkLabel = new QLabel(widget);
        networkLabel->setObjectName(QStringLiteral("networkLabel"));

        gridLayout->addWidget(networkLabel, 1, 0, 1, 1);

        networkSelect = new QComboBox(widget);
        networkSelect->setObjectName(QStringLiteral("networkSelect"));

        gridLayout->addWidget(networkSelect, 1, 1, 1, 1);

        wpaguiTab = new QTabWidget(widget);
        wpaguiTab->setObjectName(QStringLiteral("wpaguiTab"));
        statusTab = new QWidget();
        statusTab->setObjectName(QStringLiteral("statusTab"));
        gridLayout1 = new QGridLayout(statusTab);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        frame3 = new QFrame(statusTab);
        frame3->setObjectName(QStringLiteral("frame3"));
        frame3->setFrameShape(QFrame::NoFrame);
        frame3->setFrameShadow(QFrame::Plain);
        gridLayout2 = new QGridLayout(frame3);
        gridLayout2->setSpacing(6);
        gridLayout2->setContentsMargins(11, 11, 11, 11);
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        statusLabel = new QLabel(frame3);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        gridLayout2->addWidget(statusLabel, 0, 0, 1, 1);

        lastMessageLabel = new QLabel(frame3);
        lastMessageLabel->setObjectName(QStringLiteral("lastMessageLabel"));

        gridLayout2->addWidget(lastMessageLabel, 1, 0, 1, 1);

        authenticationLabel = new QLabel(frame3);
        authenticationLabel->setObjectName(QStringLiteral("authenticationLabel"));

        gridLayout2->addWidget(authenticationLabel, 2, 0, 1, 1);

        encryptionLabel = new QLabel(frame3);
        encryptionLabel->setObjectName(QStringLiteral("encryptionLabel"));

        gridLayout2->addWidget(encryptionLabel, 3, 0, 1, 1);

        ssidLabel = new QLabel(frame3);
        ssidLabel->setObjectName(QStringLiteral("ssidLabel"));

        gridLayout2->addWidget(ssidLabel, 4, 0, 1, 1);

        bssidLabel = new QLabel(frame3);
        bssidLabel->setObjectName(QStringLiteral("bssidLabel"));

        gridLayout2->addWidget(bssidLabel, 5, 0, 1, 1);

        ipAddressLabel = new QLabel(frame3);
        ipAddressLabel->setObjectName(QStringLiteral("ipAddressLabel"));

        gridLayout2->addWidget(ipAddressLabel, 6, 0, 1, 1);

        textStatus = new QLabel(frame3);
        textStatus->setObjectName(QStringLiteral("textStatus"));

        gridLayout2->addWidget(textStatus, 0, 1, 1, 1);

        textLastMessage = new QLabel(frame3);
        textLastMessage->setObjectName(QStringLiteral("textLastMessage"));

        gridLayout2->addWidget(textLastMessage, 1, 1, 1, 3);

        textAuthentication = new QLabel(frame3);
        textAuthentication->setObjectName(QStringLiteral("textAuthentication"));

        gridLayout2->addWidget(textAuthentication, 2, 1, 1, 1);

        textEncryption = new QLabel(frame3);
        textEncryption->setObjectName(QStringLiteral("textEncryption"));

        gridLayout2->addWidget(textEncryption, 3, 1, 1, 1);

        textSsid = new QLabel(frame3);
        textSsid->setObjectName(QStringLiteral("textSsid"));

        gridLayout2->addWidget(textSsid, 4, 1, 1, 1);

        textBssid = new QLabel(frame3);
        textBssid->setObjectName(QStringLiteral("textBssid"));

        gridLayout2->addWidget(textBssid, 5, 1, 1, 1);

        textIpAddress = new QLabel(frame3);
        textIpAddress->setObjectName(QStringLiteral("textIpAddress"));

        gridLayout2->addWidget(textIpAddress, 6, 1, 1, 1);


        gridLayout1->addWidget(frame3, 0, 0, 1, 5);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem, 1, 0, 1, 1);

        connectButton = new QPushButton(statusTab);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        gridLayout1->addWidget(connectButton, 1, 1, 1, 1);

        disconnectButton = new QPushButton(statusTab);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));

        gridLayout1->addWidget(disconnectButton, 1, 2, 1, 1);

        scanButton = new QPushButton(statusTab);
        scanButton->setObjectName(QStringLiteral("scanButton"));

        gridLayout1->addWidget(scanButton, 1, 3, 1, 1);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem1, 1, 4, 1, 1);

        wpaguiTab->addTab(statusTab, QString());
        networkconfigTab = new QWidget();
        networkconfigTab->setObjectName(QStringLiteral("networkconfigTab"));
        gridLayout3 = new QGridLayout(networkconfigTab);
        gridLayout3->setSpacing(6);
        gridLayout3->setContentsMargins(11, 11, 11, 11);
        gridLayout3->setObjectName(QStringLiteral("gridLayout3"));
        networkList = new QListWidget(networkconfigTab);
        networkList->setObjectName(QStringLiteral("networkList"));
        networkList->setSelectionRectVisible(true);

        gridLayout3->addWidget(networkList, 0, 0, 1, 5);

        spacerItem2 = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout3->addItem(spacerItem2, 1, 0, 2, 1);

        enableRadioButton = new QRadioButton(networkconfigTab);
        enableRadioButton->setObjectName(QStringLiteral("enableRadioButton"));

        gridLayout3->addWidget(enableRadioButton, 1, 1, 1, 1);

        editNetworkButton = new QPushButton(networkconfigTab);
        editNetworkButton->setObjectName(QStringLiteral("editNetworkButton"));

        gridLayout3->addWidget(editNetworkButton, 1, 2, 1, 1);

        removeNetworkButton = new QPushButton(networkconfigTab);
        removeNetworkButton->setObjectName(QStringLiteral("removeNetworkButton"));

        gridLayout3->addWidget(removeNetworkButton, 1, 3, 1, 1);

        spacerItem3 = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout3->addItem(spacerItem3, 1, 4, 2, 1);

        disableRadioButton = new QRadioButton(networkconfigTab);
        disableRadioButton->setObjectName(QStringLiteral("disableRadioButton"));

        gridLayout3->addWidget(disableRadioButton, 2, 1, 1, 1);

        addNetworkButton = new QPushButton(networkconfigTab);
        addNetworkButton->setObjectName(QStringLiteral("addNetworkButton"));

        gridLayout3->addWidget(addNetworkButton, 2, 2, 1, 1);

        scanNetworkButton = new QPushButton(networkconfigTab);
        scanNetworkButton->setObjectName(QStringLiteral("scanNetworkButton"));

        gridLayout3->addWidget(scanNetworkButton, 2, 3, 1, 1);

        wpaguiTab->addTab(networkconfigTab, QString());
        wpsTab = new QWidget();
        wpsTab->setObjectName(QStringLiteral("wpsTab"));
        wpsGridLayout = new QGridLayout(wpsTab);
        wpsGridLayout->setSpacing(6);
        wpsGridLayout->setContentsMargins(11, 11, 11, 11);
        wpsGridLayout->setObjectName(QStringLiteral("wpsGridLayout"));
        label_2 = new QLabel(wpsTab);
        label_2->setObjectName(QStringLiteral("label_2"));

        wpsGridLayout->addWidget(label_2, 0, 0, 1, 1);

        wpsStatusText = new QLabel(wpsTab);
        wpsStatusText->setObjectName(QStringLiteral("wpsStatusText"));

        wpsGridLayout->addWidget(wpsStatusText, 0, 1, 1, 3);

        wpsPbcButton = new QPushButton(wpsTab);
        wpsPbcButton->setObjectName(QStringLiteral("wpsPbcButton"));

        wpsGridLayout->addWidget(wpsPbcButton, 1, 0, 1, 2);

        wpsPinButton = new QPushButton(wpsTab);
        wpsPinButton->setObjectName(QStringLiteral("wpsPinButton"));

        wpsGridLayout->addWidget(wpsPinButton, 2, 0, 1, 2);

        label = new QLabel(wpsTab);
        label->setObjectName(QStringLiteral("label"));

        wpsGridLayout->addWidget(label, 2, 2, 1, 1);

        wpsPinEdit = new QLineEdit(wpsTab);
        wpsPinEdit->setObjectName(QStringLiteral("wpsPinEdit"));
        wpsPinEdit->setEnabled(false);
        wpsPinEdit->setReadOnly(true);

        wpsGridLayout->addWidget(wpsPinEdit, 2, 3, 1, 1);

        wpsApPinButton = new QPushButton(wpsTab);
        wpsApPinButton->setObjectName(QStringLiteral("wpsApPinButton"));
        wpsApPinButton->setEnabled(false);

        wpsGridLayout->addWidget(wpsApPinButton, 3, 0, 1, 2);

        label_3 = new QLabel(wpsTab);
        label_3->setObjectName(QStringLiteral("label_3"));

        wpsGridLayout->addWidget(label_3, 3, 2, 1, 1);

        wpsApPinEdit = new QLineEdit(wpsTab);
        wpsApPinEdit->setObjectName(QStringLiteral("wpsApPinEdit"));
        wpsApPinEdit->setEnabled(false);

        wpsGridLayout->addWidget(wpsApPinEdit, 3, 3, 1, 1);

        wpsInstructions = new QTextEdit(wpsTab);
        wpsInstructions->setObjectName(QStringLiteral("wpsInstructions"));
        wpsInstructions->setReadOnly(true);

        wpsGridLayout->addWidget(wpsInstructions, 4, 0, 1, 4);

        wpaguiTab->addTab(wpsTab, QString());

        gridLayout->addWidget(wpaguiTab, 2, 0, 1, 2);

        WpaGui->setCentralWidget(widget);
        MenuBar = new QMenuBar(WpaGui);
        MenuBar->setObjectName(QStringLiteral("MenuBar"));
        MenuBar->setGeometry(QRect(0, 0, 800, 23));
        fileMenu = new QMenu(MenuBar);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        networkMenu = new QMenu(MenuBar);
        networkMenu->setObjectName(QStringLiteral("networkMenu"));
        helpMenu = new QMenu(MenuBar);
        helpMenu->setObjectName(QStringLiteral("helpMenu"));
        WpaGui->setMenuBar(MenuBar);

        MenuBar->addAction(fileMenu->menuAction());
        MenuBar->addAction(networkMenu->menuAction());
        MenuBar->addAction(helpMenu->menuAction());
        fileMenu->addAction(fileSaveConfigAction);
        fileMenu->addAction(actionWPS);
        fileMenu->addSeparator();
        fileMenu->addAction(actionExit);
        networkMenu->addAction(networkAddAction);
        networkMenu->addAction(networkEditAction);
        networkMenu->addAction(networkRemoveAction);
        networkMenu->addSeparator();
        networkMenu->addAction(networkEnableAllAction);
        networkMenu->addAction(networkDisableAllAction);
        networkMenu->addAction(networkRemoveAllAction);
        helpMenu->addAction(helpContentsAction);
        helpMenu->addAction(helpIndexAction);
        helpMenu->addSeparator();
        helpMenu->addAction(helpAboutAction);

        retranslateUi(WpaGui);

        wpaguiTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WpaGui);
    } // setupUi

    void retranslateUi(QMainWindow *WpaGui)
    {
        WpaGui->setWindowTitle(QApplication::translate("WpaGui", "wpa_gui", 0));
        fileEventHistoryAction->setText(QApplication::translate("WpaGui", "Event &History", 0));
        fileSaveConfigAction->setText(QApplication::translate("WpaGui", "&Save Configuration", 0));
        fileSaveConfigAction->setShortcut(QApplication::translate("WpaGui", "Ctrl+S", 0));
        networkAddAction->setText(QApplication::translate("WpaGui", "&Add", 0));
        networkEditAction->setText(QApplication::translate("WpaGui", "&Edit", 0));
        networkRemoveAction->setText(QApplication::translate("WpaGui", "&Remove", 0));
        networkEnableAllAction->setText(QApplication::translate("WpaGui", "E&nable All", 0));
        networkDisableAllAction->setText(QApplication::translate("WpaGui", "&Disable All", 0));
        networkRemoveAllAction->setText(QApplication::translate("WpaGui", "Re&move All", 0));
        helpContentsAction->setText(QApplication::translate("WpaGui", "&Contents...", 0));
        helpIndexAction->setText(QApplication::translate("WpaGui", "&Index...", 0));
        helpAboutAction->setText(QApplication::translate("WpaGui", "&About", 0));
        actionWPS->setText(QApplication::translate("WpaGui", "&Wi-Fi Protected Setup", 0));
        actionPeers->setText(QApplication::translate("WpaGui", "&Peers", 0));
        actionExit->setText(QApplication::translate("WpaGui", "exit", 0));
        adapterLabel->setText(QApplication::translate("WpaGui", "Adapter:", 0));
        networkLabel->setText(QApplication::translate("WpaGui", "Network:", 0));
        statusLabel->setText(QApplication::translate("WpaGui", "Status:", 0));
        lastMessageLabel->setText(QApplication::translate("WpaGui", "Last message:", 0));
        authenticationLabel->setText(QApplication::translate("WpaGui", "Authentication:", 0));
        encryptionLabel->setText(QApplication::translate("WpaGui", "Encryption:", 0));
        ssidLabel->setText(QApplication::translate("WpaGui", "SSID:", 0));
        bssidLabel->setText(QApplication::translate("WpaGui", "BSSID:", 0));
        ipAddressLabel->setText(QApplication::translate("WpaGui", "IP address:", 0));
        textStatus->setText(QString());
        textLastMessage->setText(QString());
        textAuthentication->setText(QString());
        textEncryption->setText(QString());
        textSsid->setText(QString());
        textBssid->setText(QString());
        textIpAddress->setText(QString());
        connectButton->setText(QApplication::translate("WpaGui", "Connect", 0));
        disconnectButton->setText(QApplication::translate("WpaGui", "Disconnect", 0));
        scanButton->setText(QApplication::translate("WpaGui", "Scan", 0));
        wpaguiTab->setTabText(wpaguiTab->indexOf(statusTab), QApplication::translate("WpaGui", "Current Status", 0));
        enableRadioButton->setText(QApplication::translate("WpaGui", "Enabled", 0));
        editNetworkButton->setText(QApplication::translate("WpaGui", "Edit", 0));
        removeNetworkButton->setText(QApplication::translate("WpaGui", "Remove", 0));
        disableRadioButton->setText(QApplication::translate("WpaGui", "Disabled", 0));
        addNetworkButton->setText(QApplication::translate("WpaGui", "Add", 0));
        scanNetworkButton->setText(QApplication::translate("WpaGui", "Scan", 0));
        wpaguiTab->setTabText(wpaguiTab->indexOf(networkconfigTab), QApplication::translate("WpaGui", "Manage Networks", 0));
        label_2->setText(QApplication::translate("WpaGui", "Status:", 0));
        wpsStatusText->setText(QString());
        wpsPbcButton->setText(QApplication::translate("WpaGui", "PBC - push button", 0));
        wpsPinButton->setText(QApplication::translate("WpaGui", "Generate PIN", 0));
        label->setText(QApplication::translate("WpaGui", "PIN:", 0));
        wpsApPinButton->setText(QApplication::translate("WpaGui", "Use AP PIN", 0));
        label_3->setText(QApplication::translate("WpaGui", "AP PIN:", 0));
        wpaguiTab->setTabText(wpaguiTab->indexOf(wpsTab), QApplication::translate("WpaGui", "WPS", 0));
        fileMenu->setTitle(QApplication::translate("WpaGui", "&File", 0));
        networkMenu->setTitle(QApplication::translate("WpaGui", "&Network", 0));
        helpMenu->setTitle(QApplication::translate("WpaGui", "&Help", 0));
    } // retranslateUi

};

namespace Ui {
    class WpaGui: public Ui_WpaGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WPAGUI_H
