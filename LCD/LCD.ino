// Include the library
#include <LiquidCrystal.h>
// Start the library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
long deltatime;

void setup() {
    lcd.begin(16, 2);
    pinMode(switchPin, INPUT);

    lcd.print("Hello World");
    //lcd.autoscroll();
    Serial.begin(9600);
}

void loop() {
    while (Serial.available() == 0) {}     //wait for data available
    String teststr = Serial.readString();  //read until timeout
    teststr.trim();
    if (teststr != "") {
        lcd.clear();
        Serial.println(teststr);
        lcd.println(teststr);
    }
}
