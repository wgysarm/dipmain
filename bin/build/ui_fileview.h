/********************************************************************************
** Form generated from reading UI file 'fileview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEVIEW_H
#define UI_FILEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileview
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *exitButton;
    QToolButton *backButton;
    QToolButton *forwardButton;
    QToolButton *aheadButton;
    QToolButton *listButton;
    QToolButton *detailButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QListView *listView;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *closeButton;

    void setupUi(QWidget *fileview)
    {
        if (fileview->objectName().isEmpty())
            fileview->setObjectName(QStringLiteral("fileview"));
        fileview->resize(800, 480);
        QFont font;
        font.setFamily(QStringLiteral("WenQuanYi Zen Hei"));
        font.setPointSize(12);
        fileview->setFont(font);
        verticalLayout = new QVBoxLayout(fileview);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        exitButton = new QToolButton(fileview);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setStyleSheet(QLatin1String("border-style: flat;\n"
"border-image: url(:/images/image/res/exit.png);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/buttons/images/viewdetailed-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitButton->setIcon(icon);
        exitButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(exitButton);

        backButton = new QToolButton(fileview);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setEnabled(true);
        backButton->setStyleSheet(QLatin1String("border-style: flat;\n"
"border-image: url(:/images/image/fileman/left-24.png);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/buttons/images/left-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon1);
        backButton->setIconSize(QSize(24, 24));
        backButton->setAutoRaise(true);

        horizontalLayout->addWidget(backButton);

        forwardButton = new QToolButton(fileview);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));
        forwardButton->setStyleSheet(QLatin1String("border-style: flat;\n"
"border-image: url(:/images/image/fileman/right-24.png);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/buttons/images/right-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon2);
        forwardButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(forwardButton);

        aheadButton = new QToolButton(fileview);
        aheadButton->setObjectName(QStringLiteral("aheadButton"));
        aheadButton->setStyleSheet(QLatin1String("border-style: flat;\n"
"border-image: url(:/images/image/fileman/up-24.png);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/buttons/images/up-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        aheadButton->setIcon(icon3);
        aheadButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(aheadButton);

        listButton = new QToolButton(fileview);
        listButton->setObjectName(QStringLiteral("listButton"));
        listButton->setStyleSheet(QLatin1String("border-style: flat;\n"
"border-image: url(:/images/image/fileman/viewlist-24.png);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/buttons/images/viewlist-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        listButton->setIcon(icon4);
        listButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(listButton);

        detailButton = new QToolButton(fileview);
        detailButton->setObjectName(QStringLiteral("detailButton"));
        detailButton->setStyleSheet(QLatin1String("border-style: flat;\n"
"border-image: url(:/images/image/fileman/viewdetailed-24.png);"));
        detailButton->setIcon(icon);
        detailButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(detailButton);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(fileview);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listView = new QListView(page);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout_2->addWidget(listView);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(page_2);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout_3->addWidget(treeView);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        closeButton = new QPushButton(fileview);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setFlat(false);

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(fileview);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(fileview);
    } // setupUi

    void retranslateUi(QWidget *fileview)
    {
        fileview->setWindowTitle(QApplication::translate("fileview", "Widget", 0));
        exitButton->setText(QString());
        backButton->setText(QString());
        forwardButton->setText(QString());
        aheadButton->setText(QString());
        listButton->setText(QString());
        detailButton->setText(QString());
        closeButton->setText(QApplication::translate("fileview", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class fileview: public Ui_fileview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEVIEW_H
