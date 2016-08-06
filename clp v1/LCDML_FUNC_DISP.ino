uint8_t vh, vmi, vs = 0;
#define hour()    vh
#define minute()  vmi
#define second()  vs
#define setTime(h,mi,s) vh=h; vmi=mi; vs=s;;
uint8_t _pos = 0;
void atualizarH (int h, int m, int s){
  hour() = h;
  minute() = m;
  second() = s;
}
void HELP_FUNC_set_dat(int8_t l_i)
{

  switch (_pos)
  {
    case 0: setTime(hour() + l_i, minute(), second());  break; // hour
    case 1: setTime(hour(), minute() + l_i, second()); break; // mi

  }
  if (hour() == 24) {
    hour() = 0;
  }
  if (minute() == 60) {
    minute() = 0;
  }
  if (second() == 60) {
    second() = 0;
  }
  if (hour() == 255) {
    hour() = 23;
  }
  if (minute() == 255) {
    minute() = 59;
  }
  if (second() == 255) {
    second() = 59;
  }
}
void digitalClockDisplay() {
  lcd.setCursor(3, 0);
  printDigits(hour());
  lcd.print(":");
  if (_pos == 1) {
    lcd.print(" ");
  }
  printDigits(minute());
  lcd.print(":");
  printDigits(second());
  switch (_pos) {
    case 0: lcd.setCursor(2, 0); lcd.blink(); break; //hour
    case 1: lcd.setCursor(6, 0); lcd.blink(); break; //min
    default: lcd.noBlink(); break;
  }
}
void printDigits(int digits) {
  if (digits < 10) {
    lcd.print('0');
  }
  lcd.print(digits);
}
void LCDML_DISP_setup(LCDML_FUNC_change_datetime)
{
  digitalClockDisplay();
}
void LCDML_DISP_loop(LCDML_FUNC_change_datetime)
{
  if (LCDML_BUTTON_checkAny()) {
    if (LCDML_BUTTON_checkUp())    {
      HELP_FUNC_set_dat(+1);
      LCDML_BUTTON_resetUp();
    }
    if (LCDML_BUTTON_checkDown())  {
      HELP_FUNC_set_dat(-1);
      LCDML_BUTTON_resetDown();
    }
    if (LCDML_BUTTON_checkRight()) {
      _pos = (_pos + 1) % 5;
      LCDML_BUTTON_resetRight();
    }
    lcd.clear();
    digitalClockDisplay()  ;
  }

}
void LCDML_DISP_loop_end(LCDML_FUNC_change_datetime)
{
  tempo_ajustado(hour(), minute(), second());
  lcd.noBlink();
}





/*
     =============   ====    =====       =====   ==========   ========
     =============   ====    ======     ======   ==========   ==========
         ====                === ===   === ===   ===          ===    ====
         ====        ====    ===  === ===  ===   =======      ===   ====
         ====        ====    ===   =====   ===   ===          ===  ====
         ====        ====    ===           ===   ==========   ===    ====
         ====        ====    ===           ===   ==========   ===     ====
*/


