// Libraryies
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define the screen variables
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64

// Declare the oled screen object
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Set the different pins using constant integers
const int sensorPin = 2;
const int buzzerPin = 6;
const int ledPin = 4;
const int vPin = A0;
const int buttonPin = 3;

// Declare some global variables
int mode;
int inVal;
int buttonState;

// Function drawFrame to run every loop
void drawFrame(int Mode) { // Takes mode int as parameter 0 for continuity and 1 for voltage
    switch(Mode) {
        case 0:
            // If in continuity mode then...
            inVal = digitalRead(sensorPin); // Read the sensor pin
            // If there is a connection then..
            if (inVal == 1) {
                // beep and show beep on the screen
                analogWrite(buzzerPin, 200);
                printState(Mode);
                oled.setCursor(0, 16);
                oled.print("beep!");
                oled.display();
            } else {
                // stop beep and show no beep on the screen
                analogWrite(buzzerPin, 0);
                printState(Mode);
                oled.setCursor(0, 16);
                oled.print("no beep");
                oled.display();
            }
            break;
        case 1:
            // If in voltage mode then...
            int analogVal = analogRead(vPin); // Raw data from the pin 
            float inVoltage1 = analogVal * 5.0 / 1023.0; // Math to get it to volts
            printState(Mode);
            // Print the voltage on the screen :)
            oled.setCursor(0, 16);
            oled.print(inVoltage1);
            oled.display();
            break;
  }
}

// Function to print the name of the mode you are in at the top of the screen
void printState(int Mode) { // takes the mode as input
    switch(Mode) {
        case 0:
            oled.clearDisplay();
            oled.setCursor(0, 0);
            oled.print("Continuity");
            break;
        case 1:
            oled.clearDisplay();
            oled.setCursor(0, 0);
            oled.print("Voltage:");
            break;

    }
}

void setup() {
    Serial.begin(9600);
    pinMode(sensorPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(buttonPin, INPUT);

    // initialize the oled
    if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        while (true); // Wait until oled is ready
    }
    delay(1000); // wait a little
    oled.clearDisplay(); // clearDisplay
    oled.setTextSize(2); // Set the display size
    oled.println("hiii :3"); //  My little splash screen :3
    oled.display(); 
    delay(1000);
    }

void loop() {
    buttonState = digitalRead(buttonPin); // read the button pin and assign the mode accordingly
    if (buttonState == HIGH) {
        mode = 1;
    } else {
        mode = 0;
    }
    // Draw the frame!!
    drawFrame(mode);
}


