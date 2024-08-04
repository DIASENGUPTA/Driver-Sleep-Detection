#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "OnePlus 6T"; //Your Network SSID
const char* password = "Diya2519"; //Your Network Password
int val;
int PulseSensorpin = A0; //Pulse Sensor Pin Connected at A0 Pin
WiFiClient client;

unsigned long myChannelNumber = 1371763 ; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "N2YCKGMR0QDGMM75"; //Your Write API Key

void setup()
{
 Serial.begin(9600);
 delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop()
{
  val = analogRead(PulseSensorpin); //Read Analog values and Store in val variable
  Serial.println("Pulse Sensorvalue=  "); // Start Printing on Pulse sensor value on LCD
  Serial.println(val/8); // Start Printing on Pulse sensor value on LCD
  delay(10);
  ThingSpeak.writeField(myChannelNumber, 1,val/8, myWriteAPIKey); //Update in ThingSpeak
}
