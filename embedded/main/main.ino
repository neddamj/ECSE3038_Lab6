#include <SoftwareSerial.h>

#define DEBUG true
SoftwareSerial esp(10, 11);

int tank_id = 0;

String sendData(String command, const int timeout, boolean debug) {
    String response = "";
    
    esp.print(command); // send the read character to the esp8266
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp.available())
      {
        
        // The esp has data so display its output to the serial window 
        char c = esp.read(); // read the next character.
        response += c;
      }  
    }
    
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}

int getWaterLevel() {
  return (int)random(10, 201);
}

void setup() {
  // put your setup code here, to run once:
  esp.begin(115200);
  Serial.begin(115200);
  
  sendData("AT+RST\r\n", 10000, DEBUG);
  sendData("AT+CWLAP\r\n", 10000, DEBUG);
  sendData("AT+CWJAP=\"FLOW\",\"5\"\r\n", 5000, DEBUG);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}


/*
 * Physical Connections: ESP TX - 10
 *                       ESP RX - 11
 *                       ESP VCC - 3.3V
 *                       ESP GND - GND
 *                       ESP CH_PD - 3.3V   
*/
