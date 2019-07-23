#include "mainwindow.h"
#include <QApplication>
#include <pixel.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  MainWindow w;
    //w.show();
    std::cout<<"Jakies text";
    Pixel p1={1,2,3};
    p1[2]=10;
    //return a.exec();
    return 1;
}
