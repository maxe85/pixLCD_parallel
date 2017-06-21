#include "Arduino.h"
#include <avr/pgmspace.h>
#include "pixLCD.h"
#include "TinyCharsDataSource.h"

//***************************************************************************************************************************
#ifdef LCD_E
pixLCD::pixLCD(void)
{
#else
pixLCD::pixLCD(uint8_t Epin)
{   
	__EnablePin = Epin;
#endif 
    LCD_CTRL_OUT();
#ifdef LCD_PSB
    LCD_PSB_HIGH();   
#endif
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION); 
    __Write(LCD_COMMAND,LCD_CLEAR_SCREEN);   
    __Write(LCD_COMMAND,0x06);           
    __Write(LCD_COMMAND,0x0C);           

   clearGraph();
}
//***************************************************************************************************************************
void pixLCD::__Write( uint8_t Data_Command , uint8_t uc_Content )   
{       
    __CheckBusy();   
    LCD_DATA_OUT();   
   
    if(Data_Command)   
    {   
        LCD_RS_HIGH(); 
        //LCD_RW_LOW();
    }   
    else    
    {   
        LCD_RS_LOW();  
        //LCD_RW_LOW();
    }   
    LCD_RW_LOW();  
   
    LCD_DATA_PORT = uc_Content;
    LCD_E_HIGH();  
    _delay_us(5);
    LCD_E_LOW();   
}   
//***************************************************************************************************************************
void pixLCD::__CheckBusy(void)   
{  
#ifdef CHECK_BUSY_LED_PIN
	digitalWrite(CHECK_BUSY_LED_PIN,HIGH);
#endif

	uint8_t watchDog = 1;
    LCD_DATA_IN();

    LCD_RS_LOW(); 
    LCD_RW_HIGH();  

    _delay_us(5);
	LCD_E_HIGH(); 
    do {
		_delay_us(5);
		if ( watchDog++ == 0 )
		{
			//digitalWrite(CHECK_BUSY_LED_PIN,digitalRead(CHECK_BUSY_LED_PIN^1));
			break;
		}
	} while( 0x80==(LCD_DATA_GET()&0x80) );   
	LCD_E_LOW();
#ifdef CHECK_BUSY_LED_PIN
	digitalWrite(CHECK_BUSY_LED_PIN,LOW);
#endif
}   
   
