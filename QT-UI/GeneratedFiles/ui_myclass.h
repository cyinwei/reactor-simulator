/********************************************************************************
** Form generated from reading UI file 'myclass.ui'
**
** Created: Tue Dec 24 04:44:46 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLASS_H
#define UI_MYCLASS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClassClass
{
public:
    QAction *actionFile_name;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QRadioButton *TempBubble;
    QRadioButton *FlowBubble;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_9;
    QPushButton *OkButton;
    QPushButton *CancelButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QString::fromUtf8("MyClassClass"));
        MyClassClass->resize(729, 304);
        actionFile_name = new QAction(MyClassClass);
        actionFile_name->setObjectName(QString::fromUtf8("actionFile_name"));
        centralWidget = new QWidget(MyClassClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        verticalLayout_8->addWidget(frame_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(false);

        verticalLayout_10->addWidget(label);


        verticalLayout_8->addLayout(verticalLayout_10);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        TempBubble = new QRadioButton(frame);
        TempBubble->setObjectName(QString::fromUtf8("TempBubble"));

        verticalLayout_8->addWidget(TempBubble);

        FlowBubble = new QRadioButton(frame);
        FlowBubble->setObjectName(QString::fromUtf8("FlowBubble"));
        FlowBubble->setChecked(true);

        verticalLayout_8->addWidget(FlowBubble);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        OkButton = new QPushButton(frame);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));

        verticalLayout_9->addWidget(OkButton);

        CancelButton = new QPushButton(frame);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        verticalLayout_9->addWidget(CancelButton);


        horizontalLayout_4->addLayout(verticalLayout_9);


        verticalLayout_8->addLayout(horizontalLayout_4);


        verticalLayout_7->addWidget(frame);

        MyClassClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyClassClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 21));
        MyClassClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyClassClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyClassClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyClassClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyClassClass->setStatusBar(statusBar);

        retranslateUi(MyClassClass);
        QObject::connect(CancelButton, SIGNAL(clicked()), MyClassClass, SLOT(close()));
        QObject::connect(OkButton, SIGNAL(clicked()), MyClassClass, SLOT(close()));

        QMetaObject::connectSlotsByName(MyClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyClassClass)
    {
        MyClassClass->setWindowTitle(QApplication::translate("MyClassClass", "MyClass", 0, QApplication::UnicodeUTF8));
        actionFile_name->setText(QApplication::translate("MyClassClass", "file_name", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MyClassClass", "Choose type of simulation Temp or Flow. Then enter an output file name and press ok.", 0, QApplication::UnicodeUTF8));
        TempBubble->setText(QApplication::translate("MyClassClass", "Temp Files", 0, QApplication::UnicodeUTF8));
        FlowBubble->setText(QApplication::translate("MyClassClass", "Flow Files", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MyClassClass", "Output File Name", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("MyClassClass", "OK", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("MyClassClass", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyClassClass: public Ui_MyClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H
