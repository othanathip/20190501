#include "DHT.h"  // นำเข้าไรบลารี่ DHT.h

#define DHTPIN 2  // กำหนด Pin เชื่อมต่อเซนเซอร์
#define DHTTYPE DHT11  // กำหนดชนิดของเซนเซอร์ DHT11, DHT22, DHT21

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
}

void loop() {
  delay(1000);  // หน่วงเวลา 1000 มิลลิเวินาที

  // เซนเซอร์ใช้เวลาในการอ่านค่าความชื้นและอุณหมิประมาณ 250 มิลลิเวินาที
  
  float h = dht.readHumidity();  // อ่านค่าความชื้นไว้ในตัวแปร h ชนิด float (ทศนิยม)
  float t = dht.readTemperature();  // อ่านค่าความอุณหภูมิเป็นองศาเซลเซียส (ค่าเริ่มต้น) ไว้ในตัวแปร t ชนิด float (ทศนิยม)

  // ตรจสอบความผิดพลาดของขอ้มูล หากผผิดพลาดให้ทำการตวจสอบอีกครั้ง
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
    
  }

  
  Serial.print("Humidity: ");
  Serial.print(h); // แสดงค่าความชื้น
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);  // แสดงค่าอุณหภูมิเป็นองศาเซลเซียส
  Serial.print(" *C ");
  
}
