// generates diffrent waveforms using pwm.

#include <Tone.h>  // Include the Tone library
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64  

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI 10
#define OLED_CLK 9
#define OLED_DC 12
#define OLED_CS 13
#define OLED_RESET 11
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//some stuff that is needed to be decalred
const int BUTTON_PINS[] = {0, 1, 2, 3, 4, 5, 6, 9};                        // Pins for buttons
const int NUM_BUTTONS = sizeof(BUTTON_PINS) / sizeof(BUTTON_PINS[0]);  // Number of buttons
const int LED_PIN = 7;                                                 // Pin for LED

// Define the pin for the speaker
const int SPEAKER_PIN = A0;

// Define frequency for each wave type
const int WAVE_FREQS[] = { 262, 294, 330, 349, 392, 440, 494, 470 };  // Frequencies for different wave types

Tone speaker;  // Create a Tone object for the speaker

void setup() {
  // Initialize the serial communication for debugging
  Serial.begin(9600);

  // Initialise the speaker pin
  speaker.begin(SPEAKER_PIN);

  // Initialize the button pins as inputs with pull-up resistors
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }

  // Initialize the LED pin as output
  pinMode(LED_PIN, OUTPUT);

  // Initialize the display
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
  // Check each button and play the corresponding tone continuously if pressed
  for (int i = 0; i < NUM_BUTTONS; i++) {
    // Read the current state of the button
    bool buttonState = digitalRead(BUTTON_PINS[i]);

    //if the button is pressed (LOW)
    if (buttonState == HIGH) {
      // Turn on the LED
      digitalWrite(LED_PIN, HIGH); // need to fix the LED loop

      // Play the corresponding tone
      speaker.play(WAVE_FREQS[i]);

      // Display information on the serial monitor
      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.println(" pressed");
    } else {
      // Turn off the LED
      digitalWrite(LED_PIN, LOW);

      // Stop playing the tone
      speaker.stop();
    }
  }
}