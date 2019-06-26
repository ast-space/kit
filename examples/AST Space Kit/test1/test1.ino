/**
* Function: Using ultrasonic module to obtain distance
* Author: Xiaotian Chen
* Modify: XP
* Pins: Using D7,D12 and D13 pins without Dupont 
**/
int inputPin=13; 
int outputPin=12; 
void setup()
{
Serial.begin(9600);
pinMode(inputPin, INPUT);
pinMode(outputPin, OUTPUT);
pinMode(7, OUTPUT);
}
void loop()
{
digitalWrite(outputPin, LOW); 
delayMicroseconds(2);
digitalWrite(outputPin, HIGH); 
delayMicroseconds(10);
digitalWrite(outputPin, LOW); 
int distance = pulseIn(inputPin, HIGH); // Read distance from sensor
distance= distance/58; 
Serial.println(distance); //Print distance value
delay(50);
if (distance >=20)//If the distance is greater than 20 cm, the buzzer will work
{
digitalWrite(7,LOW);
}
else
{
digitalWrite(7,HIGH);
}
}
