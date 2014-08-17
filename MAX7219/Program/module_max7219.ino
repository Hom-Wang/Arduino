/*====================================================================================================*/
/*====================================================================================================*/
#include "module_max7219.h"
/*====================================================================================================*/
/*====================================================================================================*/
const byte MAX7219_CLK  = 2;
const byte MAX7219_DIN  = 3;
const byte MAX7219_LOAD = 4;
/*====================================================================================================*/
/*====================================================================================================*
**函數 : MAX7219_SendByte
**功能 : MAX7219 SendByte
**輸入 : data
**輸出 : None
**使用 : MAX7219_SendByte();
**====================================================================================================*/
/*====================================================================================================*/
static void MAX7219_SendByte( byte data )
{
  for (byte i=0; i<8; i++) {
    digitalWrite(MAX7219_CLK, LOW);
    if (data & (0x80 >> i))
      digitalWrite(MAX7219_DIN, HIGH);
    else
      digitalWrite(MAX7219_DIN, LOW);
    digitalWrite(MAX7219_CLK, HIGH);
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : MAX7219_WriteData
**功能 : MAX7219 WriteData
**輸入 : addr, data
**輸出 : None
**使用 : MAX7219_WriteData();
**====================================================================================================*/
/*====================================================================================================*/
void MAX7219_WriteData( byte addr, byte data )
{
  digitalWrite(MAX7219_LOAD, LOW);
  MAX7219_SendByte(addr);
  MAX7219_SendByte(data);
  digitalWrite(MAX7219_LOAD, HIGH);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : MAX7219_Config
**功能 : MAX7219 Config
**輸入 : None
**輸出 : None
**使用 : MAX7219_Config();
**====================================================================================================*/
/*====================================================================================================*/
static void MAX7219_Config( void )
{
  pinMode(MAX7219_DIN,  OUTPUT);
  pinMode(MAX7219_CLK,  OUTPUT);
  pinMode(MAX7219_LOAD, OUTPUT);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : MAX7219_Init
**功能 : MAX7219 Init
**輸入 : None
**輸出 : None
**使用 : MAX7219_Init();
**====================================================================================================*/
/*====================================================================================================*/
void MAX7219_Init( void )
{
  MAX7219_Config();

  MAX7219_WriteData(MAX7219_SHUTDOWN,     0x01);  // Normal Operation
  MAX7219_WriteData(MAX7219_DISPLAY_TEST, 0x00);  // No Display Test
  MAX7219_WriteData(MAX7219_SCAN_LIMIT,   0x07);  // Scan All
  MAX7219_WriteData(MAX7219_DECODE_MODE,  0x00);  // No Decode
  MAX7219_WriteData(MAX7219_INTENSITY,    0x00);  // Min (01/32)

  MAX7219_Clear();
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : MAX7219_Fill
**功能 : Fill MatrixLED
**輸入 : None
**輸出 : None
**使用 : MAX7219_Fill();
**====================================================================================================*/
/*====================================================================================================*/
void MAX7219_Fill( void )
{
  MAX7219_WriteData(1, 255);
  MAX7219_WriteData(2, 255);
  MAX7219_WriteData(3, 255);
  MAX7219_WriteData(4, 255);
  MAX7219_WriteData(5, 255);
  MAX7219_WriteData(6, 255);
  MAX7219_WriteData(7, 255);
  MAX7219_WriteData(8, 255);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : MAX7219_Clear
**功能 : Clear MatrixLED
**輸入 : None
**輸出 : None
**使用 : MAX7219_Clear();
**====================================================================================================*/
/*====================================================================================================*/
void MAX7219_Clear( void )
{
  MAX7219_WriteData(1, 0);
  MAX7219_WriteData(2, 0);
  MAX7219_WriteData(3, 0);
  MAX7219_WriteData(4, 0);
  MAX7219_WriteData(5, 0);
  MAX7219_WriteData(6, 0);
  MAX7219_WriteData(7, 0);
  MAX7219_WriteData(8, 0);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : MAX7219_TestMatrixLED
**功能 : Test MatrixLED
**輸入 : None
**輸出 : None
**使用 : MAX7219_TestMatrixLED();
**====================================================================================================*/
/*====================================================================================================*/
void MAX7219_TestMatrixLED( void )
{
  for (int i=0; i<256; i++) {
    MAX7219_WriteData(1, i);
    MAX7219_WriteData(2, i);
    MAX7219_WriteData(3, i);
    MAX7219_WriteData(4, i);
    MAX7219_WriteData(5, i);
    MAX7219_WriteData(6, i);
    MAX7219_WriteData(7, i);
    MAX7219_WriteData(8, i);
  }

  for (byte i=0; i<2; i++) {
    MAX7219_Fill();
    delay(200);
    MAX7219_Clear();
    delay(200);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
