#include "Arduino.h"
#include "pixLCD.h"


#ifdef LCD_E
pixLCD::pixLCD(void)
{
#else
pixLCD::pixLCD(uint8_t Epin)
{   
	__EnablePin = Epin;
#endif 
    LCD_CTRL_OUT();   
    LCD_PSB_HIGH();   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION); 
    __Write(LCD_COMMAND,LCD_CLEAR_SCREEN);   
    __Write(LCD_COMMAND,0x06);           
    __Write(LCD_COMMAND,0x0C);           
   
}  

//************************************************************************************   
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
    _delay_us(1);
    LCD_E_LOW();   
}   
//***********************************************
   void pixLCD::__CheckBusy(void)   
{   
    uint8_t temp;   
    LCD_DATA_IN();
    LCD_RS_LOW(); 
    LCD_RW_HIGH();  
    _delay_us(5);
    LCD_E_HIGH();
    do   
    {      
        temp = LCD_DATA_GET();  //temp = BUSY;   
    }   
    while( 0x80==(temp&0x80) );
       
    LCD_E_LOW();  

}   
   
//****************************************************
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
   
    _delay_us(1); 
}   
   
   
   
   
   
//***************************************************  
void pixLCD::__DDRAM_AddressSet(uint8_t ucDDramAdd)   
{   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION);         
    __Write(LCD_COMMAND,ucDDramAdd);           
}   
   
   
//*************************************************   
//*     RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0   
//*     0   0   0   1   AC5 AC4 AC3 AC2 AC1 AC0   
void pixLCD::__CGRAM_AddressSet(uint8_t ucCGramAdd)   
{   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION);   
    __Write(LCD_COMMAND,ucCGramAdd);           
}   
   
   
//*************************************************   
//*     RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0   
//*     0   0   1   AC6 AC5 AC4 AC3 AC2 AC1 AC0
void pixLCD::__GDRAM_AddressSet(uint8_t ucGDramAdd)   
{   
    __Write(LCD_COMMAND,LCD_EXTEND_FUNCTION);     
    __Write(LCD_COMMAND,ucGDramAdd);         
}   
   
    
   
 
   
   
   
//********************************************************   
//*         RS  RW  DB7  DB6  DB5  DB4  DB3 DB2 DB1 DB0 
//*         0   0    0    0    0    0    0   0   0   1 
void pixLCD::__ClearRam(void)   
{   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION);        
    __Write(LCD_COMMAND,LCD_CLEAR_SCREEN);    
	__CheckBusy();    
}   
   
   
//*****************************************************   
//*     RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0 
//*     0   0   0   0   1   1   X   RE   G   X  
//*     G :0,OFF
//*     G :1,ON  
void pixLCD::__GraphModeSet(uint8_t Select)   
{   
    __Write(LCD_COMMAND,LCD_EXTEND_FUNCTION);
    if(Select)   
    {   
        __Write(LCD_COMMAND,LCD_GRAPH_ON);  
    }   
    else   
    {   
        __Write(LCD_COMMAND,LCD_GRAPH_OFF); 
    }   
}   
   
   
//*********************************************************************  
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
   
uint8_t pixLCD::__getAddressLine(uint8_t y)
{	switch( y&0x03 )
	{   
        case 0: return 0x80;
		case 1: return 0x90;
		case 2: return 0x88;
		case 3: return 0x98; 
	}
 }   

//*********************************************************************  
char* pixLCD::write(uint8_t x,uint8_t y, const uint8_t *p, uint8_t Delay)   
{   
    uint8_t  length,   addr,   Data1 ,   AddrEO;   
   
    y &= 0x03;  //y < 4
	addr = __getAddressLine(y);   
    x &= 0x0F;  //x < 16   
   
    addr += x/2;   
    AddrEO = x&0x01;   
   
    length = strlen(p);   
   
    __Write(LCD_COMMAND,LCD_BASIC_FUNCTION);         
    __DDRAM_AddressSet(addr);   
   
	if(AddrEO == 0x01 )   
	{   
     //   Data1 = __ReadData();   
     //   __DDRAM_AddressSet(addr);   
		__Write(LCD_DATA,  0x20); //Data1);   
	}   

    for( ;  length  ; length -- )   
	{
		__Write(LCD_DATA, *(p++));
		if ((*p) == 0)
		{
			return p;
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
				return p;
			}
			addr = __getAddressLine(++y);
		    __DDRAM_AddressSet(addr);   
		}

	}
	return p;
}      
   
