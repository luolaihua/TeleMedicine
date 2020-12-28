#include "mainwindow.h"

#include <QBuffer>
#include <QFileDialog>
#include <QMouseEvent>
#include<QDebug>
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
    //使用了列表初始化，三种情况必须要用：常成员，引用类型 成员，无默认构造函数的类成员对象。
    ,
    hough_dp(2), hough_minDist(100), hough_param1(100), hough_param2(100), threshold_type(0),ksize(21),upThreshold(100),downThreshold(200),erodeSize(1),dilateSize(3) {
    ui->setupUi(this);
    initMainWindow();
    initData ();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::initData()
{
    //参数输入窗口
    inputDlg = new InputDialog(this);
    cellDlg = new cellSettingDialog(this);
    //基本视图信息；
    model = new QSqlTableModel(this);
    model->setTable("basic_inf");
    model->select();  //加载数据
    //附加详细信息视图
    model_d = new QSqlTableModel(this);
    model_d->setTable("details_inf");
    model_d->select();
//    //数据网格信息加载
//    ui->basicTableView->setModel(model);
//    //初始化表单患者信息
//    onTableSelectChange(0);
}
/**
 * @brief 初始化窗体中要显示的CT相片及系统当前日期时间
 */
void MainWindow::initMainWindow() {
    //QString ctImgPath = ":/Tumor.jpg";
    //Mat ctImg = imread(ctImgPath.toLatin1().data());
    Mat ctImg;
    QFile file(":/CT.jpg");
    QByteArray ba;
    if(!file.open(QFile::ReadOnly))
    {
        qDebug("读取失败");
    }else{
        ba = file.readAll();
        ctImg = imdecode(vector<char>(ba.begin(), ba.end()), 1);
    }
    if(ctImg.empty ()){
        qDebug("图像为空");
    }
    cvtColor(ctImg, ctImg, COLOR_BGR2RGB);  //转换色彩空间，opencv中的是BGR，Qt中的是RGB
    myCtImg = ctImg;
    myProCtImg = ctImg;
    Mat ctGrayImg;
    cvtColor(ctImg, ctGrayImg, COLOR_RGB2GRAY);
    myCtGrayImg = ctGrayImg;

    myCtQImage = QImage(ctImg.data, ctImg.cols, ctImg.rows, QImage::Format_RGB888);

    //ui->Img_Label->setText ("What's going wrong?");
    //ctImgShow();
    //更新时间
    updateTime();
    //连接所有信号槽
    connectAll ();
    //给CT照片的label安装事件过滤器
    //ui->CT_Img_Label->installEventFilter(this);


}
/**
 * @brief 过滤出CT_Img_Label的双击事件
 * @param watched 被安装过滤器的对象，可能不止一个
 * @param event 处理它的事件
 * @return
 */
//处理步骤：先找到相应的对象，在找到相应的事件
//bool MainWindow::eventFilter(QObject* watched, QEvent* event) {
//    //return QMainWindow::eventFilter(watched, event);
//    //过滤出CT_Img_Label对象
//    if (watched == ui->CT_Img_Label) {
//        //判断是否是双击事件
//        if (event->type() == QEvent::MouseButtonDblClick) {
//            //可以将QEvent转成QMouseEvent
//            // QMouseEvent *mouseE = static_cast<QMouseEvent*>(event);
//            qDebug() << "MouseButtonDblClick";
//            imshow("CT", myCtImg);
//            return true;
//        }else if(event->type() == QEvent::MouseButtonPress){
//            //可以将QEvent转成QMouseEvent
//            QMouseEvent *mouseE = static_cast<QMouseEvent*>(event);
//            qDebug()<< "test:"<<mouseE->pos ();
//        }
//    } else {
//        //将其他事件交给父类
//        return QMainWindow::eventFilter(watched, event);
//    }
//}

void MainWindow::ctImgShow() {
    // QImage img(":/CT.jpg");
    ui->CT_Img_Label->setPixmap(QPixmap::fromImage(myCtQImage.scaled(ui->CT_Img_Label->size(), Qt::KeepAspectRatio)));
}
void MainWindow::connectAll(){
    //绑定消息槽函数
    connect(ui->actionStart, &QAction::triggered, this, &MainWindow::ctImgProc);
    connect(ui->actionparamSet, &QAction::triggered, this, &MainWindow::slot_getParams);
    connect(ui->actionresetCT, &QAction::triggered, this, &MainWindow::slot_resetCT);
    //旋转缩放，对比度亮度调节
    ui->label_horizon->hide();
    ui->label_vertical->hide();
    ui->horizontalSlider->hide();
    ui->verticalSlider->hide();
    connect(ui->actionlight, &QAction::triggered, [=]() {
        ui->label_horizon->setText("亮度");
        ui->label_vertical->setText("对比度");
        ui->label_horizon->show();
        ui->label_vertical->show();
        ui->horizontalSlider->show();
        ui->verticalSlider->show();
    });
    connect(ui->actionscale, &QAction::triggered, [=]() {
        ui->label_horizon->setText("旋转");
        ui->label_vertical->setText("缩放");
        ui->label_horizon->show();
        ui->label_vertical->show();
        ui->horizontalSlider->show();
        ui->verticalSlider->show();
    });

    //文件菜单中的三个action
    //退出动作
    connect(ui->actionexit, &QAction::triggered, this, &MainWindow::close);
    //重新读取CT照片动作
    connect(ui->actionreadCT, &QAction::triggered, this, &MainWindow::ctImgRead);
    //保存CT
    connect(ui->actionsaveCT, &QAction::triggered, this, &MainWindow::ctImgSave);

    /// CT相片处理中的动作
    connect(ui->actiongray, &QAction::triggered, this, &MainWindow::slot_img2Gray);
    //高斯滤波
    connect(ui->actionguassainBlur, &QAction::triggered, this, &MainWindow::slot_guassianBlur);
    connect(ui->actionbitlateBlur, &QAction::triggered, this, &MainWindow::slot_bilateBlur);
    //    connect(ui->actionclearNoise, &QAction::triggered, this, &MainWindow::slot_clearNoise);
    //阈值动作
    connect(ui->action0, &QAction::triggered, this, [=]() { slot_threshold(0); });
    connect(ui->action1, &QAction::triggered, this, [=]() { slot_threshold(1); });
    connect(ui->action2, &QAction::triggered, this, [=]() { slot_threshold(2); });
    connect(ui->action3, &QAction::triggered, this, [=]() { slot_threshold(3); });
    connect(ui->action4, &QAction::triggered, this, [=]() { slot_threshold(4); });

    //细胞计数动作
    connect(ui->actionimportCell, &QAction::triggered, this, [=]() { ctImgRead(); });
    connect(ui->actionstartCount, &QAction::triggered, this, &MainWindow::slot_cellCount);
    connect(ui->actioncellSetting, &QAction::triggered, this, [=]() {
        cellDlg->show();
    });
}

void MainWindow::updateTime() {
    //时间日期更新
    QDate date = QDate::currentDate();
    int year = date.year();
    ui->yearLcdNumber->display(year);
    int month = date.month();
    ui->monthLcdNumber->display(month);
    int day = date.day();
    ui->dayLcdNumber->display(day);
    myTimer = new QTimer();
    myTimer->setInterval(1000);
    myTimer->start();
    connect(myTimer, &QTimer::timeout, this, &MainWindow::onTimeOut);
}

void MainWindow::ctImgBlur(QString type, int value) {
    // qDebug() << "type:" << type << " value:" << value;
    Mat procImg = myProCtImg;
    Mat imgDst;
    if (type == "高斯滤波") {
        int i = ((value / 3) % 2 == 0) ? (value / 3) + 1 : (value / 3);
        qDebug() << i;
        GaussianBlur(procImg, imgDst, Size(i, i), 0, 0);
    } else if (type == "双边滤波") {
        int i = value / 3;
        bilateralFilter(procImg, imgDst, i, i * 2, i / 2);

    } else if (type == "阈值") {
        double i = value * 2.5;
        //        Mat grayImg;
        //        cvtColor(myCtImg, grayImg, COLOR_RGB2GRAY);
        //        //        imshow("", grayImg);
        threshold(procImg, imgDst, i, 255, threshold_type);
    }

    enum QImage::Format m = (imgDst.channels() > 1) ? QImage::Format_RGB888 : QImage::Format_Grayscale8;
    myCtQImage = QImage(imgDst.data, imgDst.cols, imgDst.rows, m);
    ctImgShow();
}
/**
 * @brief 读取CT照片
 */
void MainWindow::ctImgRead() {
    QString ctImgName = QFileDialog::getOpenFileName(this, "载入CT相片", ".", "Image File (*.png *.jpg *.jepg *.bmp)");
    if (ctImgName.isEmpty())
        return;
    Mat ctRgbImg, ctGrayImg;
    Mat ctImg = imread(ctImgName.toLatin1().data());
    cvtColor(ctImg, ctRgbImg, COLOR_BGR2RGB);
    cvtColor(ctRgbImg, ctGrayImg, COLOR_RGB2GRAY);
    myCtImg = ctRgbImg;
    myCtGrayImg = ctGrayImg;
    myCtQImage = QImage(ctRgbImg.data, ctRgbImg.cols, ctRgbImg.rows, QImage::Format_RGB888);
    ctImgShow();
}

void MainWindow::ctImgProc() {
    //    QTime time;
    //    time.start ();
    //    ui->progressBar->setValue (19);
    //    while(time.elapsed ()<1000)
    //    {
    //        QCoreApplication::processEvents ();
    //    }
    ctImgHoughCircles();  //霍夫圆算法处理
    //    while(time.elapsed ()<1000)
    //    {
    //        QCoreApplication::processEvents ();
    //    }
    // ui->progressBar->setValue (ui->progressBar->value ()+20);
    ctImgShow();  //显示处理后的CT相片
    //    while(time.elapsed ()<1000)
    //    {
    //        QCoreApplication::processEvents ();
    //    }
    // ui->progressBar->setValue (ui->progressBar->maximum ());
    // QMessageBox::information (this,tr("完毕"),tr("子宫内壁见椭球形阴影，疑似子宫肌瘤"));
}


/**
 * @brief 将图片另存
 */
void MainWindow::ctImgSave() {
    QString fileName =
        QFileDialog::getSaveFileName(this, tr("Sava CT"), "untitled.jpg", tr("Images (*.png *.bmp *.jpg)"));
    qDebug() << fileName;
    if (!fileName.isEmpty()) {
        QFile image(fileName);
        if (!image.open(QIODevice::ReadWrite))
            return;
        QByteArray qba;
        QBuffer buf(&qba);
        buf.open(QIODevice::WriteOnly);
        myCtQImage.save(&buf, "JPG");
        image.write(qba);
        QMessageBox::information(this, "保存CT", QString("成功将图片保存在\n") + fileName);
    }
}


/**
 * @brief 使用Contrib扩展库中的霍夫圆算法检测和定位病灶所在的位置
 */
void MainWindow::ctImgHoughCircles() {
    Mat ctGrayImg = myCtGrayImg.clone();
    Mat ctColorImg;
    cvtColor(ctGrayImg, ctColorImg, COLOR_GRAY2BGR);
    GaussianBlur(ctGrayImg, ctGrayImg, Size(9, 9), 2, 2);  //对图像做高斯模糊，平滑处理
    vector<Vec3f> h_circles;                               //用向量数组存储病灶区圆圈

    int dp = hough_dp > 0 ? hough_dp : 2;
    int minDist = hough_minDist > 0 ? hough_minDist : 100;
    int param1 = hough_param1 > 0 ? hough_param1 : 100;
    int param2 = hough_param2 > 0 ? hough_param2 : 100;

    HoughCircles(ctGrayImg, h_circles, HOUGH_GRADIENT, dp, minDist, param1, param2);
    //    int processValue = 45;
    //    ui->progressBar->setValue (processValue);
    //    QTime time;
    //    time.start ();
    //    while(time.elapsed ()<1000)
    //    {
    //        QCoreApplication::processEvents ();
    //    }
    qDebug() << h_circles.size();
    for (size_t i = 0; i < h_circles.size(); i++) {
        Point center(cvRound(h_circles[i][0]), cvRound(h_circles[i][1]));
        int h_radius = cvRound(h_circles[i][2]);
        // circle(ctColorImg, Point(h_circles[i][0], h_circles[i][1]), h_circles[i][2], Scalar(0, 0, 255), 2);
        circle(ctColorImg, center, h_radius, Scalar(238, 0, 238), 3, 8, 0);
        circle(ctColorImg, center, 3, Scalar(238, 0, 0), -1, 8, 0);
        //        processValue++;
        //        ui->progressBar->setValue (processValue);
    }
    myProCtImg = ctColorImg;
    myCtQImage = QImage(myProCtImg.data, myProCtImg.cols, myProCtImg.rows, QImage::Format_RGB888);
}

void MainWindow::ctImgPro_light(float contrat, int brightness) {
    // qDebug() << "contrat:"<<contrat<<"brightness"<<brightness;
    Mat imgSrc = myCtImg;
    Mat imgDst = Mat::zeros(imgSrc.size(), imgSrc.type());  //初始生成0像素矩阵
    imgSrc.convertTo(imgDst, -1, contrat, brightness);

    myCtQImage = QImage(imgDst.data, imgDst.cols, imgDst.rows, QImage::Format_RGB888);
    ctImgShow();
}

void MainWindow::ctImgPro_scale(float angle, float scale) {
    // qDebug() << "angle:"<<angle<<"scale："<<scale;
    Mat imgSrc = myCtImg;
    Mat imgDst;
    Point centerPoint = Point(imgSrc.cols / 2, imgSrc.rows / 2);
    //这是仿射变换矩阵
    Mat imgRot = getRotationMatrix2D(centerPoint, angle, scale);
    warpAffine(imgSrc, imgDst, imgRot, myCtImg.size());

    myCtQImage = QImage(imgDst.data, imgDst.cols, imgDst.rows, QImage::Format_RGB888);
    ctImgShow();
}



void MainWindow::onTimeOut() {
    QTime time = QTime::currentTime();
    ui->timeEdit->setTime(time);
}

void MainWindow::slot_getParams() {
    inputDlg->show();
    //按下的是Cancel键,通过exec判断按的是哪个按钮
    if (inputDlg->exec() == InputDialog::Accepted) {
        qDebug("确认");
        hough_dp = inputDlg->get_hough_dp();
        hough_minDist = inputDlg->get_hough_minDist();
        hough_param1 = inputDlg->get_hough_param1();
        hough_param2 = inputDlg->get_hough_param2();
        ctImgProc();
    }
    //按下的是OK键
    else {
        qDebug("取消");
    }
    qDebug() << "hough_dp: " << hough_dp << "hough_minDist: " << hough_minDist << "hough_param1: " << hough_param1
             << "hough_param2: " << hough_param2;
}

void MainWindow::slot_resetCT() {
    // imshow ("",myCtImg);
    myProCtImg = myCtImg;
    myCtQImage = QImage(myCtImg.data, myCtImg.cols, myCtImg.rows, QImage::Format_RGB888);
    ctImgShow();
}

//水平方向是亮度和旋转；滤波功能
void MainWindow::on_horizontalSlider_valueChanged(int value) {
    QString text = ui->label_horizon->text();
    if (text == "亮度") {
        ctImgPro_light(1.0, value);
    } else if (text == "对比度") {
        ctImgPro_scale((value / 100.0) * 720.0 - 360, ui->verticalSlider->value() / 30.0);
    } else {
        ctImgBlur(text, value);
    }
}
//水平方向是亮度和旋转
void MainWindow::on_horizontalSlider_sliderMoved(int position) {
    QString text = ui->label_horizon->text();
    if (text == "亮度") {
        ctImgPro_light(1.0, position);
    } else if (text == "对比度") {
        ctImgPro_scale((position / 100.0) * 720.0 - 360, ui->verticalSlider->value() / 30.0);
    } else {
        ctImgBlur(text, position);
    }
}
//垂直方向是缩放和对比度
void MainWindow::on_verticalSlider_valueChanged(int value) {
    if (ui->label_horizon->text() == "亮度") {
        ctImgPro_light(value / 33.0, 0);
    } else {
        ctImgPro_scale((ui->horizontalSlider->value() / 100.0) * 720.0 - 360, value / 30.0);
    }
}
//垂直方向是缩放和对比度
void MainWindow::on_verticalSlider_sliderMoved(int position) {
    if (ui->label_horizon->text() == "亮度") {
        ctImgPro_light(position / 33.0, 0);
    } else {
        ctImgPro_scale((ui->horizontalSlider->value() / 100.0) * 720.0 - 360, position / 30.0);
    }
}

/**
 * @brief 二值化操作
 */
void MainWindow::slot_img2Gray() {
    // imshow ("",myCtGrayImg);
    myCtQImage = QImage(myCtGrayImg.data, myCtGrayImg.cols, myCtGrayImg.rows, QImage::Format_Grayscale8);
    ctImgShow();
    myProCtImg = myCtGrayImg;
}

/**
 * @brief 高斯滤波
 */
void MainWindow::slot_guassianBlur() {
    Mat proImg = myProCtImg;
    ui->label_horizon->show();
    ui->horizontalSlider->setValue(10);
    ui->horizontalSlider->show();
    ui->label_horizon->setText("高斯滤波");
    ui->label_vertical->hide();
    ui->verticalSlider->hide();
    ui->horizontalSlider->setValue(10);
}

void MainWindow::slot_bilateBlur() {
    Mat proImg = myProCtImg;
    ui->label_horizon->show();
    ui->horizontalSlider->setValue(10);
    ui->horizontalSlider->show();
    ui->label_horizon->setText("双边滤波");
    ui->label_vertical->hide();
    ui->verticalSlider->hide();
}

void MainWindow::slot_threshold(int type) {
    threshold_type = type;
    Mat proImg = myProCtImg;
    ui->label_horizon->show();
    ui->horizontalSlider->setValue(10);
    ui->horizontalSlider->show();
    ui->label_horizon->setText("阈值");
    ui->label_vertical->hide();
    ui->verticalSlider->hide();
    ui->horizontalSlider->setValue(10);
}
//填充
void fillHole(const Mat srcBw, Mat& dstBw) {
    Size m_Size = srcBw.size();
    Mat Temp = Mat::zeros(m_Size.height + 2, m_Size.width + 2, srcBw.type());  //延展图像
    srcBw.copyTo(Temp(Range(1, m_Size.height + 1), Range(1, m_Size.width + 1)));

    //选择（0，0）作为种子点，归入种子点区域内像素点的新像素值为255（白色）
    cv::floodFill(Temp, Point(0, 0), Scalar(255));  //填充区域

    Mat cutImg;  //裁剪延展的图像
    Temp(Range(1, m_Size.height + 1), Range(1, m_Size.width + 1)).copyTo(cutImg);

    dstBw = srcBw | (~cutImg);
}
void MainWindow::slot_cellCount() {
//    ///opencv矩阵赋值函数copyTo、clone、重载元算赋‘=’之间实现的功能相似均是给不同的矩阵赋值功能。

//    copyTo和clone函数基本相同，被赋值的矩阵和赋值矩阵之间空间独立，不共享同一空间。

//        但是重载元算赋‘=’，被赋值的矩阵和赋值矩阵之间空间共享，改变任一个矩阵的值，会同时影响到另一个矩阵。当矩阵作为函数的返回值时其功能和重载元算赋‘=’相同，赋值运算赋会给矩阵空间增加一次计数，所以函数变量返回后函数内部申请的变量空间并不会被撤销，在主函数中仍可以正常使用传递后的参数。
    Mat srcImg = myCtImg.clone ();
    Mat srcGrayImage = myCtGrayImg.clone ();

    ksize = cellDlg->get_blur_ksize ();
    upThreshold = cellDlg->get_canny_up ();
    downThreshold = cellDlg->get_canny_down ();
    erodeSize = cellDlg->get_erode_size ();
    dilateSize = cellDlg->get_dilate_size ();
    //qDebug() << ksize;

    // TODO 参数输入做安全检查


    // resize(srcImg, srcImg, Size(200, 200));//重定义图片大小
    //    namedWindow("原图", 0);
    //    imshow("原图", srcImg);

    //灰度化
    // cvtColor(srcImg, srcGrayImage, COLOR_BGR2GRAY);

    //二值化，也可以使用阈值处理threshold
    srcGrayImage = srcGrayImage > 160;
    // threshold(srcImage, srcImage, 0, 255, THRESH_OTSU);

    //创建一个8比特单通道的与原图尺寸相同的空Mat
    Mat vec_rgb = Mat::zeros(srcGrayImage.size(), CV_8UC1);

    //对原图做中值滤波，结果保存在vec_rgb,初步除噪，如果滤波之后还有很多杂点，尝试提高ksize
    medianBlur(srcGrayImage, vec_rgb, ksize);
    //    namedWindow("中值滤波", 0);
    //    imshow("中值滤波", vec_rgb);

    /// Reduce noise with a kernel 3x3
    // blur(srcImage, vec_rgb, Size(3, 3));

    /// 边缘检测，输入的是单通道图像，主要是靠上阀值和下阀值，
    Canny(vec_rgb, vec_rgb, upThreshold, downThreshold, 3);
    //    namedWindow("边缘检测", 0);
    //    imshow("边缘检测", vec_rgb);

    fillHole(vec_rgb, vec_rgb);  //填充
                                 //    namedWindow("填充", 0);
                                 //    imshow("填充", vec_rgb);

    //先腐蚀再膨胀，除噪 ,getStructuringElement函数经常与腐蚀膨胀操作配套使用
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2 * erodeSize + 1, 2 * erodeSize + 1), Point(erodeSize, erodeSize));
    erode(vec_rgb, vec_rgb, element);  //腐蚀
                                       //    namedWindow("腐蚀", 0);
                                       //    imshow("腐蚀", vec_rgb);

    Mat element1 = getStructuringElement(MORPH_ELLIPSE, Size(2 * dilateSize + 1, 2 * dilateSize + 1), Point(dilateSize, dilateSize));
    dilate(vec_rgb, vec_rgb, element1);  //膨胀
                                         //    namedWindow("膨胀", 0);
                                         //    imshow("膨胀", vec_rgb);

    //开始找寻轮廓
    vector<vector<Point>> contours;  //轮廓
    vector<Vec4i> hierarchy;         //分层

    Point centerPoint;  //红色灯的中点

    //轮廓的检索模式为RETR_LIST，检测所有的轮廓，包括内围、外围轮廓，但是检测到的轮廓不建立等级关
    //系，彼此之间独立，没有等级关系，这就意味着这个检索模式下不存在父轮廓或内嵌轮廓，
    //	所以hierarchy向量内所有元素的第3、第4个分量都会被置为 - 1
    //定义轮廓的近似方法为CHAIN_APPROX_NONE，保存物体边界上所有连续的轮廓点到contours向量内
    findContours(vec_rgb, contours, hierarchy, RETR_LIST, CHAIN_APPROX_NONE, Point(0, 0));  //寻找轮廓

    vector<vector<Point>> contours_poly(contours.size());  //近似后的轮廓点集
    vector<Rect> boundRect(contours.size());               //包围点集的最小矩形vector
    vector<Point2f> center(contours.size());               //包围点集的最小圆形vector
    vector<float> radius(contours.size());                 //包围点集的最小圆形半径vector

    for (int i = 0; i < contours.size(); i++) {
        /**
         *approxPolyDP 函数：主要功能是把一个连续光滑曲线折线化
         */
        approxPolyDP(Mat(contours[i]), contours_poly[i], 3,
                     true);  //对多边形曲线做适当近似，contours_poly[i]是输出的近似点集
        /**
         * boundingRect 函数：计算轮廓的垂直边界最小矩形，矩形是与图像上下边界平行的
         * 读入的参数必须是vector或者Mat点集
         */
        boundRect[i] = boundingRect(Mat(contours_poly[i]));  //计算并返回包围轮廓点集的最小矩形
        /**
         * 寻找包裹轮廓的最小圆：minEnclosingCircle 函数
         */
        minEnclosingCircle(contours_poly[i], center[i], radius[i]);  //计算并返回包围轮廓点集的最小圆形及其半径
        // cout << "细胞颗粒坐标" << center[i] << endl;
    }

    Mat drawing = Mat::zeros(vec_rgb.size(), CV_8UC3);
    for (int i = 0; i < contours.size(); i++) {
        Scalar color = (0, 0, 255);  //蓝色线画轮廓
        /**
         * drawContours函数的作用:主要用于画出图像的轮廓
         */
        drawContours(drawing, contours_poly, i, color, 1, 4, hierarchy, 0,
                     Point());  //根据轮廓点集contours_poly和轮廓结构hierarchy画出轮廓
        //画矩形
        /**
         * void rectangle(InputOutputArray img, Point pt1, Point pt2,
                          const Scalar& color, int thickness = 1,
                          int lineType = LINE_8, int shift = 0);
         */
        rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);  //画矩形，tl矩形左上角，br右上角
        //画圆
        /**
         * CV_EXPORTS_W void circle(InputOutputArray img, Point center, int radius,
                       const Scalar& color, int thickness = 1,
                       int lineType = LINE_8, int shift = 0);
         */
        circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);  //画圆形
        rectangle(srcImg, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 10, 50), 2, 8, 0);
    }

    /// 显示在一个窗口
    //    namedWindow("包围最小矩形和圆形", 0);
    //    imshow("包围最小矩形和圆形", drawing);
    //    namedWindow("原图中的细胞", 0);
    //    imshow("原图中的细胞", srcImg);
    myCtQImage = QImage(srcImg.data, srcImg.cols, srcImg.rows, QImage::Format_RGB888);
    ctImgShow();
    QMessageBox::information(this, "细胞计数", QString("计算成功，当前图片中细胞个数为%1").arg(contours.size()));
    // qDebug() << "细胞个数" << contours.size();
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    QString itemText = item->text (column);
    if(itemText == "校本部"){
        //数据网格信息加载
        ui->basicTableView->setModel(model);
        //初始化表单患者信息
        onTableSelectChange(0);
    }else if(itemText == "紫金学院"||itemText == "江阴校区"){
        QMessageBox::information (this,"提示","暂无数据");
    }
}

