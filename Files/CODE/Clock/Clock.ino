//Source: https://www.youtube.com/watch?v=qwM8oiy0Vy4

#include <WiFi.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NTPClient.h> 
#include <WiFiUdp.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

const char* ssid     = "INSERT HERE YOUR SSID";                         // SSID of local network
const char* password = "INSERT HERE YOUR WIFI PASSWORD";                    // Password on network
bool id = false;
WiFiClient client;
String result;

WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP);
NTPClient timeClient(ntpUDP, "my.pool.ntp.org", 7200, 60000); // 

/*
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +2 = 7200
*/


// Variables to save date and time
String formattedTime;
String dayStamp;
String timeStamp;

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  WiFi.mode(WIFI_STA);   //   create wifi station
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3D for 128x64
  delay(200);
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0, 0);            // Start at top-left corner
  display.println("SURVIVAL HACKING");
  display.print("Connecting.");
  display.display();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    display.print(".");
    display.display();
  }

  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Connected ");
  display.println("IP Address: ");
  display.println(WiFi.localIP());
  display.display();
  delay(1000);
  display.clearDisplay();
  timeClient.begin();

/*
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  //timeClient.setTimeOffset(3600); - As result Malaysia is GMT + 8, therefore, the value will be 28800                    
  //getData();
  //delay(500);
*/

}

void loop()                    
{
  timeClient.update();

  Serial.println(timeClient.getFormattedTime()); //- First Option
  formattedTime = timeClient.getFormattedTime();
  Serial.println(formattedTime);
  
  // Extract time
  timeStamp = formattedTime;

  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setCursor(18, 25);            // Start at top-left corner
  display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
  //display.print("Time: ");
  display.println(timeStamp);
  display.display();
  
  delay(1000);     // 1 second delay

}