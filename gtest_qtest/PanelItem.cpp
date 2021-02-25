#include "PanelItem.h"

GPanelItem::GPanelItem(QWidget * parent) : QWidget(parent)
{
    this->resize(600, 400);
    increaseButton = new QPushButton(QString(tr("<")),this);
    increaseButton->move(50, 50);
    increaseButton->resize(200, 50);
    QObject::connect(increaseButton,SIGNAL(clicked()),this,SLOT(increaseNum()));
    decreaseButton = new QPushButton(QString(tr(">")),this);
    decreaseButton->move(300, 50);
    decreaseButton->resize(200, 50);
    QObject::connect(decreaseButton,SIGNAL(clicked()),this,SLOT(decreaseNum()));
    value = 0;
    numLabel = new QLabel(); // 另外一个窗口
    numLabel->setNum(value);
    numLabel->resize(100,50);
    numLabel->show();
}
GPanelItem::~GPanelItem()
{
    delete numLabel;
}

void GPanelItem::reset()
{
    setValue(0);
}
void GPanelItem::setValue(int value)
{
    this->value = value;
    numLabel->setNum(value);
}

void GPanelItem::increaseNum()
{
    if(value < 9)
        value++;
    numLabel->setNum(value);
}
void GPanelItem::decreaseNum()
{
    if(value > 0)
        value--;
    numLabel->setNum(value);
}

QPushButton * GPanelItem::getIncreaseButton() { return increaseButton; }
QPushButton * GPanelItem::getDecreaseButton() { return decreaseButton; }
QLabel * GPanelItem::getNumLabel() { return numLabel; }