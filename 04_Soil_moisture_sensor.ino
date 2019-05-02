/*
 * Soil Moisture Sensor Module
 * เซ็นเซอร์วัดความชื้นในดิน
 * ใช้วัดความชื่นในดิน โดยการวัดค่าความต้านทานระหว่างอิเล็กโทรดที่ขาเซ็นเซอร์ทั้งสองขาที่ชุบโลหะไว้
 * 
 * ใช้ขา Analog = A0, 5V, GND
 * 
 * http://www.arduino.codemobiles.com/product/174/เซ็นเซอร์วัดความชื้นในดิน-soil-moisture-sensor
 */

int sensorPin = A0;


void setup() {
  Serial.begin(9600);
  delay(500);
  }

void loop() {
  
  int sensorValue;
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 1023, 0, 100);    //ใช้คำสั่ง map แปลงค่าจาก 0-1023 มาเป็น 0-100 เพื่อแปลงเป็น %
  Serial.print("Soil moisture: ");
  Serial.print(sensorValue);
  Serial.println(" %");
  
  delay(500);
}
