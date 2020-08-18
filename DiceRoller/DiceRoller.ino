#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TrueRandom.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//variables
#define menu 3

// menu size
const int menuSize = 7;
String menuItems[menuSize];
int currMenu = 0;
String temp;
bool Next = HIGH;
char currentPrintOut[10];

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // setup the OLED
  pinMode(13, INPUT); // setup button 3
  pinMode(12, INPUT_PULLUP); // setup button 2
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.drawRect(0, 0, 128, 8, WHITE);
  display.display(); // write to display
  Serial.begin(115200);


  menuItems[0] = "D2";
  menuItems[1] = "D4";
  menuItems[2] = "D6";
  menuItems[3] = "D8";
  menuItems[4] = "D10";
  menuItems[5] = "D12";
  menuItems[6] = "D20";

  MenuChanged();
}

void loop() {

  if (digitalRead(12) != Next) {
    Next = !Next;
    if (!Next) {
      //pressed
      if (currMenu > 0) {
        currMenu--;
      }
      else {
        currMenu =
        menuSize - 1;
      }
      MenuChanged();
      Serial.print (currMenu);
    }
  }

  if (digitalRead(10) == HIGH) {
    delay(15);
    if (digitalRead(10) == HIGH) {
      if (currMenu == 0) {
        d2Roll();
      }
    }
  }
  
  if (digitalRead(10) == HIGH) {
    delay(15);
    if (digitalRead(10) == HIGH) {
      if (currMenu == 1) {
        d4Roll();
      }
    }
  }
  if (digitalRead(10) == HIGH) {
    delay(15);
    if (digitalRead(10) == HIGH) {
      if (currMenu == 2) {
        d6Roll();
      }
    }
  }
  if (digitalRead(10) == HIGH) {
    delay(15);
    if (digitalRead(10) == HIGH) {
      if (currMenu == 3) {
        d8Roll();
      }
    }
  }

  if (digitalRead(10) == HIGH) {
    delay(15);
    if (digitalRead(10) == HIGH) {
      if (currMenu == 4) {
        d10Roll();
      }
    }
  }

  if (digitalRead(10) == HIGH) {
    delay(15);
    if (digitalRead(10) == HIGH) {
      if (currMenu == 5) {
        d12Roll();
      }
    }
  }
  if (digitalRead(10) == HIGH) {
    delay(15);
    if (digitalRead(10) == HIGH) {
      if (currMenu == 6) {
        d20Roll();
      }
    }
  }
}

void MenuButton() {
  Serial.println("Right button state has changed");
  delay(25);
}

void MenuChanged() {
  display.clearDisplay();
  display.drawRect(0, 0, 128, 8, WHITE);
  if (currMenu < 4) {
    display.setCursor(53, 15);
  }
  else {
    display.setCursor(48, 15);
  }
  display.setTextColor(WHITE);
  display.setTextSize(2);
  temp = String (menuItems[currMenu]);
  temp.toCharArray (currentPrintOut, 10);
  display.println(currentPrintOut); // write the roll
  Serial.println(currentPrintOut); // write the roll
  display.display(); // write to display
  delay(25);

}
void d20() {
  // store image in EEPROM
  static const unsigned char PROGMEM imExp[] = {
    0x00, 0x00, 0x1e, 0x00, 0x00, 0x00
    , 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00
    , 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00
    , 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00
    , 0x0f, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0x80
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0x7f, 0xff, 0xff, 0xff, 0xff, 0x80
    , 0x0f, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00
    , 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00
    , 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00
    , 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00
  };
  display.drawBitmap(44, 9, imExp, 42, 23, 1); // draw dice
  //display.drawRect(32, 0, 27, 23,  WHITE);
}

void d12() {
  // store image in EEPROM
  static const unsigned char PROGMEM imExp[] = {
    0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00
    , 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x00
    , 0x00, 0xff, 0xff, 0xff, 0x80, 0x00
    , 0x01, 0xff, 0xff, 0xff, 0xf0, 0x00
    , 0x07, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0x1f, 0xff, 0xff, 0xff, 0xfe, 0x00
    , 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x00
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0x80
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0x80
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x00
    , 0x1f, 0xff, 0xff, 0xff, 0xfe, 0x00
    , 0x07, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0x01, 0xff, 0xff, 0xff, 0xf0, 0x00
    , 0x00, 0xff, 0xff, 0xff, 0x80, 0x00
    , 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x00
    , 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00

  };
  display.drawBitmap(44, 9, imExp, 42, 23, 1); // draw dice
  //display.drawRect(32, 0, 27, 23,  WHITE);
}


