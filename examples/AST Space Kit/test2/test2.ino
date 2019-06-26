
/**
* Function: Using LCD to display temperature and humidity from sensor
* Author: Xiaotian Chen
* Modify: XP
*Version: V1.2
* Pins: Using Dupont line to connect Aduino pins and LCD pins:
* LCD RS pin to pin A0
* LCD RW pin to GND
* LCD ENA pin to pin A1
* LCD D4 pin to pin A2
* LCD D5 pin to pin A3
* LCD D6 pin to pin A4
* LCD D7 pin to pin A5 
**/


// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
#include <DHT11.h>

double Fahrenheit(double celsius) 
{
        return 1.8 * celsius + 32;
}    //Converted to Celsius temperature 

double Kelvin(double celsius)
{
        return celsius + 273.15;
}     //Converted to Kelvin temperature
double dewPoint(double celsius, double humidity)
{
        double A0= 373.15/(273.15 + celsius);
        double SUM = -7.90298 * (A0-1);
        SUM += 5.02808 * log10(A0);
        SUM += -1.3816e-7 * (pow(10, (11.344*(1-1/A0)))-1) ;
        SUM += 8.1328e-3 * (pow(10,(-3.49149*(A0-1)))-1) ;
        SUM += log10(1013.246);
        double VP = pow(10, SUM-3) * humidity;
        double T = log(VP/0.61078);   // temp var
        return (241.88 * T) / (17.558-T);
}

double dewPointFast(double celsius, double humidity)
{
        double a = 17.271;
        double b = 237.7;
        double temp = (a * celsius) / (b + celsius) + log(humidity/100);
        double Td = (b * temp) / (a - temp);
        return Td;
}



dht11 DHT11;

#define DHT11PIN 2
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  }

void loop() {
  lcd.print("hello, AST Space");
   int chk = DHT11.read(DHT11PIN);
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("H:");
   lcd.setCursor(2, 1);
  lcd.print(DHT11.humidity);
   lcd.setCursor(10, 1);
   lcd.print("T:");
    lcd.setCursor(12, 1);
     lcd.print(DHT11.temperature);
     delay(500);
     lcd.clear();
     
}

