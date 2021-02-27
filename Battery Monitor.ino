// Print battery voltage
// to 16x2 LCD via I2C
// with Voltage Divider 

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define 12C_ADDR 0x27 //Add you address here. Find it form
I2C Scanner
#define BLACKLIGHT_PIN  3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
#define led_pin 13
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  lcd.begin (16,2);  //My LCD was 16x2
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home (); // go home
  
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW);
}

void loop()
{
  printVolts();
}

void printVolts()
{
  int sensorValue = analogRead(A0); //read the A0 pin value 
  float voltage = sensorValue * (5.00 / 1023.00) * 2; //convert the value to a true voltage.
    lcd.setCursor(0,0);
    lcd.print("voltage = ");
    lcd.print(voltage); //print the voltage to LCD
    lcd.print(" V");
 
}
