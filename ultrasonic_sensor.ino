long duration;
int distance;
void setup()
{
   pinMode(11,OUTPUT);//led
   pinMode(12,OUTPUT);//trig
   pinMode(13,INPUT);//eco
   Serial.begin(9600);
}
void loop()
{
  digitalWrite(12,LOW);
  delay(2);
  digitalWrite(12,HIGH);
  delayMicroseconds(10);
  digitalWrite(12,LOW);
  duration=pulseIn(13,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  if(distance>=100)
  {
  digitalWrite(11,LOW); 
  }
   if(distance<100)
  {
  digitalWrite(11,HIGH); 
  }
  delay(50);
}
