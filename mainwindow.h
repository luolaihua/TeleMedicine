#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QDebug>
#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTimer>
#include<QTreeWidgetItem>
#include<QTreeWidget>
#include <opencv2/highgui/highgui.hpp>  //opencv高层GUI和媒体IO
#include <opencv2/imgproc/imgproc.hpp>  //opencv图象处理
#include <opencv2/opencv.hpp>

#include "inputdialog.h"
#include"cellsettingdialog.h"
using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void initData(); //初始化数据
    void initMainWindow();              //初始化主窗体
    void ctImgRead();                   //读取CT相片
    void ctImgProc();                   // CT相片处理
    void ctImgShow();                   // CT相片显示
    void ctImgSave();                   //保存
    void onTableSelectChange(int row);  //改变数据网格选项联动表单
    void showUserPhoto();               //加载显示患者照片
    void ctImgHoughCircles();           //用霍夫圆算法处理CT相片
    void ctImgPro_light(float contrat, int brightness);//调整亮度
    void ctImgPro_scale(float angle, float scale);//缩放
    void updateTime();//更新时间
    void ctImgBlur(QString type, int value);//滤波功能

  protected:
    bool eventFilter(QObject* obj, QEvent* event);

  private slots:
    void on_basicTableView_clicked(const QModelIndex& index);

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
    void slot_threshold(int type);
    void slot_cellCount();
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_saveHistoryBtn_clicked();

private:
    Ui::MainWindow* ui;
    Mat myProCtImg;           //处理之后的CT相片
    Mat myCtImg;              //缓存CT相片（供程序的方法使用随时引用）
    Mat myCtGrayImg;          //缓存CT灰度图（供程序算法处理用）
    QImage myCtQImage;        //保存CT相片（转为文件存档）
    QSqlTableModel* model;    //访问数据库视图信息的模型
    QSqlTableModel* model_d;  //访问数据库附加详细信息（病历、照片）视图的模型
    QTimer* myTimer;          //获取当前系统的时间（精确到秒）

    InputDialog* inputDlg;
    double hough_dp;
    double hough_minDist;
    double hough_param1;
    double hough_param2;

    int threshold_type;

    cellSettingDialog *cellDlg;
    //细胞计数参数
    int ksize ;
    int upThreshold ;
    int downThreshold ;
    int erodeSize ;
    int dilateSize ;
};
static bool createMySqlConn() {
    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QMYSQL");
    sqldb.setHostName("localhost");
    sqldb.setDatabaseName("patient");
    sqldb.setUserName("root");
    sqldb.setPassword("123456");
    if (!sqldb.open()) {
        QMessageBox::critical(0, QObject::tr("后台数据库连接失败"), "无法创建连接！请排查故障后重新启动",
                              QMessageBox::Cancel);
        return false;
    }
    // QMessageBox::information (0,QObject::tr("后台数据库已启动、正在运行……"),"数据库连接成功，即将启动程序。");

/*
    //创建SQL查询
    QSqlQuery query(sqldb);
    //向数据库中插入数据
//    QString insStr = "insert into user_profile values('320199101011806888','张美丽','女','汉','1986-03-04','南京市高淳区淳溪镇汶溪路666号','暂无',null)";
//    if(!query.exec (insStr)){
//        qDebug() << "插入失败";
//    }else{
//        qDebug() << "插入成功";
//    }
    //向数据库中插入照片
    //照片路径
    QString photoPath = "C:\\Users\\LUO\\Desktop\\10.jpg";
    //照片文件对象
    QFile photoFile(photoPath);

    //判断照片是否存在
    if(photoFile.exists ()){
        //存在的话就存入数据库
        //用字节数组存储图片数据
        QByteArray picData;
        //用只读的方式打开图片文件
        photoFile.open (QIODevice::ReadOnly);
        //将图片数据读入字节数组
        picData = photoFile.readAll ();
        //文件关闭
        photoFile.close ();
        //将照片数据封装成变量
        QVariant var(picData);
        //更新的sql语句
        QString sqlstr = "update user_profile set picture=? where name='葛二妮'";
//                QString sqlstr = "insert into user_profile values('320199101011806999','张美兰','女','汉','1996-12-04','南京市高淳区淳溪镇汶溪路999号','暂无',?)";
        query.prepare (sqlstr);
        //绑定数据，填入照片数据参数
        query.addBindValue (var);
        //执行更新操作
        if(!query.exec ()){
            qDebug() << "插入照片失败";
        }else{
            qDebug() << "插入照片成功";
        }
    }
*/
    sqldb.close();
    return true;
}
#endif  // MAINWINDOW_H
