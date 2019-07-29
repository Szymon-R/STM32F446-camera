#ifndef SERIAL_H
#define SERIAL_H

#include <QtSerialPort/QSerialPort>
#include <string>
#include <iostream>
#include <cstddef>

class Serial
{
    QSerialPort usb;
    QByteArray data;
public:
    int acquire_data(QByteArray& data,const uint32_t size, const unsigned int timeout=100);
    Serial();
    Serial(const QString portname,const int baudrate=115200)
    {
        usb.setPortName(portname);
        usb.setBaudRate(baudrate);
    }
    int usb_init();
};

#endif // SERIAL_H
