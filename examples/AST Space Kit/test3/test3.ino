/**
* Function: Using "PREV","NEXT","VOL-" and "VOL+" on IR Remote Control 
* to control RGB LED
* Author: Xiaotian Chen
* Modify: XP
* Pins: Using D5,D6 pins without Dupont; Turn on S1 to enable pins 
**/
#include <IRremote.h>
 
int RECV_PIN = 11;
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
int blue=3;
int red=5;
int green=6;

int b=0;
int r=0;
int g=0;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //Initialize IR receiver
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value); //Serial port prints key number
if(results.value==16720605)      //Actions
{
r=r+10;
  }
 
  if(results.value==16712445)
  {
    r=r-10;
    }
    if(results.value==16769055)
  {
     g=g-10;
    }
    else if(results.value==16754775)
  {
     g=g+10;
    }
    irrecv.resume(); // Reset and prepare to get next key number
}
  if((g>255))
  {g=255;}
  else if(g<0)
  {g=0;}
  if((r>255))
  {r=255;}
  else if(r<0)
  {r=0;}
   analogWrite(red,r);
    analogWrite(green,g);
}
