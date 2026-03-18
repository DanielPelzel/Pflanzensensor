#include <Arduino.h>
bool  an = false;

void setup() {

    pinMode(13 , OUTPUT);

}


void loop() {

     //LED-Soll blinken
    an = true;
    digitalWrite(13, HIGH);
    delay(10);
    an = false;
    digitalWrite(13, LOW);
    delay(1000);

}