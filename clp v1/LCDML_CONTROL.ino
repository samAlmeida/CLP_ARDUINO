// =====================================================================
//
// CONTROL
//
// =====================================================================
// *********************************************************************
// *********************************************************************
// content:
// (0) Control over serial interface
// (1) Control over one analog input 
// (2) Control over 4 - 6 digital input pins (internal pullups enabled)
// (3) Control over encoder (internal pullups enabled)
// (4) Control with Keypad
// *********************************************************************

#define _LCDML_CONTROL_cfg      4  // serial

//#define _LCDML_CONTROL_cfg    1  // analog
//#define _LCDML_CONTROL_cfg    2  // digital
//#define _LCDML_CONTROL_cfg    3  // encoder
//#define _LCDML_CONTROL_cfg    4  // keypad

// therory:
// "#if" is a preprocessor directive and no error, look here:
// (english) https://en.wikipedia.org/wiki/C_preprocessor
// (german)  https://de.wikipedia.org/wiki/C-Pr%C3%A4prozessor


// *********************************************************************
// CONTROL TASK, DO NOT CHANGE
// *********************************************************************
void LCDML_BACK_setup(LCDML_BACKEND_control)      
// *********************************************************************
{
  // call setup   
  LCDML_CONTROL_setup();      
}
// backend loop
boolean LCDML_BACK_loop(LCDML_BACKEND_control)
{    
  // call loop
  LCDML_CONTROL_loop();

  // go to next backend function and do not block it
  return true;  
}
// backend stop stable
void LCDML_BACK_stable(LCDML_BACKEND_control)
{
}




// *********************************************************************
// *************** (0) CONTROL OVER SERIAL INTERFACE *******************
// *********************************************************************
#if(_LCDML_CONTROL_cfg == 0)
// settings
  # define _LCDML_CONTROL_serial_enter           'e'
  # define _LCDML_CONTROL_serial_up              'w'
  # define _LCDML_CONTROL_serial_down            's'
  # define _LCDML_CONTROL_serial_left            'a'
  # define _LCDML_CONTROL_serial_right           'd'
  # define _LCDML_CONTROL_serial_quit            'q'
// *********************************************************************
// setup
void LCDML_CONTROL_setup()
{
}
// *********************************************************************
// loop
void LCDML_CONTROL_loop()
{
  // check if new serial input is available  
  if (Serial.available()) {
    // read one char from input buffer   
    switch (Serial.read())
    {
      case _LCDML_CONTROL_serial_enter:  LCDML_BUTTON_enter(); break;
      case _LCDML_CONTROL_serial_up:     LCDML_BUTTON_up();    break;
      case _LCDML_CONTROL_serial_down:   LCDML_BUTTON_down();  break;
      case _LCDML_CONTROL_serial_left:   LCDML_BUTTON_left();  break;
      case _LCDML_CONTROL_serial_right:  LCDML_BUTTON_right(); break;
      case _LCDML_CONTROL_serial_quit:   LCDML_BUTTON_quit();  break;
      default: break;
    } 
  }
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************






#elif(_LCDML_CONTROL_cfg == 4)
// include
  // more information under http://playground.arduino.cc/Main/KeypadTutorial

#include "src/Key.h"
#include "src/Keypad.h"

// settings
  #define _LCDML_CONTROL_keypad_rows 6 // Four rows
  #define _LCDML_CONTROL_keypad_cols 4 // Three columns
// global vars
  char keys[_LCDML_CONTROL_keypad_rows][_LCDML_CONTROL_keypad_cols] = { 
  {'1','2','3','a'},
  {'c','b','e','d'},
  {'7','8','9','k'},
  {'o','0','#','d'},
  {'e','f','v','h'},
  {'i','j','k','l'}
  };  
  byte rowPins[_LCDML_CONTROL_keypad_rows] = {9, 10, 11, 12, 14, 15};  // Connect keypad COL0, COL1 and COL2 to these Arduino pins.
  byte colPins[_LCDML_CONTROL_keypad_cols] = {16, 17, 18, 19};  // Create the Keypad
// objects
  Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, _LCDML_CONTROL_keypad_rows, _LCDML_CONTROL_keypad_cols );
// *********************************************************************
// setup
void LCDML_CONTROL_setup()
{
}
// *********************************************************************
// loop
void LCDML_CONTROL_loop()
{    
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case 'o': LCDML_BUTTON_enter(); break;
      case 'c': LCDML_BUTTON_up();    break;
      case 'b': LCDML_BUTTON_down();  break;
      case 'e': LCDML_BUTTON_left();  break;
      case 'd': LCDML_BUTTON_right(); break;
      case 'v': LCDML_BUTTON_quit();  break;
      default: break;       
    }
  } 
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************

#else
  #error _LCDML_CONTROL_cfg is not defined or not in range
#endif

