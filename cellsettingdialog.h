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
    int get_blur_ksize();//获取滤波参数
    int get_canny_up();//获取边缘检测参数
    int get_canny_down();//获取下边缘检测参数
    int get_erode_size();//获取腐蚀强度
    int get_dilate_size();//获取膨胀强度

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

    void on_resetParams_clicked();

private:
    Ui::cellSettingDialog *ui;
};

#endif // CELLSETTINGDIALOG_H
