# pixLCD_parallel
Arduino library for a 128x64 dots grafic display using the ST7920 driver

Special thanks to zhongxu for the avr.ST7920, which was the basic for this library

This library aims specially to use the display by 8bit parallel interface at one constant output register
also the RS and R/W pins are constant.
You should rewiev the first 17 lines of the pixLCD.h 
or use theese default settings:
data register : PD  (uno pin0 - pin7)
RS            : PB2 (uno pin10)
RW            : PB3 (uno pin11)
RST           : PB1 (uno pin9)
PSB           : PB0 (uno pin8)

Constructor: Call an instance of "pixLCD pix(ENABLE_PIN);"

Methodes:

pix.write(posX, posY, string, delay);
  Parameters:
    positions are byte (aka unsigned char) 0x00-0x0F and 0x00-0x03, higher values get casted
    string is a (pointer to a) char array, alternating start positions can easily be accessed (see Hello_World example)
    delay is optional, the inbuilt delay time after each character
  Retrun:
    a pointer to the first character, that isn't displayed (see Hello_World example)
pix.clear();
  clears the screen
  
... to be continued
    