//***************************************************************************************************************************
uint8_t pixLCD::__ReadData(void)   
{   
    uint8_t uc_Content;   
    __CheckBusy();  
    LCD_DATA_IN(); 
    LCD_RS_HIGH();
    LCD_RW_HIGH(); 
    LCD_E_HIGH();  
    _delay_us(1);  
    uc_Content = LCD_DATA_GET();  
    LCD_E_LOW();   
	return uc_Content;
}   
//***************************************************************************************************************************
void pixLCD::__DDRAM_AddressSet(uint8_t ucDDramAdd)   
{   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION);         
    __Write(LCD_COMMAND,ucDDramAdd);           
}   
//*************************************************************************************************************************** 
//*     RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0   
//*     0   0   0   1   AC5 AC4 AC3 AC2 AC1 AC0   
void pixLCD::__CGRAM_AddressSet(uint8_t ucCGramAdd)   
{   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION);   
    __Write(LCD_COMMAND,ucCGramAdd);           
}   
//*************************************************************************************************************************** 
//*     RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0   
//*     0   0   1   AC6 AC5 AC4 AC3 AC2 AC1 AC0
void pixLCD::__GDRAM_AddressSet(uint8_t ucGDramAdd)   
{   
    __Write(LCD_COMMAND,LCD_EXTEND_FUNCTION);     
    __Write(LCD_COMMAND,ucGDramAdd);         
}   
//***************************************************************************************************************************
//*     RS  RW  DB7  DB6  DB5  DB4  DB3 DB2 DB1 DB0 
//*     0   0    0    0    0    0    0   0   0   1 
void pixLCD::clear(void)   
{   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION);        
    __Write(LCD_COMMAND,LCD_CLEAR_SCREEN);    
	__CheckBusy();    
}   
//***************************************************************************************************************************
//*     RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0 
//*     0   0   0   0   1   1   X   RE   G   X  
//*     G :0,OFF (0x34)
//*     G :1,ON  (0x36)
void pixLCD::__GraphModeSet(uint8_t Select)   
{   
   // __Write(LCD_COMMAND,LCD_EXTEND_FUNCTION);
	__Write(LCD_COMMAND,LCD_GRAPH_OFF);			// is the same - is it necessary twice????
	__Write(LCD_COMMAND, LCD_GRAPH_OFF | ( Select & 0x01 )<<1 );
}   
//***************************************************************************************************************************
//	80H~87H,90H~97H,88H~8FH,98H~8FH  
void pixLCD::DisplayStrings_WithAddress(uint8_t ucAdd, uint8_t *p)   
{   
    uint8_t length;   
    length = strlen(p);   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION);             
    __DDRAM_AddressSet(ucAdd);    
    for( ;  length ; length -- )   
        __Write(LCD_DATA, *(p++));                       
}   
//***************************************************************************************************************************
char* pixLCD::write(uint8_t x,uint8_t y, const uint8_t *str, uint8_t Delay)   
{   
	uint8_t length = strlen(str);
	uint8_t addr;
	uint8_t OddAddr = x&0x01; 
//	uint8_t OddData;   
    y &= 0x03;  //y < 4
	addr = __getAddressLine(y);   
    x &= 0x0F;  //x < 16   
    addr += x/2;   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION);         
    __DDRAM_AddressSet(addr);   
	if(OddAddr)   
	{   
//		OddData = __ReadData();    
//		__DDRAM_AddressSet(addr);   
//		__Write(LCD_DATA,  OddData);
		__Write(LCD_DATA,  0x20);      
	}   

    for( ;  length  ; length -- )   
	{
		__Write(LCD_DATA, *(str++));
		if ((*str) == 0)
		{
			return str;
		}
		// this is for optional user Delay after each character
		if (Delay)
			{
			delay(Delay);
			}
		// go to physical next line
		if ( !( (++x)&0x0F ) )
		{
			if (y == 3 ) //last line
			{
				return str;
			}
			addr = __getAddressLine(++y);
		    __DDRAM_AddressSet(addr);   
		}

	}
	return str;
}
//********************************************
uint8_t pixLCD::__getAddressLine(uint8_t y)
{	
	switch( y )
	{   
        case 0: return 0x80;
		case 1: return 0x90;
		case 2: return 0x88;
		case 3: return 0x98; 
	}
} 
//****************************************************************************************
char*	pixLCD::writeTiny(const uint8_t *str, uint8_t startX,uint8_t startY, uint8_t endX, uint8_t endY)
{
	
	if (startX > 112)
		startX = 0;
	if (startY > 57)
		startY = 0;
	if (endY< startY+7)
		endY = 64;
	if (endX<startX+16)
		endX = 128;
	__buffer[9]  = startX/16;	// COL_INDEX
	__buffer[10] = 16-(startX%16);	// INT_INDEX
	__buffer[11] = 0;	// number of chars in one line
	__buffer[15] = 340;	// set max number of chars to write (watchdog)

	while(startY < endY-7) //	>	>	>	>	>	>	>	>	begin line loop
	{
		//	-	-	-	-	-	-	-	-	-	-	-	-	-	-	get chars in line length
		__buffer[12] = startX; // current pixel length counter
		for (uint8_t i=0;__buffer[12]<endX;i++)
		{
			if (	str[i] == 0x09 ||	// if char is tab or newLine
					str[i] == 0x0a ||	//  or whitespace or terminator
					str[i] == 0x20 ||
					str[i] == 0x00 )	
			{
				__buffer[11] = i;	// save position
			}
			if (str[i]==0x0a || str[i] == 0x00)
				break;
			if (i)			// letter spacing after first char
				__buffer[12]++;
			__buffer[12] +=	(pgm_read_byte_near( tinyCharSet + str[i] *7 )>>5) & 0x07;	// add the CHAR_length
		} //	-	-	-	-	-	-	-	-	-	-	-	-	-	-	end get chars in line

		while (__buffer[11])	//	>	>	>	>	>	>	>	>	begin int loop
		{
			__clearBuffer(7);
			while ( __buffer[10] >= 0 && __buffer[11]) // prepare ints while INT_INDEX is in range
			{
				__buffer[10] -= (pgm_read_byte_near(tinyCharSet + *str *7)>>5) & 0x07;
				for (uint8_t i=0;i<7;i++)
				{
					if (__buffer[10]>0)
						__buffer[i] |= (pgm_read_byte_near(tinyCharSet +  *str *7 +i ) & 0x1f)<<__buffer[10];	//add char
					else
						__buffer[i] |= (pgm_read_byte_near(tinyCharSet +  *str *7 +i ) & 0x1f)>>(-__buffer[10]); //add char if in next col
				}
				if (__buffer[10] < 0)	// if INT_length is exceeded while char is not written yet
				{		// adjust INT_INDEX for continuing that char
					__buffer[10] += (pgm_read_byte_near(tinyCharSet + *str *7)>>5) & 0x07;
					break;
				}
				str++;			// increase char pointer
				__buffer[10]--;	// move one pixel for letter spacing
				__buffer[11]--; // decrease  chars in line
				__buffer[15]--;	// decrease wahtchdog
			}	// end prepare int
			for (uint8_t line=0;line<7;line++)
				__drawInt( __buffer[line] , line + startY , __buffer[9] );
			__buffer[10]+=16;	// adjust INT_INDEX
			__buffer[9]++;		// increase COL_INDEX
		}	//	>	>	>	>	>	>	>	>	>	>	>	>	>	>	end int loop
		__buffer[10] = 16-(startX%0x10);	// reset INT_INDEX
	    __buffer[9]  = (startX&0x3f) / 16;	// reset COL_INDEX
		startY += 8; 						// incement LINE_INDEX
		if (*str == 0 )	
			break;
		if (*str == 0x0A || *str == 0x20) // increment char pointer if whitespace or new line
			str++;
	} //>	>	>	>	>	>	>	>	>	>	>	>	>	>	>	>	end line loop
	return str;
} 
//***************************************************************************************************************************
//*	screen		file
//*	 a b c d	 abcdijkl
//*	 e f g h	 efghmnop
//*	 i j k l
//*	 m n o p              
void pixLCD::ImgDisplayNativeDirection(uint8_t *img, bool invert = false)
{     
	__GDRAM_AddressSet(0);
    __GraphModeSet(0x00); 
	
/*	for (uint8_t lineIndex=0 ; lineIndex<32 ; lineIndex++ )
	{
		__drawNativeLine( img+(lineIndex<<5), lineIndex , invert );
	} */
	for (uint8_t lineIndex=0 ; lineIndex<64 ; lineIndex++ )
	{
		__drawPhysicalLine( img + ((lineIndex&0x1f)<<5)+((lineIndex&0x20)>>1), lineIndex , invert );
	}

    __GraphModeSet(0x01); 
}
//********************************************
void pixLCD::__drawNativeLine(uint8_t *line, uint8_t lineIndex, bool invert)
{
	__Write( LCD_COMMAND, 0x80 | (lineIndex&0x1f) );      
	__Write( LCD_COMMAND, 0x80 ); 
	for ( uint8_t i=0; i<32;  )   
	{
		if (invert)
		{
			__Write( LCD_DATA, 0xff^line[ i++ ] );  
			__Write( LCD_DATA, 0xff^line[ i++ ] ); 
		} 
		else
		{
			__Write( LCD_DATA, line[ i++ ] );  
			__Write( LCD_DATA, line[ i++ ] ); 
		}
	} 
}
//********************************************
void pixLCD::__drawPhysicalLine(uint8_t *line, uint8_t lineIndex, bool invert)
{
	__Write( LCD_COMMAND, 0x80 | (lineIndex&0x1f) );      
	__Write( LCD_COMMAND, 0x80 | ((lineIndex&0x20)>>2) ); 
	for ( uint8_t i=0; i<16;  )   
	{
		if (invert)
		{
			__Write( LCD_DATA, 0xff^line[ i++ ] );  
			__Write( LCD_DATA, 0xff^line[ i++ ] ); 
		} 
		else
		{
			__Write( LCD_DATA, line[ i++ ] );  
			__Write( LCD_DATA, line[ i++ ] ); 
		}
	} 
}
//********************************************
void pixLCD::__drawInt(uint16_t data, uint8_t lineIndex, uint8_t colIndex)
{
	__GDRAM_AddressSet(0);
    __GraphModeSet(0x00); 
	colIndex &= 0x07;
	if (lineIndex & 0x20)
		colIndex |= 0x08; 
	lineIndex &= 0x1f;
	__Write( LCD_COMMAND, 0x80 | lineIndex );      
	__Write( LCD_COMMAND, 0x80 | colIndex  ); 
	__Write( LCD_DATA, data>>8 );  
	__Write( LCD_DATA, data ); 
    __GraphModeSet(0x01); 
}
//********************************************
uint16_t pixLCD::__readInt(uint8_t lineIndex, uint8_t colIndex)
{
	__GDRAM_AddressSet(0);
    __GraphModeSet(0x00); 
	colIndex &= 0x07;
	if (lineIndex & 0x20)
		colIndex |= 0x08; 
	lineIndex &= 0x1f;
	__Write( LCD_COMMAND, 0x80 | lineIndex );      
	__Write( LCD_COMMAND, 0x80 | colIndex  ); 

	
	uint16_t data = __ReadData(); // dummy read
	data  = __ReadData()<<8;
	data |= __ReadData(); 
    __GraphModeSet(0x01); 
	return data;
}
//***************************************************************************************************************************

