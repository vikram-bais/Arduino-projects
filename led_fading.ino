void setup() {
  pinMode(11,OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  int i;
  for(i=1;i<=200;i++){
  analogWrite(11,i);
  delay(1);
  }
  for(i=200;i>=1;i--)
  {
    analogWrite(11,i);
    delay(1);
  }
  // put your main code here, to run repeatedly:

}
