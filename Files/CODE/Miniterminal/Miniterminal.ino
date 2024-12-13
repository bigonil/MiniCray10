/*
  MINI CRAY TERMINAL EMULATION by Davide Gatti www.survivalhacking.it
  it simulate on screen text when using a CRAY.
  The program emulate a typewriting and scrolling text.

  Library needed: ESP8266 and ESP32 oled driver for SSD1306 display by
  ThingPulse, Daniel Eichhorn and Fabrice Weinberg
  https://thingpulse.com
*/

#include <Wire.h>               // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"        // legacy: #include "SSD1306.h"


// Optionally include custom images
# define SCROLLSPEED 10 // speed of scroling text
# define TYPESPEED 50   // speed of typewriting

// clear buffer
int nriga = 1;
String linea1 = "                   ";
String linea2 = "                   ";
String linea3 = "                   ";
String linea4 = "                   ";
String linea5 = "                   ";
String linea6 = "                   ";

// Initialize the OLED display using Arduino Wire:
 SSD1306Wire display(0x3c, SDA, SCL);   // ADDRESS, SDA, SCL  -  SDA and SCL usually populate automatically based on your board's pins_arduino.h e.g. https://github.com/esp8266/Arduino/blob/master/variants/nodemcu/pins_arduino.h

void setup() {
  Serial.begin(115200);
  Serial.println("Start");

  // Initialising the UI will init the display too.
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  // create more fonts at http://oleddisplay.squix.ch/
  display.clear(); // clear the display
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);


//  SlowText("Survival Hacking",0,0);
  AddText("CRAY Station Ver.4.2  ");
  AddText("TOP-0 Sn504/2 Core 1  ");
  AddText("                      ");
  AddText("Enter Date [MM/DD/YY] ");
  delay(1000);
  AddText("10/28/65 ");
  delay(500);
  AddText("Enter Time [HH:MM:SS] ");
  delay(1000);
  AddText("12:35:00 ");
  delay(500);
  AddText("                      ");
  AddText("READY ");
  delay(1000);
  AddText("HELP ");
  delay(500);
  AddText("*       ABORT    BUGOFF ");
  AddText("CONTEST CLEAR    CONFIG ");
  AddText("DDUMP    DEBUG    COPY   ");
  AddText("FLOAD    HELP     INIT   ");
  AddText("LIST       PART     STOP   ");
  AddText("VME        TTY      START   ");
  delay(1000);
  AddText("                      ");
  AddText("START COS_116 Deadstart ");
  delay(1000);
  AddText("                      ");
  AddText("CPU <> MIOP Channel init ");
  AddText("CPU <> MIOP Linckage full ");
  AddText("                      ");
  AddText("START COMPLETE ");
  AddText("                      ");
  AddText("Concentr. ordinal 3 init ");
  AddText("Concentr. ordinal 3 logon ");
  AddText("                     ");
  AddText("STATION READY ");
  AddText("                     ");
  AddText("LOGON ");
  delay(500);
  AddText("COS 1.17   10/28/65 ");
  AddText("        ");
  Blink(3);
  AddText(">STMSG ");
  delay(1000);
  AddText("---------------------------------------- ");
  AddText("CRAY STATION MESSAGE ");
  AddText("Enter configuration ");
  AddText("changes or 'GO' to ");
  AddText("continue. Reply REQ ");
  AddText("        ");
  Blink(3);
  AddText(">REPLY,0,60 ");
  delay(1000);
  AddText("        ");
  AddText("configuration accepted ");
  AddText("running normal ");
  AddText("        ");
  Blink(10);
  AddText(">SHUTDOWN ");
  delay(1000);
  AddText("ARE YOU SURE !! Y/N ");
  delay(2000);
  AddText(">Y ");
  delay(500);
  AddText(">Shutdown initiated ");
  AddText(">----------------------------------------- ");
  AddText(">Shutdown start 10/28/65 ");
  AddText(">Shutdown time 12:35:00 ");
  delay(500);
  AddText(">Dismount COS_116 ");
  delay(2500);
  AddText(">Disconnect concentr. 3 ");
  delay(1500);
  AddText(">LOGOUT ");
  delay(1500);
  AddText("                      ");
  AddText("---------------------------------------- ");
  AddText("    CRY STATION OFF ");
  AddText("          GOODBAY     ");
  AddText("---------------------------------------- ");
  AddText("                      ");
  BlinkD(15);
  display.clear(); // clear the display
  nriga=1;
}

// simulate cursor blink
void Blink(int nblink) {
  for (int r=0 ; r < nblink ; r++) {
    display.drawString(0, 51, ">_ ");
    display.display();
    delay(700);
    display.setColor(BLACK); // alternate colors
    display.fillRect(0, 51, 30,13);
    display.display();
    display.setColor(WHITE); // alternate colors
    display.drawString(0, 51, ">  ");
    display.display();
    delay(700);
  }
}

// simulate blinking dot
void BlinkD(int nblink) {
  for (int r=0 ; r < nblink ; r++) {
    display.setColor(BLACK); // alternate colors
    display.fillRect(0, 51, 30,13);
    display.display();
    display.setColor(WHITE); // alternate colors
    display.drawString(0, 51, ".");
    display.display();
    delay(700);
    display.setColor(BLACK); // alternate colors
    display.fillRect(0, 51, 30,13);
    display.display();
    display.setColor(WHITE); // alternate colors
    display.drawString(0, 51, "o");
    display.display();
    delay(700);
  }
}

// add text to screen buffer
void AddText(char *text) {
  Serial.println("Riga=" + String(nriga));
  switch (nriga) {
  case 1:
    linea1 = String(text);
    SlowText(text,1);
    nriga=2;  
    break;
  case 2:
    linea2 = String(text);
    SlowText(text,11);
    nriga=3;  
    break;
  case 3:
    linea3 = String(text);
    SlowText(text,21);
    nriga=4;  
    break;
  case 4:
    linea4 = String(text);
    SlowText(text,31);
    nriga=5;  
    break;
  case 5:
    linea5 = String(text);
    SlowText(text,41);
    nriga=6;  
    break;
  case 6:
    linea6 = String(text);
    SlowText(text,51);
    nriga=7;  
    break;
  default:
    display.clear(); // clear the display
    linea1=linea2;
    linea2=linea3;
    linea3=linea4;
    linea4=linea5;
    linea5=linea6;
    display.drawString(0, 41, linea5);
    display.display();
    delay(SCROLLSPEED);
    display.drawString(0, 31, linea4);
    display.display();
    delay(SCROLLSPEED);
    display.drawString(0, 21, linea3);
    display.display();
    delay(SCROLLSPEED);
    display.drawString(0, 11, linea2);
    display.display();
    delay(SCROLLSPEED);
    display.drawString(0, 1, linea1);
    display.display();
    delay(SCROLLSPEED);
    linea6 = String(text);
    SlowText(text,51);
  break;
  }
}


// write text on screen with programmable speed
void SlowText(char *text, int y) {
//  display.drawString(0, y, String(text));
  for (int r=0 ; r < String(text).length() ; r++) {
    display.drawString(0, y, String(text).substring(0,r));
    delay(TYPESPEED);
    display.display();
  }
}


