#include <Arduino.h>

int feuchtigkeit = 0;
int feuchtigkeit_prozent = 0;
int Luftfeuchtigkeit = 464;
int Wasserfeuchtigkeit = 191;

void setup() {

    //Pins belegen
    pinMode(11 , OUTPUT);
    pinMode(A0, INPUT);
    Serial.begin(9600);

}

void loop() {

    //Misst Feuchtigkeit und sendet Prozentwert an Computer
    feuchtigkeit = analogRead(A0);
    feuchtigkeit_prozent  = map(feuchtigkeit, Luftfeuchtigkeit, Wasserfeuchtigkeit, 0, 100);
    feuchtigkeit_prozent = constrain(feuchtigkeit_prozent, 0, 100);  //Begrenzt Wert auf zischen 0-100
    Serial.println(feuchtigkeit_prozent);


    //Lässt die Lampe leuchten wenn die Bodenkapazität unter 20% fällt

    if (feuchtigkeit_prozent < 20) {
        digitalWrite(11, HIGH);
    }else {
        digitalWrite(11, LOW);
    }
    // kurze Pause damit nicht zu viele Daten an Computer geschickt werden
    delay(1000);
}

