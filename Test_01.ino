#include <Tone.h>  // Include the Tone library
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

//IMPORTANT!!!!
//CHANGE THE PINS FOR THE SCREEN!!!!
// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI 10
#define OLED_CLK 9
#define OLED_DC 12
#define OLED_CS 13
#define OLED_RESET 11
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


// Define the pins for the buttons
const int DO_BUTTON_PIN = 1;
const int RE_BUTTON_PIN = 2;
const int MI_BUTTON_PIN = 3;
const int FA_BUTTON_PIN = 4;
const int SO_BUTTON_PIN = 5;
const int LA_BUTTON_PIN = 6;
const int TI_BUTTON_PIN = 7;
const int DO_HIGH_BUTTON_PIN = 8;

// Define the pin for the speaker
const int SPEAKER_PIN = A0; // for

// Define the frequencies for Do, Re, Mi, Fa, Sol, La, Ti
const int DO_FREQ = 262;  // Frequency of Do (C)
const int RE_FREQ = 294;  // Frequency of Re (D)
const int MI_FREQ = 330;  // Frequency of Mi (E)
const int FA_FREQ = 349;  // Frequency of Fa (F)
const int SO_FREQ = 392;  // Frequency of Sol (G)
const int LA_FREQ = 220;  // Frequency of La (A)
const int TI_FREQ = 247;  // Frequency of Ti (B)

void setup() {
  // Initialize the serial communication for debugging
  Serial.begin(9600);

  // initialise the speakers pins
  pinMode(SPEAKER_PIN, OUTPUT);

  // Initialize the button pins as inputs with pull-up resistors
  pinMode(DO_BUTTON_PIN, INPUT);       //do
  pinMode(RE_BUTTON_PIN, INPUT);       //re
  pinMode(MI_BUTTON_PIN, INPUT);       //mi
  pinMode(FA_BUTTON_PIN, INPUT);       //fa
  pinMode(SO_BUTTON_PIN, INPUT);       //sol
  pinMode(LA_BUTTON_PIN, INPUT);       //la
  pinMode(TI_BUTTON_PIN, INPUT);       //ti
  pinMode(DO_HIGH_BUTTON_PIN, INPUT);  //do at a higher octave

  pinMode(SPEAKER_PIN, OUTPUT);  //setting the speakerpin as an output




  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000);  // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
}
//the layout for the tone library is
//tone(pin, Frequency, duration)
//think were going to do 10ms for each noise


void loop() {
  //Serial.print("HI");
  // Check each button and play the corresponding note if pressed



  // if(digitalRead(RE_BUTTON_PIN)==HIGH){
  //   tone(SPEAKER_PIN,110,10);
  // }this is an example

  if (digitalRead(DO_BUTTON_PIN) == HIGH) {
    playNote(DO_FREQ, 400);
    Serial.println("DO");
    display.clearDisplay();
    writeDO();
    delay(200);
  }
  if (digitalRead(RE_BUTTON_PIN) == HIGH) {
    playNote(MI_FREQ, 350);
    Serial.println("RE");
    display.clearDisplay();
    writeRE();
    delay(200);
  }
  if (digitalRead(MI_BUTTON_PIN) == HIGH) {
    playNote(MI_FREQ, 400);
    Serial.println("MI");
    display.clearDisplay();
    writeMI();
    delay(200);
  }
  if (digitalRead(FA_BUTTON_PIN) == HIGH) {
    playNote(FA_FREQ, 200);
    Serial.println("FA");
    display.clearDisplay();
    writeFA();
    delay(200);
  }
  if (digitalRead(SO_BUTTON_PIN) == HIGH) {
   // playNote(SOL_FREQ, 500);
    Serial.println("SO");
    display.clearDisplay();
    writeSO();
    delay(200);
  }
  if (digitalRead(LA_BUTTON_PIN) == HIGH) {
    playNote(LA_FREQ, 500);
    Serial.println("LA");
    display.clearDisplay();
    writeLA();
    delay(200);
  }

  if (digitalRead(TI_BUTTON_PIN) == HIGH) {
    playNote(TI_FREQ, 500);
    Serial.println("TI");
    display.clearDisplay();
    writeTI();
    delay(200);
  }

  if (digitalRead(DO_HIGH_BUTTON_PIN) == HIGH) {
    playNote(DO_FREQ * 2, 500);  // this plays a higher octave of the Do note
    Serial.println("DOx2");
    display.clearDisplay();
    writeDO();
    delay(200);
  }
}