void pixLCD::drawGrid(uint8_t size)
{     

	uint8_t template_byte;
	switch (size)
	{
		case 2:
			template_byte = 0xaa;
			break;
		case 4:
			template_byte = 0x88;
			break;
		default:
			size  = 8;
			template_byte = 0x80;
	}

	__GDRAM_AddressSet(0);
    __GraphModeSet(0x00); 

	for (uint8_t lineIndex=0 ; lineIndex<32 ; lineIndex++ )
	{
		__Write( LCD_COMMAND, 0x80 | lineIndex );      
		__Write( LCD_COMMAND, 0x80 ); 
		for (uint8_t colIndex=0 ; colIndex<32 ; colIndex++ )
		{
			if (lineIndex%size)
				__Write( LCD_DATA, template_byte );
			else
				__Write( LCD_DATA, 0xff );
		}
	} 

    __GraphModeSet(0x01); 
}   

//***************************************************************************************************************************

void pixLCD::drawGreyScreen(void)
{     


	__GDRAM_AddressSet(0);
    __GraphModeSet(0x00); 

	for (uint8_t lineIndex=0 ; lineIndex<32 ; lineIndex++ )
	{
		__Write( LCD_COMMAND, 0x80 | lineIndex );      
		__Write( LCD_COMMAND, 0x80 ); 
		for (uint8_t colIndex=0 ; colIndex<32 ; colIndex++ )
		{
			if (lineIndex&0x01)
				__Write( LCD_DATA, 0x55 );
			else
				__Write( LCD_DATA, 0xaa );
		}
	} 

    __GraphModeSet(0x01); 
}   

//***************************************************************************************************************************
void pixLCD::clearGraph()   
{ 
    uint8_t i, j;   
    __GraphModeSet(0x00);  

    for(j=0;j<32;j++)   
     {   
        for(i=0;i<8;i++)   
         {   
            __Write(LCD_COMMAND,0x80+j);     
            __Write(LCD_COMMAND,0x80+i);       
            __Write(LCD_DATA,0x00); 
            __Write(LCD_DATA,0x00);   
         }   
     }   
    for(j=32;j<64;j++)   
     {   
        for(i=0;i<8;i++)   
         {   
            __Write(LCD_COMMAND,0x80+j-32);   
            __Write(LCD_COMMAND,0x88+i);   
            __Write(LCD_DATA,0x00);   
            __Write(LCD_DATA,0x00);   
         }   
     }  
    __GraphModeSet(0x01);  
}
//***************************************************************************************************************************
