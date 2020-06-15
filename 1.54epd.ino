#include <SPI.h>
#include "epd1in54.h"
#include "imagedata.h"
#include "epdpaint.h"
#define COLORED     0
#define UNCOLORED   1

unsigned long time_start_ms;
unsigned long time_now_s;
unsigned char image[1024];



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Epd epd;
  if (epd.Init() != 0) {
    Serial.println("e-Paper init failed");
    return;}
   
  /* This clears the SRAM of the e-paper display */
  epd.ClearFrame();

  Paint paint(image, 152, 22);    //width should be the multiple of 8 
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(8, 2, "e-Paper Demo", &Font16, COLORED);
  epd.SetPartialWindow(paint.GetImage(), 0, 10, paint.GetWidth(), paint.GetHeight(),1);

  paint.Clear(COLORED);
  paint.DrawStringAt(8, 2, "YuSky", &Font20, UNCOLORED);
  epd.SetPartialWindow(paint.GetImage(), 0, 30, paint.GetWidth(), paint.GetHeight(),1);

  paint.Clear(UNCOLORED);
  paint.DrawStringAt(8, 2, "e-Paper Demo", &Font16, COLORED);
  epd.SetPartialWindow(paint.GetImage(), 0, 60, paint.GetWidth(), paint.GetHeight(),2);

  paint.Clear(COLORED);
  paint.DrawStringAt(8, 2, "YuSky", &Font20, UNCOLORED);
  epd.SetPartialWindow(paint.GetImage(), 0, 80, paint.GetWidth(), paint.GetHeight(),2);
  
  
  epd.DisplayFrame();
  delay(10000);
  
  epd.ClearFrame();
  
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(8, 2, "e-Paper Demo", &Font16, COLORED);
  epd.SetPartialWindow(paint.GetImage(), 0, 2, paint.GetWidth(), paint.GetHeight(),1);

  paint.Clear(COLORED);
  paint.DrawStringAt(8, 2, "YuSky", &Font20, UNCOLORED);
  epd.SetPartialWindow(paint.GetImage(), 0, 20, paint.GetWidth(), paint.GetHeight(),1);


  
  paint.SetWidth(64);
  paint.SetHeight(64);

  paint.Clear(UNCOLORED);
  paint.DrawRectangle(0, 0, 40, 50, COLORED);
  paint.DrawLine(0, 0, 40, 50, COLORED);
  paint.DrawLine(40, 0, 0, 50, COLORED);
  epd.SetPartialWindow(paint.GetImage(), 8, 45, paint.GetWidth(), paint.GetHeight(),1);
  
  paint.Clear(UNCOLORED);
  paint.DrawCircle(16, 16, 15, COLORED);
  epd.SetPartialWindow(paint.GetImage(), 64, 45, paint.GetWidth(), paint.GetHeight(),2);

  paint.Clear(UNCOLORED);
  paint.DrawFilledRectangle(0, 0, 40, 50, COLORED);
  epd.SetPartialWindow(paint.GetImage(), 8, 100, paint.GetWidth(), paint.GetHeight(),1);

  paint.Clear(UNCOLORED);
  paint.DrawFilledCircle(16, 16, 15, COLORED);
  epd.SetPartialWindow(paint.GetImage(), 64, 100, paint.GetWidth(), paint.GetHeight(),2);

  /* This displays the data from the SRAM in e-Paper module */
  epd.DisplayFrame();
  delay(10000);
  
  epd.DisplayFrame(IMAGE1_BLACK,IMAGE1_RED);
  
  delay(10000);
  epd.ClearFrame();    //刷白保存
  epd.DisplayFrame();
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
