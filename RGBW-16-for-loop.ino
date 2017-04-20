// RGBW (Red Green Blue White Neo-Pixel starter code
// 16 LEDS  increment
// CW Coleman 170413
int clearColor();
int redColor();
int blueColor();
int greenColor();
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 16

#define BRIGHTNESS 25
#define BRIGHTNESS1 100
#define BRIGHTNESS2 150
#define BRIGHTNESS3 255

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  Serial.begin(115800);
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() { 
  clearColor(); redColor(); 
  blueColor(); greenColor();
  clearColor(); blueColor(); 
  redColor(); greenColor(); 
  clearColor();greenColor(); 
  blueColor(); redColor(); 
}

int clearColor(){
  strip.setBrightness(BRIGHTNESS);
  // Initialize some variables for the void loop()
int red = 0, green= 0, blue = 0, white = 100;
int wait = 800;
int led = 0;
int i;

  for ( led = 0; led < 16; led++){  
    strip.setPixelColor(led, red, green , blue, white);
  }//end of for loop
    strip.show();
    delay(wait);
    red = red + 32;
    green = green + 25;
    blue = blue + 47;
    white = white + 1;

    if (red > 255) red = 0;
    if (green > 255) green = 0;
    if (blue > 255) blue = 0;
    if (white > 50) white = 0;
       
    if (red < 0) red = 255;
    if (green  < 0) green = 255;
    if (blue < 0) blue = 255;
    if (white  < 0 ) white = 50;
}
int redColor(){
  strip.setBrightness(BRIGHTNESS1);
  // Initialize some variables for the void loop()
int red = 255, green= 54, blue = 54, white = 0;
int wait = 800;
int led = 0;
int i;

  for ( led = 0; led < 16; led++){  
    strip.setPixelColor(led, red, green , blue, white);
  }//end of for loop
    strip.show();
    delay(wait);
    red = red + 32;
    green = green + 25;
    blue = blue + 47;
    white = white + 1;

    if (red > 255) red = 255;
    if (green > 255) green = 0;
    if (blue > 255) blue = 0;
    if (white > 50) white = 0;
       
    if (red < 0) red = 255;
    if (green  < 0) green = 255;
    if (blue < 0) blue = 255;
    if (white  < 0 ) white = 50;
}
int blueColor(){
  strip.setBrightness(BRIGHTNESS2);
  // Initialize some variables for the void loop()
int red = 54, green= 54, blue = 255, white = 0;
int wait = 800;
int led = 0;
int i;

  for ( led = 0; led < 16; led++){  
    strip.setPixelColor(led, red, green , blue, white);
  }//end of for loop
    strip.show();
    delay(wait);
    red = red + 32;
    green = green + 25;
    blue = blue + 47;
    white = white + 1;

    if (red > 255) red = 0;
    if (green > 255) green = 0;
    if (blue > 255) blue = 255;
    if (white > 50) white = 0;
       
    if (red < 0) red = 255;
    if (green  < 0) green = 255;
    if (blue < 0) blue = 255;
    if (white  < 0 ) white = 50;
}
int greenColor(){
  strip.setBrightness(BRIGHTNESS3);
  // Initialize some variables for the void loop()
int red = 54, green= 255, blue = 54, white = 0;
int wait = 800;
int led = 0;
int i;

  for ( led = 0; led < 16; led++){  
    strip.setPixelColor(led, red, green , blue, white);
  }//end of for loop
    strip.show();
    delay(wait);
    red = red + 32;
    green = green + 25;
    blue = blue + 47;
    white = white + 1;

    if (red > 255) red = 0;
    if (green > 255) green = 255;
    if (blue > 255) blue = 0;
    if (white > 50) white = 0;
       
    if (red < 0) red = 255;
    if (green  < 0) green = 255;
    if (blue < 0) blue = 255;
    if (white  < 0 ) white = 50;
}
