#ifndef EPDIF_H
#define EPDIF_H

#include <arduino.h>

// Pin definition
#define RST_PIN         33
#define DC_PIN          25
#define CS_PIN          26
#define BUSY_PIN        27

#define SDA_PIN         12
#define SCK_PIN         13

class EpdIf {
public:
    EpdIf(void);
    ~EpdIf(void);

    static int  IfInit(void);
    static void DigitalWrite(int pin, int value);
    static int  DigitalRead(int pin);
    static void DelayMs(unsigned int delaytime);
    static void SpiTransfer(unsigned char data);
};

#endif
