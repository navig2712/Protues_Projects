int relay = 7;
int push = 2;

void setup()
{
pinMode(relay,OUTPUT);
pinMode(push,INPUT_PULLUP);
  
  }

void loop()
{
int a = digitalRead(push);
if(a == 0)
digitalWrite(relay,HIGH);
else
digitalWrite(relay,LOW);

  
  }
