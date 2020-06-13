#include <SPI.h>
#include "epd1in54.h"
#include "imagedata.h"
#include "epdpaint.h"
#define COLORED     0
#define UNCOLORED   1

unsigned long time_start_ms;
unsigned long time_now_s;
unsigned char image[1024];
Paint paint(image, 0, 0);    //width should be the multiple of 8 
Epd epd;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  if (epd.Init() != 0) {
    Serial.println("e-Paper init failed");
    return;
                        }
   
  /* This clears the SRAM of the e-paper display */
  epd.ClearFrame();
//  
//  paint.Clear(UNCOLORED);
//  paint.DrawStringAt(8, 2, "e-Paper Demo", &Font12, COLORED);
//  epd.SetPartialWindow(paint.GetImage(), 0, 8, paint.GetWidth(), paint.GetHeight());
//
//  paint.Clear(COLORED);
//  paint.DrawStringAt(8, 2, "YuSky", &Font12, UNCOLORED);
//  epd.SetPartialWindow(paint.GetImage(), 0, 24, paint.GetWidth(), paint.GetHeight());
//  
//  paint.SetWidth(64);
//  paint.SetHeight(64);
//
//  paint.Clear(UNCOLORED);
//  paint.DrawRectangle(0, 0, 40, 50, COLORED);
//  paint.DrawLine(0, 0, 40, 50, COLORED);
//  paint.DrawLine(40, 0, 0, 50, COLORED);
//  epd.SetPartialWindow(paint.GetImage(), 8, 45, paint.GetWidth(), paint.GetHeight());
//  
//  paint.Clear(UNCOLORED);
//  paint.DrawCircle(16, 16, 15, COLORED);
//  epd.SetPartialWindow(paint.GetImage(), 64, 45, paint.GetWidth(), paint.GetHeight());
//
//  paint.Clear(UNCOLORED);
//  paint.DrawFilledRectangle(0, 0, 40, 50, COLORED);
//  epd.SetPartialWindow(paint.GetImage(), 8, 100, paint.GetWidth(), paint.GetHeight());
//
//  paint.Clear(UNCOLORED);
//  paint.DrawFilledCircle(16, 16, 15, COLORED);
//  epd.SetPartialWindow(paint.GetImage(), 64, 100, paint.GetWidth(), paint.GetHeight());
//
//  /* This displays the data from the SRAM in e-Paper module */
//  epd.DisplayFrame();
//

  Serial.println("start");
  epd.DisplayFrame(IMAGE1_BLACK,IMAGE1_RED);
  Serial.println("end");
  
  delay(10000);
  epd.DisplayFrame(NULL,NULL);    //刷白保存
//  epd.SendCommand(VCOM_AND_DATA_INTERVAL_SETTING);
//  epd.SendData(0x87);
//  epd.DisplayFrame(NULL,IMAGE);
//  delay(2000);
//  
//  epd.SendCommand(VCOM_AND_DATA_INTERVAL_SETTING);
//  epd.SendData(0xF7);
//  epd.DisplayFrame(NULL,IMAGE1);
//  delay(2000);
//  
//  epd.SendCommand(VCOM_AND_DATA_INTERVAL_SETTING);
//  epd.SendData(0x87);
//  epd.DisplayFrame(NULL,IMAGE1);
//  delay(2000);
//  epd.SendCommand(VCOM_AND_DATA_INTERVAL_SETTING);
//  epd.SendData(0xF7);
//  
//  delay(8000);
//  epd.ClearFrame();
//  epd.DisplayFrame();
//  
  epd.Sleep();
}

void loop() {
  // put your main code here, to run repeatedly:

}
