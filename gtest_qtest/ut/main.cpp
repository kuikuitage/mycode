//主程序
#include <QApplication>
#include "qtut.h"
#include <gtest/gtest.h>

#if 0
int main(int argc,char ** argv)
{
    QApplication app(argc,argv);

    ::testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();

    //QTEST_MAIN(TestQString)
    //return app.exec();
}
#else

QT_BEGIN_NAMESPACE
QTEST_ADD_GPU_BLACKLIST_SUPPORT_DEFS
QT_END_NAMESPACE
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    app.setAttribute(Qt::AA_Use96Dpi, true);
    QTEST_DISABLE_KEYPAD_NAVIGATION
    QTEST_ADD_GPU_BLACKLIST_SUPPORT
    QTestGPanelItemTest tc;
    QTEST_SET_MAIN_SOURCE_PATH

    ::testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();

    return QTest::qExec(&tc, argc, argv);
}
#endif