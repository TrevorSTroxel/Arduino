
/*
The Circuit:
 Most other analog buttons circuits call for the resistors to be
 lined up in series from ground. The analog pin and each button
 connect off one of the resistors. My cuicuit requires that the
 resistors tie in from +5 to the buttons. The buttons all connect
 to the analog pin which is tied to ground threw a 1k resistor as
 seen in the diagram below. 
        Analog pin 0
                  |
Ground-- 330 Ohm--|--------|--------|-------|-------|
                  |        |        |       |       |
                  btn1     btn2     btn3    btn4    btn5
                  |        |        |       |       |
                  330 Ohm  330 Ohm  330 Ohm  330 Ohm  330 Ohm
                  |--------|--------|-------|-------|-- +5V
           
modified by CWCcoleman
test 170122
left to right
Ground to 5v
5      4      3     2    1
200   253    337   508  1013
*/
void cursor(int h, int k);
int clearPix ();
int drawmatix ();
int readButtons(int pin);
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      64
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int i = 0, j = 0;

int temp[8][8] = {
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1}   
};

int m[8][8] = {  
    {-1,1,2,3,4,5,6,4} ,
    {1,0,0,0,0,0,0,0} ,
    {2,0,0,0,0,0,0,0} ,
    {3,0,0,0,0,0,0,0} ,
    {4,0,0,0,0,0,0,0} ,
    {5,0,0,0,0,0,0,0} ,
    {6,0,0,0,0,0,0,0},
    {7,7,7,7,7,7,7,7}   
};



int delayval = 50; 
void setup()
{
 Serial.begin(9600); 
  pinMode(A0, INPUT_PULLUP); // sets analog pin for input 
  
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  
  pixels.begin(); 
}

int ButtonNumber = 0;
int x = 4;
int y = 4;
int p = 36;
void loop()
{
   // Check for input
   ButtonNumber = readButtons(0);
   Serial.print("Button # ");
   Serial.println(ButtonNumber);
   //delay(500);
// code to move
temp[x][y]= 1;
drawMatrix();
//  move
if (ButtonNumber == 5){  
  temp[x][y] = -1;
  x = 4; //x = x - 1;                        
  y = 4;
  temp[x][y] = 0;
  temp[x+1][y+1] = 0;
  temp[x+1][y] = 0;
  temp[x][y+1] = 0;
  temp[x-1][y-1] = 0;
  temp[x-1][y] = 0;
  temp[x][y-1] = 0;
  temp[x+1][y-1] = 0;
  temp[x-1][y+1] = 0;
}
if (ButtonNumber == 4){
 temp[x][y] = -1;
 x = x - 1;
 y = y;
 temp[x][y] = 0;
 temp[x+1][y] = 1;
  temp[x+1][y+1] = 1;
  temp[x+1][y] = 1;
  temp[x][y+1] = 1;
  temp[x-1][y-1] = 1;
  temp[x-1][y] = 1;
  temp[x][y-1] = 1;
  temp[x+1][y-1] = 1;
  temp[x-1][y+1] = 1;
}
if (ButtonNumber == 3){
 temp[x][y] = -1;
 x = x + 1;
 y = y;
 temp[x][y] = 0;
  temp[x-1][y] = 2;
   temp[x+1][y+1] = 2;
  temp[x+1][y] = 2;
  temp[x][y+1] = 2;
  temp[x-1][y-1] = 2;
  temp[x-1][y] = 2;
  temp[x][y-1] = 2;
  temp[x+1][y-1] = 2;
  temp[x-1][y+1] = 2;
} 
if (ButtonNumber == 2){
 temp[x][y] = -1;
 x = x;
 y = y - 1;
 temp[x][y] = 0;
  temp[x][y+1] = 3;
   temp[x+1][y+1] = 3;
  temp[x+1][y] = 3;
  temp[x][y+1] = 3;
  temp[x-1][y-1] = 3;
  temp[x-1][y] = 3;
  temp[x][y-1] = 3;
  temp[x+1][y-1] = 3;
  temp[x-1][y+1] = 3;
}
if (ButtonNumber == 1){
 temp[x][y] = -1;
 x = x;
 y = y + 1;
 temp[x][y] = 0;
  temp[x][y-1] = 4;
   temp[x+1][y+1] = 4;
  temp[x+1][y] = 4;
  temp[x][y+1] = 4;
  temp[x-1][y-1] = 4;
  temp[x-1][y] = 4;
  temp[x][y-1] = 4;
  temp[x+1][y-1] = 4;
  temp[x-1][y+1] = 4;
}
}

//end code to move
   



int readButtons(int A0pin)
// returns the button number pressed, or zero for none pressed 
// int pin is the analog pin number to read 
/*Ground to 5v
5      4      3     2    1
200   253    337   508  1013
*/
{
  int b,r = 0;  // b is button.  r is resistance
  r=analogRead(A0pin); // get the analog value from A0
// Serial.println(r);
// Serial.print("   ");
  if (r >1000)
  {
    b=1; // buttons have not been pressed
  }   
else
  if (r>480 && r< 600)
  {
    b=2; // button 1 pressed
  }     
  else
    if (r>350 && r<400)
    {
      b=3; // button 2 pressed
    }       
    else
      if (r>300 && r< 340)
      {
        b=4; // button 3 pressed
      }         
      else
        if (r>150 && r<300)
        {
          b=5; // button 4 pressed
        }           
        else
          if (r<20)
          {
            b=0; // button 5 pressed
          }
return b;
}


int clearPix (){
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    }
    pixels.show();
  }

int drawMatrix(){
//ser base color
int r,c;//row and column
int red = 0, green = 0, blue = 0;

  i = 0;
  int val;
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue
      val = temp[r][c];
      switch ( val ) {
           case 0:
            red = 15; green = 15; blue =15;//colors red
          break;
          case 1:
            red = 15; green = 0; blue =0;//colors red
          break;
          case 2:
            red = 0; green = 25; blue =0;//colors  green
          break;
           case 3:
          red = 0; green = 0; blue =25;//colors blue
          break;
            case 4:
          red = 32; green = 32; blue =0;//colors yellow
          break;
            case 5:
          red = 0; green =35; blue =35;//colors cyan
          break;
          case 6:
          red = 60; green = 0; blue =60;//colors
          break;
          case 7:
          red = 65; green = 20; blue =0;//colors
          break;
         default:
          red = 0; green = 0; blue =0;//colors
          break;
          ///////////////////////////////////////////////
}
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
         
      pixels.show(); 
      i++;
      
    }//end y
}//end y and end of loop that increments x,y and i
}

void cursor(int h, int k){
    //ser base color
int r,c;//row and column
int red = 0, green = 0, blue = 0;

  i = 0;
  int val;
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue
      val = temp[r][c];
      switch ( val ) {
           case 0:
            red = 15; green = 15; blue =15;//colors red
          break;
          case 1:
            red = 15; green = 0; blue =0;//colors red
          break;
          case 2:
            red = 0; green = 25; blue =0;//colors  green
          break;
           case 3:
          red = 0; green = 0; blue =25;//colors blue
          break;
            case 4:
          red = 32; green = 32; blue =0;//colors yellow
          break;
            case 5:
          red = 0; green =35; blue =35;//colors cyan
          break;
          case 6:
          red = 60; green = 0; blue =60;//colors
          break;
          case 7:
          red = 65; green = 20; blue =0;//colors
          break;
         default:
          red = 0; green = 0; blue =0;//colors
          break;
          ///////////////////////////////////////////////
}
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
         
      pixels.show(); 
      i++;
      
    }//end y
}//end y and end of loop that increments x,y and i

}


