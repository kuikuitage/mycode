#ifndef EDITER_H
#define EDITER_H

#include <QMainWindow>
#include <QCloseEvent>
#include "about.h"

namespace Ui {
class fileEditer;
}

class fileEditer : public QMainWindow
{
    Q_OBJECT

public:
    explicit fileEditer(QWidget *parent = nullptr);
    ~fileEditer();
private:
    virtual void closeEvent(QCloseEvent* event);
private slots:
    void oNewFileTriggered();
    void onOpenFileTriggered();
    void onSaveFileTriggered();
    void onSaveFileAsTriggered();
    void onPrintFileTriggered();
    void onDateTimeTriggered();
    void onFontTriggered();
    void onColorTriggered();
    void onAboutWebTriggered();
    void onAboutTriggered();
private:
    Ui::fileEditer *ui;
    QString m_saveFileName;//当前打开的文件名，也是保存时默认的文件名
};

#endif // EDITER_H
