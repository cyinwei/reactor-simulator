/********************************************************************************
** Form generated from reading UI file 'loadingwin.ui'
**
** Created: Thu Jan 9 16:56:45 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGWIN_H
#define UI_LOADINGWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Loadingwindow
{
public:
    QAction *actionProgress;
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Loadingwindow)
    {
        if (Loadingwindow->objectName().isEmpty())
            Loadingwindow->setObjectName(QString::fromUtf8("Loadingwindow"));
        Loadingwindow->resize(400, 200);
        Loadingwindow->setMinimumSize(QSize(400, 200));
        Loadingwindow->setMaximumSize(QSize(400, 200));
        actionProgress = new QAction(Loadingwindow);
        actionProgress->setObjectName(QString::fromUtf8("actionProgress"));
        centralwidget = new QWidget(Loadingwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(150, 100, 118, 23));
        progressBar->setValue(0);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 0, 351, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 110, 75, 23));
        Loadingwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Loadingwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 21));
        Loadingwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Loadingwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Loadingwindow->setStatusBar(statusbar);

        retranslateUi(Loadingwindow);

        QMetaObject::connectSlotsByName(Loadingwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Loadingwindow)
    {
        Loadingwindow->setWindowTitle(QApplication::translate("Loadingwindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionProgress->setText(QApplication::translate("Loadingwindow", "progress", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Loadingwindow", "Please wait while output file is formatted.", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Loadingwindow", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Loadingwindow: public Ui_Loadingwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGWIN_H
