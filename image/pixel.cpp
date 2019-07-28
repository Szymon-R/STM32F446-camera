#include "pixel.h"

std::ostream& operator<<(std::ostream& os, Pixel& pi)
{
    os<<"["<<static_cast<int>(pi[0])<<","<<static_cast<int>(pi[1])<<","<<static_cast<int>(pi[2])<<"]";
    return os;
}
