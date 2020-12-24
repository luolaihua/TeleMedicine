#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
}

InputDialog::~InputDialog()
{
    delete ui;
}

QStringList InputDialog::getData()
{
    QStringList ret;
    ret<<ui->dp->text ()<<ui->minDist->text ()<<ui->param1->text ()<<ui->param2->text ();
    return ret;
}

double InputDialog::get_hough_dp()
{
    return ui->dp->text ().toDouble ();
}

double InputDialog::get_hough_minDist()
{
    return ui->minDist->text ().toDouble ();
}

double InputDialog::get_hough_param1()
{
    return ui->param1->text ().toDouble ();
}

double InputDialog::get_hough_param2()
{
    return ui->param2->text ().toDouble ();
}

