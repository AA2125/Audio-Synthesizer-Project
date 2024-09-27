// test 7 with ultrasonic (works)

// the gain of the OpAmp does not matter since the volume control is related to the ultrasonic distance.

#include <Tone.h>  //Tone library to generate sounds.
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for SSD1306 display connected using software SPI (default case):
//////////////////////////////////////////////////////////////////////
#define OLED_MOSI 10
#define OLED_CLK 9
#define OLED_DC 12
#define OLED_CS 13
#define OLED_RESET 11
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
/////////////////////////////////////////////////////////////////////////////

//button pins
/////////////////////////////////////////////////////////////////////
const int BUTTON_PINS[] = { 0, 1, 2, 3, 4, 5, 6, 9 };
const int NUM_BUTTONS = sizeof(BUTTON_PINS) / sizeof(BUTTON_PINS[0]);
//////////////////////////////////////////////////////////////////////

// LED pin to verify if things work.
const int LED_PIN = 7;

// Speaker Pin.
const int SPEAKER_PIN = A0;

// Frequncy of each note (DO , SO , RE ... etc..)
const int WAVE_FREQS[] = { 262, 294, 330, 349, 392, 440, 508, 524 };  // Frequencies for different wave types

// Ultrasonic sensor pins (All of this stuff is taken from 2E10)
const int TRIGGER_PIN = A3;
const int ECHO_PIN = A2;

Tone speaker;  // No idea how that works(something to do with the tone libary), i trusted stackoverflow.

void setup() {
  Serial.begin(9600);

  // Initialise the speaker pin
  speaker.begin(SPEAKER_PIN);

  // pull up ressistors are defined.
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }

  // The LED acts as output.
  pinMode(LED_PIN, OUTPUT);

  // The Ultrasonic Echo reads in and gives an output (volume level).
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Display stuff taken from the example libary.
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();  // Clear the display
  display.display();       // Show initial display buffer contents on the screen
  delay(2000);             // Pause for 2 seconds
  display.clearDisplay();  // Clear the display again
}

void loop() {
  // Each button is connnected to a tone, using this loop helps in the constant play of the tone rather than a quick tone.
  for (int i = 0; i < NUM_BUTTONS; i++) {
    bool buttonState = digitalRead(BUTTON_PINS[i]);

    //if the button is pressed (HIGH)
    if (buttonState == HIGH) {
      digitalWrite(LED_PIN, HIGH);  // Turn on the LED

      ///////////////////////////////////////////////////////////////
      // related to the ultrasonic stuff (barrowed from 2E10 days)
      // Measure distance with ultrasonic sensor.
      int distance = measureDistance();

      // Adjust volume based on distance.
      int volume = map(distance, 0, 170, 0, 800);  // i can adjust the distance to control the voulme, values are not final yet

      // Play the corresponding tone with adjusted volume
      speaker.play(WAVE_FREQS[i], volume);

      // Display information on the serial monitor
      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.print(" pressed, Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      ///////////////////////////////////////////////////////////////

    } else {
      digitalWrite(LED_PIN, LOW);  // Turn off the LED
      speaker.stop();              // Stop playing the tone
    }
  }
}

// Function to measure distance with ultrasonic sensor (took this stuff from back from 2E10 days)
int measureDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;  // this could be played around with for the distance.
  return distance;
}
