#ifndef QT_UT_H
#define QT_UT_H

#include <gtest/gtest.h>
#include "PanelItem.h"
#include <QtTest/QtTest> //for testing Gui
#include <QtTest>
#include <QString>

class QTestGPanelItemTest : public QObject
{
    Q_OBJECT
private:
    bool myCondition();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void myFirstTest();
    void mySecondTest();
};

class GTestGPanelItemTest : public ::testing::Test
{
protected:
    virtual void SetUp();
    virtual void TearDown();
    GPanelItem * panelItem = nullptr;
};

#endif // QT_UT_H