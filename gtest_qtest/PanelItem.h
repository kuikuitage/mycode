#ifndef PANELITEM_H
#define PANELITEM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QObject>

class GPanelItem : public QWidget
{
    Q_OBJECT
public:
    GPanelItem(QWidget * parent = 0);
    ~GPanelItem();
    void reset();
    void setValue(int value);
public slots:
    void increaseNum();

    void decreaseNum();

    QPushButton * getIncreaseButton();
    QPushButton * getDecreaseButton();
    QLabel * getNumLabel();
private:
    QPushButton* increaseButton;
    QPushButton* decreaseButton;
    QLabel * numLabel;
private:
    int value;
};

#endif
