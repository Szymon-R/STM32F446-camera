#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <array>
#include <assert.h>
class Pixel
{
    std::array<unsigned char, 3> element;
    static const int max_size=3;
public:
    constexpr Pixel():element({0}){}
    constexpr Pixel(const unsigned char val1, const unsigned char val2=0, const unsigned char val3=0 ):element({val1,val2,val3}){}
    constexpr std::array<unsigned char, 3> get_pixel() const{return element;}
    unsigned char& operator[](const size_t val){assert(val<max_size);return element.at(val);}

};

#endif // PIXEL_H
