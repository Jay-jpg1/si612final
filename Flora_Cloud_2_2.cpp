
#include "../lib/neopixel/src/neopixel.h"
#include "../lib/Adafruit_ST7735/src/Adafruit_ST7735/Adafruit_mfGFX.h"
#include "../lib/Adafruit_ST7735/src/Adafruit_ST7735/Adafruit_ST7735.h"

#define PIXEL_PIN SPI1
#define PIXEL_COUNT 16
#define PIXEL_TYPE WS2812

#define CS S3
#define RST D0
#define DC D1 

#define BLUE 0x00E7
#define MAIZE 0xFE01


SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);

Adafruit_NeoPixel ring(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
Adafruit_ST7735 display = Adafruit_ST7735(CS, DC, RST); //CS, RS, RST



int setNPColor(String colorName);



void setup() {
  ring.begin();
  // Expose a function called colorName to the cloud, which calls custom function setNPColor
  Particle.function("colorName", setNPColor);



  display.initR(INITR_GREENTAB); // Initialize the display

  display.fillScreen(BLUE);
  display.setCursor(5, 5);
  display.setTextColor(MAIZE); 
  display.setTextWrap(true);
  display.setTextSize(5);
  display.print(" ");
}

void loop() {

}

int setNPColor(String colorName) {
  uint8_t red = 0;
  uint8_t green = 0;
  uint8_t blue = 0;

  if (colorName == "tooFast"){
    red = 255;
    green = 255;
    blue = 0;

  } else if (colorName == "nothing"){
    red = 0;
    green = 0;
    blue = 0;

    display.initR(INITR_GREENTAB); // Initialize the display
    display.fillScreen(BLUE);
    display.setCursor(5, 5);
    display.setTextColor(MAIZE); 
    display.setTextWrap(true);
    display.setTextSize(5);
    display.print(" ");

  } else if (colorName == "red"){
    red = 255;
    green = 0;
    blue = 0;

  } else if (colorName == "good"){
    red = 0;
    green = 255;
    blue = 0;

    display.initR(INITR_GREENTAB); // Initialize the display
    display.fillScreen(BLUE);
    display.setCursor(5, 5);
    display.setTextColor(MAIZE); 
    display.setTextWrap(true);
    display.setTextSize(5);
    display.print("Good\n\Job!");

  }



  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, red, green, blue);
  }

  if (colorName == "loud"){
    // ring.setPixelColor(i, red, green, blue);
    ring.setPixelColor(0, 255, 0, 0);
    ring.setPixelColor(1, 255, 0, 0);
    ring.setPixelColor(2, 255, 0, 0);
    ring.setPixelColor(3, 0, 0, 0);
    ring.setPixelColor(4, 0, 0, 0);
    ring.setPixelColor(5, 0, 0, 0);
    ring.setPixelColor(6, 0, 0, 0);
    ring.setPixelColor(7, 0, 0, 0);
    ring.setPixelColor(8, 0, 0, 0);
    ring.setPixelColor(9, 0, 0, 0);
    ring.setPixelColor(10, 0, 0, 0);
    ring.setPixelColor(11, 0, 0, 0);
    ring.setPixelColor(12, 0, 0, 0);
    ring.setPixelColor(13, 0, 0, 0);
    ring.setPixelColor(14, 0, 0, 0);
    ring.setPixelColor(15, 0, 0, 0);

    display.initR(INITR_GREENTAB);
    display.fillScreen(BLUE);
    display.setCursor(5, 5);
    display.setTextColor(MAIZE);
    display.setTextWrap(true);
    display.setTextSize(4);
    display.print("Speak\nUp!");

  } else if (colorName == "ted"){
    // ring.setPixelColor(i, red, green, blue);
    ring.setPixelColor(0, 255, 0, 0);
    ring.setPixelColor(1, 0, 255, 0);
    ring.setPixelColor(2, 0, 0, 255);
    ring.setPixelColor(3, 255, 0, 0);
    ring.setPixelColor(4, 0, 255, 0);
    ring.setPixelColor(5, 0, 0, 255);
    ring.setPixelColor(6, 255, 0, 0);
    ring.setPixelColor(7, 0, 255, 0);
    ring.setPixelColor(8, 0, 0, 255);
    ring.setPixelColor(9, 255, 0, 0);
    ring.setPixelColor(10, 0, 255, 0);
    ring.setPixelColor(11, 0, 0, 255);
    ring.setPixelColor(12, 255, 0, 0);
    ring.setPixelColor(13, 0, 255, 0);
    ring.setPixelColor(14, 0, 0, 255);
    ring.setPixelColor(15, 255, 0, 0);

    display.initR(INITR_GREENTAB); // Initialize the display
    display.fillScreen(BLUE);
    display.setCursor(5, 5);
    display.setTextColor(MAIZE); 
    display.setTextWrap(true);
    display.setTextSize(5);
    display.print("I'm\n\Ted!");
  
  } else if (colorName == "slow"){
    // ring.setPixelColor(i, red, green, blue);
    ring.setPixelColor(0, 255, 0, 0);
    ring.setPixelColor(1, 255, 0, 0);
    ring.setPixelColor(2, 255, 0, 0);
    ring.setPixelColor(3, 255, 0, 0);
    ring.setPixelColor(4, 255, 0, 0);
    ring.setPixelColor(5, 0, 0, 0);
    ring.setPixelColor(6, 0, 0, 0);
    ring.setPixelColor(7, 0, 0, 0);
    ring.setPixelColor(8, 0, 0, 0);
    ring.setPixelColor(9, 0, 0, 0);
    ring.setPixelColor(10, 0, 0, 0);
    ring.setPixelColor(11, 0, 0, 0);
    ring.setPixelColor(12, 255, 0, 0);
    ring.setPixelColor(13, 255, 0, 0);
    ring.setPixelColor(14, 255, 0, 0);
    ring.setPixelColor(15, 255, 0, 0);
    
    display.initR(INITR_GREENTAB);
    display.fillScreen(BLUE);
    display.setCursor(5, 5);
    display.setTextColor(MAIZE);
    display.setTextWrap(true);
    display.setTextSize(4);
    display.print("Slow\n\Down!");

  } else if (colorName == "fast"){
    // ring.setPixelColor(i, red, green, blue);
    ring.setPixelColor(0, 0, 0, 0);
    ring.setPixelColor(1, 0, 0, 0);
    ring.setPixelColor(2, 0, 0, 0);
    ring.setPixelColor(3, 0, 0, 0);
    ring.setPixelColor(4, 0, 0, 0);
    ring.setPixelColor(5, 255, 255, 0);
    ring.setPixelColor(6, 255, 255, 0);
    ring.setPixelColor(7, 255, 255, 0);
    ring.setPixelColor(8, 255, 255, 0);
    ring.setPixelColor(9, 255, 255, 0);
    ring.setPixelColor(10, 255, 255, 0);
    ring.setPixelColor(11, 255, 255, 0);
    ring.setPixelColor(12, 0, 0, 0);
    ring.setPixelColor(13, 0, 0, 0);
    ring.setPixelColor(14, 0, 0, 0);
    ring.setPixelColor(15, 0, 0, 0);

    display.initR(INITR_GREENTAB);
    display.fillScreen(BLUE);
    display.setCursor(5, 5);
    display.setTextColor(MAIZE);
    display.setTextWrap(true);
    display.setTextSize(4);
    display.print("Speed\nUp!");
  
  }
  

  ring.setBrightness(50);
  ring.show();
  return 0;
}
