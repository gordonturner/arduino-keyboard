#include <Keyboard.h>

/* 
  Arduino Keyboard
  ================
 
  Processing code for Ardunio Micro to send a text string when a button is pressed.
  
  - Adapted by Gordon Turner from code by Tom Igoe.
  - Reference:
      TODO: Include url
  
  - NOTE: Please be careful what the device is plugged into and what has focus, or bad things can happen.
  
 */

// OSX:
char ctrlKey = KEY_LEFT_GUI;

// Windows and Linux:
//char ctrlKey = KEY_LEFT_CTRL;  

// 
const int button1Pin = 2;

// 
const int button2Pin = 3;

// 
const int button3Pin = 4;

// 
const int button4Pin = 5;

// 
const int button5Pin = 6;

// Storing previous state of button1
int previousButton1State = HIGH;

// Storing previous state of button2
int previousButton2State = HIGH;

// Storing previous state of button3
int previousButton3State = HIGH;

// Storing previous state of button4
int previousButton4State = HIGH;

// Storing previous state of button5
int previousButton5State = HIGH;
 
// Pin 13 has an LED connected on most Arduino boards
int led = 13;


void setup() 
{ 
  // Set the screen toggle push button pin as an input
  pinMode(button1Pin, INPUT_PULLUP);
  
  // Set the screen toggle push button pin as an input
  pinMode(button2Pin, INPUT_PULLUP);
  
  // Set the screen toggle push button pin as an input
  pinMode(button3Pin, INPUT_PULLUP);
  
  // Set the screen toggle push button pin as an input
  pinMode(button4Pin, INPUT_PULLUP);
  
  // Set the screen toggle push button pin as an input
  pinMode(button5Pin, INPUT_PULLUP);
  
  // Set the led pin as an output
  pinMode(led, OUTPUT);
  
  // Start up the keyboard
  Keyboard.begin();
}


void loop() 
{  

  //
  // Button 1
  //

  // Read the refresh push button.
  int button1State = digitalRead(button1Pin);

  // If the refresh button state has changed.
  if ((button1State != previousButton1State) && (button1State == HIGH)) 
  {
    // Turn the led on to indicate button press processed and key combination sent.
    digitalWrite(led, HIGH);

    Serial.println("button1 pressed");

    // Call function to send the keypress
    refreshBrowser();

    digitalWrite(led, LOW);
  }
  
  // Save the current button state to debounce
  previousButton1State = button1State;


  //
  // Button 2
  //

  // Read the refresh push button
  int button2State = digitalRead(button2Pin);

  // If the refresh button state has changed
  if ((button2State != previousButton2State) && (button2State == HIGH)) 
  {
    // Turn the led on to indicate button press processed and key combination sent.
    digitalWrite(led, HIGH);

    Serial.println("button2 pressed");

    // Call function to send the keypress
    toggleMicrophone();

    digitalWrite(led, LOW);
  }
  
  // Save the current button state to debounce
  previousButton2State = button2State;


  //
  // Button 3
  //

  // Read the refresh push button
  int button3State = digitalRead(button3Pin);

  // If the refresh button state has changed
  if ((button3State != previousButton3State) && (button3State == HIGH)) 
  {
    // Turn the led on to indicate button press processed and key combination sent.
    digitalWrite(led, HIGH);

    Serial.println("button3 pressed");

    // Call function to send the keypress
    toggleVideo();

    digitalWrite(led, LOW);
  }
  
  // Save the current button state to debounce
  previousButton3State = button3State;


  //
  // Button 4
  //

  // Read the refresh push button
  int button4State = digitalRead(button4Pin);

  // If the refresh button state has changed
  if ((button4State != previousButton4State) && (button4State == HIGH)) 
  {
    // Turn the led on to indicate button press processed and key combination sent.
    digitalWrite(led, HIGH);

    Serial.println("button4 pressed");

    // Call function to send the keypress
    hangUp();

    digitalWrite(led, LOW);
  }
  
  // Save the current button state to debounce
  previousButton4State = button4State;


  //
  // Button 5
  //

  // Read the refresh push button
  int button5State = digitalRead(button5Pin);

  // If the refresh button state has changed
  if ((button5State != previousButton5State) && (button5State == HIGH)) 
  {
    // Turn the led on to indicate button press processed and key combination sent.
    digitalWrite(led, HIGH);

    Serial.println("button5 pressed");

    // Call function to send the keypress
    //toggleMicrophone();

    digitalWrite(led, LOW);
  }
  
  // Save the current button state to debounce
  previousButton5State = button5State;
}

/*
 * 
 */
void toggleMicrophone()
{
  // MS Teams, toggle microphone: Command+Shift+m
  Keyboard.press(ctrlKey);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('m');
  delay(50);
  Keyboard.releaseAll();
}

/*
 * 
 */
void toggleVideo()
{
  // MS Teams, toggle video: Command+Shift+o
  Keyboard.press(ctrlKey);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('o');
  delay(50);
  Keyboard.releaseAll();
}

/*
 * 
 */
void hangUp()
{
  // MS Teams, toggle video: Command+Shift+b
  Keyboard.press(ctrlKey);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('b');
  delay(50);
  Keyboard.releaseAll();
}

/*
 * 
 */
void acceptAudioCall()
{
  // MS Teams, accept audio call: Command+Shift+s
}

/*
 * 
 */
void acceptVideoCall()
{
  // MS Teams, accept video call: Command+Shift+a  
}

/*
 * 
 */
void declineCall()
{
  // MS Teams, decline call: Command+Shift+d
}

/*
 * This should refresh most browsers.
 */
void refreshBrowser()
{
  // Send a control-r key combination.
  Keyboard.press(ctrlKey);
  Keyboard.press('r');
  delay(50);
  Keyboard.releaseAll();
}


/*
 * The following sends a 'device' on, off and toggle using either Windows key and 0, 1 or 2.
 * 
 * Ideally this will work in a desktop environment where those 3 three key combinations can be mapped to a script.
 */


void deviceOff() 
{
  Serial.println("Sending device off");
    
  // Send a WINDOWS-0 key combination.
  //  Keyboard.press(KEY_LEFT_GUI);
  //  Keyboard.press('0');
  
  // Send Control 0
  Keyboard.press(ctrlKey);
  Keyboard.press('0');
  delay(50);
  Keyboard.releaseAll();  
}


void deviceOn() 
{
  Serial.println("Sending device on");
    
  // Send a WINDOWS-1 key combination.
  //  Keyboard.press(KEY_LEFT_GUI);
  //  Keyboard.press('1');
  
  // Send Control 1
  Keyboard.press(ctrlKey);
  Keyboard.press('1');
  delay(50);
  Keyboard.releaseAll();  
}


void deviceToggle() 
{
  Serial.println("Sending device toggle");
    
  // Send a WINDOWS-3 key combination.
  //  Keyboard.press(KEY_LEFT_GUI);
  //  Keyboard.press('3');
  // Send Control 2
  Keyboard.press(ctrlKey);
  Keyboard.press('2');
  delay(50);
  Keyboard.releaseAll();  
}
