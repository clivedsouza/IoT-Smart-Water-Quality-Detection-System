#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 16);

int sensorPin = A0;
void setup()
{
 // Serial.begin(9600);
  lcd.begin();
  pinMode(3,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  int turbidity = analogRead(A0);
  int Value = map(turbidity, 0,584, 100, 0);
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("Value:");
  lcd.print("   ");
  lcd.setCursor(10, 0);
  lcd.print(Value);
  delay(100);
    if (Value < 20) {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    lcd.setCursor(0, 1);
    lcd.print(" its CLEAR ");
  }
  if ((Value > 10) && (Value < 50)) {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    lcd.setCursor(0, 1);
    lcd.print(" its CLOUDY ");
  }
  if (Value > 50) {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    lcd.setCursor(0, 1);
    lcd.print(" its DIRTY ");
  }

}
