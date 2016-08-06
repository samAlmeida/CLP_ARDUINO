
uint8_t vh, vmi, vs= 0;
  #define hour()    vh
  #define minute()  vmi
  #define second()  vs
  #define setTime(h,mi,s) vh=h; vmi=mi; vs=s;;
  uint8_t _pos = 0;
  void HELP_FUNC_set_dat(int8_t l_i)
  {
    switch(_pos)
    {
      case 0: setTime(hour()+l_i,minute(),second());  break; // hour
      case 1: setTime(hour(),minute()+l_i,second()); break; // min

    }
  }
  void digitalClockDisplay(){   
    lcd.setCursor(3,0);
    printDigits(hour());
    lcd.print(":");
    if(_pos == 1) { lcd.print(" "); }
    printDigits(minute());
    lcd.print(":");
    printDigits(second());
    switch(_pos) {
      case 0: lcd.setCursor(2,0); lcd.blink(); break; //hour
      case 1: lcd.setCursor(6,0); lcd.blink(); break; //min
      default: lcd.noBlink(); break;
     }
  }
  void printDigits(int digits){
    if(digits < 10) {
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
  if(LCDML_BUTTON_checkAny()) {
      if (LCDML_BUTTON_checkUp())    { HELP_FUNC_set_dat(+1); LCDML_BUTTON_resetUp(); }
      if (LCDML_BUTTON_checkDown())  { HELP_FUNC_set_dat(-1);  LCDML_BUTTON_resetDown(); }
      if (LCDML_BUTTON_checkRight()) { _pos=(_pos+1)%5; LCDML_BUTTON_resetRight(); }
      lcd.clear();
      digitalClockDisplay();

   }   
  
}
void LCDML_DISP_loop_end(LCDML_FUNC_change_datetime) 
{  
  tempo_ajustado(hour(),minute(),second());
  lcd.noBlink();  
} 



//========================== Timer 0101 ===========================================
uint8_t vh0101, vmi0101, vs0101, vhff0101,vmff0101, vsff0101 = 0;
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
    switch(posicao_do_cursor0101)
    {
      case 0: setTime0101(hora0101()+l_i,minuto0101(),segundo0101(),hora0101Off(),minuto0101Off(),segundo0101Off());  break; // hora0101
      case 1: setTime0101(hora0101(),minuto0101()+l_i,segundo0101(),hora0101Off(),minuto0101Off(),segundo0101Off()); break; // min
      case 2: setTime0101(hora0101(),minuto0101(),segundo0101(),hora0101Off()+l_i,minuto0101Off(),segundo0101Off()); break; // hora0101Off
      case 3: setTime0101(hora0101(),minuto0101(),segundo0101(),hora0101Off(),minuto0101Off()+l_i,segundo0101Off()); break; // minuto0101Off
    }
  }
  void Display0101(){   
   lcd.print("ON");
    lcd.setCursor(5,0);
    lcd.print(hora0101());
    lcd.print(":");
    if(posicao_do_cursor0101 == 1) { lcd.print(" "); }
    lcd.print(minuto0101());
    lcd.print(":");
    lcd.print(segundo0101());
    lcd.setCursor(0,1);  
    lcd.print("OFF");
    lcd.setCursor(5,1);  
    lcd.print(hora0101Off());
    lcd.print(":");
    if(posicao_do_cursor0101 == 3) { lcd.print(" "); }
    lcd.print(minuto0101Off());
    lcd.print(":");
    if(posicao_do_cursor0101 == 4) { lcd.print(" "); }
    lcd.print(segundo0101Off());
    switch(posicao_do_cursor0101) {
      case 0: lcd.setCursor(4,0); lcd.blink(); break; //hora0101
      case 1: lcd.setCursor(7,0); lcd.blink(); break; //min
      case 2: lcd.setCursor(4,1); lcd.blink(); break; //hora0101Off
      case 3: lcd.setCursor(7+((hora0101Off()<10)?0:1),1); lcd.blink(); break;//minuto0101Off
      case 4: lcd.setCursor(9+((hora0101Off()<10)?0:1)+((minuto0101Off()<10)?0:1),1); lcd.blink(); break; //segundo0101Off
      default: lcd.noBlink(); break;
     }
  }
//========================== Fim  Timer 0101 ===========================================

//========================== Timer 0102 ===========================================
uint8_t vh0102, vmi0102, vs0102, vhff0102,vmff0102, vsff0102 = 0;
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
    switch(posicao_do_cursor0102)
    {
      case 0: setTime0102(hora0102()+l_i,minuto0102(),segundo0102(),hora0102Off(),minuto0102Off(),segundo0102Off());  break; // hora0102
      case 1: setTime0102(hora0102(),minuto0102()+l_i,segundo0102(),hora0102Off(),minuto0102Off(),segundo0102Off()); break; // min
      case 2: setTime0102(hora0102(),minuto0102(),segundo0102(),hora0102Off()+l_i,minuto0102Off(),segundo0102Off()); break; // hora0102Off
      case 3: setTime0102(hora0102(),minuto0102(),segundo0102(),hora0102Off(),minuto0102Off()+l_i,segundo0102Off()); break; // minuto0102Off
    }
  }
  void Display0102(){   
   lcd.print("ON");
    lcd.setCursor(5,0);
    lcd.print(hora0102());
    lcd.print(":");
    if(posicao_do_cursor0102 == 1) { lcd.print(" "); }
    lcd.print(minuto0102());
    lcd.print(":");
    lcd.print(segundo0102());
    lcd.setCursor(0,1);  
    lcd.print("OFF");
    lcd.setCursor(5,1);  
    lcd.print(hora0102Off());
    lcd.print(":");
    if(posicao_do_cursor0102 == 3) { lcd.print(" "); }
    lcd.print(minuto0102Off());
    lcd.print(":");
    if(posicao_do_cursor0102 == 4) { lcd.print(" "); }
    lcd.print(segundo0102Off());
    switch(posicao_do_cursor0102) {
      case 0: lcd.setCursor(4,0); lcd.blink(); break; //hora0102
      case 1: lcd.setCursor(7,0); lcd.blink(); break; //min
      case 2: lcd.setCursor(4,1); lcd.blink(); break; //hora0102Off
      case 3: lcd.setCursor(7+((hora0102Off()<10)?0:1),1); lcd.blink(); break;//minuto0102Off
      case 4: lcd.setCursor(9+((hora0102Off()<10)?0:1)+((minuto0102Off()<10)?0:1),1); lcd.blink(); break; //segundo0102Off
      default: lcd.noBlink(); break;
     }
  }
