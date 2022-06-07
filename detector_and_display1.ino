/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
 # define Buzzer 7
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = 0;
int tempC, tempF;

void setup() {
   pinMode(A0,INPUT);
  pinMode(A1,INPUT);
   pinMode(7,OUTPUT);
  // set up the LCD's number of columns and rows:
 
  
  lcd.begin(16, 2);
  
   Serial.begin(9600);
}

void loop() {
  int smoke = analogRead(A0);
  if(smoke>180)
  {
    lcd.setCursor(0, 0);
    lcd.print("Danger! smoke");
     digitalWrite(Buzzer,HIGH);

  }else
  {
    lcd.setCursor(0, 0);
    lcd.print("low smoke");
    digitalWrite(Buzzer, LOW) ;
  }
  
    tempC = get_temperature(sensorPin);
tempF = celsius_to_fahrenheit(tempC);
lcd.setCursor(0,1);
lcd.print(tempF); lcd.print(" "); lcd.print((char)223); lcd.print("F");
delay(200);
}
int get_temperature(int pin) {

int temperature = analogRead(pin);
// Calculate the temperature based on the reading and send that value back
float voltage = temperature * 5.0;
voltage = voltage / 1024.0;
return ((voltage - 0.5) * 100);
}
int celsius_to_fahrenheit(int temp) {
return (temp * 9 / 5) + 32;
  
}
 