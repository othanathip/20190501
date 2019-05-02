/*
DHT มาจากคำว่า Digital Humidity and Temperature Sensor
แปลตรงตัวเลยก็คือเซนเซอร์ตรวจจับความชื้นและอุณหภูมิแบบดิจิทัล

ก่อนใช้งานจะต้องติดตั้งชุด Library เพิ่มเติม
เพื่อสั่งงานอุปกรณ์ผ่านชุดคำสั่งใน Library แทนที่จะต้องเขียนโค้ดเองทั้งหมด

วิธีติดตั้ง Library 
1.คลิกที่เมนู Sketch > Include Library > Manage Libraries...
2.ค้นหา Library ที่ชื่อว่า DHT sensor library by Adafruit แล้วกด Install
3.ค้นหา Library ที่ชื่อว่า Adafruit Unified Sensor by Adafruit แล้วกด Install

เชื่อมต่อขา DAT ที่เซ็นเซอร์กับขา Digital หมายเลข 2, 5V, GND

ที่มา https://www.arduinospro.com/article/42/arduino-sensor-example-ep7-dht-sensor-เซนเซอร์วัดอุณหภูมิและความชื้นในอากาศ
*/

#include "DHT.h"                          // นำเข้าไรบลารี่ DHT.h

#define DHTPIN 2                          // กำหนด Pin เชื่อมต่อเซนเซอร์
#define DHTTYPE DHT11                     // กำหนดชนิดของเซนเซอร์ DHT11, DHT22, DHT21

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
}

void loop() {
  delay(1000);                            // หน่วงเวลา 1000 มิลลิวินาที
                                          // เซนเซอร์ใช้เวลาในการอ่านค่าความชื้นและอุณหมิประมาณ 250 มิลลิวินาที
  
  float h = dht.readHumidity();           // อ่านค่าความชื้นไว้ในตัวแปร h ชนิด float (ทศนิยม)
  float t = dht.readTemperature();        // อ่านค่าความอุณหภูมิเป็นองศาเซลเซียส (ค่าเริ่มต้น
                                          // ไว้ในตัวแปร t ชนิด float (ทศนิยม)

  
  // ตรวจสอบค่าที่ได้จากเซ็นเซอร์ หากมีความผิดพลาดของข้อมูล ให้แสดงข้อความ Failed แล้วให้ทำการตรวจสอบอีกครั้ง
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
    
  }

  
  Serial.print("Humidity: ");
  Serial.print(h);                          // แสดงค่าความชื้น
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);                          // แสดงค่าอุณหภูมิเป็นองศาเซลเซียส
  Serial.println(" *C ");
  
}
