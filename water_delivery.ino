#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int sensor=A0;
int relay = A5;

int sensorState=0;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(sensor,INPUT);
pinMode(relay,OUTPUT);;

lcd.setCursor(0,0);
lcd.print("COIN BASED        ");

lcd.setCursor(0,1);
lcd.print("WATER DISPENSERY          ");
delay(2000);
}

void loop() {
   sensorState=digitalRead(sensor);  

    if(sensorState==HIGH)
    {
      lcd.setCursor(0,0);
lcd.print("PLEASE WAIT        ");
delay(1000);
lcd.setCursor(0,1);
lcd.print("WATER DELEVERING          ");
delay(1000);
digitalWrite(relay,HIGH);
delay(5000);   // water delevering time
    }
else if(sensorState==LOW)
{
  lcd.setCursor(0,0);
lcd.print("PLEASE INSERT        ");

lcd.setCursor(0,1);
lcd.print("COIN                ");
digitalWrite(relay,LOW);
      }
  
  
       
  
}
