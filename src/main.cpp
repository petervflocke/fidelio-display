#include <Arduino.h>
#include "fidelio_display.h"

#define dioPin 13
#define clkPin 14
#define stbPin 15
#define spiClk 1000000UL 

FidelioDisplay display(dioPin, clkPin, stbPin, spiClk);

char text1[] = "1234";
char text2[] = "5:6:"; // "5:6:" = "5 6 "
char text3[] = "7890";
char text4[] = "21";   // short string
char text5[] = "0123456789"; // long string

void setup() {
  Serial.begin(115200);
  delay(1000);

  display.write(text1);
  delay(2000);
  display.write(text2);
  delay(2000);
  display.write(text3);
  delay(2000);
  display.write(text4);
  delay(2000);  
  display.write(text5);
  delay(2000);    
}

void loop() {
/*   display.cls(); 
  for (int i=0; i < 3; i++) {
    Serial.println("on");
    display.toogleDots();
    display.write(text2);
    delay(500);
    display.toogleDots();
    display.write(text2);
    delay(500);
    Serial.println("off");
    display.write(text3);
    delay(1000);
  } */
  display.cls();
/*   display.alarm(true);
  display.dots(false);
  display.at(0, '0');
  display.at(1, '2');
  display.at(2, '4');
  display.at(3, '6');
  delay(3000); */
  display.cls();
  display.alarm(false);
  display.dots(false);
  display.dots(true);
  for (byte i = 0; i < 0x80; i++) {
    Serial.println(i);
    display.at(0, '0'+(i/10));
    display.at(1, '0'+(i%10));
    display.draw(3, i);
    delay(1000);
  }
}
/*


*/