//========================== Timer 0101 ===========================================
uint8_t vh0101, vmi0101, vs0101, vhff0101, vmff0101, vsff0101 = 0;
#define hora0101()    vh0101
#define minuto0101()  vmi0101
#define segundo0101()  vs0101
#define hora0101Off()     vhff0101
#define minuto0101Off()   vmff0101
#define segundo0101Off()    vsff0101
#define setTime0101(h0101,mi0101,s0101,hf0101,mf0101,sf0101) vh0101=h0101; vmi0101=mi0101; vs0101=s0101; vhff0101=hf0101; vmff0101=mf0101; vsff0101=sf0101;
uint8_t posicao_do_cursor0101 = 0;
void Conig_relogio0101(int8_t l_i)
{
  switch (posicao_do_cursor0101)
  {

    case 0: setTime0101(hora0101() + l_i, minuto0101(), segundo0101(), hora0101Off(), minuto0101Off(), segundo0101Off());  break; // hora0101
    case 1: setTime0101(hora0101(), minuto0101() + l_i, segundo0101(), hora0101Off(), minuto0101Off(), segundo0101Off()); break; // min
    case 2: setTime0101(hora0101(), minuto0101(), segundo0101(), hora0101Off() + l_i, minuto0101Off(), segundo0101Off()); break; // hora0101Off
    case 3: setTime0101(hora0101(), minuto0101(), segundo0101(), hora0101Off(), minuto0101Off() + l_i, segundo0101Off()); break; // minuto0101Off
  }
  if (hora0101() == 24) {
    hora0101() = 0;
  }
  if (minuto0101() == 60) {
    minuto0101() = 0;
  }
  if (segundo0101() == 60) {
    segundo0101() = 0;
  }
  if (hora0101() == 255) {
    hora0101() = 23;
  }
  if (minuto0101() == 255) {
    minuto0101() = 59;
  }
  if (segundo0101() == 255) {
    segundo0101() = 59;
  }
  if (hora0101Off() == 24) {
    hora0101Off() = 0;
  }
  if (minuto0101Off() == 60) {
    minuto0101Off() = 0;
  }
  if (segundo0101Off() == 60) {
    segundo0101Off() = 0;
  }
  if (hora0101Off() == 255) {
    hora0101Off() = 23;
  }
  if (minuto0101Off() == 255) {
    minuto0101Off() = 59;
  }
  if (segundo0101Off() == 255) {
    segundo0101Off() = 59;
  }
}
void Display0101() {
  lcd.print("ON");
  lcd.setCursor(5, 0);
  lcd.print(hora0101());
  lcd.print(":");
  if (posicao_do_cursor0101 == 1) {
    lcd.print(" ");
  }
  lcd.print(minuto0101());
  lcd.print(":");
  lcd.print(segundo0101());
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  lcd.setCursor(5, 1);
  lcd.print(hora0101Off());
  lcd.print(":");
  if (posicao_do_cursor0101 == 3) {
    lcd.print(" ");
  }
  lcd.print(minuto0101Off());
  lcd.print(":");
  if (posicao_do_cursor0101 == 4) {
    lcd.print(" ");
  }
  lcd.print(segundo0101Off());
  switch (posicao_do_cursor0101) {
    case 0: lcd.setCursor(4, 0); lcd.blink(); break; //hora0101
    case 1: lcd.setCursor(7, 0); lcd.blink(); break; //min
    case 2: lcd.setCursor(4, 1); lcd.blink(); break; //hora0101Off
    case 3: lcd.setCursor(7 + ((hora0101Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //minuto0101Off
    case 4: lcd.setCursor(9 + ((hora0101Off() < 10) ? 0 : 1) + ((minuto0101Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //segundo0101Off
    default: lcd.noBlink(); break;
  }
}
//========================== Fim  Timer 0101 ===========================================

//========================== Timer 0102 ===========================================
uint8_t vh0102, vmi0102, vs0102, vhff0102, vmff0102, vsff0102 = 0;
#define hora0102()    vh0102
#define minuto0102()  vmi0102
#define segundo0102()  vs0102
#define hora0102Off()     vhff0102
#define minuto0102Off()   vmff0102
#define segundo0102Off()    vsff0102
#define setTime0102(h0102,mi0102,s0102,hf0102,mf0102,sf0102) vh0102=h0102; vmi0102=mi0102; vs0102=s0102; vhff0102=hf0102; vmff0102=mf0102; vsff0102=sf0102;
uint8_t posicao_do_cursor0102 = 0;
void Conig_relogio0102(int8_t l_i)
{
  switch (posicao_do_cursor0102)
  {
    case 0: setTime0102(hora0102() + l_i, minuto0102(), segundo0102(), hora0102Off(), minuto0102Off(), segundo0102Off());  break; // hora0102
    case 1: setTime0102(hora0102(), minuto0102() + l_i, segundo0102(), hora0102Off(), minuto0102Off(), segundo0102Off()); break; // min
    case 2: setTime0102(hora0102(), minuto0102(), segundo0102(), hora0102Off() + l_i, minuto0102Off(), segundo0102Off()); break; // hora0102Off
    case 3: setTime0102(hora0102(), minuto0102(), segundo0102(), hora0102Off(), minuto0102Off() + l_i, segundo0102Off()); break; // minuto0102Off
  }
}
void Display0102() {
  lcd.print("ON");
  lcd.setCursor(5, 0);
  lcd.print(hora0102());
  lcd.print(":");
  if (posicao_do_cursor0102 == 1) {
    lcd.print(" ");
  }
  lcd.print(minuto0102());
  lcd.print(":");
  lcd.print(segundo0102());
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  lcd.setCursor(5, 1);
  lcd.print(hora0102Off());
  lcd.print(":");
  if (posicao_do_cursor0102 == 3) {
    lcd.print(" ");
  }
  lcd.print(minuto0102Off());
  lcd.print(":");
  if (posicao_do_cursor0102 == 4) {
    lcd.print(" ");
  }
  lcd.print(segundo0102Off());
  switch (posicao_do_cursor0102) {
    case 0: lcd.setCursor(4, 0); lcd.blink(); break; //hora0102
    case 1: lcd.setCursor(7, 0); lcd.blink(); break; //min
    case 2: lcd.setCursor(4, 1); lcd.blink(); break; //hora0102Off
    case 3: lcd.setCursor(7 + ((hora0102Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //minuto0102Off
    case 4: lcd.setCursor(9 + ((hora0102Off() < 10) ? 0 : 1) + ((minuto0102Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //segundo0102Off
    default: lcd.noBlink(); break;
  }
}
//========================== Fim  Timer 0102 ===========================================



//========================== Timer 0201 ===========================================
uint8_t vh0201, vmi0201, vs0201, vhff0201, vmff0201, vsff0201 = 0;
#define hora0201()    vh0201
#define minuto0201()  vmi0201
#define segundo0201()  vs0201
#define hora0201Off()     vhff0201
#define minuto0201Off()   vmff0201
#define segundo0201Off()    vsff0201
#define setTime0201(h0201,mi0201,s0201,hf0201,mf0201,sf0201) vh0201=h0201; vmi0201=mi0201; vs0201=s0201; vhff0201=hf0201; vmff0201=mf0201; vsff0201=sf0201;
uint8_t posicao_do_cursor0201 = 0;
void Conig_relogio0201(int8_t l_i)
{
  switch (posicao_do_cursor0201)
  {
    case 0: setTime0201(hora0201() + l_i, minuto0201(), segundo0201(), hora0201Off(), minuto0201Off(), segundo0201Off());  break; // hora0201
    case 1: setTime0201(hora0201(), minuto0201() + l_i, segundo0201(), hora0201Off(), minuto0201Off(), segundo0201Off()); break; // min
    case 2: setTime0201(hora0201(), minuto0201(), segundo0201(), hora0201Off() + l_i, minuto0201Off(), segundo0201Off()); break; // hora0201Off
    case 3: setTime0201(hora0201(), minuto0201(), segundo0201(), hora0201Off(), minuto0201Off() + l_i, segundo0201Off()); break; // minuto0201Off
  }
}
void Display0201() {
  lcd.print("ON");
  lcd.setCursor(5, 0);
  lcd.print(hora0201());
  lcd.print(":");
  if (posicao_do_cursor0201 == 1) {
    lcd.print(" ");
  }
  lcd.print(minuto0201());
  lcd.print(":");
  lcd.print(segundo0201());
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  lcd.setCursor(5, 1);
  lcd.print(hora0201Off());
  lcd.print(":");
  if (posicao_do_cursor0201 == 3) {
    lcd.print(" ");
  }
  lcd.print(minuto0201Off());
  lcd.print(":");
  if (posicao_do_cursor0201 == 4) {
    lcd.print(" ");
  }
  lcd.print(segundo0201Off());
  switch (posicao_do_cursor0201) {
    case 0: lcd.setCursor(4, 0); lcd.blink(); break; //hora0201
    case 1: lcd.setCursor(7, 0); lcd.blink(); break; //min
    case 2: lcd.setCursor(4, 1); lcd.blink(); break; //hora0201Off
    case 3: lcd.setCursor(7 + ((hora0201Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //minuto0201Off
    case 4: lcd.setCursor(9 + ((hora0201Off() < 10) ? 0 : 1) + ((minuto0201Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //segundo0201Off
    default: lcd.noBlink(); break;
  }
}
//========================== Fim  Timer 0201 ===========================================
//========================== Timer 0202 ===========================================
uint8_t vh0202, vmi0202, vs0202, vhff0202, vmff0202, vsff0202 = 0;
#define hora0202()    vh0202
#define minuto0202()  vmi0202
#define segundo0202()  vs0202
#define hora0202Off()     vhff0202
#define minuto0202Off()   vmff0202
#define segundo0202Off()    vsff0202
#define setTime0202(h0202,mi0202,s0202,hf0202,mf0202,sf0202) vh0202=h0202; vmi0202=mi0202; vs0202=s0202; vhff0202=hf0202; vmff0202=mf0202; vsff0202=sf0202;
uint8_t posicao_do_cursor0202 = 0;
void Conig_relogio0202(int8_t l_i)
{
  switch (posicao_do_cursor0202)
  {

    case 0: setTime0202(hora0202() + l_i, minuto0202(), segundo0202(), hora0202Off(), minuto0202Off(), segundo0202Off());  break; // hora0202
    case 1: setTime0202(hora0202(), minuto0202() + l_i, segundo0202(), hora0202Off(), minuto0202Off(), segundo0202Off()); break; // min
    case 2: setTime0202(hora0202(), minuto0202(), segundo0202(), hora0202Off() + l_i, minuto0202Off(), segundo0202Off()); break; // hora0202Off
    case 3: setTime0202(hora0202(), minuto0202(), segundo0202(), hora0202Off(), minuto0202Off() + l_i, segundo0202Off()); break; // minuto0202Off
  }
  if (hora0202() == 24) {
    hora0202() = 0;
  }
  if (minuto0202() == 60) {
    minuto0202() = 0;
  }
  if (segundo0202() == 60) {
    segundo0202() = 0;
  }
  if (hora0202() == 255) {
    hora0202() = 23;
  }
  if (minuto0202() == 255) {
    minuto0202() = 59;
  }
  if (segundo0202() == 255) {
    segundo0202() = 59;
  }
  if (hora0202Off() == 24) {
    hora0202Off() = 0;
  }
  if (minuto0202Off() == 60) {
    minuto0202Off() = 0;
  }
  if (segundo0202Off() == 60) {
    segundo0202Off() = 0;
  }
  if (hora0202Off() == 255) {
    hora0202Off() = 23;
  }
  if (minuto0202Off() == 255) {
    minuto0202Off() = 59;
  }
  if (segundo0202Off() == 255) {
    segundo0202Off() = 59;
  }
}
void Display0202() {
  lcd.print("ON");
  lcd.setCursor(5, 0);
  lcd.print(hora0202());
  lcd.print(":");
  if (posicao_do_cursor0202 == 1) {
    lcd.print(" ");
  }
  lcd.print(minuto0202());
  lcd.print(":");
  lcd.print(segundo0202());
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  lcd.setCursor(5, 1);
  lcd.print(hora0202Off());
  lcd.print(":");
  if (posicao_do_cursor0202 == 3) {
    lcd.print(" ");
  }
  lcd.print(minuto0202Off());
  lcd.print(":");
  if (posicao_do_cursor0202 == 4) {
    lcd.print(" ");
  }
  lcd.print(segundo0202Off());
  switch (posicao_do_cursor0202) {
    case 0: lcd.setCursor(4, 0); lcd.blink(); break; //hora0202
    case 1: lcd.setCursor(7, 0); lcd.blink(); break; //min
    case 2: lcd.setCursor(4, 1); lcd.blink(); break; //hora0202Off
    case 3: lcd.setCursor(7 + ((hora0202Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //minuto0202Off
    case 4: lcd.setCursor(9 + ((hora0202Off() < 10) ? 0 : 1) + ((minuto0202Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //segundo0202Off
    default: lcd.noBlink(); break;
  }
}
//========================== Fim  Timer 0202 ===========================================


//========================== Timer 0301 ===========================================
uint8_t vh0301, vmi0301, vs0301, vhff0301, vmff0301, vsff0301 = 0;
#define hora0301()    vh0301
#define minuto0301()  vmi0301
#define segundo0301()  vs0301
#define hora0301Off()     vhff0301
#define minuto0301Off()   vmff0301
#define segundo0301Off()    vsff0301
#define setTime0301(h0301,mi0301,s0301,hf0301,mf0301,sf0301) vh0301=h0301; vmi0301=mi0301; vs0301=s0301; vhff0301=hf0301; vmff0301=mf0301; vsff0301=sf0301;
uint8_t posicao_do_cursor0301 = 0;
void Conig_relogio0301(int8_t l_i)
{
  switch (posicao_do_cursor0301)
  {

    case 0: setTime0301(hora0301() + l_i, minuto0301(), segundo0301(), hora0301Off(), minuto0301Off(), segundo0301Off());  break; // hora0301
    case 1: setTime0301(hora0301(), minuto0301() + l_i, segundo0301(), hora0301Off(), minuto0301Off(), segundo0301Off()); break; // min
    case 2: setTime0301(hora0301(), minuto0301(), segundo0301(), hora0301Off() + l_i, minuto0301Off(), segundo0301Off()); break; // hora0301Off
    case 3: setTime0301(hora0301(), minuto0301(), segundo0301(), hora0301Off(), minuto0301Off() + l_i, segundo0301Off()); break; // minuto0301Off
  }
  if (hora0301() == 24) {
    hora0301() = 0;
  }
  if (minuto0301() == 60) {
    minuto0301() = 0;
  }
  if (segundo0301() == 60) {
    segundo0301() = 0;
  }
  if (hora0301() == 255) {
    hora0301() = 23;
  }
  if (minuto0301() == 255) {
    minuto0301() = 59;
  }
  if (segundo0301() == 255) {
    segundo0301() = 59;
  }
  if (hora0301Off() == 24) {
    hora0301Off() = 0;
  }
  if (minuto0301Off() == 60) {
    minuto0301Off() = 0;
  }
  if (segundo0301Off() == 60) {
    segundo0301Off() = 0;
  }
  if (hora0301Off() == 255) {
    hora0301Off() = 23;
  }
  if (minuto0301Off() == 255) {
    minuto0301Off() = 59;
  }
  if (segundo0301Off() == 255) {
    segundo0301Off() = 59;
  }
}
void Display0301() {
  lcd.print("ON");
  lcd.setCursor(5, 0);
  lcd.print(hora0301());
  lcd.print(":");
  if (posicao_do_cursor0301 == 1) {
    lcd.print(" ");
  }
  lcd.print(minuto0301());
  lcd.print(":");
  lcd.print(segundo0301());
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  lcd.setCursor(5, 1);
  lcd.print(hora0301Off());
  lcd.print(":");
  if (posicao_do_cursor0301 == 3) {
    lcd.print(" ");
  }
  lcd.print(minuto0301Off());
  lcd.print(":");
  if (posicao_do_cursor0301 == 4) {
    lcd.print(" ");
  }
  lcd.print(segundo0301Off());
  switch (posicao_do_cursor0301) {
    case 0: lcd.setCursor(4, 0); lcd.blink(); break; //hora0301
    case 1: lcd.setCursor(7, 0); lcd.blink(); break; //min
    case 2: lcd.setCursor(4, 1); lcd.blink(); break; //hora0301Off
    case 3: lcd.setCursor(7 + ((hora0301Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //minuto0301Off
    case 4: lcd.setCursor(9 + ((hora0301Off() < 10) ? 0 : 1) + ((minuto0301Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //segundo0301Off
    default: lcd.noBlink(); break;
  }
}
//========================== Fim  Timer 0301 ===========================================

//========================== Timer 0302 ===========================================
uint8_t vh0302, vmi0302, vs0302, vhff0302, vmff0302, vsff0302 = 0;
#define hora0302()    vh0302
#define minuto0302()  vmi0302
#define segundo0302()  vs0302
#define hora0302Off()     vhff0302
#define minuto0302Off()   vmff0302
#define segundo0302Off()    vsff0302
#define setTime0302(h0302,mi0302,s0302,hf0302,mf0302,sf0302) vh0302=h0302; vmi0302=mi0302; vs0302=s0302; vhff0302=hf0302; vmff0302=mf0302; vsff0302=sf0302;
uint8_t posicao_do_cursor0302 = 0;
void Conig_relogio0302(int8_t l_i)
{
  switch (posicao_do_cursor0302)
  {

    case 0: setTime0302(hora0302() + l_i, minuto0302(), segundo0302(), hora0302Off(), minuto0302Off(), segundo0302Off());  break; // hora0302
    case 1: setTime0302(hora0302(), minuto0302() + l_i, segundo0302(), hora0302Off(), minuto0302Off(), segundo0302Off()); break; // min
    case 2: setTime0302(hora0302(), minuto0302(), segundo0302(), hora0302Off() + l_i, minuto0302Off(), segundo0302Off()); break; // hora0302Off
    case 3: setTime0302(hora0302(), minuto0302(), segundo0302(), hora0302Off(), minuto0302Off() + l_i, segundo0302Off()); break; // minuto0302Off
  }
  if (hora0302() == 24) {
    hora0302() = 0;
  }
  if (minuto0302() == 60) {
    minuto0302() = 0;
  }
  if (segundo0302() == 60) {
    segundo0302() = 0;
  }
  if (hora0302() == 255) {
    hora0302() = 23;
  }
  if (minuto0302() == 255) {
    minuto0302() = 59;
  }
  if (segundo0302() == 255) {
    segundo0302() = 59;
  }
  if (hora0302Off() == 24) {
    hora0302Off() = 0;
  }
  if (minuto0302Off() == 60) {
    minuto0302Off() = 0;
  }
  if (segundo0302Off() == 60) {
    segundo0302Off() = 0;
  }
  if (hora0302Off() == 255) {
    hora0302Off() = 23;
  }
  if (minuto0302Off() == 255) {
    minuto0302Off() = 59;
  }
  if (segundo0302Off() == 255) {
    segundo0302Off() = 59;
  }
}
void Display0302() {
  lcd.print("ON");
  lcd.setCursor(5, 0);
  lcd.print(hora0302());
  lcd.print(":");
  if (posicao_do_cursor0302 == 1) {
    lcd.print(" ");
  }
  lcd.print(minuto0302());
  lcd.print(":");
  lcd.print(segundo0302());
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  lcd.setCursor(5, 1);
  lcd.print(hora0302Off());
  lcd.print(":");
  if (posicao_do_cursor0302 == 3) {
    lcd.print(" ");
  }
  lcd.print(minuto0302Off());
  lcd.print(":");
  if (posicao_do_cursor0302 == 4) {
    lcd.print(" ");
  }
  lcd.print(segundo0302Off());
  switch (posicao_do_cursor0302) {
    case 0: lcd.setCursor(4, 0); lcd.blink(); break; //hora0302
    case 1: lcd.setCursor(7, 0); lcd.blink(); break; //min
    case 2: lcd.setCursor(4, 1); lcd.blink(); break; //hora0302Off
    case 3: lcd.setCursor(7 + ((hora0302Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //minuto0302Off
    case 4: lcd.setCursor(9 + ((hora0302Off() < 10) ? 0 : 1) + ((minuto0302Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //segundo0302Off
    default: lcd.noBlink(); break;
  }
}
//========================== Fim  Timer 0302 ===========================================



//========================== Timer 0401 ===========================================
uint8_t vh0401, vmi0401, vs0401, vhff0401, vmff0401, vsff0401 = 0;
#define hora0401()    vh0401
#define minuto0401()  vmi0401
#define segundo0401()  vs0401
#define hora0401Off()     vhff0401
#define minuto0401Off()   vmff0401
#define segundo0401Off()    vsff0401
#define setTime0401(h0401,mi0401,s0401,hf0401,mf0401,sf0401) vh0401=h0401; vmi0401=mi0401; vs0401=s0401; vhff0401=hf0401; vmff0401=mf0401; vsff0401=sf0401;
uint8_t posicao_do_cursor0401 = 0;
void Conig_relogio0401(int8_t l_i)
{
  switch (posicao_do_cursor0401)
  {

    case 0: setTime0401(hora0401() + l_i, minuto0401(), segundo0401(), hora0401Off(), minuto0401Off(), segundo0401Off());  break; // hora0401
    case 1: setTime0401(hora0401(), minuto0401() + l_i, segundo0401(), hora0401Off(), minuto0401Off(), segundo0401Off()); break; // min
    case 2: setTime0401(hora0401(), minuto0401(), segundo0401(), hora0401Off() + l_i, minuto0401Off(), segundo0401Off()); break; // hora0401Off
    case 3: setTime0401(hora0401(), minuto0401(), segundo0401(), hora0401Off(), minuto0401Off() + l_i, segundo0401Off()); break; // minuto0401Off
  }
  if (hora0401() == 24) {
    hora0401() = 0;
  }
  if (minuto0401() == 60) {
    minuto0401() = 0;
  }
  if (segundo0401() == 60) {
    segundo0401() = 0;
  }
  if (hora0401() == 255) {
    hora0401() = 23;
  }
  if (minuto0401() == 255) {
    minuto0401() = 59;
  }
  if (segundo0401() == 255) {
    segundo0401() = 59;
  }
  if (hora0401Off() == 24) {
    hora0401Off() = 0;
  }
  if (minuto0401Off() == 60) {
    minuto0401Off() = 0;
  }
  if (segundo0401Off() == 60) {
    segundo0401Off() = 0;
  }
  if (hora0401Off() == 255) {
    hora0401Off() = 23;
  }
  if (minuto0401Off() == 255) {
    minuto0401Off() = 59;
  }
  if (segundo0401Off() == 255) {
    segundo0401Off() = 59;
  }
}
void Display0401() {
  lcd.print("ON");
  lcd.setCursor(5, 0);
  lcd.print(hora0401());
  lcd.print(":");
  if (posicao_do_cursor0401 == 1) {
    lcd.print(" ");
  }
  lcd.print(minuto0401());
  lcd.print(":");
  lcd.print(segundo0401());
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  lcd.setCursor(5, 1);
  lcd.print(hora0401Off());
  lcd.print(":");
  if (posicao_do_cursor0401 == 3) {
    lcd.print(" ");
  }
  lcd.print(minuto0401Off());
  lcd.print(":");
  if (posicao_do_cursor0401 == 4) {
    lcd.print(" ");
  }
  lcd.print(segundo0401Off());
  switch (posicao_do_cursor0401) {
    case 0: lcd.setCursor(4, 0); lcd.blink(); break; //hora0401
    case 1: lcd.setCursor(7, 0); lcd.blink(); break; //min
    case 2: lcd.setCursor(4, 1); lcd.blink(); break; //hora0401Off
    case 3: lcd.setCursor(7 + ((hora0401Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //minuto0401Off
    case 4: lcd.setCursor(9 + ((hora0401Off() < 10) ? 0 : 1) + ((minuto0401Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //segundo0401Off
    default: lcd.noBlink(); break;
  }
}
//========================== Fim  Timer 0401 ===========================================
//========================== Timer 0402 ===========================================
uint8_t vh0402, vmi0402, vs0402, vhff0402, vmff0402, vsff0402 = 0;
#define hora0402()    vh0402
#define minuto0402()  vmi0402
#define segundo0402()  vs0402
#define hora0402Off()     vhff0402
#define minuto0402Off()   vmff0402
#define segundo0402Off()    vsff0402
#define setTime0402(h0402,mi0402,s0402,hf0402,mf0402,sf0402) vh0402=h0402; vmi0402=mi0402; vs0402=s0402; vhff0402=hf0402; vmff0402=mf0402; vsff0402=sf0402;
uint8_t posicao_do_cursor0402 = 0;
void Conig_relogio0402(int8_t l_i)
{
  switch (posicao_do_cursor0402)
  {

    case 0: setTime0402(hora0402() + l_i, minuto0402(), segundo0402(), hora0402Off(), minuto0402Off(), segundo0402Off());  break; // hora0402
    case 1: setTime0402(hora0402(), minuto0402() + l_i, segundo0402(), hora0402Off(), minuto0402Off(), segundo0402Off()); break; // min
    case 2: setTime0402(hora0402(), minuto0402(), segundo0402(), hora0402Off() + l_i, minuto0402Off(), segundo0402Off()); break; // hora0402Off
    case 3: setTime0402(hora0402(), minuto0402(), segundo0402(), hora0402Off(), minuto0402Off() + l_i, segundo0402Off()); break; // minuto0402Off
  }
  if (hora0402() == 24) {
    hora0402() = 0;
  }
  if (minuto0402() == 60) {
    minuto0402() = 0;
  }
  if (segundo0402() == 60) {
    segundo0402() = 0;
  }
  if (hora0402() == 255) {
    hora0402() = 23;
  }
  if (minuto0402() == 255) {
    minuto0402() = 59;
  }
  if (segundo0402() == 255) {
    segundo0402() = 59;
  }
  if (hora0402Off() == 24) {
    hora0402Off() = 0;
  }
  if (minuto0402Off() == 60) {
    minuto0402Off() = 0;
  }
  if (segundo0402Off() == 60) {
    segundo0402Off() = 0;
  }
  if (hora0402Off() == 255) {
    hora0402Off() = 23;
  }
  if (minuto0402Off() == 255) {
    minuto0402Off() = 59;
  }
  if (segundo0402Off() == 255) {
    segundo0402Off() = 59;
  }
}
void Display0402() {
  lcd.print("ON");
  lcd.setCursor(5, 0);
  lcd.print(hora0402());
  lcd.print(":");
  if (posicao_do_cursor0402 == 1) {
    lcd.print(" ");
  }
  lcd.print(minuto0402());
  lcd.print(":");
  lcd.print(segundo0402());
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  lcd.setCursor(5, 1);
  lcd.print(hora0402Off());
  lcd.print(":");
  if (posicao_do_cursor0402 == 3) {
    lcd.print(" ");
  }
  lcd.print(minuto0402Off());
  lcd.print(":");
  if (posicao_do_cursor0402 == 4) {
    lcd.print(" ");
  }
  lcd.print(segundo0402Off());
  switch (posicao_do_cursor0402) {
    case 0: lcd.setCursor(4, 0); lcd.blink(); break; //hora0402
    case 1: lcd.setCursor(7, 0); lcd.blink(); break; //min
    case 2: lcd.setCursor(4, 1); lcd.blink(); break; //hora0402Off
    case 3: lcd.setCursor(7 + ((hora0402Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //minuto0402Off
    case 4: lcd.setCursor(9 + ((hora0402Off() < 10) ? 0 : 1) + ((minuto0402Off() < 10) ? 0 : 1), 1); lcd.blink(); break; //segundo0402Off
    default: lcd.noBlink(); break;
  }
}
//========================== Fim  Timer 0402 ===========================================



void LCDML_DISP_setup(Timer)
{
  uint8_t p = LCDML_DISP_getParameter();
  switch (p) {

    case 0101:
      Display0101();
      break;
    case 0102:
      Display0102();
      break;
    case 0201:
      Display0201();
      break;
    case 0202:
      Display0202();
      break;
    case 0301:
      Display0301();
      break;
    case 0302:
      Display0302();
      break;
    case 0401:
      Display0401();
      break;
    case 0402:
      Display0402();
      break;

  }
}

void LCDML_DISP_loop(Timer)
{
  uint8_t p = LCDML_DISP_getParameter();
  switch (p)
  {


    case 0101:
      if (LCDML_BUTTON_checkAny())
      {
        if (LCDML_BUTTON_checkUp())    {
          Conig_relogio0101(+1);
          LCDML_BUTTON_resetUp();
        }
        if (LCDML_BUTTON_checkDown())  {
          Conig_relogio0101(-1);
          LCDML_BUTTON_resetDown();
        }
        if (LCDML_BUTTON_checkRight()) {
          posicao_do_cursor0101 = (posicao_do_cursor0101 + 1) % 4;
          LCDML_BUTTON_resetRight();
        }
        lcd.clear();
        Display0101();
      }
      break;
    case 0102:
      if (LCDML_BUTTON_checkUp())    {
        Conig_relogio0102(+1);
        LCDML_BUTTON_resetUp();
      }
      if (LCDML_BUTTON_checkDown())  {
        Conig_relogio0102(-1);
        LCDML_BUTTON_resetDown();
      }
      if (LCDML_BUTTON_checkRight()) {
        posicao_do_cursor0102 = (posicao_do_cursor0102 + 1) % 4;
        LCDML_BUTTON_resetRight();
      }
      lcd.clear();
      Display0102();
      break;


    case 0201:
      if (LCDML_BUTTON_checkAny())
      {
        if (LCDML_BUTTON_checkUp())    {
          Conig_relogio0201(+1);
          LCDML_BUTTON_resetUp();
        }
        if (LCDML_BUTTON_checkDown())  {
          Conig_relogio0201(-1);
          LCDML_BUTTON_resetDown();
        }
        if (LCDML_BUTTON_checkRight()) {
          posicao_do_cursor0201 = (posicao_do_cursor0201 + 1) % 4;
          LCDML_BUTTON_resetRight();
        }
        lcd.clear();
        Display0201();
      }
      break;

    case 0202:
      if (LCDML_BUTTON_checkAny())
      {
        if (LCDML_BUTTON_checkUp())    {
          Conig_relogio0202(+1);
          LCDML_BUTTON_resetUp();
        }
        if (LCDML_BUTTON_checkDown())  {
          Conig_relogio0202(-1);
          LCDML_BUTTON_resetDown();
        }
        if (LCDML_BUTTON_checkRight()) {
          posicao_do_cursor0202 = (posicao_do_cursor0202 + 1) % 4;
          LCDML_BUTTON_resetRight();
        }
        lcd.clear();
        Display0202();
      }
      break;

    case 0301:
      if (LCDML_BUTTON_checkAny())
      {
        if (LCDML_BUTTON_checkUp())    {
          Conig_relogio0301(+1);
          LCDML_BUTTON_resetUp();
        }
        if (LCDML_BUTTON_checkDown())  {
          Conig_relogio0301(-1);
          LCDML_BUTTON_resetDown();
        }
        if (LCDML_BUTTON_checkRight()) {
          posicao_do_cursor0301 = (posicao_do_cursor0301 + 1) % 4;
          LCDML_BUTTON_resetRight();
        }
        lcd.clear();
        Display0301();
      }
      break;

    case 0302:
      if (LCDML_BUTTON_checkAny())
      {
        if (LCDML_BUTTON_checkUp())    {
          Conig_relogio0302(+1);
          LCDML_BUTTON_resetUp();
        }
        if (LCDML_BUTTON_checkDown())  {
          Conig_relogio0302(-1);
          LCDML_BUTTON_resetDown();
        }
        if (LCDML_BUTTON_checkRight()) {
          posicao_do_cursor0302 = (posicao_do_cursor0302 + 1) % 4;
          LCDML_BUTTON_resetRight();
        }
        lcd.clear();
        Display0302();
      }
      break;

    case 0401:
      if (LCDML_BUTTON_checkAny())
      {
        if (LCDML_BUTTON_checkUp())    {
          Conig_relogio0401(+1);
          LCDML_BUTTON_resetUp();
        }
        if (LCDML_BUTTON_checkDown())  {
          Conig_relogio0401(-1);
          LCDML_BUTTON_resetDown();
        }
        if (LCDML_BUTTON_checkRight()) {
          posicao_do_cursor0401 = (posicao_do_cursor0401 + 1) % 4;
          LCDML_BUTTON_resetRight();
        }
        lcd.clear();
        Display0401();
      }
      break;

    case 0402:
      if (LCDML_BUTTON_checkAny())
      {
        if (LCDML_BUTTON_checkUp())    {
          Conig_relogio0402(+1);
          LCDML_BUTTON_resetUp();
        }
        if (LCDML_BUTTON_checkDown())  {
          Conig_relogio0402(-1);
          LCDML_BUTTON_resetDown();
        }
        if (LCDML_BUTTON_checkRight()) {
          posicao_do_cursor0402 = (posicao_do_cursor0402 + 1) % 4;
          LCDML_BUTTON_resetRight();
        }
        lcd.clear();
        Display0402();
      }
      break;

  }
}
void LCDML_DISP_loop_end(Timer) {
  lcd.noBlink();
}

void FuncaoTimer(int h, int m) {


  if (hora0101() == h & minuto0101() == m)
  {
    digitalWrite(13,HIGH);
    lcd.setCursor(0,0);
    lcd.print("Saida 01 ON");
  }
  if (hora0102() == hora & minuto0102() == minuto)
  {
    // digitalWrire(saida01,HIGH);
    // lcd.display("Saida 01 ON")
  }


  if (hora0201() == hora & minuto0201() == minuto)
  {
    // digitalWrire(saida02,HIGH);
    // lcd.display("Saida 02 ON")
  }
  if (hora0202() == hora & minuto0202() == minuto)
  {
    // digitalWrire(saida02,HIGH);
    // lcd.display("Saida 02 ON")
  }
  if (hora0301() == hora & minuto0301() == minuto)
  {
    // digitalWrire(saida03,HIGH);
    // lcd.display("Saida 03 ON")
  }
  if (hora0302() == hora & minuto0302() == minuto)
  {
    // digitalWrire(saida03,HIGH);
    // lcd.display("Saida 03 ON")
  }
  if (hora0401() == hora & minuto0401() == minuto)
  {
    // digitalWrire(saida01,HIGH);
    // lcd.display("Saida 01 ON")
  }
  if (hora0402() == hora & minuto0402() == minuto)
  {
    // digitalWrire(saida01,HIGH);
    // lcd.display("Saida 01 ON")
  }

  if (hora0101Off() == h & minuto0101Off() == m)
  {
    digitalWrite(13,LOW);
    lcd.setCursor(0,0);
    lcd.print("Saida 01 OFF");
  
  }
  if (hora0102Off() == hora & minuto0102Off() == minuto)
  {
    // digitalWrire(saida01,HIGH);
    // lcd.display("Saida 01 ON")
  }

  if (hora0201Off() == hora & minuto0201Off() == minuto)
  {
    // digitalWrire(saida02,LOW);
    // lcd.display("Saida 02 ON")
  }
  if (hora0202Off() == hora & minuto0202Off() == minuto)
  {
    // digitalWrire(saida02,LOW);
    // lcd.display("Saida 02 ON")
  }
  if (hora0301Off() == hora & minuto0301Off() == minuto)
  {
    // digitalWrire(saida03,LOW);
    // lcd.display("Saida 03 ON")
  }
  if (hora0302Off() == hora & minuto0302Off() == minuto)
  {
    // digitalWrire(saida03,LOW);
    // lcd.display("Saida 03 ON")
  }
  if (hora0401Off() == hora & minuto0401Off() == minuto)
  {
    // digitalWrire(saida01,LOW);
    // lcd.display("Saida 01 ON")
  }
  if (hora0402Off() == hora & minuto0402Off() == minuto)
  {
    // digitalWrire(saida01,LOW);
    // lcd.display("Saida 01 ON")
  }

}




void LCDML_DISP_setup(Inic_operacao)
{
  uint8_t p = LCDML_DISP_getParameter();
  switch (p)
  {
    case 0:
      LCDML_BACK_start(Iniciar_operacao);
      break;
    case 1:
      LCDML_BACK_stop(Iniciar_operacao);
      LCDML.goRoot();
      break;
  }
}
void LCDML_DISP_loop(Inic_operacao) {}
void LCDML_DISP_loop_end(Inic_operacao) {}
void LCDML_DISP_setup(Entrada) {}
void LCDML_DISP_loop(Entrada) {}
void LCDML_DISP_loop_end(Entrada) {}