//========================== Fim  Timer 0102 ===========================================



//========================== Timer 0201 ===========================================
uint8_t vh0201, vmi0201, vs0201, vhff0201,vmff0201, vsff0201 = 0;
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
    switch(posicao_do_cursor0201)
    {
      case 0: setTime0201(hora0201()+l_i,minuto0201(),segundo0201(),hora0201Off(),minuto0201Off(),segundo0201Off());  break; // hora0201
      case 1: setTime0201(hora0201(),minuto0201()+l_i,segundo0201(),hora0201Off(),minuto0201Off(),segundo0201Off()); break; // min
      case 2: setTime0201(hora0201(),minuto0201(),segundo0201(),hora0201Off()+l_i,minuto0201Off(),segundo0201Off()); break; // hora0201Off
      case 3: setTime0201(hora0201(),minuto0201(),segundo0201(),hora0201Off(),minuto0201Off()+l_i,segundo0201Off()); break; // minuto0201Off
    }
  }
  void Display0201(){   
   lcd.print("ON");
    lcd.setCursor(5,0);
    lcd.print(hora0201());
    lcd.print(":");
    if(posicao_do_cursor0201 == 1) { lcd.print(" "); }
    lcd.print(minuto0201());
    lcd.print(":");
    lcd.print(segundo0201());
    lcd.setCursor(0,1);  
    lcd.print("OFF");
    lcd.setCursor(5,1);  
    lcd.print(hora0201Off());
    lcd.print(":");
    if(posicao_do_cursor0201 == 3) { lcd.print(" "); }
    lcd.print(minuto0201Off());
    lcd.print(":");
    if(posicao_do_cursor0201 == 4) { lcd.print(" "); }
    lcd.print(segundo0201Off());
    switch(posicao_do_cursor0201) {
      case 0: lcd.setCursor(4,0); lcd.blink(); break; //hora0201
      case 1: lcd.setCursor(7,0); lcd.blink(); break; //min
      case 2: lcd.setCursor(4,1); lcd.blink(); break; //hora0201Off
      case 3: lcd.setCursor(7+((hora0201Off()<10)?0:1),1); lcd.blink(); break;//minuto0201Off
      case 4: lcd.setCursor(9+((hora0201Off()<10)?0:1)+((minuto0201Off()<10)?0:1),1); lcd.blink(); break; //segundo0201Off
      default: lcd.noBlink(); break;
     }
  }
//========================== Fim  Timer 0201 ===========================================


 
void LCDML_DISP_setup(Timer)
{
  uint8_t p = LCDML_DISP_getParameter();
  switch (p) {
      case 0101:
        Display0101();
        break;
      case 0102:
;
        break;

  }
}

void LCDML_DISP_loop(Timer)
{
  uint8_t p = LCDML_DISP_getParameter();
  switch (p) {
      case 0101:
  if(LCDML_BUTTON_checkAny()) {
      if (LCDML_BUTTON_checkUp())    { Conig_relogio0101(+1); LCDML_BUTTON_resetUp(); }
      if (LCDML_BUTTON_checkDown())  { Conig_relogio0101(-1);  LCDML_BUTTON_resetDown(); }
      if (LCDML_BUTTON_checkRight()) { posicao_do_cursor0101=(posicao_do_cursor0101+1)%5; LCDML_BUTTON_resetRight(); }
      lcd.clear();
      Display0101();
   }   
  
        break;
      case 0102:
      if (LCDML_BUTTON_checkUp())    { Conig_relogio0102(+1); LCDML_BUTTON_resetUp(); }
      if (LCDML_BUTTON_checkDown())  { Conig_relogio0102(-1);  LCDML_BUTTON_resetDown(); }
      if (LCDML_BUTTON_checkRight()) { posicao_do_cursor0102=(posicao_do_cursor0102+1)%5; LCDML_BUTTON_resetRight(); }
      lcd.clear();
      Display0102();

        break;
}
}
void LCDML_DISP_loop_end(Timer) 
{
lcd.noBlink();
}


void LCDML_DISP_setup(Entrada)
{
   uint8_t p = LCDML_DISP_getParameter();
      switch (p) {
      case 1:
      LCDML_BACK_start(LCDML_BACKEND_static);
      break;
      case 2:
      LCDML_BACK_stop(LCDML_BACKEND_static);
      LCDML.goRoot();
      break;
    }


}

void LCDML_DISP_loop(Entrada)
{ 

}
void LCDML_DISP_loop_end(Entrada) 
{

}
