#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
    class InputDialog;
}

class InputDialog : public QDialog {
    Q_OBJECT

  public:
    explicit InputDialog(QWidget* parent = nullptr);
    ~InputDialog();
    QStringList getData();
    double get_hough_dp();
    double get_hough_minDist();
    double get_hough_param1();
    double get_hough_param2();

    // TODO:重新选择功能未做
    // TODO:数据的回传显示
    // TODO:重置操作

  private:
    Ui::InputDialog* ui;
};

#endif  // INPUTDIALOG_H
