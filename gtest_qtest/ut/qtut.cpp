#include <gtest/gtest.h>
#include "qtut.h"

void GTestGPanelItemTest::SetUp()
{
    panelItem = new GPanelItem();
}

void GTestGPanelItemTest::TearDown()
{
    delete panelItem;
}

TEST_F(GTestGPanelItemTest,testInit)
{
}

//GUI testing using QtTest
TEST_F(GTestGPanelItemTest,testIncButton)
{
    panelItem->reset();
    QTest::mouseClick(panelItem->getIncreaseButton(),Qt::LeftButton);
    QCOMPARE(panelItem->getNumLabel()->text(),QString("1"));
}

TEST_F(GTestGPanelItemTest,testDescButton)
{
    panelItem->setValue(1);
    QCOMPARE(panelItem->getNumLabel()->text(),QString("1"));
    QTest::mouseClick(panelItem->getDecreaseButton(),Qt::LeftButton);
    QCOMPARE(panelItem->getNumLabel()->text(),QString("0"));
}

TEST_F(GTestGPanelItemTest,testIncButtonEdge)
{
    panelItem->setValue(9);
    QTest::mouseClick(panelItem->getIncreaseButton(),Qt::LeftButton);
    QCOMPARE(panelItem->getNumLabel()->text(),QString("9"));
}

TEST_F(GTestGPanelItemTest,testDescButtonEdge)
{
    panelItem->setValue(0);
    QTest::mouseClick(panelItem->getDecreaseButton(),Qt::LeftButton);
    QCOMPARE(panelItem->getNumLabel()->text(),QString("0"));
}

bool QTestGPanelItemTest::myCondition()
{
    return true;
}

void QTestGPanelItemTest::initTestCase()
{
    qDebug("Called before everything else.");
}

void QTestGPanelItemTest::myFirstTest()
{
    QVERIFY(true); // check that a condition is satisfied
    QCOMPARE(1, 1); // compare two values
}

void QTestGPanelItemTest::mySecondTest()
{
    QVERIFY(myCondition());
    QVERIFY(1 != 2);
}
void QTestGPanelItemTest::cleanupTestCase()
{
    qDebug("Called after myFirstTest and mySecondTest.");
}