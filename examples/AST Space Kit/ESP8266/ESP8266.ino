// TCP_Pure_Data_Mode.ino

// in this example ,esp8266 conneted to a TCP Server ,and working in pure data mode

#include "esp8266.h"
#include "SoftwareSerial.h"

#define SERIAL_TX_BUFFER_SIZE 128
#define SERIAL_RX_BUFFER_SIZE 128

#define	ssid		"ASTspace"    //Nme of AP
#define	password	"goodluck"   //Password of AP
#define	serverIP	"api.yeelink.net"   //The IP of server 
#define serverPort	"80"    //The port of sever

Esp8266 wifi;
SoftwareSerial mySerial(A0, A1); // RX, TX  softerware serialport
String str="";
String url="http://api.yeelink.net/v1.0/device/19527/sensor/34289/datapoints\r\n\r\n\r\n";
int flag=0;
void setup() {

     pinMode(A3,OUTPUT);
     digitalWrite(A3,LOW);
  	Serial.begin(9600);
  	mySerial.begin(115200);
	wifi.begin(&mySerial, &Serial);		//Serial is used to communicate with esp8266 module, mySerial is used to debug

	if (wifi.checkEsp8266()) {
		wifi.debugPrintln("esp8266 is online!");
	}
        else
        {
                wifi.debugPrintln("esp8266 is offline!");
        }     
              
    wifi.connectAP(ssid, password);
    wifi.setSingleConnect();
    wifi.connectTCPServer(serverIP, serverPort);
    wifi.setPureDataMode();
        	     
}

void loop() {
  
      
        str=wifi.getData(url);
      //   wifi.debugPrintln(str);
          delay(500);
       
         
  	if(str=="1")
	{	
          str=wifi.getData(url);
          if(str=="1")
          {				
	    digitalWrite(A3,HIGH);
          }
        }
	else if(str=="0")
	{
	   str=wifi.getData(url);
          if(str=="0")
          {				
	    digitalWrite(A3,LOW);
          }		
        }
        else
        {
        
        }

//    if(str=="1")
//	{	
//         			
//	    digitalWrite(A3,HIGH);
//         
//        }
//	else if(str=="0")
//	{
//	       			
//	    digitalWrite(A3,LOW);	
//        }
//        else
//        {
//        
//        }

}