void MainWindow::on_saveHistoryBtn_clicked()
{
    QString name = ui->nameLabel->text ();
    QString str = ui->caseTextEdit->document()->toPlainText ();
    //存入前先转为QVAriant类型
    QVariant var(str);
//    //更新数据库中的病历
//    QSqlQuery query;
//    QString sqlStr = "update user_profile set casehistory=? where name=?";
//    query.prepare (sqlStr);
//    query.bindValue (0,str);
//    query.bindValue (1,name);
//    if(query.exec()){
//        qDebug() << "更新成功";
//    }else{
//        qDebug() << "更新失败";
//    }
    //直接更新model里的数据，不用去操作数据库,有两个model，他们的index不一样
    QModelIndex index ;
    //只能逐行按照名字查找

    for(int i=0;i<model_d->rowCount ();i++){
        //第0列是姓名，第1列是病历，第2列是图片
        index = model_d->index(i, 0);
        if(model_d->data (index).toString () == name){
            //找到那个人的病历的index，更改
            index = model_d->index (i,1);
            break;
        }
    }
    //找到那个人的病历，更改
    qDebug() <<"原病历："<< model_d->data (index).toString ();
    model_d->setData (index,var);
    model_d->submitAll ();
}
void MainWindow::on_basicTableView_clicked(const QModelIndex& index) { onTableSelectChange(1); }

