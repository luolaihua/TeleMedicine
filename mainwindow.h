#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>//opencv高层GUI和媒体IO
#include<opencv2/imgproc/imgproc.hpp>//opencv图象处理
#include<QSqlTableModel>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QTimer>
#include"inputdialog.h"
using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initMainWindow();//初始化主窗体
    void ctImgRead();//读取CT相片
    void ctImgProc();//CT相片处理
    void ctImgShow();//CT相片显示
    void ctImgSave();//保存
    void onTableSelectChange(int row);//改变数据网格选项联动表单
    void showUserPhoto();//加载显示患者照片
    void ctImgHoughCircles();//用霍夫圆算法处理CT相片
    void ctImgPro_light(float contrat,int brightness);
    void ctImgPro_scale(float angle,float scale);
    void updateTime();

    void ctImgBlur(QString type,int value);


protected:
    bool eventFilter(QObject *obj,QEvent *event);


private slots:
    void on_basicTableView_clicked(const QModelIndex &index);

    void on_tabWidget_tabBarClicked(int index);

    void onTimeOut();
    void slot_getParams();
    void slot_resetCT();
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_sliderMoved(int position);

    void on_verticalSlider_valueChanged(int value);

    void on_verticalSlider_sliderMoved(int position);

    void slot_img2Gray();
    void slot_guassianBlur();
    void slot_bilateBlur();
    void slot_clearNoise();


private:
    Ui::MainWindow *ui;
    Mat myProCtImg;//处理之后的CT相片
    Mat myCtImg;//缓存CT相片（供程序的方法使用随时引用）
    Mat myCtGrayImg;//缓存CT灰度图（供程序算法处理用）
    QImage myCtQImage;//保存CT相片（转为文件存档）
    QSqlTableModel *model;//访问数据库视图信息的模型
    QSqlTableModel *model_d;//访问数据库附加详细信息（病历、照片）视图的模型
    QTimer *myTimer;//获取当前系统的时间（精确到秒）

    InputDialog *inputDlg;
    double hough_dp;
    double hough_minDist;
    double hough_param1;
    double hough_param2;


};
static bool createMySqlConn()
{
    QSqlDatabase sqldb = QSqlDatabase::addDatabase ("QMYSQL");
    sqldb.setHostName ("localhost");
    sqldb.setDatabaseName ("patient");
    sqldb.setUserName ("root");
    sqldb.setPassword ("123456");
    if(!sqldb.open ())
    {
        QMessageBox::critical(0,QObject::tr("后台数据库连接失败"),"无法创建连接！请排查故障后重新启动",QMessageBox::Cancel);
        return false;
    }
    //QMessageBox::information (0,QObject::tr("后台数据库已启动、正在运行……"),"数据库连接成功，即将启动程序。");
    sqldb.close ();
    return true;

}
#endif // MAINWINDOW_H
