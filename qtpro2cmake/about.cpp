#include "about.h"
#include "ui_about.h"
#include <QString>
#include <QDebug>

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("about"));
    this->setAttribute(Qt::WA_QuitOnClose,false);//非模式对话框关闭时不退出程序
    m_gif = new QMovie("about.gif", nullptr, this);
    ui->gifLabel->setMovie(m_gif);
    m_gif->start();

    connect(ui->start, SIGNAL(clicked()), this, SLOT(onStart()));
    connect(ui->stop, SIGNAL(clicked()), this, SLOT(onStop()));
}

about::~about()
{
    m_gif->stop();
    delete ui;
    qDebug() << "delete " << this;
}

void about::onStart()
{
    m_gif->start();
}

void about::onStop()
{
    m_gif->stop();
}
