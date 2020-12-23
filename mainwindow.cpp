#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBuffer>
#include<QFileDialog>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow ();
    //基本视图信息；
    model = new QSqlTableModel(this);
    model->setTable ("basic_inf");
    model->select ();//加载数据
    //附加详细信息视图
    model_d = new QSqlTableModel(this);
    model_d->setTable ("details_inf");
    model_d->select ();
    //数据网格信息加载
    ui->basicTableView->setModel (model);
    //初始化表单患者信息
    onTableSelectChange(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief 初始化窗体中要显示的CT相片及系统当前日期时间
 */
void MainWindow::initMainWindow()
{
    QString ctImgPath = "Tumor3.jpg";
    Mat ctImg = imread(ctImgPath.toLatin1 ().data ());
    cvtColor (ctImg,ctImg,COLOR_BGR2RGB);//转换色彩空间，opencv中的是BGR，Qt中的是RGB
    myCtImg = ctImg;
    Mat ctGrayImg;
    cvtColor (ctImg,ctGrayImg,COLOR_RGB2GRAY);
    myCtGrayImg = ctGrayImg;
    myCtQImage = QImage(ctImg.data,ctImg.cols,ctImg.rows,QImage::Format_RGB888);
    ctImgShow ();
    //时间日期更新
    QDate date = QDate::currentDate ();
    int year = date.year ();
    ui->yearLcdNumber->display (year);
    int month = date.month ();
    ui->monthLcdNumber->display (month);
    int day = date.day ();
    ui->dayLcdNumber->display (day);
    myTimer = new QTimer();
    myTimer->setInterval (1000);
    myTimer->start ();
    //绑定消息槽函数
    connect (myTimer,&QTimer::timeout ,this,&MainWindow::onTimeOut );
}

/**
 * @brief 读取CT照片
 */
void MainWindow::ctImgRead()
{
    QString ctImgName = QFileDialog::getOpenFileName(this,"载入CT相片",".","Image File (*.png *.jpg *.jepg *.bmp)");
    if(ctImgName.isEmpty ()) return;
    Mat ctRgbImg ,ctGrayImg;
    Mat ctImg = imread(ctImgName.toLatin1 ().data ());
    cvtColor (ctImg,ctRgbImg,COLOR_BGR2RGB);
    cvtColor (ctRgbImg,ctGrayImg,COLOR_RGB2GRAY);
    myCtImg = ctRgbImg;
    myCtGrayImg = ctGrayImg;
    myCtQImage = QImage(ctRgbImg.data,ctRgbImg.cols,ctRgbImg.rows,QImage::Format_RGB888);
    ctImgShow ();
}

void MainWindow::ctImgProc()
{
//    QTime time;
//    time.start ();
//    ui->progressBar->setValue (19);
//    while(time.elapsed ()<1000)
//    {
//        QCoreApplication::processEvents ();
//    }
    ctImgHoughCircles();//霍夫圆算法处理
//    while(time.elapsed ()<1000)
//    {
//        QCoreApplication::processEvents ();
//    }
    //ui->progressBar->setValue (ui->progressBar->value ()+20);
    ctImgShow ();//显示处理后的CT相片
//    while(time.elapsed ()<1000)
//    {
//        QCoreApplication::processEvents ();
//    }
   // ui->progressBar->setValue (ui->progressBar->maximum ());
    //QMessageBox::information (this,tr("完毕"),tr("子宫内壁见椭球形阴影，疑似子宫肌瘤"));

}

void MainWindow::ctImgShow()
{
    ui->CT_Img_Label->setPixmap (QPixmap::fromImage (myCtQImage.scaled (ui->CT_Img_Label->size (),Qt::KeepAspectRatio)));
}

void MainWindow::ctImgSave()
{
    QFile image("C:/Users/LUO/Desktop/CPP/Tumor_1.jpg");
    if(!image.open (QIODevice::ReadWrite)) return;
    QByteArray qba;
    QBuffer buf(&qba);
    buf.open (QIODevice::WriteOnly);
    myCtQImage.save (&buf,"JPG");
    image.write (qba);
}

void MainWindow::onTableSelectChange(int row)
{
    int r=1; //默认显示第一行
    //获取当前索引
    if(row!=0) r=ui->basicTableView->currentIndex ().row ();
    QModelIndex index;
    //姓名列
    index = model->index (r,1);
    ui->nameLabel->setText (model->data(index).toString ());
    //性别 列
    index = model->index (r,2);
    QString sex = model->data (index).toString ();
    (sex.compare ("男")==0) ? ui->maleRadioButton->setChecked (true):ui->femaleRadioButton->setChecked (true);
    //出生日期
    index = model->index (r,4);
    QDate date;
    int now = date.currentDate ().year ();
    int birth = model->data (index).toDate ().year ();
    ui->ageSpinBox->setValue (now-birth);//计算年龄
    //民族
    index = model->index (r,3);
    QString ethnic = model->data (index).toString ();
    ui->ethniComboBox->setCurrentText (ethnic);
    //医保卡号
    index = model->index (r,0);
    QString ssn = model->data (index).toString ();
    ui->ssnLineEdit->setText (ssn);
    showUserPhoto ();

}

void MainWindow::showUserPhoto()
{
    QPixmap photo;
    QModelIndex index;
    for(int i=0;i<model_d->rowCount ();i++)
    {
        index = model_d->index (i,0);
        QString current_name = model_d->data (index).toString ();
        if(current_name.compare (ui->nameLabel->text ()) == 0)
        {
            index = model_d->index (i,2);
            break;
        }

    }
    photo.loadFromData (model_d->data (index).toByteArray (),"JPG");
    ui->photoLabel->setPixmap (photo);
}

/**
 * @brief 使用Contrib扩展库中的霍夫圆算法检测和定位病灶所在的位置
 */
void MainWindow::ctImgHoughCircles()
{
    Mat ctGrayImg = myCtGrayImg.clone ();
    Mat ctColorImg;
    cvtColor (ctGrayImg,ctColorImg,COLOR_GRAY2BGR);
    GaussianBlur (ctGrayImg,ctGrayImg,Size(9,9),2,2);//对图像做高斯模糊，平滑处理
    vector<Vec3f> h_circles;//用向量数组存储病灶区圆圈
    int dp = ui->dp->text ().toInt ();
    int minDist = ui->minDist->text ().toInt ();
    int param1 = ui->param1->text ().toInt ();
    int param2 = ui->param2->text ().toInt ();
    HoughCircles (ctGrayImg,h_circles,HOUGH_GRADIENT,dp,minDist,param1,param2);
//    int processValue = 45;
//    ui->progressBar->setValue (processValue);
//    QTime time;
//    time.start ();
//    while(time.elapsed ()<1000)
//    {
//        QCoreApplication::processEvents ();
//    }
    qDebug() << h_circles.size();
    for(size_t i=0;i<h_circles.size();i++)
    {
        Point center(cvRound (h_circles[i][0]),cvRound (h_circles[i][1]));
        int h_radius = cvRound (h_circles[i][2]);
        circle(ctColorImg, Point(h_circles[i][0], h_circles[i][1]), h_circles[i][2], Scalar(0, 0, 255), 2);
        circle (ctColorImg,center,h_radius,Scalar(238,0,238),3,8,0);
        circle (ctColorImg,center,3,Scalar(238,0,0),-1,8,0);
//        processValue++;
//        ui->progressBar->setValue (processValue);
    }
    myCtImg = ctColorImg;
    myCtQImage = QImage(myCtImg.data,myCtImg.cols,myCtImg.rows,QImage::Format_RGB888);

}


void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked ()) ctImgRead ();

//    QTime time;
//    time.start ();
//    ui->progressBar->setMaximum (0);
//    ui->progressBar->setMinimum (0);
//    while(time.elapsed ()<5000)
//    {
//        QCoreApplication::processEvents ();//处理事件以保持界面刷新
//    }
//    ui->progressBar->setMaximum (100);
//    ui->progressBar->setMinimum (0);
    ctImgProc ();
   // ui->progressBar->setValue (0);
   // ctImgSave();
}

void MainWindow::on_basicTableView_clicked(const QModelIndex &index)
{
    onTableSelectChange (1);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    //填写病历
    if(index==1)
    {
        QModelIndex index;
        for(int i=0;i<model_d->rowCount ();i++)
        {
            index = model_d->index (i,0);
            QString current_name = model_d->data (index).toString ();
            if(current_name.compare (ui->nameLabel->text ())==0)
            {
                index = model_d->index (i,1);
                break;
            }
        }
        ui->caseTextEdit->setText (model_d->data (index).toString ());
        ui->caseTextEdit->setFont (QFont("楷体",12));
    }
}

void MainWindow::onTimeOut()
{
    QTime time= QTime::currentTime ();
    ui->timeEdit->setTime (time);
}
