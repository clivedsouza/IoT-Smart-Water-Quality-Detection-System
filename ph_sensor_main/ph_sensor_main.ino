/* sunrobotronics technologies 
 *  if any help then contact me - sunrobotronics@gmail.com
 */
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27, 2, 16); 
const int analogInPin = A1; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp=0;

void setup() 
{
 Serial.begin(9600);
 pinMode(13,OUTPUT);
lcd.begin();
lcd.setCursor(0,0);
lcd.print("Measure Ph ");
lcd.setCursor(0,1);    
lcd.print("Value ....... ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Extracting Data In");
lcd.setCursor(0,1);    
lcd.print("3");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Verifying Data");
lcd.setCursor(0,1);    
lcd.print("Uploading Data");
delay(2000);  
lcd.clear();
}
 
void loop() 
{
 for(int i=0;i<10;i++) 
 { 
  buf[i]=analogRead(analogInPin);
  delay(10);
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
 
 float phValue=(float)avgValue*5.0/1024/6; //convert the analog into millivolt
  phValue=3.5*phValue;
 

 Serial.print("sensor = ");
 Serial.println(phValue);
 lcd.clear();
 lcd.setCursor(0,0);  
 lcd.print("pH Value");
 lcd.setCursor(3,1);  
 lcd.print(phValue);
 delay(900);
}
