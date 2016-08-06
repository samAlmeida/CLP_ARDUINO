String itensDoMenuPrincipal[] = {"Horario", "programa", "configurar", "testar"};
char button = 'n';
int savedDistance = 0;
int paginaDoMenuPrincipal = 0;
int maxpaginaDoMenuPrincipals = round(((sizeof(itensDoMenuPrincipal) / sizeof(String)) / 2) + .5);
int cursorPosition = 0;

// Creates 3 custom characters for the menu display
byte downArrow[8] = {
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b10101, // * * *
  0b01110, //  ***
  0b00100  //   *
};

byte upArrow[8] = {
  0b00100, //   *
  0b01110, //  ***
  0b10101, // * * *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100  //   *
};

byte menuCursor[8] = {
  B01000, //  *
  B00100, //   *
  B00010, //    *
  B00001, //     *
  B00010, //    *
  B00100, //   *
  B01000, //  *
  B00000  //
};

#include <Wire.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

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

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(0, menuCursor);
  lcd.createChar(1, upArrow);
  lcd.createChar(2, downArrow);
}

void loop() {
  mainMenuDraw();
  drawCursor();
  operateMainMenu();
}
void mainMenuDraw() {
  Serial.print(paginaDoMenuPrincipal);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(itensDoMenuPrincipal[paginaDoMenuPrincipal]);
  lcd.setCursor(1, 1);
  lcd.print(itensDoMenuPrincipal[paginaDoMenuPrincipal + 1]);
  if (paginaDoMenuPrincipal == 0) {
    lcd.setCursor(15, 1);
    lcd.write(byte(2));
  } else if (paginaDoMenuPrincipal > 0 and paginaDoMenuPrincipal < maxpaginaDoMenuPrincipals) {
    lcd.setCursor(15, 1);
    lcd.write(byte(2));
    lcd.setCursor(15, 0);
    lcd.write(byte(1));
  } else if (paginaDoMenuPrincipal == maxpaginaDoMenuPrincipals) {
    lcd.setCursor(15, 0);
    lcd.write(byte(1));
  }
}
void drawCursor() {
  for (int x = 0; x < 2; x++) {     // Erases current cursor
    lcd.setCursor(0, x);
    lcd.print(" ");
  }

  // The menu is set up to be progressive (paginaDoMenuPrincipal 0 = Item 1 & Item 2, paginaDoMenuPrincipal 1 = Item 2 & Item 3, paginaDoMenuPrincipal 2 = Item 3 & Item 4), so
  // in order to determine where the cursor should be you need to see if you are at an odd or even menu page and an odd or even cursor position.
  if (paginaDoMenuPrincipal % 2 == 0) {
    if (cursorPosition % 2 == 0) {  // If the menu page is even and the cursor position is even that means the cursor should be on line 1
      lcd.setCursor(0, 0);
      lcd.write(byte(0));
    }
    if (cursorPosition % 2 != 0) {  // Se a página de menu é o mesmo e a posição do cursor é estranho que significa que o cursor deve ser na linha 2
      lcd.setCursor(0, 1);
      lcd.write(byte(0));
    }
  }
  if (paginaDoMenuPrincipal % 2 != 0) {
    if (cursorPosition % 2 == 0) {  // Se a página de menu é ímpar e a posição do cursor é mesmo significa que o cursor deve estar na linha 2
      lcd.setCursor(0, 1);
      lcd.write(byte(0));
    }
    if (cursorPosition % 2 != 0) {  // Se a página de menu é ímpar e a posição do cursor é ímpar, o que significa que o cursor deve ser na linha 1
      lcd.setCursor(0, 0);
      lcd.write(byte(0));
    }
  }
}


void operateMainMenu() {
  int activeButton = 0;
  while (activeButton == 0) {
    button = 'n';
    button = customKeypad.getKey();
    switch (button) {
      case 'n': // Quando o botão retorna n nenhuma medida é tomada
        break;
      case 'o':  // Este caso será executado se for pressionado o botão "ok"
        button = 0;
        switch (cursorPosition) { // O caso selecionado aqui é dependente na qual página de menu você esta.
          case 0:
            menuItem1();
            break;
          case 1:
            menuItem2();
            break;
          case 2:
            menuItem3();
            break;
        }
        activeButton = 1;
        mainMenuDraw();
        drawCursor();
        break;
      case 'c':
        button = 'n';
        if (paginaDoMenuPrincipal == 0) {
          cursorPosition = cursorPosition - 1;
          cursorPosition = constrain(cursorPosition, 0, ((sizeof(itensDoMenuPrincipal) / sizeof(String)) - 1));
        }
        if (paginaDoMenuPrincipal % 2 == 0 and cursorPosition % 2 == 0) {
          paginaDoMenuPrincipal = paginaDoMenuPrincipal - 1;
          paginaDoMenuPrincipal = constrain(paginaDoMenuPrincipal, 0, maxpaginaDoMenuPrincipals);
        }

        if (paginaDoMenuPrincipal % 2 != 0 and cursorPosition % 2 != 0) {
          paginaDoMenuPrincipal = paginaDoMenuPrincipal - 1;
          paginaDoMenuPrincipal = constrain(paginaDoMenuPrincipal, 0, maxpaginaDoMenuPrincipals);
        }

        cursorPosition = cursorPosition - 1;
        cursorPosition = constrain(cursorPosition, 0, ((sizeof(itensDoMenuPrincipal) / sizeof(String)) - 1));

        mainMenuDraw();
        drawCursor();
        activeButton = 1;
        break;
      case 'b':
        button = 'n';
        if (paginaDoMenuPrincipal % 2 == 0 and cursorPosition % 2 != 0) {
          paginaDoMenuPrincipal = paginaDoMenuPrincipal + 1;
          paginaDoMenuPrincipal = constrain(paginaDoMenuPrincipal, 0, maxpaginaDoMenuPrincipals);
        }

        if (paginaDoMenuPrincipal % 2 != 0 and cursorPosition % 2 == 0) {
          paginaDoMenuPrincipal = paginaDoMenuPrincipal + 1;
          paginaDoMenuPrincipal = constrain(paginaDoMenuPrincipal, 0, maxpaginaDoMenuPrincipals);
        }

        cursorPosition = cursorPosition + 1;
        cursorPosition = constrain(cursorPosition, 0, ((sizeof(itensDoMenuPrincipal) / sizeof(String)) - 1));
        mainMenuDraw();
        drawCursor();
        activeButton = 1;
        break;
    }
  }
}
void menuItem1() { // Function executes when you select the 2nd item from main menu
  int activeButton = 0;

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Ajuste hr");
  while (activeButton == 0) {
    char button  = 'n';
    button = customKeypad.getKey();
    switch (button) {
      case 'v':  // Este caso será executado se for pressionado o botão "voltar"
        button = 'n';
        activeButton = 1;
        break;

    }
  }
}

void menuItem2() { // Function executes when you select the 2nd item from main menu
  int activeButton = 0;

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("programa 1");

  while (activeButton == 0) {
    char button = 'n';
    button = customKeypad.getKey();
    switch (button) {
      case 'v':  // Este caso será executado se for pressionado o botão "voltar"
        button = 'n';
        activeButton = 1;
        break;
    }
  }
}

void menuItem3() { // Function executes when you select the 3rd item from main menu
  int activeButton = 0;

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("configurar");

  while (activeButton == 0) {
    char button = 'n';
    button = customKeypad.getKey();
    switch (button) {
      case 'v':  // Este caso será executado se for pressionado o botão "voltar"
        button = 'n';
        activeButton = 1;
        break;
    }
  }
}


