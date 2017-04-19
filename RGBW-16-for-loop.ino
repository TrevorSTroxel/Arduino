// RGBW (Red Green Blue White Neo-Pixel starter code
// 16 LEDS  increment
// CW Coleman 170413

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 16

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// Initialize some variables for the void loop()
int red = 0, green= 0, blue = 0, white = 10;
int wait = 200;
int led = 0;
int i;

void loop() {
  
  for ( led = 0; led < 16; led++){  
    strip.setPixelColor(led, red, green , blue, white);
  }//end of for loop
    strip.show();
    delay(wait);
    red = red + 32;
    green = green + 25;
    blue = blue + 47;
    white = white + 1;

    if (red > 255) red = 32;
    if (green > 255) green = 25;
    if (blue > 255) blue = 47;
    if (white > 50) white = 0;
       
    if (red < 0) red = 115;
    if (green  < 0) green = 137;
    if (blue < 0) blue = 216;
    if (white  < 0 ) white = 50;
}


