#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();
private slots:
    void onStart();
    void onStop();
private:
    Ui::about *ui;
    QMovie* m_gif;
};

#endif // ABOUT_H
