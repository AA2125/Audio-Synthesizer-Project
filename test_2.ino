#include <Tone.h>  // Include the Tone library

// Define the pins for the buttons
//const int DO_BUTTON_PIN = 2;
const int RE_BUTTON_PIN = 3;
const int MI_BUTTON_PIN = 4;
const int FA_BUTTON_PIN = 5;
const int SOL_BUTTON_PIN = 6;

//const int LA_BUTTON_PIN = 10;
//const int TI_BUTTON_PIN = 11;
//const int DO_HIGH_BUTTON_PIN = 12;

// Define the pin for the speaker
//const int SPEAKER_PIN = 8;

// Define the frequencies for Do, Re, Mi, Fa, Sol, La, Ti
const int DO_FREQ = 262;   // Frequency of Do (C)
const int RE_FREQ = 294;   // Frequency of Re (D)
const int MI_FREQ = 330;   // Frequency of Mi (E)
const int FA_FREQ = 349;   // Frequency of Fa (F)
const int SOL_FREQ = 392;  // Frequency of Sol (G)
const int LA_FREQ = 220;   // Frequency of La (A)
const int TI_FREQ = 247;   // Frequency of Ti (B)

void setup() {
  // Initialize the serial communication for debugging
  Serial.begin(9600);

  // initialise the speakers pins
 // pinMode(SPEAKER_PIN, OUTPUT);

  // Initialize the button pins as inputs with pull-up resistors
  pinMode(2,INPUT);//do
  pinMode(3,INPUT);//re
  pinMode(4,INPUT);//mi
  // pinMode(FA_BUTTON_PIN) ;//fa
  // pinMode(SOL_BUTTON_PIN);//sol
  // pinMode(LA_BUTTON_PIN);//la
  // pinMode(TI_BUTTON_PIN);//ti
  // pinMode(DO_HIGH_BUTTON_PIN);//do at a higher octave
}

void loop() {
  //Serial.print("HI");
  // Check each button and play the corresponding note if pressed
//  if (digitalRead(DO_BUTTON_PIN) == HIGH) {
   // playNote(DO_FREQ, 500);
  //  Serial.println("DO");
   // delay(200);
  //}
  if (digitalRead(RE_BUTTON_PIN) == HIGH) {
    //playNote(RE_FREQ, 500);
    Serial.println("RE");
    delay(200);
  }
  if (digitalRead(MI_BUTTON_PIN) == HIGH) {
   //playNote(MI_FREQ, 500);
    Serial.println("MI");
    delay(200);
  }
  if (digitalRead(FA_BUTTON_PIN) == HIGH) {
   //playNote(FA_FREQ, 500);
    Serial.print("FA");
    delay(200);
  }
  if (digitalRead(SOL_BUTTON_PIN) == HIGH) {
    //playNote(SOL_FREQ, 500);
    Serial.print("SOL");
    delay(200);
  }
  //if (digitalRead(LA_BUTTON_PIN) == LOW) {
  // playNote(LA_FREQ, 500);
    //Serial.print("LA");
    //delay(200);
  //}
  //if (digitalRead(TI_BUTTON_PIN) == LOW) {
    //playNote(TI_FREQ, 500);
    //Serial.print("TI");
    //delay(200);
  //}
  //if (digitalRead(DO_HIGH_BUTTON_PIN) == HIGH) {
    //playNote(DO_FREQ * 2, 500); // this plays a higher octave of the Do note
    //delay(200);
  //}

}

// // Function to play a note at a given frequency and duration
// void playNote(int frequency, int duration) {
//   tone(SPEAKER_PIN, frequency, duration);  // Play the note
//   delay(duration + 50);                    // Delay to avoid overlap between notes
// }
