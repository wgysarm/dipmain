/********************************************************************************
** Form generated from reading UI file 'networkconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKCONFIG_H
#define UI_NETWORKCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkConfig
{
public:
    QFrame *frame9;
    QGroupBox *wepBox;
    QGridLayout *gridLayout;
    QRadioButton *wep0Radio;
    QRadioButton *wep1Radio;
    QRadioButton *wep3Radio;
    QRadioButton *wep2Radio;
    QLineEdit *wep0Edit;
    QLineEdit *wep1Edit;
    QLineEdit *wep2Edit;
    QLineEdit *wep3Edit;
    QGroupBox *optionalSettingsBox;
    QGridLayout *gridLayout1;
    QLineEdit *idstrEdit;
    QSpinBox *prioritySpinBox;
    QLabel *idstrLabel;
    QLabel *priorityLabel;
    QLabel *phase2Label;
    QComboBox *phase2Select;
    QLabel *ssidLabel;
    QLineEdit *ssidEdit;
    QLabel *authLabel;
    QComboBox *authSelect;
    QLabel *encrLabel;
    QComboBox *encrSelect;
    QLabel *pskLabel;
    QLineEdit *pskEdit;
    QLabel *eapLabel;
    QComboBox *eapSelect;
    QLabel *identityLabel;
    QLineEdit *identityEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QLabel *cacertLabel;
    QLineEdit *cacertEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *useWpsButton;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *cancelButton;
    QPushButton *addButton_2;

    void setupUi(QDialog *NetworkConfig)
    {
        if (NetworkConfig->objectName().isEmpty())
            NetworkConfig->setObjectName(QStringLiteral("NetworkConfig"));
        NetworkConfig->resize(800, 381);
        frame9 = new QFrame(NetworkConfig);
        frame9->setObjectName(QStringLiteral("frame9"));
        frame9->setGeometry(QRect(220, 10, 371, 291));
        frame9->setFrameShape(QFrame::NoFrame);
        frame9->setFrameShadow(QFrame::Plain);
        wepBox = new QGroupBox(frame9);
        wepBox->setObjectName(QStringLiteral("wepBox"));
        wepBox->setEnabled(true);
        wepBox->setGeometry(QRect(430, 30, 212, 130));
        gridLayout = new QGridLayout(wepBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        wep0Radio = new QRadioButton(wepBox);
        wep0Radio->setObjectName(QStringLiteral("wep0Radio"));
        wep0Radio->setEnabled(false);

        gridLayout->addWidget(wep0Radio, 0, 0, 1, 1);

        wep1Radio = new QRadioButton(wepBox);
        wep1Radio->setObjectName(QStringLiteral("wep1Radio"));
        wep1Radio->setEnabled(false);

        gridLayout->addWidget(wep1Radio, 1, 0, 1, 1);

        wep3Radio = new QRadioButton(wepBox);
        wep3Radio->setObjectName(QStringLiteral("wep3Radio"));
        wep3Radio->setEnabled(false);

        gridLayout->addWidget(wep3Radio, 3, 0, 1, 1);

        wep2Radio = new QRadioButton(wepBox);
        wep2Radio->setObjectName(QStringLiteral("wep2Radio"));
        wep2Radio->setEnabled(false);

        gridLayout->addWidget(wep2Radio, 2, 0, 1, 1);

        wep0Edit = new QLineEdit(wepBox);
        wep0Edit->setObjectName(QStringLiteral("wep0Edit"));
        wep0Edit->setEnabled(false);

        gridLayout->addWidget(wep0Edit, 0, 1, 1, 1);

        wep1Edit = new QLineEdit(wepBox);
        wep1Edit->setObjectName(QStringLiteral("wep1Edit"));
        wep1Edit->setEnabled(false);

        gridLayout->addWidget(wep1Edit, 1, 1, 1, 1);

        wep2Edit = new QLineEdit(wepBox);
        wep2Edit->setObjectName(QStringLiteral("wep2Edit"));
        wep2Edit->setEnabled(false);

        gridLayout->addWidget(wep2Edit, 2, 1, 1, 1);

        wep3Edit = new QLineEdit(wepBox);
        wep3Edit->setObjectName(QStringLiteral("wep3Edit"));
        wep3Edit->setEnabled(false);

        gridLayout->addWidget(wep3Edit, 3, 1, 1, 1);

        optionalSettingsBox = new QGroupBox(frame9);
        optionalSettingsBox->setObjectName(QStringLiteral("optionalSettingsBox"));
        optionalSettingsBox->setEnabled(true);
        optionalSettingsBox->setGeometry(QRect(430, 190, 337, 78));
        gridLayout1 = new QGridLayout(optionalSettingsBox);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        idstrEdit = new QLineEdit(optionalSettingsBox);
        idstrEdit->setObjectName(QStringLiteral("idstrEdit"));

        gridLayout1->addWidget(idstrEdit, 0, 1, 1, 1);

        prioritySpinBox = new QSpinBox(optionalSettingsBox);
        prioritySpinBox->setObjectName(QStringLiteral("prioritySpinBox"));
        prioritySpinBox->setMaximum(10000);
        prioritySpinBox->setSingleStep(10);

        gridLayout1->addWidget(prioritySpinBox, 0, 3, 1, 1);

        idstrLabel = new QLabel(optionalSettingsBox);
        idstrLabel->setObjectName(QStringLiteral("idstrLabel"));

        gridLayout1->addWidget(idstrLabel, 0, 0, 1, 1);

        priorityLabel = new QLabel(optionalSettingsBox);
        priorityLabel->setObjectName(QStringLiteral("priorityLabel"));

        gridLayout1->addWidget(priorityLabel, 0, 2, 1, 1);

        phase2Label = new QLabel(optionalSettingsBox);
        phase2Label->setObjectName(QStringLiteral("phase2Label"));

        gridLayout1->addWidget(phase2Label, 1, 0, 1, 1);

        phase2Select = new QComboBox(optionalSettingsBox);
        phase2Select->setObjectName(QStringLiteral("phase2Select"));
        phase2Select->setEnabled(false);

        gridLayout1->addWidget(phase2Select, 1, 1, 1, 1);

        ssidLabel = new QLabel(frame9);
        ssidLabel->setObjectName(QStringLiteral("ssidLabel"));
        ssidLabel->setGeometry(QRect(9, 9, 24, 16));
        ssidEdit = new QLineEdit(frame9);
        ssidEdit->setObjectName(QStringLiteral("ssidEdit"));
        ssidEdit->setGeometry(QRect(99, 9, 251, 20));
        authLabel = new QLabel(frame9);
        authLabel->setObjectName(QStringLiteral("authLabel"));
        authLabel->setGeometry(QRect(10, 40, 84, 16));
        authSelect = new QComboBox(frame9);
        authSelect->setObjectName(QStringLiteral("authSelect"));
        authSelect->setGeometry(QRect(100, 40, 253, 20));
        encrLabel = new QLabel(frame9);
        encrLabel->setObjectName(QStringLiteral("encrLabel"));
        encrLabel->setGeometry(QRect(10, 70, 60, 16));
        encrSelect = new QComboBox(frame9);
        encrSelect->setObjectName(QStringLiteral("encrSelect"));
        encrSelect->setGeometry(QRect(100, 70, 251, 20));
        pskLabel = new QLabel(frame9);
        pskLabel->setObjectName(QStringLiteral("pskLabel"));
        pskLabel->setGeometry(QRect(10, 100, 18, 16));
        pskEdit = new QLineEdit(frame9);
        pskEdit->setObjectName(QStringLiteral("pskEdit"));
        pskEdit->setEnabled(false);
        pskEdit->setGeometry(QRect(100, 100, 251, 20));
        pskEdit->setEchoMode(QLineEdit::Normal);
        eapLabel = new QLabel(frame9);
        eapLabel->setObjectName(QStringLiteral("eapLabel"));
        eapLabel->setGeometry(QRect(10, 130, 60, 16));
        eapSelect = new QComboBox(frame9);
        eapSelect->setObjectName(QStringLiteral("eapSelect"));
        eapSelect->setEnabled(false);
        eapSelect->setGeometry(QRect(100, 140, 151, 20));
        identityLabel = new QLabel(frame9);
        identityLabel->setObjectName(QStringLiteral("identityLabel"));
        identityLabel->setGeometry(QRect(10, 170, 48, 16));
        identityEdit = new QLineEdit(frame9);
        identityEdit->setObjectName(QStringLiteral("identityEdit"));
        identityEdit->setEnabled(false);
        identityEdit->setGeometry(QRect(100, 170, 151, 20));
        passwordLabel = new QLabel(frame9);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(10, 210, 48, 16));
        passwordEdit = new QLineEdit(frame9);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEnabled(false);
        passwordEdit->setGeometry(QRect(100, 210, 151, 20));
        passwordEdit->setEchoMode(QLineEdit::Password);
        cacertLabel = new QLabel(frame9);
        cacertLabel->setObjectName(QStringLiteral("cacertLabel"));
        cacertLabel->setGeometry(QRect(10, 250, 84, 16));
        cacertEdit = new QLineEdit(frame9);
        cacertEdit->setObjectName(QStringLiteral("cacertEdit"));
        cacertEdit->setEnabled(false);
        cacertEdit->setGeometry(QRect(100, 250, 151, 20));
        widget = new QWidget(NetworkConfig);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 330, 691, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        useWpsButton = new QPushButton(widget);
        useWpsButton->setObjectName(QStringLiteral("useWpsButton"));
        useWpsButton->setEnabled(false);

        horizontalLayout->addWidget(useWpsButton);

        addButton = new QPushButton(widget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        removeButton = new QPushButton(widget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setEnabled(false);

        horizontalLayout->addWidget(removeButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        addButton_2 = new QPushButton(widget);
        addButton_2->setObjectName(QStringLiteral("addButton_2"));

        horizontalLayout->addWidget(addButton_2);

        addButton_2->raise();
        cancelButton->raise();
        addButton->raise();
        removeButton->raise();
        useWpsButton->raise();
        frame9->raise();
        QWidget::setTabOrder(ssidEdit, authSelect);
        QWidget::setTabOrder(authSelect, encrSelect);
        QWidget::setTabOrder(encrSelect, pskEdit);
        QWidget::setTabOrder(pskEdit, eapSelect);
        QWidget::setTabOrder(eapSelect, identityEdit);
        QWidget::setTabOrder(identityEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, cacertEdit);
        QWidget::setTabOrder(cacertEdit, wep0Radio);
        QWidget::setTabOrder(wep0Radio, wep0Edit);
        QWidget::setTabOrder(wep0Edit, wep1Radio);
        QWidget::setTabOrder(wep1Radio, wep1Edit);
        QWidget::setTabOrder(wep1Edit, wep2Radio);
        QWidget::setTabOrder(wep2Radio, wep2Edit);
        QWidget::setTabOrder(wep2Edit, wep3Radio);
        QWidget::setTabOrder(wep3Radio, wep3Edit);
        QWidget::setTabOrder(wep3Edit, idstrEdit);
        QWidget::setTabOrder(idstrEdit, prioritySpinBox);
        QWidget::setTabOrder(prioritySpinBox, phase2Select);
        QWidget::setTabOrder(phase2Select, addButton);
        QWidget::setTabOrder(addButton, removeButton);
        QWidget::setTabOrder(removeButton, cancelButton);

        retranslateUi(NetworkConfig);

        QMetaObject::connectSlotsByName(NetworkConfig);
    } // setupUi

    void retranslateUi(QDialog *NetworkConfig)
    {
        NetworkConfig->setWindowTitle(QApplication::translate("NetworkConfig", "NetworkConfig", 0));
        wepBox->setTitle(QApplication::translate("NetworkConfig", "WEP keys", 0));
        wep0Radio->setText(QApplication::translate("NetworkConfig", "key 0", 0));
        wep1Radio->setText(QApplication::translate("NetworkConfig", "key 1", 0));
        wep3Radio->setText(QApplication::translate("NetworkConfig", "key 3", 0));
        wep2Radio->setText(QApplication::translate("NetworkConfig", "key 2", 0));
        optionalSettingsBox->setTitle(QApplication::translate("NetworkConfig", "Optional Settings", 0));
#ifndef QT_NO_TOOLTIP
        idstrEdit->setToolTip(QApplication::translate("NetworkConfig", "Network Identification String", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        prioritySpinBox->setToolTip(QApplication::translate("NetworkConfig", "Network Priority", 0));
#endif // QT_NO_TOOLTIP
        idstrLabel->setText(QApplication::translate("NetworkConfig", "IDString", 0));
        priorityLabel->setText(QApplication::translate("NetworkConfig", "Priority", 0));
        phase2Label->setText(QApplication::translate("NetworkConfig", "Inner auth", 0));
        ssidLabel->setText(QApplication::translate("NetworkConfig", "SSID", 0));
#ifndef QT_NO_TOOLTIP
        ssidEdit->setToolTip(QApplication::translate("NetworkConfig", "Network name (Service Set IDentifier)", 0));
#endif // QT_NO_TOOLTIP
        ssidEdit->setText(QString());
        authLabel->setText(QApplication::translate("NetworkConfig", "Authentication", 0));
        authSelect->clear();
        authSelect->insertItems(0, QStringList()
         << QApplication::translate("NetworkConfig", "Plaintext (open / no authentication)", 0)
         << QApplication::translate("NetworkConfig", "Static WEP (no authentication)", 0)
         << QApplication::translate("NetworkConfig", "Static WEP (Shared Key authentication)", 0)
         << QApplication::translate("NetworkConfig", "IEEE 802.1X", 0)
         << QApplication::translate("NetworkConfig", "WPA-Personal (PSK)", 0)
         << QApplication::translate("NetworkConfig", "WPA-Enterprise (EAP)", 0)
         << QApplication::translate("NetworkConfig", "WPA2-Personal (PSK)", 0)
         << QApplication::translate("NetworkConfig", "WPA2-Enterprise (EAP)", 0)
        );
        encrLabel->setText(QApplication::translate("NetworkConfig", "Encryption", 0));
        encrSelect->clear();
        encrSelect->insertItems(0, QStringList()
         << QApplication::translate("NetworkConfig", "None", 0)
         << QApplication::translate("NetworkConfig", "WEP", 0)
         << QApplication::translate("NetworkConfig", "TKIP", 0)
         << QApplication::translate("NetworkConfig", "CCMP", 0)
        );
        pskLabel->setText(QApplication::translate("NetworkConfig", "PSK", 0));
#ifndef QT_NO_TOOLTIP
        pskEdit->setToolTip(QApplication::translate("NetworkConfig", "WPA/WPA2 pre-shared key or passphrase", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pskEdit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        eapLabel->setText(QApplication::translate("NetworkConfig", "EAP method", 0));
        identityLabel->setText(QApplication::translate("NetworkConfig", "Identity", 0));
#ifndef QT_NO_TOOLTIP
        identityEdit->setToolTip(QApplication::translate("NetworkConfig", "Username/Identity for EAP methods", 0));
#endif // QT_NO_TOOLTIP
        passwordLabel->setText(QApplication::translate("NetworkConfig", "Password", 0));
#ifndef QT_NO_TOOLTIP
        passwordEdit->setToolTip(QApplication::translate("NetworkConfig", "Password for EAP methods", 0));
#endif // QT_NO_TOOLTIP
        cacertLabel->setText(QApplication::translate("NetworkConfig", "CA certificate", 0));
        useWpsButton->setText(QApplication::translate("NetworkConfig", "WPS", 0));
        addButton->setText(QApplication::translate("NetworkConfig", "Add", 0));
        removeButton->setText(QApplication::translate("NetworkConfig", "Remove", 0));
        cancelButton->setText(QApplication::translate("NetworkConfig", "Cancel", 0));
        addButton_2->setText(QApplication::translate("NetworkConfig", "close", 0));
    } // retranslateUi

};

namespace Ui {
    class NetworkConfig: public Ui_NetworkConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKCONFIG_H
