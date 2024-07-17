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

    lcd.print("Hello World");
    //lcd.autoscroll();
    Serial.begin(9600);
    delay(1000);
}

void loop() {
    deltatime += 1;
    lcd.clear();
    lcd.print(deltatime);
    delay(100);
}
