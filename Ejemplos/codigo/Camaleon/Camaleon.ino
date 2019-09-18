#include "MeOrion.h"
#include <Wire.h>
/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * \class   MeGyro
 * \brief   Driver for MeColorSensor module.
 * @file    MeColorSensor.h
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2017/01/17
 * @brief   Header for MeColorSensor.cpp module.
 * \par Description
 * This file is a drive for MeColorSensor module, It supports MeColorSensor V1.0 device provided
 * by MakeBlock.
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 *  zzipeng         2017/04/12          1.0.0         complete the driver code.
 *  javacasm        2019/09/18          1.1.0         show RGB Color
 * </pre>
 *                 Attention please!
 *                 8mm~24mm detection distance.
 *              orion board only support PORT 1 2 3 4,as for this module!!
 */
//本例程示例单个颜色传感器模块工作，获取颜色识别值。单个模块工作数据返回率每秒6次。

MeColorSensor colorsensor(PORT_4);

MeRGBLed led(PORT_3);

uint8_t colorresult;
uint16_t redvalue=0,greenvalue=0,bluevalue=0,colorvalue=0,hue;
uint8_t grayscale = 0;
long systime = 0,colorcode=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  colorsensor.SensorInit();//
  systime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-systime>100)
  {
    systime = millis();
    colorresult = colorsensor.Returnresult();
    redvalue   = colorsensor.ReturnRedData();
    greenvalue = colorsensor.ReturnGreenData();
    bluevalue  = colorsensor.ReturnBlueData();
    colorvalue = colorsensor.ReturnColorData();
    colorcode = colorsensor.ReturnColorCode();//RGB24code
    grayscale  = colorsensor.ReturnGrayscale();

    Serial.print("R:");
    Serial.print(redvalue);
    Serial.print("\t");
    Serial.print("G:");
    Serial.print(greenvalue);
    Serial.print("\t");
    Serial.print("B:");
    Serial.print(bluevalue);
    Serial.print("\t");
    Serial.print("C:");
    Serial.print(colorvalue);
    Serial.print("\t");
    Serial.print("color:");
    switch(colorresult)
    {
       case BLACK:
      Serial.print("BLACK");

      led.setColorAt(0, 0, 0, 0);
      
      break;
      case BLUE:
      Serial.print("BLUE");

      led.setColorAt(0, 0,0,255);
      
      break;
      case YELLOW:
      Serial.print("YELLOW");

      led.setColorAt(0, 255, 200, 0);
      
      break;
      case GREEN:
      Serial.print("GREEN");

      led.setColorAt(0, 0, 255, 0);
      
      break;
      case RED:
      Serial.print("RED");

      led.setColorAt(0, 255, 0, 0);
      
      break;
      case WHITE:
      Serial.print("WHITE");

      led.setColorAt(0, 255, 255, 255);
      
      break;
      default:
      break;    
     }

    led.show();
     
    Serial.print("\t");
    Serial.print("code:");
    Serial.print(colorcode,HEX); 
    Serial.print("\t");
    Serial.print("grayscale:");
    Serial.println(grayscale);
  }
}
