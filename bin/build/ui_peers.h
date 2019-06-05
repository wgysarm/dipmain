/********************************************************************************
** Form generated from reading UI file 'peers.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEERS_H
#define UI_PEERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_Peers
{
public:
    QGridLayout *gridLayout;
    QListView *peers;

    void setupUi(QDialog *Peers)
    {
        if (Peers->objectName().isEmpty())
            Peers->setObjectName(QStringLiteral("Peers"));
        Peers->resize(648, 441);
        gridLayout = new QGridLayout(Peers);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        peers = new QListView(Peers);
        peers->setObjectName(QStringLiteral("peers"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(peers->sizePolicy().hasHeightForWidth());
        peers->setSizePolicy(sizePolicy);
        peers->setMouseTracking(true);
        peers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        peers->setViewMode(QListView::IconMode);

        gridLayout->addWidget(peers, 0, 0, 1, 1);


        retranslateUi(Peers);

        QMetaObject::connectSlotsByName(Peers);
    } // setupUi

    void retranslateUi(QDialog *Peers)
    {
        Peers->setWindowTitle(QApplication::translate("Peers", "Peers", 0));
    } // retranslateUi

};

namespace Ui {
    class Peers: public Ui_Peers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEERS_H
