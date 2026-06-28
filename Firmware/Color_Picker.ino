#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

int PauseButton = 23;
int SensorLight = 19;

void setup() {
  //Begins serial and displays splash screen
  Serial.begin(115200);
  pinMode(PauseButton, INPUT_PULLUP);
  pinMode(SensorLight, OUTPUT);

  
  delay(500);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(10,12);
  display.setTextSize(1);
  display.println("Color Companion V1");
  display.setCursor(13, 24);
  display.println("Awaiting Input...");
  display.display();
  display.clearDisplay();
}

void loop() {

    while (digitalRead(PauseButton)) {
    //Stop display refresh and turn off LED
    digitalWrite(SensorLight, LOW);
  }

  //Setting Up Variables and pins before display loop
  char ColorHex[8];
  float red, green, blue;
  tcs.getRGB(&red, &green, &blue);
  int red_I = (int)red;
  int blue_I = (int)blue;
  int green_I = (int)green;
  digitalWrite(SensorLight, HIGH);
  sprintf(ColorHex, "#%02x%02x%02x", red_I, green_I, blue_I);

  // Display Text Loop
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);
  display.println("R: ");
  display.setCursor(36,0);
  display.println(red_I);

  display.setCursor(0,16);
  display.setTextSize(2);
  display.println("G: ");
  display.setCursor(36,16);
  display.println(green_I);

  display.setCursor(0,32);
  display.setTextSize(2);
  display.println("B: ");
  display.setCursor(36,32);
  display.println(blue_I);

  display.setTextSize(2);
  display.setCursor(0,48);
  display.println(ColorHex);
  
  display.display();


}