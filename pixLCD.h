#include "Arduino.h" 
#ifndef __pixLCD_h__ 
#define __pixLCD_h__ 
  	#define SERIAL_MODE if you use PORTB (uno) and Serial
	#define SERIAL_MODE
	#define LCD_CTRL_PORT 	PORTB 
	#define LCD_CTRL_DDR 	DDRB 
	#define LCD_CTRL_PIN 	PINB											 
	#define LCD_RS	2	// uno pin 10
	#define LCD_RW	3	// uno pin 11
	//#define LCD_E	4	// uno pin 12 
	#define LCD_RST	1 	// uno pin 9
	#define LCD_PSB	0 	// uno pin 10
 
	#define LCD_DATA_DDR	DDRD 
	#define LCD_DATA_PIN	PIND 
	#define LCD_DATA_PORT	PORTD 
 
	#define LCD_CTRL_OUT()	DDRB |= 0x3f
 
	#define LCD_RS_LOW()	LCD_CTRL_PORT &= ~(1<<LCD_RS) 
	#define LCD_RS_HIGH()	LCD_CTRL_PORT |= (1<<LCD_RS) 
 
	#define LCD_RW_LOW()	LCD_CTRL_PORT &= ~(1<<LCD_RW) 
	#define LCD_RW_HIGH()	LCD_CTRL_PORT |= (1<<LCD_RW) 

#ifdef LCD_E
	#define LCD_E_LOW()		LCD_CTRL_PORT &= ~(1<<LCD_E)) 
	#define LCD_E_HIGH()	LCD_CTRL_PORT |= (1<<LCD_E)
#else
	#define LCD_E_LOW()		digitalWrite(__EnablePin,LOW) 
	#define LCD_E_HIGH()	digitalWrite(__EnablePin,HIGH)
#endif

	#ifdef LCD_RST 
	#define LCD_RST_LOW()	LCD_CTRL_PORT &= ~(1<<LCD_RST) 
	#define LCD_RST_HIGH()	LCD_CTRL_PORT |= (1<<LCD_RST) 
	#endif	//#ifdef LCD_RST 
 
	#ifdef LCD_PSB 
	#define LCD_PSB_LOW()	LCD_CTRL_PORT &= ~(1<<LCD_PSB) 
	#define LCD_PSB_HIGH()	LCD_CTRL_PORT |= (1<<LCD_PSB) 
	#endif	//#ifdef LCD_PSB 
  
 
	#define LCD_DATA_IN()	LCD_DATA_PORT = 0x00; LCD_DATA_DDR = 0x00
	#define LCD_DATA_OUT()	LCD_DATA_DDR = 0xFF
#ifdef SERIAL_MODE
	#define LCD_DATA_SER()  LCD_DATA_DDR = 0x02
#endif
	#define LCD_DATA_GET()	LCD_DATA_PIN 
 



#define LCD_X_MAX	127 
#define LCD_Y_MAX	63 
  
#define LINE_ONE_ADDRESS   0x80 
#define LINE_TWO_ADDRESS   0x90 
#define LINE_THREE_ADDRESS 0x88 
#define LINE_FOUR_ADDRESS  0x98 
 
#define LCD_DATA               	1         	// 
#define LCD_COMMAND            	0		 	// 
#define	LCD_CLEAR_SCREEN       	0x01 	 	//	 
#define	LCD_ADDRESS_RESET      	0x02		//	  
#define	LCD_BASIC_FUNCTION	  	0x30		// 
#define	LCD_EXTEND_FUNCTION	   	0x34		// 
 

#define	LCD_AWAIT_MODE			0x01	 	//	 
#define LCD_ROLLADDRESS_ON		0x03		// 
#define LCD_IRAMADDRESS_ON		0x02		//	 
#define	LCD_SLEEP_MODE			0x08	 	// 
#define	LCD_NO_SLEEP_MODE		0x0c	 	//
#define LCD_GRAPH_ON			0x36		//
#define LCD_GRAPH_OFF			0x34		//
 
 
#define LCD_COLOR_BLACK			1 
#define LCD_COLOR_WHITE			0 


class pixLCD {

	public:
#ifdef LCD_E
		pixLCD(void); 
#else
		pixLCD(uint8_t Epin);
#endif
		void	DisplayStrings_WithAddress(uint8_t ucAdd, uint8_t *p);
		char*	write(uint8_t x,uint8_t y, const uint8_t *p, uint8_t Delay = 0);
		void	ImgDisplay(uint8_t *img);
		void	clear();
		void	ImgDisplayCharacter(uint8_t x,uint8_t y,uint8_t *img);
		void	Point(uint8_t x,uint8_t y,uint8_t color);
	private:
#ifndef LCD_E
		uint8_t	__EnablePin;
#endif
		void    __Write( uint8_t Data_Command , uint8_t uc_Content );
		uint8_t __ReadData(void); 
		uint8_t __getAddressLine(uint8_t y);  
		void    __CheckBusy(void);
		void    __ClearRam(void);
		void    __GraphModeSet(uint8_t Select);
		void	__DDRAM_AddressSet(uint8_t);
		void	__CGRAM_AddressSet(uint8_t);
		void	__GDRAM_AddressSet(uint8_t);
};




#endif

