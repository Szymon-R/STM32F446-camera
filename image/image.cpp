#include "image.h"
Image::Image(const QByteArray& data,const uint16_t r, const uint16_t c, im_types type):data(r*c)
{
    this->cols=c;
    this->rows=r;
    this->im_type=type;
    int result;

    switch(im_type)
    {
    case im_types::RGB:
        result=insert_RGB(data);
        break;
    default:                                                                    //so what?
        std::cout<<"Type not suportted\n";
        break;

    }
    assert(result);
}
int Image::insert_RGB(const QByteArray& data)
{
    std::cout<<"Data size: "<<data.size()<<std::endl;
    std::cout<<"Image rows: "<<this->rows<<std::endl;
    std::cout<<"Image cols: "<<this->cols<<std::endl;
    std::cout<<"Vector size: "<<this->data.size()<<std::endl;
    if(data.size()!=this->rows*this->cols*3)
    {
        return 0;
    }
    uint32_t i=0;
    uint32_t counter=0;
    while(i<static_cast<uint32_t>(data.size()))
    {
        std::cout<<counter<<std::endl;
        for(uint16_t j=0; j<3 ;++j)
        {
            //this->data[counter][j];
            //static_cast<unsigned char>(data[i+j]);
            std::cout<<"I: "<<i<<std::endl;
            this->data[counter][j]=static_cast<unsigned char>(data[i]);
            ++i;
        }
        ++counter;
    }
    return 1;
}
