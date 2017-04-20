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
int red = 255, green= 255, blue = 255, white = 0;
int wait = 0;
int led = 0;

void loop() {
  
    
  strip.setPixelColor(led, red, green , blue, white);
  strip.show();
    delay(wait);
    
  red = red + 37;
  green = green + 91;
  blue = blue + 64;
  white = white + 1;

  // Increment the led.  This can also be done with led++
  led = led + 1;
  

  if (red > 255) red = 37;
   if (green > 255) green = 37;
    if (blue > 255) blue = 37;
     if (white > 50) white = 0;
       
    if (red < 0) red = 255;
   if (green  < 0) green = 255;
    if (blue < 0) blue = 255;
     if (white  < 0 ) white = 1;

   Serial.println(red);
}

