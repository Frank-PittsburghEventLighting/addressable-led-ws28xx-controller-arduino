
#include <Keypad.h>
#include "FastLED.h"
#define DATA_PIN 2
#define LED_TYPE WS2813
#define COLOR_ORDER GRB
#define NUM_LEDS 79
#define BRIGHTNESS 30

CRGB leds[NUM_LEDS];
const byte ROWS = 8; // Eight rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'x','0','Y'},
  {'a','e','j'},
  {'b','f','k'},
  {'c','g','m'},
  {'d','h','n'},
};
// Connect keypad ROW0, ROW1, ROW2, to ROW8 to these Arduino pins.
byte rowPins[ROWS] = { 10, 9, 8, 7, 6, 5, 4, 3 };
// Connect keypad COL0, COL1 and COL2 to these Arduino Due pins.
byte colPins[COLS] = { 13, 12, 11 }; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{

  Serial.begin(9600);
}

void loop()
{
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '1':
       {
      for (int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = CRGB::Red;
      }
      } 
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
    break;
      case '2':
      
      default:
        Serial.println(key);
    }
  }
}
