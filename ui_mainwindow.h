/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart;
    QAction *actionparamSet;
    QAction *actionresetCT;
    QAction *actionlight;
    QAction *actionscale;
    QAction *actiongray;
    QAction *actionguassainBlur;
    QAction *actionbitlateBlur;
    QAction *actionreadCT;
    QAction *actionsaveCT;
    QAction *actionexit;
    QAction *action0;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *actioncellSetting;
    QAction *actionimportCell;
    QAction *actionstartCount;
    QWidget *centralwidget;
    QLabel *label;
    QTreeWidget *treeWidget;
    QLabel *CT_Img_Label;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_6;
    QLabel *photoLabel;
    QLineEdit *ssnLineEdit;
    QLabel *nameLabel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_sex;
    QLabel *label_4;
    QLabel *label_age;
    QLabel *label_5;
    QLabel *label_ethic;
    QWidget *tab_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QTextEdit *caseTextEdit;
    QPushButton *saveHistoryBtn;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QTimeEdit *timeEdit;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *yearLcdNumber;
    QLCDNumber *monthLcdNumber;
    QLCDNumber *dayLcdNumber;
    QTableView *basicTableView;
    QLabel *label_horizon;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QLabel *label_vertical;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuCT;
    QMenu *menu_2;
    QMenu *menu_CT;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1110, 894);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionparamSet = new QAction(MainWindow);
        actionparamSet->setObjectName(QString::fromUtf8("actionparamSet"));
        actionresetCT = new QAction(MainWindow);
        actionresetCT->setObjectName(QString::fromUtf8("actionresetCT"));
        actionlight = new QAction(MainWindow);
        actionlight->setObjectName(QString::fromUtf8("actionlight"));
        actionscale = new QAction(MainWindow);
        actionscale->setObjectName(QString::fromUtf8("actionscale"));
        actiongray = new QAction(MainWindow);
        actiongray->setObjectName(QString::fromUtf8("actiongray"));
        actionguassainBlur = new QAction(MainWindow);
        actionguassainBlur->setObjectName(QString::fromUtf8("actionguassainBlur"));
        actionbitlateBlur = new QAction(MainWindow);
        actionbitlateBlur->setObjectName(QString::fromUtf8("actionbitlateBlur"));
        actionreadCT = new QAction(MainWindow);
        actionreadCT->setObjectName(QString::fromUtf8("actionreadCT"));
        actionsaveCT = new QAction(MainWindow);
        actionsaveCT->setObjectName(QString::fromUtf8("actionsaveCT"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        action0 = new QAction(MainWindow);
        action0->setObjectName(QString::fromUtf8("action0"));
        action1 = new QAction(MainWindow);
        action1->setObjectName(QString::fromUtf8("action1"));
        action2 = new QAction(MainWindow);
        action2->setObjectName(QString::fromUtf8("action2"));
        action3 = new QAction(MainWindow);
        action3->setObjectName(QString::fromUtf8("action3"));
        action4 = new QAction(MainWindow);
        action4->setObjectName(QString::fromUtf8("action4"));
        actioncellSetting = new QAction(MainWindow);
        actioncellSetting->setObjectName(QString::fromUtf8("actioncellSetting"));
        actionimportCell = new QAction(MainWindow);
        actionimportCell->setObjectName(QString::fromUtf8("actionimportCell"));
        actionstartCount = new QAction(MainWindow);
        actionstartCount->setObjectName(QString::fromUtf8("actionstartCount"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 10, 521, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(26);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem4);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(10, 400, 271, 221));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        treeWidget->setPalette(palette);
        CT_Img_Label = new QLabel(centralwidget);
        CT_Img_Label->setObjectName(QString::fromUtf8("CT_Img_Label"));
        CT_Img_Label->setGeometry(QRect(291, 91, 754, 504));
        CT_Img_Label->setFrameShape(QFrame::Box);
        CT_Img_Label->setFrameShadow(QFrame::Sunken);
        CT_Img_Label->setPixmap(QPixmap(QString::fromUtf8(":/CT.jpg")));
        CT_Img_Label->setScaledContents(true);
        CT_Img_Label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 60, 60, 20));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 60, 271, 331));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 220, 90, 15));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        label_6->setFont(font2);
        photoLabel = new QLabel(tab);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));
        photoLabel->setGeometry(QRect(110, 10, 151, 191));
        photoLabel->setFrameShape(QFrame::Panel);
        photoLabel->setScaledContents(true);
        photoLabel->setAlignment(Qt::AlignCenter);
        ssnLineEdit = new QLineEdit(tab);
        ssnLineEdit->setObjectName(QString::fromUtf8("ssnLineEdit"));
        ssnLineEdit->setGeometry(QRect(20, 250, 241, 31));
        ssnLineEdit->setFont(font1);
        ssnLineEdit->setAlignment(Qt::AlignCenter);
        ssnLineEdit->setReadOnly(true);
        nameLabel = new QLabel(tab);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(10, 10, 91, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font3.setPointSize(14);
        nameLabel->setFont(font3);
        nameLabel->setAlignment(Qt::AlignCenter);
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 60, 91, 131));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        label_sex = new QLabel(widget);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));
        label_sex->setFrameShape(QFrame::NoFrame);
        label_sex->setFrameShadow(QFrame::Raised);
        label_sex->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_sex, 0, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_age = new QLabel(widget);
        label_age->setObjectName(QString::fromUtf8("label_age"));
        label_age->setFrameShape(QFrame::NoFrame);
        label_age->setFrameShadow(QFrame::Raised);
        label_age->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_age, 1, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_ethic = new QLabel(widget);
        label_ethic->setObjectName(QString::fromUtf8("label_ethic"));
        label_ethic->setFrameShape(QFrame::NoFrame);
        label_ethic->setFrameShadow(QFrame::Raised);
        label_ethic->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ethic, 2, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        widget1 = new QWidget(tab_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(0, 0, 261, 291));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        caseTextEdit = new QTextEdit(widget1);
        caseTextEdit->setObjectName(QString::fromUtf8("caseTextEdit"));

        verticalLayout->addWidget(caseTextEdit);

        saveHistoryBtn = new QPushButton(widget1);
        saveHistoryBtn->setObjectName(QString::fromUtf8("saveHistoryBtn"));

        verticalLayout->addWidget(saveHistoryBtn);

        tabWidget->addTab(tab_2, QString());
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(780, 60, 254, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        timeEdit = new QTimeEdit(layoutWidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        horizontalLayout_2->addWidget(timeEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        yearLcdNumber = new QLCDNumber(layoutWidget);
        yearLcdNumber->setObjectName(QString::fromUtf8("yearLcdNumber"));
        yearLcdNumber->setDigitCount(4);
        yearLcdNumber->setSegmentStyle(QLCDNumber::Filled);
        yearLcdNumber->setProperty("value", QVariant(1996.000000000000000));
        yearLcdNumber->setProperty("intValue", QVariant(1996));

        horizontalLayout->addWidget(yearLcdNumber);

        monthLcdNumber = new QLCDNumber(layoutWidget);
        monthLcdNumber->setObjectName(QString::fromUtf8("monthLcdNumber"));
        monthLcdNumber->setDigitCount(2);
        monthLcdNumber->setProperty("value", QVariant(2.000000000000000));

        horizontalLayout->addWidget(monthLcdNumber);

        dayLcdNumber = new QLCDNumber(layoutWidget);
        dayLcdNumber->setObjectName(QString::fromUtf8("dayLcdNumber"));
        dayLcdNumber->setDigitCount(2);
        dayLcdNumber->setProperty("intValue", QVariant(25));

        horizontalLayout->addWidget(dayLcdNumber);


        horizontalLayout_2->addLayout(horizontalLayout);

        basicTableView = new QTableView(centralwidget);
        basicTableView->setObjectName(QString::fromUtf8("basicTableView"));
        basicTableView->setGeometry(QRect(10, 630, 1061, 201));
        label_horizon = new QLabel(centralwidget);
        label_horizon->setObjectName(QString::fromUtf8("label_horizon"));
        label_horizon->setGeometry(QRect(291, 601, 45, 17));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(343, 601, 691, 18));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(60);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(5);
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(1060, 100, 20, 471));
        verticalSlider->setMaximum(100);
        verticalSlider->setValue(30);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setTickPosition(QSlider::TicksAbove);
        verticalSlider->setTickInterval(5);
        label_vertical = new QLabel(centralwidget);
        label_vertical->setObjectName(QString::fromUtf8("label_vertical"));
        label_vertical->setGeometry(QRect(1050, 580, 45, 17));
        label_vertical->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1110, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuCT = new QMenu(menubar);
        menuCT->setObjectName(QString::fromUtf8("menuCT"));
        menu_2 = new QMenu(menuCT);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_CT = new QMenu(menubar);
        menu_CT->setObjectName(QString::fromUtf8("menu_CT"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_CT->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menuCT->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(actionStart);
        menu->addAction(actionparamSet);
        menu->addAction(actionresetCT);
        menuCT->addAction(actionlight);
        menuCT->addAction(actionscale);
        menuCT->addAction(actionbitlateBlur);
        menuCT->addAction(actionguassainBlur);
        menuCT->addAction(actiongray);
        menuCT->addAction(menu_2->menuAction());
        menu_2->addAction(action0);
        menu_2->addAction(action1);
        menu_2->addAction(action2);
        menu_2->addAction(action3);
        menu_2->addAction(action4);
        menu_CT->addAction(actionreadCT);
        menu_CT->addAction(actionsaveCT);
        menu_CT->addAction(actionexit);
        menu_3->addAction(actionimportCell);
        menu_3->addAction(actionstartCount);
        menu_3->addAction(actioncellSetting);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\257\212\346\226\255", nullptr));
        actionparamSet->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        actionresetCT->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256CT\347\233\270\347\211\207", nullptr));
        actionlight->setText(QCoreApplication::translate("MainWindow", "\345\257\271\346\257\224\345\272\246\345\222\214\344\272\256\345\272\246", nullptr));
        actionscale->setText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254\345\222\214\347\274\251\346\224\276", nullptr));
        actiongray->setText(QCoreApplication::translate("MainWindow", "\347\201\260\345\272\246\345\214\226", nullptr));
        actionguassainBlur->setText(QCoreApplication::translate("MainWindow", "\351\253\230\346\226\257\346\273\244\346\263\242", nullptr));
        actionbitlateBlur->setText(QCoreApplication::translate("MainWindow", "\345\217\214\350\276\271\346\273\244\346\263\242", nullptr));
        actionreadCT->setText(QCoreApplication::translate("MainWindow", " \350\257\273\345\217\226 CT", nullptr));
        actionsaveCT->setText(QCoreApplication::translate("MainWindow", "\345\260\206\345\275\223\345\211\215 CT \345\217\246\345\255\230\344\270\272", nullptr));
        actionexit->setText(QCoreApplication::translate("MainWindow", " \351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
        action0->setText(QCoreApplication::translate("MainWindow", "\344\272\214\350\277\233\345\210\266\351\230\210\345\200\274", nullptr));
        action1->setText(QCoreApplication::translate("MainWindow", "\345\217\215\344\272\214\350\277\233\345\210\266\351\230\210\345\200\274", nullptr));
        action2->setText(QCoreApplication::translate("MainWindow", "\346\210\252\346\226\255\351\230\210\345\200\274", nullptr));
        action3->setText(QCoreApplication::translate("MainWindow", "0\351\230\210\345\200\274", nullptr));
        action4->setText(QCoreApplication::translate("MainWindow", "\345\217\2150\351\230\210\345\200\274", nullptr));
        actioncellSetting->setText(QCoreApplication::translate("MainWindow", "\350\256\241\346\225\260\350\256\276\347\275\256", nullptr));
        actionimportCell->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\347\273\206\350\203\236\345\233\276\347\211\207", nullptr));
        actionstartCount->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\256\241\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\215\227\347\220\206\345\267\245\346\240\241\345\214\273\351\231\242\350\277\234\347\250\213\350\257\212\346\226\255\347\263\273\347\273\237", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\346\240\241\345\214\273\351\231\242", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\346\240\241\346\234\254\351\203\250", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\345\206\205\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\347\245\236\347\273\217\345\206\205\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "\346\266\210\345\214\226\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem2->child(2);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "\345\206\205\345\210\206\346\263\214\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem2->child(3);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("MainWindow", "\345\246\207\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem2->child(4);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("MainWindow", "\345\221\274\345\220\270\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem2->child(5);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("MainWindow", "\350\202\276\345\206\205\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("MainWindow", "\345\244\226\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("MainWindow", "\350\202\235\350\203\206\345\244\226\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem11->setText(0, QCoreApplication::translate("MainWindow", "\350\241\200\347\256\241\345\244\226\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem9->child(2);
        ___qtreewidgetitem12->setText(0, QCoreApplication::translate("MainWindow", "\345\277\203\350\203\270\345\244\226\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem9->child(3);
        ___qtreewidgetitem13->setText(0, QCoreApplication::translate("MainWindow", "\350\200\263\351\274\273\345\222\275\345\226\211\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem14->setText(0, QCoreApplication::translate("MainWindow", "\346\200\245\350\257\212\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem15 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem15->setText(0, QCoreApplication::translate("MainWindow", "\346\261\237\351\230\264\346\240\241\345\214\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem15->child(0);
        ___qtreewidgetitem16->setText(0, QCoreApplication::translate("MainWindow", "\351\252\250\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem15->child(1);
        ___qtreewidgetitem17->setText(0, QCoreApplication::translate("MainWindow", "\350\241\200\347\256\241\345\244\226\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem15->child(2);
        ___qtreewidgetitem18->setText(0, QCoreApplication::translate("MainWindow", "\345\277\203\350\204\217\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem15->child(3);
        ___qtreewidgetitem19->setText(0, QCoreApplication::translate("MainWindow", "\350\204\221\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem15->child(4);
        ___qtreewidgetitem20->setText(0, QCoreApplication::translate("MainWindow", "\347\245\236\347\273\217\345\206\205\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem21 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem21->setText(0, QCoreApplication::translate("MainWindow", "\347\264\253\351\207\221\345\255\246\351\231\242", nullptr));
        QTreeWidgetItem *___qtreewidgetitem22 = ___qtreewidgetitem21->child(0);
        ___qtreewidgetitem22->setText(0, QCoreApplication::translate("MainWindow", "\346\266\210\345\214\226\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem23 = ___qtreewidgetitem21->child(1);
        ___qtreewidgetitem23->setText(0, QCoreApplication::translate("MainWindow", "\345\221\274\345\220\270\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem24 = ___qtreewidgetitem21->child(2);
        ___qtreewidgetitem24->setText(0, QCoreApplication::translate("MainWindow", "\346\263\214\345\260\277\345\244\226\347\247\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem25 = ___qtreewidgetitem21->child(3);
        ___qtreewidgetitem25->setText(0, QCoreApplication::translate("MainWindow", "\344\270\255\345\214\273\347\247\221", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        CT_Img_Label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "CT\345\275\261\345\203\217", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\214\273\344\277\235\345\215\241\347\274\226\345\217\267\357\274\232", nullptr));
        photoLabel->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\347\205\247\347\211\207", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "\346\202\243\350\200\205\345\220\215", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_sex->setText(QCoreApplication::translate("MainWindow", "\347\224\267", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_age->setText(QCoreApplication::translate("MainWindow", "21", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\260\221\346\227\217\357\274\232", nullptr));
        label_ethic->setText(QCoreApplication::translate("MainWindow", "\346\261\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257", nullptr));
        caseTextEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\232\202\346\234\252\344\277\241\346\201\257</p></body></html>", nullptr));
        saveHistoryBtn->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\347\227\205\345\216\206", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "H:mm:ss", nullptr));
        label_horizon->setText(QCoreApplication::translate("MainWindow", "\344\272\256\345\272\246", nullptr));
        label_vertical->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\257\271\346\257\224\345\272\246</p></body></html>", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\227\205\347\201\266\346\243\200\346\265\213", nullptr));
        menuCT->setTitle(QCoreApplication::translate("MainWindow", "CT\347\233\270\347\211\207\345\244\204\347\220\206", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\351\230\210\345\200\274\345\244\204\347\220\206", nullptr));
        menu_CT->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\347\273\206\350\203\236\350\256\241\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
