
void setup() {

  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  	     
}

void loop() {
 digitalWrite(10,LOW);
 delay(1000); //Unit is microsecond
 digitalWrite(10,HIGH);
 delay(1000); 
}

