// a example to demonstrate the writeTiny() method

#include "pixLCD.h"
#define BACKGROUND_LED 13

pixLCD pix(12);

char a_long_string[] = "Call the method like this:\nwriteTiny( *char,\n\t\t\tstartX, startY,\n\t\t\tendX, endY)\nAll coordinates are optional!\0It will wrap lines at whitespaces and tabs before the last word exceedes the limit.\nIf you use a tab and the line gets wrapped, the tab will be displayed at the beginning of the next line.\nI just want to tell a lot of things to create a long text to demonstrate the returned pointer. It points to the first not displayed char, so it may point to a zero if the string terminates. If you know it doesn't, like I knewhere, you need to increment the pointer to start with the next character.\nHave Fun!!\0since the string was terminated, this will no be displayed";
char* pointer_to_first_not_displayed_char;
void setup()
{
  pinMode(BACKGROUND_LED,OUTPUT);
  digitalWrite(BACKGROUND_LED,HIGH);

  pix.clearGraph();

}


void loop()
{
  
  
  pointer_to_first_not_displayed_char = pix.writeTiny(a_long_string,4,3);
  
  delay(8000);

  pointer_to_first_not_displayed_char++;
  
  while (pointer_to_first_not_displayed_char[0])
  {
    pix.clearGraph();
    delay(300);
    pointer_to_first_not_displayed_char = pix.writeTiny(pointer_to_first_not_displayed_char,random(0,24),random(0,16),random(104,128),random(48,64));
    delay(7000);
  }
}