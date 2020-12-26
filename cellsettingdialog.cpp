#include "cellsettingdialog.h"
#include "ui_cellsettingdialog.h"

cellSettingDialog::cellSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cellSettingDialog)
{
    ui->setupUi(this);
}

cellSettingDialog::~cellSettingDialog()
{
    delete ui;
}

int cellSettingDialog::get_blur_ksize()
{
   return  ui->noiseSpinBox->value ();
}

int cellSettingDialog::get_canny_up()
{
    return  ui->upThreshold->text ().toInt ();
}

int cellSettingDialog::get_canny_down()
{
    return  ui->downThreshold->text ().toInt ();
}

int cellSettingDialog::get_erode_size()
{
    return  ui->erodeSpinBox->value ();
}

int cellSettingDialog::get_dilate_size()
{
    return  ui->dilateSpinBox->value ();
}

void cellSettingDialog::on_buttonBox_2_accepted()
{
    accept ();
}

void cellSettingDialog::on_buttonBox_2_rejected()
{
    reject ();
}

void cellSettingDialog::on_resetParams_clicked()
{
    ui->noiseSpinBox->setValue (25);
    ui->dilateSpinBox->setValue (3);
    ui->erodeSpinBox->setValue (1);
    ui->upThreshold->setText ("100");
    ui->downThreshold->setText ("200");
}
