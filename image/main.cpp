#include "mainwindow.h"
#include <QApplication>
#include <pixel.h>
#include <random>
#include "image.h"
#include "serial.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  MainWindow w;
    //w.show();
 //   std::cout<<"Jakies text";
    uint16_t rows=300;
    uint16_t cols=300;
    int res=3;
    QByteArray test_data(rows*cols*res,255);
    Serial USB("COM21");
    USB.usb_init();

    MainWindow w;


        QByteArray data;
        USB.acquire_data(data,rows*cols);

        int size=rows*cols*res;
        QImage image( rows, cols, QImage::Format_RGB888 );
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                QRgb rgb = qRgb( test_data[i*rows + cols+ 1], //red
                                   test_data[i*rows + cols + 2], //green
                                   test_data[i*rows + cols + 3]);
               /*   QRgb rgb = qRgb( 200, //red
                                   0, //green
                                   0);
                image.setPixel (i,j,rgb);*/
            }
        }


        w.insert_image(image);
        w.show();

    a.exec();

    return 1;
}

