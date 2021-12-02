
#include <BlynkSimpleStream.h>

 // You should get Auth Token in the Blynk App.
 // Go to the Project Settings (nut icon).
 char auth[] = "U1rUx-31g8CGGTFwgF34AG1nYq5d_2Jn";

 void setup()
 {
   Serial.begin(9600);
   Blynk.begin(Serial,auth);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
 }

 BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  int pinData = param.asInt(); 
  if(pinData==1){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
}
 BLYNK_WRITE(V2) //Button Widget is writing to pin V1
{
  int pinData = param.asInt(); 
  if(pinData==1){
    digitalWrite(12, HIGH);
  }else{
    digitalWrite(12, LOW);
  }
}
 BLYNK_WRITE(V3) //Button Widget is writing to pin V1
{
  int pinData = param.asInt(); 
  if(pinData==1){
    digitalWrite(11, HIGH);
  }else{
    digitalWrite(11, LOW);
  }
}

 void loop()
 {
   Blynk.run();
 }
