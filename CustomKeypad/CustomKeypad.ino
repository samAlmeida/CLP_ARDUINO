/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);

const byte ROWS = 6; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','a'},
  {'b','c','e','d'},
  {'7','8','9','k'},
  {'o','0','#','d'},
  {'e','f','v','h'},
  {'i','j','k','l'}
};
byte rowPins[ROWS] = {9, 10, 11, 12, 14, 15}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {16, 17, 18, 19}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    lcd.print(customKey);
    if(customKey == '1'){
      lcd.clear();
    }
  }
}
