/**
The MIT License (MIT)
Copyright (c) 2017 by Daniel Eichhorn
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please note: I am spending a lot of my free time in developing Software and Hardware
for these projects. Please consider supporting me by
a) Buying my hardware kits from https://blog.squix.org/shop
b) Send a donation: https://www.paypal.me/squix/5USD
c) Or using this affiliate link while shopping: https://www.banggood.com/?p=6R31122484684201508S

See more at https://blog.squix.org

This code is based on a driver from http://waveshare.com
*/

#ifndef EPD7IN5_H
#define EPD7IN5_H

#include <Arduino.h>
#include <SPI.h>
#include "DisplayDriver.h"

// Display resolution
#define EPD_WIDTH       640
#define EPD_HEIGHT      384

// EPD7IN5 commands
#define PANEL_SETTING                               0x00
#define POWER_SETTING                               0x01
#define POWER_OFF                                   0x02
#define POWER_OFF_SEQUENCE_SETTING                  0x03
#define POWER_ON                                    0x04
#define POWER_ON_MEASURE                            0x05
#define BOOSTER_SOFT_START                          0x06
#define DEEP_SLEEP                                  0x07
#define DATA_START_TRANSMISSION_1                   0x10
#define DATA_STOP                                   0x11
#define DISPLAY_REFRESH                             0x12
#define IMAGE_PROCESS                               0x13
#define LUT_FOR_VCOM                                0x20
#define LUT_BLUE                                    0x21
#define LUT_WHITE                                   0x22
#define LUT_GRAY_1                                  0x23
#define LUT_GRAY_2                                  0x24
#define LUT_RED_0                                   0x25
#define LUT_RED_1                                   0x26
#define LUT_RED_2                                   0x27
#define LUT_RED_3                                   0x28
#define LUT_XON                                     0x29
#define PLL_CONTROL                                 0x30
#define TEMPERATURE_SENSOR_COMMAND                  0x40
#define TEMPERATURE_CALIBRATION                     0x41
#define TEMPERATURE_SENSOR_WRITE                    0x42
#define TEMPERATURE_SENSOR_READ                     0x43
#define VCOM_AND_DATA_INTERVAL_SETTING              0x50
#define LOW_POWER_DETECTION                         0x51
#define TCON_SETTING                                0x60
#define TCON_RESOLUTION                             0x61
#define SPI_FLASH_CONTROL                           0x65
#define REVISION                                    0x70
#define GET_STATUS                                  0x71
#define AUTO_MEASUREMENT_VCOM                       0x80
#define READ_VCOM_VALUE                             0x81
#define VCM_DC_SETTING                              0x82

class EPD_WaveShare75 : public DisplayDriver {
public:
    EPD_WaveShare75(uint8_t csPin, uint8_t rstPin, uint8_t dcPin, uint8_t busyPin);
    ~EPD_WaveShare75();
    void  init(void);
    void setRotation(uint8_t r);
    void writeBuffer(uint8_t *buffer, uint8_t bitsPerPixel, uint16_t *palette, uint16_t x, uint16_t y, uint16_t bufferWidth, uint16_t bufferHeight);


    void WaitUntilIdle(void);
    void Reset(void);
    void SetLut(void);
    void DisplayFrame(const unsigned char* frame_buffer);
    void SendCommand(unsigned char command);
    void SendData(unsigned char data);
    void Sleep(void);
    int  IfInit(void);
    void DelayMs(unsigned int delaytime);
    void DigitalWrite(int pin, int value);
    int  DigitalRead(int pin);
    void SpiTransfer(unsigned char data);
    void setFastRefresh(boolean isFastRefreshEnabled);
    uint8_t getPixel(const unsigned char* buffer, uint16_t x, uint16_t y);
    uint8_t reverse(uint8_t in);

private:
    uint8_t reset_pin;
    uint8_t dc_pin;
    uint8_t cs_pin;
    uint8_t busy_pin;
    uint16_t width;
    uint16_t height;
    uint16_t bufferWidth;
    uint16_t bufferHeight;
    uint8_t rotation;
};

#endif /* EPD7IN5_H */

/* END OF FILE */
