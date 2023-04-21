#include "mainwindow.h"

#include <QApplication>
#include <QProcess>
int
main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  //    if(!createMySqlConn ())
  //    {
  //        //初次连接不成功，就转而使用代码方式启动MySql服务进程
  //        QProcess process;
  //        process.start ("D:/mysql-8.0.22-winx64/bin/mysqld.exe");
  //        //第二次尝试连接
  //        if(!createMySqlConn ()) return 1;
  //    }
  MainWindow w;
  w.show();
  return a.exec();
}
