
#include <SPI.h>
#include <RFID.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define SDA_DIO 9
#define RESET_DIO 8
#define OLED_ADDR   0x3C
RFID RC522(SDA_DIO, RESET_DIO); 

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Error SSD1306");
#endif

void setup(){ 
  Serial.begin(9600);
  SPI.begin();
  RC522.init();

  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  // display a pixel in each corner of the screen
  display.drawPixel(0, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 63, WHITE);
  display.drawPixel(127, 63, WHITE);

  // display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(27,30);
  display.print("MIFARE SKIMMER");

  // update display with all of the above graphics
  display.display();
}

void loop(){
  /* Has a card been detected? */
  if (RC522.isCard()){
    /* If so then get its serial number */
    RC522.readCardSerial();
    // initialize and clear display
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    display.clearDisplay();
    display.display();
    // display a pixel in each corner of the screen
    display.drawPixel(0, 0, WHITE);
    display.drawPixel(127, 0, WHITE);
    display.drawPixel(0, 63, WHITE);
    display.drawPixel(127, 63, WHITE);
    // display a line of text
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(27,30);
    for(int i=0;i<5;i++){
      display.print(RC522.serNum[i],DEC);
      //Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
    }
    display.display();
  }
  delay(1000);
}
