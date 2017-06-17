// a example to demonstrate the writeTiny() method

#include "pixLCD.h"
#define BACKGROUND_LED 13

pixLCD pix(12);

char a_long_string[] = "Call the method like this:\n\twriteTiny(*char,\tstartX,\n\t\tstartY,\tendX,\tendY)\nAll coordinates are optional!\nIt will wrap lines at whitespaces and tabs before the last word exceedes the limit.\0If you use a tab and the line gets wrapped, it will be displayed at the beginning of the next line.\nI just want to tell a few things to create a long text to demonstrate the returned pointer. It points to the first not displayed char, so it may point to a zero if the string terminates. If you know it doesn't, like I knew it here, you need to increment the pointer to start with the next character.\nHave Fun!!";
char* pointer_to_first_not_displayed_char;
void setup()
{
  pinMode(BACKGROUND_LED,OUTPUT);
  digitalWrite(BACKGROUND_LED,HIGH);
}


void loop()
{
  
  pointer_to_first_not_displayed_char = pix.writeTiny(a_long_string);
  
  delay(10000);
  
  pointer_to_first_not_displayed_char++;
  
  while (pointer_to_first_not_displayed_char[0])
  {
    pix.clearGraph();
    delay(500);
    pointer_to_first_not_displayed_char = pix.writeTiny(pointer_to_first_not_displayed_char,random(0,24),random(0,16),random(104,128),random(48,64));
    delay(10000);
  }
  pix.clearGraph();
  delay(3000);
}