void d10() {
  // store image in EEPROM
  static const unsigned char PROGMEM imExp[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00
    , 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00
    , 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00
    , 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00
    , 0x00, 0xff, 0xff, 0xff, 0x80, 0x00
    , 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00
    , 0x01, 0xff, 0xff, 0xff, 0xf0, 0x00
    , 0x03, 0xff, 0xff, 0xff, 0xf8, 0x00
    , 0x03, 0xff, 0xff, 0xff, 0xf8, 0x00
    , 0x07, 0xff, 0xff, 0xff, 0xf8, 0x00
    , 0x07, 0xff, 0xff, 0xff, 0xf0, 0x00
    , 0x07, 0xff, 0xff, 0xff, 0xf0, 0x00
    , 0x03, 0xff, 0xff, 0xff, 0xe0, 0x00
    , 0x00, 0xff, 0xff, 0xff, 0xe0, 0x00
    , 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00
    , 0x00, 0x3f, 0xff, 0xff, 0x80, 0x00
    , 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00
    , 0x00, 0x07, 0xff, 0x80, 0x00, 0x00
    , 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

  };
  display.drawBitmap(44, 9, imExp, 42, 23, 1); // draw dice
  //display.drawRect(32, 0, 27, 23,  WHITE);
}

void d8() {
  // store image in EEPROM
  static const unsigned char PROGMEM imExp[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00
    , 0x00, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00
    , 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 0x00
    , 0x00, 0x1f, 0xff, 0xff, 0xff, 0x80, 0x00
    , 0x00, 0x3f, 0xff, 0xff, 0xff, 0xe0, 0x00
    , 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0x00
    , 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x00
    , 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80
    , 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80
    , 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0x03, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00
    , 0x01, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 0x00
    , 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf8, 0x00
    , 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00
    , 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 0x00
    , 0x00, 0x00, 0x7f, 0xff, 0xe0, 0x00, 0x00
    , 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00
  };
  display.drawBitmap(44, 9, imExp, 55, 27, 1);//draw dice
  //display.drawRect(32, 0, 27, 23,  WHITE);
}

void d6() {
  // store image in EEPROM
  static const unsigned char PROGMEM imExp[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
    , 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0
  };
  display.drawBitmap(44, 11, imExp, 40, 21, 1); // draw dice
  //display.drawRect(32, 0, 27, 23,  WHITE);
}

void d4() {
  // store image in EEPROM
  static const unsigned char PROGMEM imExp[] = {
    0x00, 0x00, 0x08, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x7f, 0x80, 0x00, 0x00
    , 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00
    , 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00
    , 0x00, 0x03, 0xff, 0xf0, 0x00, 0x00
    , 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00
    , 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00
    , 0x00, 0x1f, 0xff, 0xfe, 0x00, 0x00
    , 0x00, 0x3f, 0xff, 0xff, 0x00, 0x00
    , 0x00, 0x7f, 0xff, 0xff, 0x80, 0x00
    , 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00
    , 0x01, 0xff, 0xff, 0xff, 0xe0, 0x00
    , 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00
    , 0x07, 0xff, 0xff, 0xff, 0xf8, 0x00
    , 0x0f, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0x1f, 0xff, 0xff, 0xff, 0xfe, 0x00
    , 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0x7f, 0xff, 0xff, 0xff, 0xff, 0x80

  };
  display.drawBitmap(43, 9, imExp, 42, 20, 1); // draw dice
  //display.drawRect(32, 0, 27, 23,  WHITE);
}

