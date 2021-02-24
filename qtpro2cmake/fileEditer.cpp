#include "fileEditer.h"
#include "ui_fileEditer.h"
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include "about.h"

fileEditer::fileEditer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fileEditer)
{
    ui->setupUi(this);
    //this->setMinimumSize(QSize(300, 300));
    this->setWindowTitle(QString("UnTitled.txt"));

    connect(ui->newFile, SIGNAL(triggered()), this, SLOT(oNewFileTriggered()));
    connect(ui->openFile, SIGNAL(triggered()), this, SLOT(onOpenFileTriggered()));
    connect(ui->saveFile, SIGNAL(triggered()), this, SLOT(onSaveFileTriggered()));
    connect(ui->saveFileAs, SIGNAL(triggered()), this, SLOT(onSaveFileAsTriggered()));
    connect(ui->printFile, SIGNAL(triggered()), this, SLOT(onPrintFileTriggered()));
    connect(ui->exitFile, SIGNAL(triggered()), this, SLOT(close()));

    connect(ui->cancel, SIGNAL(triggered()), ui->fileContent, SLOT(undo()));
    connect(ui->redo, SIGNAL(triggered()), ui->fileContent, SLOT(redo()));
    connect(ui->copy, SIGNAL(triggered()), ui->fileContent, SLOT(copy()));
    connect(ui->cut, SIGNAL(triggered()), ui->fileContent, SLOT(cut()));
    connect(ui->paste, SIGNAL(triggered()), ui->fileContent, SLOT(paste()));
    connect(ui->selectAll, SIGNAL(triggered()), ui->fileContent, SLOT(selectAll()));
    connect(ui->date, SIGNAL(triggered()), this, SLOT(onDateTimeTriggered()));

    connect(ui->font, SIGNAL(triggered()), this, SLOT(onFontTriggered()));
    connect(ui->color, SIGNAL(triggered()), this, SLOT(onColorTriggered()));

    connect(ui->aboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->aboutWeb, SIGNAL(triggered()), this, SLOT(onAboutWebTriggered()));
    connect(ui->about, SIGNAL(triggered()), this, SLOT(onAboutTriggered()));
}

fileEditer::~fileEditer()
{
    delete ui;
}

void fileEditer::oNewFileTriggered()
{
    if(ui->fileContent->document()->isModified())
    {
        qDebug() << "currrent file modified";
    }
    else
    {
        qDebug() << "not modified";
    }
}

void fileEditer::onOpenFileTriggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath());
    qDebug() << "fileName " << fileName;
    if(fileName.isEmpty())
    {
        QMessageBox::information(this, "Error Message", "Please select a text file");
        return;
    }
    else
    {
        m_saveFileName = fileName;
        QFile* file = new QFile();
        file->setFileName(fileName);
        bool ok = file->open(QIODevice::ReadOnly);
        if(ok)
        {
            QTextStream in(file);
            ui->fileContent->setText(in.readAll());
        }
        else
        {
            QMessageBox::information(this, "Error Message", "File open failed" + file->errorString());
        }
        file->close();
        delete file;
    }
}

void fileEditer::onSaveFileTriggered()
{
    if(m_saveFileName.isEmpty())
    {
        this->onSaveFileAsTriggered();
        return;
    }
    QFile* file = new QFile();
    file->setFileName(m_saveFileName);
    bool ok = file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out << ui->fileContent->toPlainText();
    }
    else
    {
        QMessageBox::information(this, "Error Message", "File save to  " + m_saveFileName + "failed");
    }
    file->close();
    delete file;
}

void fileEditer::onSaveFileAsTriggered()
{
    m_saveFileName = QFileDialog::getSaveFileName(this, "Save File", QDir().currentPath());
    if(m_saveFileName.isEmpty())
    {
        QMessageBox::information(this, "Error Message", "please input a file name");
        return;
    }
    QFile* file = new QFile();
    file->setFileName(m_saveFileName);
    bool ok = file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out << ui->fileContent->toPlainText();
    }
    else
    {
        QMessageBox::information(this, "Error Message", "File save to  " + m_saveFileName + "failed");
    }
    file->close();
    delete file;
}

void fileEditer::onPrintFileTriggered()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if(printDialog.exec() == QDialog::Accepted)
    {
        qDebug() << "Printing ... ";
    }
}

void fileEditer::onDateTimeTriggered()
{
    QDateTime current = QDateTime::currentDateTime();
    QString str = current.toString("yyyy-M-d hh:mm:ss");
    ui->fileContent->append(str);
}

void fileEditer::onFontTriggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        ui->fileContent->setFont(font);
    }
    else
    {
        QMessageBox::information(this, "Error Message", "Font set Error");
    }
}

void fileEditer::onColorTriggered()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Color");
    if(color.isValid())
    {
        ui->fileContent->setTextColor(color);
    }
    else
    {
        QMessageBox::information(this, "Error Message", "Color set Error");
    }
}

void fileEditer::onAboutWebTriggered()
{
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}

void fileEditer::onAboutTriggered()
{
    about* ab = new about();
    qDebug() << "this = " << ab;
    ab->setAttribute(Qt::WA_DeleteOnClose);//非模式对话框关闭事件时，自动销毁该对象
    ab->show();
}

void fileEditer::closeEvent(QCloseEvent* event)
{
    if(ui->fileContent->document()->isModified())
    {
        QMessageBox msgBox(this);
        msgBox.setMinimumSize(QSize(259, 116));//设置最小对话框，否则可能存在警告
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret)
        {
            case QMessageBox::Save:
                // Save was clicked
                this->onSaveFileTriggered();
                //这里如果没有正常保存需要额外处理，暂时还是会直接退出
                break;
            case QMessageBox::Discard:
                // Don't Save was clicked
                event->accept();
                break;
            case QMessageBox::Cancel:
                // Cancel was clicked
                event->ignore();
                break;
            default:
                // should never be reached
                break;
          }
    }
    else
    {
        event->accept();
    }
}
