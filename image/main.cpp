#include "mainwindow.h"
#include <QApplication>
#include <pixel.h>
#include <random>
#include "image.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  MainWindow w;
    //w.show();
 //   std::cout<<"Jakies text";
    uint16_t rows=4;
    uint16_t cols=2;
    int res=3;
    QByteArray test_data(rows*cols*res,50);
    Image im1(test_data,rows,cols);
    for(uint16_t i=0; i<rows*cols; ++i)
    {
        std::cout<<im1(i);
    }



    return 1;
}
