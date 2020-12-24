/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InputDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *minDist;
    QLabel *label_10;
    QLineEdit *param1;
    QLabel *dpla;
    QLabel *minDist66;
    QPushButton *resetParams;
    QCheckBox *isRechoose;
    QLineEdit *param2;
    QLineEdit *dp;
    QLabel *label_9;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InputDialog)
    {
        if (InputDialog->objectName().isEmpty())
            InputDialog->setObjectName(QString::fromUtf8("InputDialog"));
        InputDialog->resize(287, 196);
        gridLayout_2 = new QGridLayout(InputDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        minDist = new QLineEdit(InputDialog);
        minDist->setObjectName(QString::fromUtf8("minDist"));

        gridLayout->addWidget(minDist, 1, 1, 1, 1);

        label_10 = new QLabel(InputDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 3, 0, 1, 1);

        param1 = new QLineEdit(InputDialog);
        param1->setObjectName(QString::fromUtf8("param1"));

        gridLayout->addWidget(param1, 2, 1, 1, 1);

        dpla = new QLabel(InputDialog);
        dpla->setObjectName(QString::fromUtf8("dpla"));

        gridLayout->addWidget(dpla, 0, 0, 1, 1);

        minDist66 = new QLabel(InputDialog);
        minDist66->setObjectName(QString::fromUtf8("minDist66"));

        gridLayout->addWidget(minDist66, 1, 0, 1, 1);

        resetParams = new QPushButton(InputDialog);
        resetParams->setObjectName(QString::fromUtf8("resetParams"));

        gridLayout->addWidget(resetParams, 5, 0, 1, 1);

        isRechoose = new QCheckBox(InputDialog);
        isRechoose->setObjectName(QString::fromUtf8("isRechoose"));

        gridLayout->addWidget(isRechoose, 4, 1, 1, 1);

        param2 = new QLineEdit(InputDialog);
        param2->setObjectName(QString::fromUtf8("param2"));

        gridLayout->addWidget(param2, 3, 1, 1, 1);

        dp = new QLineEdit(InputDialog);
        dp->setObjectName(QString::fromUtf8("dp"));

        gridLayout->addWidget(dp, 0, 1, 1, 1);

        label_9 = new QLabel(InputDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(InputDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 1, 1, 1);

        gridLayout->setRowStretch(5, 1);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(InputDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InputDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InputDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InputDialog);
    } // setupUi

    void retranslateUi(QDialog *InputDialog)
    {
        InputDialog->setWindowTitle(QCoreApplication::translate("InputDialog", "Dialog", nullptr));
        minDist->setInputMask(QString());
        minDist->setText(QCoreApplication::translate("InputDialog", "100", nullptr));
        label_10->setText(QCoreApplication::translate("InputDialog", "param2", nullptr));
        param1->setInputMask(QString());
        param1->setText(QCoreApplication::translate("InputDialog", "100", nullptr));
        dpla->setText(QCoreApplication::translate("InputDialog", "dp", nullptr));
        minDist66->setText(QCoreApplication::translate("InputDialog", "minDist", nullptr));
        resetParams->setText(QCoreApplication::translate("InputDialog", "\351\207\215\347\275\256\345\217\202\346\225\260", nullptr));
        isRechoose->setText(QCoreApplication::translate("InputDialog", "\351\207\215\346\226\260\351\200\211\346\213\251CT\347\233\270\347\211\207", nullptr));
        param2->setInputMask(QString());
        param2->setText(QCoreApplication::translate("InputDialog", "100", nullptr));
        dp->setInputMask(QString());
        dp->setText(QCoreApplication::translate("InputDialog", "2", nullptr));
        label_9->setText(QCoreApplication::translate("InputDialog", "param1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputDialog: public Ui_InputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
