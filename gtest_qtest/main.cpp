//主程序
#include <QApplication>
#include "PanelItem.h"

int main(int argc,char ** argv)
{
  QApplication app(argc,argv);


  GPanelItem * panelItem = new GPanelItem();
  panelItem->show();

  return app.exec();
}