void d2() {
  // store image in EEPROM
  static const unsigned char PROGMEM imExp[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00
    , 0x00, 0x1f, 0xff, 0xfe, 0x00, 0x00
    , 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00
    , 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00
    , 0x0f, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0x1f, 0xff, 0xff, 0xff, 0xfe, 0x00
    , 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00
    , 0x1f, 0xff, 0xff, 0xff, 0xfe, 0x00
    , 0x0f, 0xff, 0xff, 0xff, 0xfc, 0x00
    , 0x23, 0xff, 0xff, 0xff, 0xf1, 0x00
    , 0x30, 0xff, 0xff, 0xff, 0xc3, 0x00
    , 0x12, 0x1f, 0xff, 0xfe, 0x12, 0x00
    , 0x03, 0x80, 0x7f, 0x80, 0x70, 0x00
    , 0x03, 0xf0, 0x00, 0x03, 0xf0, 0x00
    , 0x00, 0xf3, 0xf3, 0xf3, 0xc0, 0x00
    , 0x00, 0x13, 0xf3, 0xf2, 0x00, 0x00
    , 0x00, 0x00, 0x33, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

  };
  display.drawBitmap(44, 11, imExp, 42, 20, 1); // draw dice
  //display.drawRect(32, 0, 27, 23,  WHITE);
}



