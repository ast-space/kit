#include "esp8266.h"
#include "SoftwareSerial.h"
#include <DHT11.h> 

dht11 DHT11;
#define DHT11PIN 2 // Pin of DHT11

#define SERIAL_TX_BUFFER_SIZE 128
#define SERIAL_RX_BUFFER_SIZE 128

#define  ssid    "ghost"    //Nme of wifi
#define password  "goodluck"   //Password of wifi
#define	serverIP	"api.lewei50.com"   //The IP of server 
#define serverPort	"80"    //The port of sever

String userkey= "1a11cce4603c4da589d46d74f9017c56 ";

String Sensor_T= "T6"; // Number of your kit
String Sensor_H= "H6";


Esp8266 wifi;
SoftwareSerial mySerial(A0, A1); // RX, TX  softerware serialport
String str="";
String url="http://api.yeelink.net/v1.0/device/19527/sensor/34289/datapoints\r\n\r\n\r\n";
int i=0;
void setup() {

  pinMode(A3,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  digitalWrite(A3,LOW);
  Serial.begin(9600);
  mySerial.begin(115200);
  wifi.begin(&mySerial, &Serial);		//Serial is used to communicate with esp8266 module, mySerial is used to debug

  if (wifi.checkEsp8266())
  {
      wifi.debugPrintln("esp8266 is online!");
  }
 else
  {
      wifi.debugPrintln("esp8266 is offline!");
  }     
 
 if ( wifi.connectAP(ssid, password)) 
 {
      wifi.debugPrintln("esp8266 is connected to wifi");
 }
 else
 {
      wifi.debugPrintln("esp8266 is failed to connect to wifi");
 }        
 
   wifi.setSingleConnect();
   wifi.connectTCPServer(serverIP, serverPort);
   wifi.setPureDataMode();
	     
}

void loop() {
 DHT11.read(DHT11PIN);
 SendData(DHT11.temperature,DHT11.humidity);
 delay(20000);
 
 digitalWrite(10,LOW);
 delay(500); 
 digitalWrite(10,HIGH);
}
void SendData(int tem,int hum)
{
 mySerial.println("POST /api/V1/gateway/Updatesensors/01 HTTP/1.1");
 mySerial.println("userkey: 1a11cce4603c4da589d46d74f9017c56 ");
 mySerial.println("Host: open.lewei50.com");
 mySerial.println("Content-Length: 55");
 mySerial.println("Connection: close\r\n");       
 mySerial.println("[{\"Name\":\""+Sensor_T+"\",\"Value\":\""+String(tem)+"\"},{\"Name\":\""+Sensor_H+"\",\"Value\":\""+String(hum)+"\"}]\r\n");
}

