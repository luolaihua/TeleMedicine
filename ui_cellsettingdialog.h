/********************************************************************************
** Form generated from reading UI file 'cellsettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLSETTINGDIALOG_H
#define UI_CELLSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_cellSettingDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *dpla;
    QSpinBox *noiseSpinBox;
    QLabel *minDist66;
    QLineEdit *upThreshold;
    QLabel *minDist66_2;
    QLineEdit *downThreshold;
    QSpinBox *erodeSpinBox;
    QLabel *label_11;
    QSpinBox *dilateSpinBox;
    QPushButton *resetParams;
    QDialogButtonBox *buttonBox_2;
    QLabel *label_10;

    void setupUi(QDialog *cellSettingDialog)
    {
        if (cellSettingDialog->objectName().isEmpty())
            cellSettingDialog->setObjectName(QString::fromUtf8("cellSettingDialog"));
        cellSettingDialog->resize(362, 201);
        horizontalLayout = new QHBoxLayout(cellSettingDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dpla = new QLabel(cellSettingDialog);
        dpla->setObjectName(QString::fromUtf8("dpla"));

        gridLayout->addWidget(dpla, 0, 0, 1, 1);

        noiseSpinBox = new QSpinBox(cellSettingDialog);
        noiseSpinBox->setObjectName(QString::fromUtf8("noiseSpinBox"));
        noiseSpinBox->setAlignment(Qt::AlignCenter);
        noiseSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        noiseSpinBox->setMinimum(3);
        noiseSpinBox->setMaximum(49);
        noiseSpinBox->setSingleStep(2);
        noiseSpinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        noiseSpinBox->setValue(25);

        gridLayout->addWidget(noiseSpinBox, 0, 2, 1, 1);

        minDist66 = new QLabel(cellSettingDialog);
        minDist66->setObjectName(QString::fromUtf8("minDist66"));

        gridLayout->addWidget(minDist66, 1, 0, 1, 2);

        upThreshold = new QLineEdit(cellSettingDialog);
        upThreshold->setObjectName(QString::fromUtf8("upThreshold"));
        upThreshold->setAlignment(Qt::AlignCenter);
        upThreshold->setClearButtonEnabled(false);

        gridLayout->addWidget(upThreshold, 1, 2, 1, 1);

        minDist66_2 = new QLabel(cellSettingDialog);
        minDist66_2->setObjectName(QString::fromUtf8("minDist66_2"));

        gridLayout->addWidget(minDist66_2, 2, 0, 1, 2);

        downThreshold = new QLineEdit(cellSettingDialog);
        downThreshold->setObjectName(QString::fromUtf8("downThreshold"));
        downThreshold->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(downThreshold, 2, 2, 1, 1);

        erodeSpinBox = new QSpinBox(cellSettingDialog);
        erodeSpinBox->setObjectName(QString::fromUtf8("erodeSpinBox"));
        erodeSpinBox->setAlignment(Qt::AlignCenter);
        erodeSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        erodeSpinBox->setMinimum(1);
        erodeSpinBox->setMaximum(9);
        erodeSpinBox->setSingleStep(2);
        erodeSpinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        erodeSpinBox->setValue(1);

        gridLayout->addWidget(erodeSpinBox, 3, 2, 1, 1);

        label_11 = new QLabel(cellSettingDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 0, 1, 1);

        dilateSpinBox = new QSpinBox(cellSettingDialog);
        dilateSpinBox->setObjectName(QString::fromUtf8("dilateSpinBox"));
        dilateSpinBox->setAlignment(Qt::AlignCenter);
        dilateSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dilateSpinBox->setMinimum(1);
        dilateSpinBox->setMaximum(9);
        dilateSpinBox->setSingleStep(2);
        dilateSpinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        dilateSpinBox->setValue(3);

        gridLayout->addWidget(dilateSpinBox, 4, 2, 1, 1);

        resetParams = new QPushButton(cellSettingDialog);
        resetParams->setObjectName(QString::fromUtf8("resetParams"));

        gridLayout->addWidget(resetParams, 5, 0, 1, 1);

        buttonBox_2 = new QDialogButtonBox(cellSettingDialog);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox_2, 5, 1, 1, 2);

        label_10 = new QLabel(cellSettingDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 3, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(cellSettingDialog);

        QMetaObject::connectSlotsByName(cellSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *cellSettingDialog)
    {
        cellSettingDialog->setWindowTitle(QCoreApplication::translate("cellSettingDialog", "Dialog", nullptr));
        dpla->setText(QCoreApplication::translate("cellSettingDialog", "\351\231\244\345\231\252\345\274\272\345\272\246", nullptr));
        minDist66->setText(QCoreApplication::translate("cellSettingDialog", "\350\276\271\347\274\230\346\243\200\346\265\213\344\270\212\351\230\210\345\200\274", nullptr));
        upThreshold->setInputMask(QString());
        upThreshold->setText(QCoreApplication::translate("cellSettingDialog", "100", nullptr));
        minDist66_2->setText(QCoreApplication::translate("cellSettingDialog", "\350\276\271\347\274\230\346\243\200\346\265\213\344\270\213\351\230\210\345\200\274", nullptr));
        downThreshold->setInputMask(QString());
        downThreshold->setText(QCoreApplication::translate("cellSettingDialog", "200", nullptr));
        label_11->setText(QCoreApplication::translate("cellSettingDialog", "\350\206\250\350\203\200\345\212\233\345\272\246", nullptr));
        resetParams->setText(QCoreApplication::translate("cellSettingDialog", "\351\207\215\347\275\256\345\217\202\346\225\260", nullptr));
        label_10->setText(QCoreApplication::translate("cellSettingDialog", "\350\205\220\350\232\200\345\212\233\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cellSettingDialog: public Ui_cellSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLSETTINGDIALOG_H