//*********************************************************************   
void pixLCD::ImgDisplay(uint8_t *img)   
{   
    uint8_t i,j;   
    __GraphModeSet(0x00); 
    for(j=0;j<32;j++)   
     {   
        for(i=0;i<8;i++)   
         {   
            __Write(LCD_COMMAND,0x80+j);      
            __Write(LCD_COMMAND,0x80+i);      
            __Write(LCD_DATA,img[j*16+i*2]);  
            __Write(LCD_DATA,img[j*16+i*2+1]); 
         }   
     }   
    for(j=32;j<64;j++)   
     {   
        for(i=0;i<8;i++)   
         {   
            __Write(LCD_COMMAND,0x80+j-32);   
            __Write(LCD_COMMAND,0x88+i);   
            __Write(LCD_DATA,img[j*16+i*2]);   
            __Write(LCD_DATA,img[j*16+i*2+1]);   
         }   
     }   
    __GraphModeSet(0x01); 
}   
   
void pixLCD::clear()   
{ 
	__ClearRam  ();
/*
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
*/
}   
   
   
//*********************************************************************  
//*       ________________128___________________________              *   
//*      |(0,0)                                    (7,0)|             *   
//*      |                                              |             *   
//*   64 |                                              |             *   
//*      |(0,31)                                  (7,31)|             *   
//*      |(8,0)                                   (15,0)|             *   
//*      |                                              |             *   
//*      |                                              |             *   
//*      |(8,31)                                 (15,31)|             *   
//*      |______________________________________________|             *   
void pixLCD::ImgDisplayCharacter(uint8_t x,uint8_t y,uint8_t *img)   
{   
    uint8_t i;   
    __GraphModeSet(0x00);    
    __Write(LCD_COMMAND,LCD_EXTEND_FUNCTION);   
    for(i=0;i<16;i++)   
     {   
        __GDRAM_AddressSet(0x80+y+i);   
        __GDRAM_AddressSet(0x80+x);   
        __Write(LCD_DATA,img[i*2]);   
        __Write(LCD_DATA,img[i*2+1]);   
     }   
   __GraphModeSet(0x01);       
}   
   
   
   
//*********************************************************************   
//*      ________________128____________________________              *   
//*      |(0,0)                                    (7,0)|             *   
//*      |                                              |             *   
//*   64 |                                              |             *   
//*      |(0,31)                                  (7,31)|             *   
//*      |(8,0)                                   (15,0)|             *   
//*      |                                              |             *   
//*      |                                              |             *   
//*      |(8,31)                                 (15,31)|             *   
//*      |______________________________________________|             *   
void pixLCD::Point(uint8_t x,uint8_t y,uint8_t color)   
{   
    uint8_t i,AddrX,AddrY;   
    uint8_t BitTemp;      // 16bit
    uint8_t DataH,DataL;   
   
    AddrX = x>>4;          
    AddrY = y&0x3F;           
    if(y > 31)   
    {   
        AddrX += 8;   
        AddrY -= 32;   
    }   
    BitTemp = x&0x0F;      
   
       
    __GraphModeSet(0x00);   
    //__Write(LCD_COMMAND,LCD_EXTEND_FUNCTION);   
       
    for(i=0;i<4;i++)   
    {   
    __GDRAM_AddressSet(0x80+AddrY);   
    __GDRAM_AddressSet(0x80+AddrX);   
    //__Write(LCD_COMMAND,LCD_BASIC_FUNCTION);  
    DataH = __ReadData();   
    DataH = __ReadData();   
    DataL = __ReadData();   
    //DataH = __ReadData();   
    //DataL = __ReadData();   
    }   
   
    if(color == LCD_COLOR_BLACK)   
    {   
        if(BitTemp > 7)   
        {   
            DataL |= (0x80>>(BitTemp-8));   
        }   
        else   
        {   
            DataH |= (0x80>>(BitTemp));   
        }   
    }   
    else   
    {   
    }   
   
    __GDRAM_AddressSet(0x80+AddrY);   
    __GDRAM_AddressSet(0x80+AddrX);   
    __Write(LCD_DATA,DataH);   
    __Write(LCD_DATA,DataL);   
       
    __GraphModeSet(0x01);        
}   
   
   
