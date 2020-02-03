#include <AFMotor.h>
AF_DCMotor motor1(1,MOTOR12_64KHZ);
AF_DCMotor motor2(4,MOTOR12_64KHZ);
int s1=A0;
int s2=A1;
int s3=A2;
int s4=A3;
int s5=A4;
int s6=A5;

int threshold=500;

void setup()
{
 
  motor1.setSpeed(80);//left
  motor2.setSpeed(80);
  Serial.begin(9600);
 // Serial.print("Hello World");
  pinMode(s1,INPUT);//left
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  pinMode(s5,INPUT);
  pinMode(s6,INPUT);
}


void loop()
{
    int a=digitalRead(s1);
  int b=digitalRead(s2);
  int c=digitalRead(s3);
  int d=digitalRead(s4);
  int e=digitalRead(s5);
  int f=digitalRead(s6);
 
 /* Serial.print(a);
  Serial.print(" ");
  Serial.print(b);
  Serial.print(" ");
  Serial.print(c);
  Serial.print(" ");
  Serial.print(d);
  Serial.print(" ");
  Serial.print(e);
  Serial.print(" ");
  Serial.print(f);
  Serial.print(" ");
  Serial.print('\n');
  
  */

  //            
  if(c==0 && d==1)
  {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
  if((a==0 || f==0)&& (c==0 ||e==0))  //Black line straight ahead
  {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
   // delay(1000);
  }
  else if(a==1 || c==0 || d==0 && f==1)  //Black line straight ahead
  {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
   // delay(1000);
  }
  

//                                                                                               left
else if((a==0|| c==0) &&  (d==1 && f==1))  
  {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    //delay(1000);
  } 
  
  else if((a==1 && c==1) && (d==0 || f ==0))           // r
  {
    motor2.run(BACKWARD);
    motor1.run(FORWARD);
  }
  else if((a==0 ||c==0 ) && (d==0 ||f==0))
  {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
  else if(a==1 &&  c==1 && d==1 && f==1)
  {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  }
}
