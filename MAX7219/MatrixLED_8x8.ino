// Use Arduino Uno

/* Arduino Board define */
int LED = 13;

/* max7219 IO define */
int max7219_din  = 2;
int max7219_load = 3;
int max7219_clk  = 4;

/* max7219 reg define */
byte MAX7219_NOOP         = 0x00;
byte MAX7219_DIGIT_0      = 0x01;
byte MAX7219_DIGIT_1      = 0x02;
byte MAX7219_DIGUT_2      = 0x03;
byte MAX7219_DIGIT_3      = 0x04;
byte MAX7219_DIGIT_4      = 0x05;
byte MAX7219_DIGIT_5      = 0x06;
byte MAX7219_DIGIT_6      = 0x07;
byte MAX7219_DIGIT_7      = 0x08;
byte MAX7219_DECODE_MODE  = 0x09;
byte MAX7219_INTENSITY    = 0x0A;
byte MAX7219_SCAN_LIMIT   = 0x0B;
byte MAX7219_SHUTDOWN     = 0x0C;
byte MAX7219_DISPLAY_TEST = 0x0D;

void sendByte( byte data )
{
  for (byte i=0; i<8; i++) {
    digitalWrite(max7219_clk, LOW);
    if (data & (0x80 >> i))
      digitalWrite(max7219_din, HIGH);
    else
      digitalWrite(max7219_din, LOW);
    digitalWrite(max7219_clk, HIGH);
  }
}

void writeData( byte addr, byte data )
{
  digitalWrite(max7219_load, LOW);
  sendByte(addr);
  sendByte(data);
  digitalWrite(max7219_load, HIGH);
}

void max7219_init( void )
{
  writeData(MAX7219_SHUTDOWN,     0x01);  // Normal Operation
  writeData(MAX7219_DISPLAY_TEST, 0x00);  // No Display Test
  writeData(MAX7219_SCAN_LIMIT,   0x07);  // Scan All
  writeData(MAX7219_DECODE_MODE,  0x00);  // No Decode
  writeData(MAX7219_INTENSITY,    0x00);  // Min (01/32)

  for (byte i=1; i<=8; i++)  // All Off
    writeData(i, 0);
}

void setup ()
{
  pinMode(LED, OUTPUT);

  pinMode(max7219_din,  OUTPUT);
  pinMode(max7219_clk,  OUTPUT);
  pinMode(max7219_load, OUTPUT);

  digitalWrite(LED, HIGH);

  delay(100);

  max7219_init();

  for (byte i=1; i<=8; i++)
    writeData(i, 1<<(i-1));
/*
  writeData(1, 1);
  writeData(2, 2);
  writeData(3, 4);
  writeData(4, 8);
  writeData(5, 16);
  writeData(6, 32);
  writeData(7, 64);
  writeData(8, 128);
*/
}

void loop ()
{
  digitalWrite(LED, LOW);
  delay(100);
  digitalWrite(LED, HIGH);
  delay(100);
}
