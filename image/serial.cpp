#include "serial.h"

Serial::Serial()
{

}
int Serial::usb_init()
{
    if(!usb.open(QIODevice::ReadWrite))
    {
        std::cout<<"Couldn't open serial"<<std::endl;
        return 0;
    }
    return 1;
}

int Serial::acquire_data(QByteArray& data,const uint32_t size, const unsigned int timeout)
{
    if(!usb.isOpen())
    {
        std::cout<<"Com port not opened"<<std::endl;
        return 0;
    }
    while (usb.waitForReadyRead(static_cast<int>(timeout)))
    {
        data += usb.read(size);
        std::cout<<data.size()<<std::endl;
        if(data.size()>=static_cast<int>(size))
            break;
    }
   // data=usb.read(size);
    std::cout<<"Data size: "<<data.size();
    return 1;
}
