#ifndef IMAGE_H
#define IMAGE_H

#include "pixel.h"
#include <vector>
#include <QApplication>
enum class im_types{RGB};

class Image
{
    uint16_t rows;
    uint16_t cols;
    im_types im_type;
    std::vector<Pixel> data;
    int insert_RGB(const QByteArray& data);
public:
    Image(im_types type=im_types::RGB,uint16_t rows=0,uint16_t cols=0):rows(rows),cols(cols),im_type(type),data(rows*cols){}
    Pixel& operator()(const uint16_t r, const uint16_t c)
    {
        assert(r<this->rows&&c<this->cols);
        return data[rows*r + c];
    }
    Pixel& operator()(const uint16_t rc)
    {
        assert(rc<this->rows*this->cols);
        return data[rc];
    }
    Image(const QByteArray& data,const uint16_t r=640, const uint16_t c=480, im_types type=im_types::RGB);
    constexpr uint16_t get_rows_count()const{return this->rows;}
    constexpr uint16_t get_cols_count()const{return this->cols;}

};

#endif // IMAGE_H
