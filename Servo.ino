/*
Into Robotics
*/
 
#include <Servo.h>
 
int servoPin = 9;
 
Servo servo;  
 
int servoAngle = 0;   // servo position in degrees

int pot_pin = A0;
int pot_val = 0;


int RL = 5;
int G1 = 4;
int G2 = 3;
int G3 = 2;



 
void setup()
{
  Serial.begin(9600);  
  servo.attach(servoPin);
  pinMode(pot_pin,INPUT);
  pinMode(RL,OUTPUT);
  pinMode(G1,OUTPUT);
  pinMode(G2,OUTPUT);
  pinMode(G3,OUTPUT);
}
 
 
void loop()
{
//control the servo's direction and the position of the motor
pot_val = analogRead(pot_pin);

if(pot_val<=800)
 {digitalWrite(RL,LOW);
 digitalWrite(G1,HIGH);
  pot_val = analogRead(pot_pin);
   servo.write(135); 
   delay(pot_val+200);          
 pot_val = analogRead(pot_pin);
   servo.write(45);      
   delay(pot_val+200);          
   
 }
 else
 {servo.write(90);
 digitalWrite(RL,HIGH);
 digitalWrite(G1,LOW);
 digitalWrite(G2,LOW);
 digitalWrite(G3,LOW);
 }

    if(pot_val<400)
   {digitalWrite(G2,HIGH);}
   else
   {digitalWrite(G2,LOW);}

   if(pot_val<100)
   {digitalWrite(G3,HIGH);}
   else
   {digitalWrite(G3,LOW);}
//end control the servo's direction and the position of the motor
 
 
//control the servo's speed  
 
/*/if you change the delay value (from example change 50 to 10), the speed of the servo changes
  for(servoAngle = 135; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    servo.write(servoAngle);              
    delay(50);                  
  }
 
  for(servoAngle = 45; servoAngle > 0; servoAngle--)  //now move back the micro servo from 0 degrees to 180 degrees
  {                                
    servo.write(servoAngle);          
    delay(50);      
  }
  //end control the servo's speed  */
}
