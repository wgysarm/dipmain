/********************************************************************************
** Form generated from reading UI file 'eventhistory.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTHISTORY_H
#define UI_EVENTHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include "wpamsg.h"

QT_BEGIN_NAMESPACE

class Ui_EventHistory
{
public:
    QGridLayout *gridLayout;
    QTreeView *eventListView;
    QSpacerItem *spacerItem;
    QPushButton *closeButton;

    void setupUi(QDialog *EventHistory)
    {
        if (EventHistory->objectName().isEmpty())
            EventHistory->setObjectName(QStringLiteral("EventHistory"));
        EventHistory->resize(809, 301);
        gridLayout = new QGridLayout(EventHistory);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        eventListView = new QTreeView(EventHistory);
        eventListView->setObjectName(QStringLiteral("eventListView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eventListView->sizePolicy().hasHeightForWidth());
        eventListView->setSizePolicy(sizePolicy);
        eventListView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        eventListView->setSelectionMode(QAbstractItemView::NoSelection);

        gridLayout->addWidget(eventListView, 0, 0, 1, 2);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 1, 0, 1, 1);

        closeButton = new QPushButton(EventHistory);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        gridLayout->addWidget(closeButton, 1, 1, 1, 1);


        retranslateUi(EventHistory);

        QMetaObject::connectSlotsByName(EventHistory);
    } // setupUi

    void retranslateUi(QDialog *EventHistory)
    {
        EventHistory->setWindowTitle(QApplication::translate("EventHistory", "Event history", 0));
        closeButton->setText(QApplication::translate("EventHistory", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class EventHistory: public Ui_EventHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTHISTORY_H
