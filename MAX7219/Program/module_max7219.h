/* #include "module_max7219.h" */

#ifndef __MODULE_MAX7219_H_
#define __MODULE_MAX7219_H_
/*====================================================================================================*/
/*====================================================================================================*/
/* max7219 reg define */
#define MAX7219_NOOP          ((byte)0x00)
#define MAX7219_DIGIT_0       ((byte)0x01)
#define MAX7219_DIGIT_1       ((byte)0x02)
#define MAX7219_DIGUT_2       ((byte)0x03)
#define MAX7219_DIGIT_3       ((byte)0x04)
#define MAX7219_DIGIT_4       ((byte)0x05)
#define MAX7219_DIGIT_5       ((byte)0x06)
#define MAX7219_DIGIT_6       ((byte)0x07)
#define MAX7219_DIGIT_7       ((byte)0x08)
#define MAX7219_DECODE_MODE   ((byte)0x09)
#define MAX7219_INTENSITY     ((byte)0x0A)
#define MAX7219_SCAN_LIMIT    ((byte)0x0B)
#define MAX7219_SHUTDOWN      ((byte)0x0C)
#define MAX7219_DISPLAY_TEST  ((byte)0x0D)
/*====================================================================================================*/
/*====================================================================================================*/
void MAX7219_Init( void );
void MAX7219_WriteData( byte addr, byte data );
void MAX7219_Fill( void );
void MAX7219_Clear( void );
void MAX7219_TestMatrixLED( void );
/*====================================================================================================*/
/*====================================================================================================*/
#endif
