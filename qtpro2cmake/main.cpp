#include "fileEditer.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //加载APP启动界面
    QPixmap pixmap("boot.jpg");
    QSplashScreen splash(pixmap);
    splash.show();

    //模拟部分初始化
    for(uint32_t k = 0; k < 800000000; k++);

    fileEditer w;
    w.setAttribute(Qt::WA_QuitOnClose,true);//该窗口退出关闭所有其他窗口，主要是非模式对话框
    w.show();

    splash.finish(&w);

    return a.exec();
}
