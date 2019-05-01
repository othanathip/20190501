int LDR = A0;  //สร้างตัวแปรชื่อ LDR กำหนดชนิดของตัวแปรเป็นแบบ int รับค่าจากขา A0
 
void setup() {
  Serial.begin(9600);  //เรียกใช้งาน Serail Monitor และกำหนดความถี่ในการเชื่อมต่อกับ Serial monitor  
}
 
void loop() {
  int LDR_Val = analogRead(LDR);  //สร้างตัวแปรชื่อ LDR_Val เป็นชนิด int เพื่อเก็บค่าที่รับได้จาก LDR เป็นค่าดิจิตอล
  Serial.print("LDR Sensor Value = ");  //แสดงค่าออกทาง Serial Monitor ว่า "LDR Sensor Value = "
  Serial.println(LDR_Val);  //แสดงค่าใน sensor_Value จากนั้นขึ้นบรรทัดใหม่
  delay(500);  //หน่วงเวลา 500 มิลลิวินาที
  
}
