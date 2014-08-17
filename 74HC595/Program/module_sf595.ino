/*====================================================================================================*/
/*====================================================================================================*/
#include "module_sf595.h"
/*====================================================================================================*/
/*====================================================================================================*/
const byte SF595_DI = 2;
const byte SF595_OE = 3;
const byte SF595_ST = 4;
const byte SF595_SH = 5;
const byte SF595_MR = 6;
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_Config
**功能 : 74HC595 Config
**輸入 : None
**輸出 : None
**使用 : SF595_Config();
**====================================================================================================*/
/*====================================================================================================*/
static void SF595_Config( void )
{
  pinMode(SF595_DI, OUTPUT);
  pinMode(SF595_OE, OUTPUT);
  pinMode(SF595_ST, OUTPUT);
  pinMode(SF595_SH, OUTPUT);
  pinMode(SF595_MR, OUTPUT);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_Init
**功能 : 74HC595 Init
**輸入 : None
**輸出 : None
**使用 : SF595_Init();
**====================================================================================================*/
/*====================================================================================================*/
void SF595_Init( void )
{
  SF595_Config();

  digitalWrite(SF595_DI, LOW);
  digitalWrite(SF595_OE, LOW);
  digitalWrite(SF595_ST, LOW);
  digitalWrite(SF595_SH, LOW);
  digitalWrite(SF595_MR, HIGH);

  SF595_Reset();
  SF595_OutputEnable(1);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_Reset
**功能 : Reset 74HC595
**輸入 : None
**輸出 : None
**使用 : SF595_Reset();
**====================================================================================================*/
/*====================================================================================================*/
void SF595_Reset( void )
{
  digitalWrite(SF595_MR, LOW);
  delay(1);
  digitalWrite(SF595_MR, HIGH);
  delay(1);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_OutputEnable
**功能 : 74HC595 Output Enable
**輸入 : None
**輸出 : None
**使用 : SF595_OutputEnable(1); // ENABLE
**====================================================================================================*/
/*====================================================================================================*/
void SF595_OutputEnable( byte OutputState )
{
  if (OutputState) {
    digitalWrite(SF595_OE, LOW);
  }
  else {
    digitalWrite(SF595_OE, HIGH);
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_Shift
**功能 : Shift bit
**輸入 : SendData
**輸出 : None
**使用 : SF595_Shift(1);
**====================================================================================================*/
/*====================================================================================================*/
void SF595_Shift( byte SendData )
{
  digitalWrite(SF595_SH, LOW);
  digitalWrite(SF595_ST, LOW);

  if (SendData & 0x01)
    digitalWrite(SF595_DI, HIGH);
  else
    digitalWrite(SF595_DI, LOW);

  digitalWrite(SF595_SH, HIGH);
  digitalWrite(SF595_ST, HIGH);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_SendByte
**功能 : Shift 8 bits
**輸入 : SendData
**輸出 : None
**使用 : SF595_SendByte(SendData);
**====================================================================================================*/
/*====================================================================================================*/
void SF595_SendByte( byte SendData )
{
  for(int i=0; i<8; i++) {
    digitalWrite(SF595_SH, LOW);
    digitalWrite(SF595_ST, LOW);

    if (SendData & (0x80>>i))
      digitalWrite(SF595_DI, HIGH);
    else
      digitalWrite(SF595_DI, LOW);

    digitalWrite(SF595_SH, HIGH);
    digitalWrite(SF595_ST, HIGH);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/