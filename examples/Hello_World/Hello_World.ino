#include "pixLCD.h"

// start LCD with EnablePin
pixLCD pix(12);

// a string                \0 terminater                    x character to change in line 20     \masked byte
char text[] = "Hello World!\0I can wrap lines by myself and xterminate at the end of the screen. \1 ";

void setup() {
  
  pinMode(13,1);digitalWrite(13,1);
// write to position x,y, pointer to char , optional delay between characters
  pix.write(         2,1, text            , 200  );

  delay(2000);

// it returns a pointer to the continuing text

  text[44] = 0x1a; // replaces the 'x'
    
// since text is a pointer it can incremented easily...
// like this:  
//            pix.write(0,2, text+13 ,100 );
// or like this:
  char* could_not_display = pix.write(0,2, &text[13] ,100 ); 


  
  delay(1000);
  pix.write(0,0,could_not_display,20);

  delay(4000);
  
  pix.clear();
  
  text[0x40] = 0;
}

void loop()
{
  // show characters page 1
  if (millis() > 20000)
  {
    text[0x40] = 1;
  }
  
  for (int i=0;i< 0x40;i++)
  {
    text[i] = i;
  }
  
  if ( pix.write(1,0,text+1,20)[0] )
  {
    // delays only if writing has reached the end of the screen
    delay(2000);
  }
  pix.clear();
  
  // show character page 2
  for (int i = 0 ; i < 0x40 ; i++ )
  {
    text[i] = i+0x40;
  }
  if ( pix.write(0,0,text,20)[0] )
  {
    delay(2000);
  }
  pix.clear();
}
/* 
 * the conditional test as shown in line 52 and 64
 * will not work if the char array is not terminated by \0
 * 
 * to work with the String object you need to convert it
 * int a char array by using string.toCharArray()
 * 
 */
