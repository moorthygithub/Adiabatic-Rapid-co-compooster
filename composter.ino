#include <SPI.h>
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3);
#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleStream.h>
SimpleTimer timer;
#include <SD.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SimpleTimer.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
// Data wire is conntec to the Arduino digital pin 4
#define ONE_WIRE_BUS 5
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);
File dataFile;
const int sensor_pin = A1;
float T;
float moisture_percentage;
const int chipSelect = 10;
uint16_t line = 1;
const int analogInPin = A0;
int sensorValue = 0;
unsigned long int avgValue;
float b;
int buf[10],temp;
char auth[] = "xYqQ1Ufy-D9WOIGYsghqh4qPyuAI5Nom";
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  Blynk.begin(Serial, auth);
/*for(int i=0;i<10;i++)
 {
  buf[i]=analogRead(analogInPin);
  delay(100);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])
   {
    temp=buf[i];
    buf[i]=buf[j];
    buf[j]=temp;
   }
  }
 }
 avgValue=0;
 for(int i=2;i<8;i++)
 avgValue+=buf[i];
 float pHVol=(float)avgValue*5.0/1024/6;
 float phValue = -5.70 * pHVol + 21.34;
 Serial.print("sensor = ");
 Serial.println(phValue);
 
  sensors.requestTemperatures();
  delay(1000);
  float T = sensors.getTempCByIndex(0);
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("temperature: ");
  Serial.println(sensors.getTempCByIndex(0));
  //Serial.print("%");
  Serial.print("Moisture = ");
  Serial.print(moisture_percentage);
 
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" pH Value ");
  lcd.print(phValue);
  //lcd.print(T);
  lcd.setCursor(0,1);
  lcd.print(" Moisture :");
  lcd.print(moisture_percentage);*/
 
}
void loop(void)
{

  for(int i=0;i<10;i++)
 {
  buf[i]=analogRead(analogInPin);
  delay(100);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])
   {
    temp=buf[i];
    buf[i]=buf[j];
    buf[j]=temp;
   }
  }
 }
 avgValue=0;
 for(int i=2;i<8;i++)
 avgValue+=buf[i];
 float pHVol=(float)avgValue*5.0/1024/6;
 float phValue = -5.70 * pHVol + 21.34;
 //Serial.print(" ");
 //Serial.print("pH = ");
 //Serial.print(phValue);
 
  Blynk.run();
  timer.run();
 
  sensors.requestTemperatures();
  delay(1000);
  float T = sensors.getTempCByIndex(0);
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  //Serial.print("temperature: ");
  //Serial.println(sensors.getTempCByIndex(0));
  //Serial.print("%");
  //Serial.print(" ");
  //Serial.print("Moisture = ");
  delay(50000);
  Serial.print(moisture_percentage);
  Serial.print(",");
  //Serial.print("pH = ");
  Serial.print(phValue);
  Serial.print(",");
  Serial.println();

  Blynk.virtualWrite(V5, moisture_percentage);
  Blynk.virtualWrite(V6, phValue);
 
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" pH Value :");
  lcd.print(phValue);
  //lcd.print(T);
  lcd.setCursor(0,1);
  lcd.print(" Moisture :");
  lcd.print(moisture_percentage);
  lcd.print("%");
    /*if (dataFile)
  {
  Serial.print(line);
    Serial.print(":    Temperature = ");
    Serial.print(T);
    Serial.print("°C,    Humidity = ");
   // Serial.print(moisture_percentage);
    //Serial.print("%");
    // Write data to SD card file (Log.txt)
    dataFile.print(line++);
    dataFile.print(":    Temperature = ");
    dataFile.print(T);
    dataFile.print("°C,    Moisture = ");
    dataFile.print(moisture_percentage);
    dataFile.println("%");
    dataFile.close();*/

}
void Read_TempHum()
{  
  //Serial.println(T);
  //Serial.println(moisture_percentage);
}
