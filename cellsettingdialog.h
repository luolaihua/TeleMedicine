#ifndef CELLSETTINGDIALOG_H
#define CELLSETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class cellSettingDialog;
}

class cellSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit cellSettingDialog(QWidget *parent = nullptr);
    ~cellSettingDialog();
    int get_blur_ksize();
    int get_canny_up();
    int get_canny_down();
    int get_erode_size();
    int get_dilate_size();

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

    void on_resetParams_clicked();

private:
    Ui::cellSettingDialog *ui;
};

#endif // CELLSETTINGDIALOG_H
