# MIFARE SKIMMER
* Author: [@037](https://twitter.com/037)


Requirements:
- Arduino Mega 2560
- RFID RC522
- OLED 

Pinout for OLED:
```
[OLED] VDD -> [MEGA] 5V
[OLED] GND -> [MEGA] GND
[OLED] SCK -> [MEGA] SCK
[OLED] SDA -> [MEGA] SDA
```

Pinout for RC522:
```
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D9
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D8
3.3V            3.3V         3.3V
```

You will also need all libraries within the source code, modify Adafruit_SSD1306.h to match the resolution of your OLED display.

For example:
```
#define SSD1306_128_64
// #define SSD1306_128_32
// #define SSD1306_96_16
```