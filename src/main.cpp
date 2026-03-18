#include <Arduino.h>

int feuchtigkeit = 0;
int feuchtigkeit_prozent = 0;
bool  an = false;

void setup() {

    //Pins belegen
    pinMode(13 , OUTPUT);
    pinMode(A0, INPUT);
    Serial.begin(9600);

}

void loop() {

    //Misst Feuchtigkeit und sendet Prozentwert an Computer
    feuchtigkeit = analogRead(A0);
    feuchtigkeit_prozent  = map(feuchtigkeit, 464, 191, 0, 100);
    Serial.println(feuchtigkeit_prozent);


    //Lässt die Lampe leuchten wenn die Bodenkapazität unter 20% fällt

    if (feuchtigkeit_prozent < 20) {
        digitalWrite(13, HIGH);
    }else {
        digitalWrite(13, LOW);
    }
    // kurze Pause damit nicht zu viele Daten an Computer geschickt werden
    delay(1000);
}