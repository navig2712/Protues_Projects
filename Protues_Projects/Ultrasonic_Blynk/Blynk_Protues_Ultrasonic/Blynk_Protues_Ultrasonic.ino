#define BLYNK_PRINT SwSerial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX

#include <BlynkSimpleStream.h>


#define TRIGGERPIN 3
#define ECHOPIN   4
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "byqnnVzst1vRysuICRWNSUV-JYkTqnKT";


WidgetLCD lcd(V1);

void Ultrasonic()
{
    lcd.clear();
  lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  long duration, distance;
 
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  
  duration = pulseIn(ECHOPIN, HIGH);
  
  
  distance = (duration * 0.034)/2;
  SwSerial.print(distance);
  SwSerial.println("Cm");
  lcd.print(7, 1, distance);
  }

void setup()
{
  SwSerial.begin(9600);
  // Debug console
  Serial.begin(9600);
pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(Serial, auth);
  // You can also specify server:
  

  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  

}

void loop()
{

  Blynk.run();
  Ultrasonic();

//  delay(3500);

}
