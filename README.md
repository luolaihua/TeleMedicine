# TeleMedicine
## 校医院远程诊断系统
医生可使用该软件查看患者的电子档案，通过查看CT相片和化验单等数据，为患者写诊断结果， 同时CT相片经过特定的图像处理算法处理后可以更加凸显病灶，提高医生的诊断效率。
· 使用Qt搭建用户界面，操作数据库以及处理CT相片等图像数据。 
· 通过Qt的Model/View架构完成表单与数据库的联动。
· 使用MySQL数据库存储患者的病历档案等信息。
· 使用OpenCV 的图像处理算法完成病灶检测和细胞计数等功能，对CT照片有很好的处理效果。
# 技术一：OpenCV
## 病灶检测功能
检测CT相片中的异物，比如肿瘤，将圈出标记。

使用到的技术：opencv中的霍夫圆检测算法

检测流程：

  ①　读取图像

  ②　灰度化

  ③　高斯滤波，除噪，平滑处理

  ④　设置霍夫圆检测算法的参数

  ⑤　调用HoughCircles进行圆检测

  ⑥　将检测到的圆在原图中标记显示
## 细胞计数功能
①　读取细胞图片

②　二值化

③　中值滤波，除噪

④　Canny边缘检测

⑤　漫水填充算法，颜色填充

⑥　腐蚀膨胀，进一步除噪

⑦　使用findContours函数找寻轮廓

⑧　轮廓数就是细胞个数

⑨　minEnclosingCircle函数寻找包裹轮廓的最小圆

⑩　将圆在原图中画出显示

细胞计数和病灶检测功能的检测效果依赖于参数的设置，因此设置了参数调节窗口。

## CT相片处理
对比度和亮度（convertTo函数）

旋转缩放（放射变化，先生成仿射变换矩阵（getRotationMatrix2D），再对图像进行仿射变换（warpAffine））

滤波除噪（高斯滤波，双边滤波，中值滤波，均值滤波，方框滤波）

阈值处理（threshold函数）

# 技术二：MySQL数据库
在 5.12 及之前的版本中，Qt 的安装包中自带 MySql 驱动，在 plugins/sqldrivers 目录下可以找到，但到了 5.13 之后，MySql 驱动便没有了，这时我们可以选择手动编译。
下载5.13的源码，手动编译生成dll动态链接库文件，将该文件放入Qt5.13的数据库驱动文件夹中。
## Mysql安装流程：

①　下载压缩包，zip文件

②　解压之后设置环境变量，将bin文件夹的路径放入

③　在安装目录中新建一个ini文件，配置端口（3306）、连接数等等

④　在bin目录下以管理员的身份打开控制窗口，cmd。输入：mysqld --initialize --console，		初始化,初始化之后，会显示本地主机localhost，管理员root，初始化的随机密码。

⑤　启动服务：net start mysql

⑥　登录数据库：mysql -u root -p，输入初始化的密码，

⑦　修改密码语句：ALTER USER root@localhost INDENTIFIED BY ’123456’

⑧　删除数据库：musqld --remove mysql

## 在Qt中使用mysql数据库：

使用QSQLDatabase的方法addDataBase(“QMYSQL”)添加一个mysql数据库，设置主机名，管理员和密码，数据库名称之后，打开数据库

使用QSqlQuery类（exec，prepare，addBindValue）对数据库增删改查，在exec函数中输入sql语句字符串即可操作数据库。

读入图片：使用QFile类将图片读入，保存为QByteArray字节数组，然后将照片数据封装成QVariant变量，在字符串语句中以问号代替数据，然后使用prepare和addBindValue函数，最后执行插入语句exec

使用QSQLTableModel类和QTableView类，模型视图架构。Model加载数据库中的表格或视图（setTable），然后QTableView设置模型（setModel），即可实现表单与数据库的联动

# 技术三：Qt

设置快捷键：setShortcut，为动作设置快捷键，可以代码添加，也可以在ui文件中添加

事件过滤器：图片双击事件

使用QTreeWidget来显示地区、科室

使用QTabWidget来显示用户信息和病历

使用QTableView来显示病人的表格


![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/1.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/2.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/3.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/4.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/5.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/6.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/7.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/8.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/9.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/10.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/11.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/12.jpg)
![](https://github.com/luolaihua/TeleMedicine/blob/master/introduction/13.jpg)
