#include <Wire.h>
//#include <LCD.h>
#include <LiquidCrystal_I2C.h>
//#include <NewPing.h>

//#define I2C_ADDR 0x27  // Add your address here.
//#define Rs_pin 0
//#define Rw_pin 1
//#define En_pin 2
//#define BACKLIGHT_PIN 3
//#define D4_pin 4
//#define D5_pin 5
//#define D6_pin 6
//#define D7_pin 7
//#define trigPin 10
//#define echoPin 13


#define ECHO_PIN 13 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN 10 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

LiquidCrystal_I2C lcd(0x27, 2, 16);

void setup()
{
 lcd.begin (); //  our LCD is a 20x4, change for your LCD if needed
  Serial.begin (9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

// LCD Backlight ON
//lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
//lcd.setBacklight(HIGH);

//lcd.home (); // go home on LCD
lcd.print("Range Finder HC-SR04"); 
}

void loop()
{
 float duration, distance;
  digitalWrite(TRIGGER_PIN, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) * 0.0344+1.42;
  
  if (distance >= 400 || distance <= 2){
    //lcd.print("Distance = ");
    lcd.println("Out of range");
    delay(500);
  }
  else if (distance <= 5){
    lcd.println("Alert!!!");
    delay(500);
  }
  
  else {
    //lcd.print("Distance = ");
    lcd.print(distance);
    lcd.println(" cm ");
    delay(500);
  }
  delay(500);
  lcd.clear();
}