void drawStar() {
  // store image in EEPROM
  static const unsigned char PROGMEM imExp[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00
    , 0x00, 0x00, 0x7f, 0x80, 0x00, 0x00
    , 0x00, 0x21, 0xff, 0x80, 0x00, 0x00
    , 0x00, 0x07, 0xff, 0x80, 0x00, 0x00
    , 0x00, 0x0f, 0xff, 0x80, 0x10, 0x00
    , 0x00, 0x1f, 0xff, 0x80, 0x00, 0x00
    , 0x00, 0x3f, 0xff, 0x82, 0x00, 0x00
    , 0x18, 0x3f, 0xff, 0xc0, 0x00, 0x00
    , 0x00, 0x3f, 0xff, 0xc0, 0x18, 0x00
    , 0x00, 0x3f, 0xff, 0xe0, 0x1c, 0x00
    , 0x00, 0x04, 0x1f, 0xf8, 0x00, 0x00
    , 0x03, 0xff, 0xf3, 0xfc, 0x00, 0x00
    , 0x07, 0xff, 0xf9, 0xff, 0x80, 0x00
    , 0x7f, 0xff, 0xfc, 0x7f, 0xf8, 0x00
    , 0xff, 0xff, 0xff, 0x9f, 0xff, 0x80
    , 0xff, 0xff, 0xff, 0xdf, 0xff, 0x00
    , 0xff, 0xff, 0xff, 0x9f, 0xfc, 0x00
    , 0x3f, 0xff, 0xff, 0x3f, 0xf0, 0x00
    , 0x00, 0xff, 0xf0, 0xfe, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  display.drawBitmap(10, 9, imExp, 42, 23, 1); // draw moon
}

void drawSkull() {
  // store image in EEPROM
  static const unsigned char PROGMEM imSku[] = {
    0x00, 0x00, 0xff, 0xc0, 0x00, 0x00
    , 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00
    , 0x00, 0x1f, 0xff, 0xfe, 0x00, 0x00
    , 0x00, 0x3f, 0xff, 0xff, 0x00, 0x00
    , 0x00, 0x78, 0x3f, 0x07, 0x80, 0x00
    , 0x00, 0xf8, 0x3f, 0x07, 0xc0, 0x00
    , 0x00, 0xff, 0xf3, 0xff, 0xc0, 0x00
    , 0x00, 0xff, 0xe1, 0xff, 0xc0, 0x00
    , 0x00, 0x7f, 0xff, 0xff, 0x80, 0x00
    , 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00
    , 0x03, 0x87, 0xff, 0xf8, 0x70, 0x00
    , 0x07, 0xc7, 0xff, 0xf8, 0xfc, 0x00
    , 0x07, 0xc3, 0xff, 0xf0, 0xfc, 0x00
    , 0x1f, 0xf8, 0x00, 0x07, 0xfe, 0x00
    , 0x3f, 0xff, 0x80, 0x7f, 0xff, 0x00
    , 0x1e, 0x1f, 0xff, 0xfe, 0x1e, 0x00
    , 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00
    , 0x0e, 0x07, 0xff, 0xfc, 0x1c, 0x00
    , 0x1f, 0xff, 0xc0, 0xff, 0xff, 0x00
    , 0x1f, 0xfc, 0x00, 0x0f, 0xfe, 0x00
    , 0x0f, 0xc0, 0x00, 0x00, 0xfc, 0x00
    , 0x0f, 0xc0, 0x00, 0x00, 0xfc, 0x00
    , 0x07, 0x80, 0x00, 0x00, 0x78, 0x00
  };
  display.drawBitmap(10, 9, imSku, 42, 23, 1); // draw skull
}

void d20Roll() {
  display.fillScreen(BLACK); // erase all
  display.drawRect(0, 0, 128, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  int roll = TrueRandom.random(1, 21); // store the number

  if (roll == 20) {
    drawStar();
    display.setCursor(77, 14);
    display.println("20"); // daaamn yuss
  }
  else if (roll == 1) {
    display.setCursor(87, 14);
    display.println("1"); //get rekt
    drawSkull();
  }
  else if (roll < 10) {
    // single character number
    d20(); // draw the outline
    display.setTextColor(BLACK);
    display.setCursor(60, 15);
    display.println(roll); // write the roll

  }
  else {
    // dual character number
    d20(); // draw the outline
    display.setTextColor(BLACK);
    display.setCursor(52, 15);
    display.println(roll); // write the roll
  }

  display.display(); // write to display
  delay(100);
}
void d12Roll() {
  display.fillScreen(BLACK); // erase the whole display
  display.drawRect(0, 0, 128, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  int roll = TrueRandom.random(1, 13); // store the random number

  if (roll < 10) {
    // single character number
    d12(); // draw the outline
    display.setTextColor(BLACK);
    display.setCursor(60, 15);
    display.println(roll); // write the roll

  }
  else {
    // dual character number
    d12(); // draw the outline
    display.setTextColor(BLACK);
    display.setCursor(52, 15);
    display.println(roll); // write the roll
  }

  display.display(); // write to display
  delay(100);
}
void d10Roll() {
  display.fillScreen(BLACK); // erase the whole display
  display.drawRect(0, 0, 128, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  int roll = TrueRandom.random(1, 11 ); // store the random number


  if (roll < 10) {
    // single character number
    d10(); // draw the outline
    display.setTextColor(BLACK);
    display.setCursor(60, 15);
    display.println(roll); // write the roll

  }
  else {
    // dual character number
    d10(); // draw the outline
    display.setTextColor(BLACK);
    display.setCursor(52, 15);
    display.println(roll); // write the roll
  }

  display.display(); // write to display
  delay(100);
}

void d8Roll() {
  display.fillScreen(BLACK); // erase the whole display
  display.drawRect(0, 0, 128, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  int roll = TrueRandom.random(1, 9); // store the random number
  d8(); // draw the outline
  display.setTextColor(BLACK);
  display.setCursor(60, 15);
  display.println(roll); // write the roll
  display.display(); // write to display
  delay(100);
}
void d6Roll() {
  display.fillScreen(BLACK); // erase the whole display
  display.drawRect(0, 0, 128, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  int roll = TrueRandom.random(1, 7); // store the random number
  d6(); // draw the outline
  display.setTextColor(BLACK);
  display.setCursor(60, 15);
  display.println(roll); // write the roll
  display.display(); // write to display
  delay(100);
}

void d4Roll() {
  display.fillScreen(BLACK); // erase the whole display
  display.drawRect(0, 0, 128, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  int roll = TrueRandom.random(1, 5); // store the random number
  d4(); // draw the outline
  display.setTextColor(BLACK);
  display.setCursor(60, 15);
  display.println(roll); // write the roll
  display.display(); // write to display
  delay(100);
}

void d2Roll() {
  display.fillScreen(BLACK); // erase the whole display
  display.drawRect(0, 0, 128, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  int roll = TrueRandom.random(1, 3); // store the random number
  d2(); // draw the outline
  display.setTextColor(BLACK);
  display.setCursor(60, 15);
  display.println(roll); // write the roll
  display.display(); // write to display
  delay(100);
}