void MainWindow::on_tabWidget_tabBarClicked(int index) {
    //填写病历
    if (index == 1) {
        QModelIndex index;
        for (int i = 0; i < model_d->rowCount(); i++) {
            //逐行按照名字查找
            index = model_d->index(i, 0);
            QString current_name = model_d->data(index).toString();
            if (current_name.compare(ui->nameLabel->text()) == 0) {
                index = model_d->index(i, 1);
                break;
            }
        }
        ui->caseTextEdit->setText(model_d->data(index).toString());
        ui->caseTextEdit->setFont(QFont("楷体", 12));
    }
}
void MainWindow::onTableSelectChange(int row) {
    int r = 1;  //默认显示第一行
    //获取当前索引
    if (row != 0)
        r = ui->basicTableView->currentIndex().row();
    QModelIndex index;
    //姓名列
    index = model->index(r, 1);
    ui->nameLabel->setText(model->data(index).toString());
    //性别 列
    index = model->index(r, 2);
    QString sex = model->data(index).toString();
    ui->label_sex->setText(sex);
    //出生日期
    index = model->index(r, 4);
    QDate date;
    int now = date.currentDate().year();
    int birth = model->data(index).toDate().year();
    ui->label_age->setText(QString::number (now-birth));  //计算年龄
    //民族
    index = model->index(r, 3);
    QString ethnic = model->data(index).toString();
    ui->label_ethic->setText(ethnic);
    //医保卡号
    index = model->index(r, 0);
    QString ssn = model->data(index).toString();
    ui->ssnLineEdit->setText(ssn);
    showUserPhoto();
    //病历内容也要更改
    on_tabWidget_tabBarClicked(1);
}

void MainWindow::showUserPhoto() {
    QPixmap photo;
    QModelIndex index;
    for (int i = 0; i < model_d->rowCount(); i++) {
        //姓名那一列
        index = model_d->index(i, 0);
        QString current_name = model_d->data(index).toString();
        if (current_name.compare(ui->nameLabel->text()) == 0) {
            //头像那一列
            index = model_d->index(i, 2);
            break;
        }
    }
    photo.loadFromData(model_d->data(index).toByteArray(), "JPG");
    ui->photoLabel->setPixmap(photo);
}
