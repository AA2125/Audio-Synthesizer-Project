#include <Tone.h>  // Include the Tone library
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI 10
#define OLED_CLK 9
#define OLED_DC 12
#define OLED_CS 13
#define OLED_RESET 11
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// Define the pins for the buttons and LED
const int BUTTON_PINS[] = { 0, 1, 2, 3, 4, 5, 6, 8, 9 };               // Pins for buttons
const int NUM_BUTTONS = sizeof(BUTTON_PINS) / sizeof(BUTTON_PINS[0]);  // Number of buttons
const int LED_PIN = 7;                                                 // Pin for LED

// Define the pin for the speaker
const int SPEAKER_PIN = A0;

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

  // Initialize the random number generator
  randomSeed(analogRead(0));

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
  static bool lastButtonState[NUM_BUTTONS] = { HIGH };  // Array to store the last state of each button
  bool buttonState;                                     // Variable to store the current state of each button

  // Check each button and play a random tone if its state changes from HIGH to LOW
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttonState = digitalRead(BUTTON_PINS[i]);  // Read the current state of the button

    // Check if the button state changed from HIGH to LOW
    if (buttonState == LOW && lastButtonState[i] == HIGH) {
      // Turn on the LED
      digitalWrite(LED_PIN, HIGH);
      // Generate a random frequency between 100 and 1000 Hz
      int randomFreq = random(400, 1000);
      // Play the random tone
      playTone(randomFreq);
      // Display the frequency on the OLED display
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Freq: ");
      display.println(randomFreq);
      display.display();
    }

    // Check if the button state changed from LOW to HIGH
    if (buttonState == HIGH && lastButtonState[i] == LOW) {
      // Turn off the LED
      digitalWrite(LED_PIN, LOW);
    }

    lastButtonState[i] = buttonState;  // Update the last button state
  }
}

// Function to play a tone at a given frequency
void playTone(int frequency) {
  speaker.play(frequency);  // Play the tone
  delay(400);               // Duration of the tone (adjust as needed)
  speaker.stop();           // Stop playing the tone
}