//Function to play a note at a given frequency and duration
void playNote(int frequency, int duration) {
  //tone(SPEAKER_PIN, frequency, duration);  // Play the note
  delay(duration + 50);                    // Delay to avoid overlap between notes
}

void writeDO() {
  display.display();
  // letter D
  display.fillRect(5, 5, 10, 50, WHITE);
  display.fillRect(15, 5, 30, 5, WHITE);
  display.fillRect(15, 50, 30, 5, WHITE);
  display.fillRect(45, 10, 5, 40, WHITE);
  display.display();
  // delay(100);

  // letter O
  display.fillRect(75, 10, 5, 40, WHITE);
  display.fillRect(80, 5, 20, 5, WHITE);
  display.fillRect(80, 50, 20, 5, WHITE);
  display.fillRect(100, 10, 5, 40, WHITE);
  display.display();
  delay(100);

  Serial.println("DO");
}

void writeRE() {
  display.display();
  // letter R
  display.fillRect(5, 5, 10, 50, WHITE);
  display.fillRect(15, 5, 20, 5, WHITE);
  display.fillRect(35, 10, 5, 10, WHITE);
  display.fillRect(15, 20, 20, 5, WHITE);
  display.fillRect(35, 25, 5, 30, WHITE);
  display.display();

  // letter E
  display.fillRect(70, 5, 10, 50, WHITE);
  display.fillRect(80, 5, 20, 5, WHITE);
  display.fillRect(80, 50, 20, 5, WHITE);
  display.fillRect(80, 25, 10, 5, WHITE);
  display.display();
  delay(100);
}

void writeMI() {
  display.display();
  // letter M
  display.fillRect(5, 5, 10, 50, WHITE);
  display.fillRect(15, 15, 10, 10, WHITE);
  display.fillRect(25, 25, 10, 10, WHITE);
  display.fillRect(35, 15, 10, 10, WHITE);
  display.fillRect(45, 5, 10, 50, WHITE);
  display.display();

  // letter I
  display.fillRect(75, 5, 10, 50, WHITE);
  display.display();
  delay(100);
}

void writeFA() {
  display.display();
  // letter F
  display.fillRect(5, 5, 10, 50, WHITE);
  display.fillRect(15, 5, 20, 5, WHITE);
  display.fillRect(15, 20, 10, 5, WHITE);
  display.display();

  // letter A
  display.fillRect(65, 10, 10, 40, WHITE);
  display.fillRect(75, 5, 20, 5, WHITE);
  display.fillRect(75, 20, 20, 5, WHITE);
  display.fillRect(95, 10, 10, 40, WHITE);
  display.display();
  delay(100);
}

void writeSO() {
  display.display();
  // letter S
  display.fillRect(5, 5, 10, 25, WHITE);
  display.fillRect(15, 5, 20, 5, WHITE);
  display.fillRect(15, 25, 10, 5, WHITE);
  display.fillRect(25, 25, 10, 25, WHITE);
  display.fillRect(5, 50, 20, 5, WHITE);
  display.display();

  // letter O
  display.fillRect(65, 10, 5, 40, WHITE);
  display.fillRect(70, 5, 20, 5, WHITE);
  display.fillRect(70, 50, 20, 5, WHITE);
  display.fillRect(90, 10, 5, 40, WHITE);
  display.display();
  delay(100);
}

void writeLA() {
  display.display();
  // letter L
  display.fillRect(5, 5, 10, 50, WHITE);
  display.fillRect(15, 50, 20, 5, WHITE);
  display.display();

  // letter A
  display.fillRect(60, 10, 10, 40, WHITE);
  display.fillRect(70, 5, 20, 5, WHITE);
  display.fillRect(70, 20, 20, 5, WHITE);
  display.fillRect(90, 10, 10, 40, WHITE);
  display.display();
  delay(100);
}

void writeTI() {
  display.display();
  // letter T
  display.fillRect(5, 5, 30, 10, WHITE);
  display.fillRect(15, 15, 10, 40, WHITE);
  display.display();

  // letter I
  display.fillRect(65, 5, 10, 50, WHITE);
  display.display();
  delay(100);
}