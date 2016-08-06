int segundo, minuto, hora, dia, mes, ano;
unsigned long UtlTime;


void tempo_ajustado(int h, int m, int s)
{
  hora = h;
  minuto = m;
  segundo = s;
}

void tempo() {

  if (millis() - UtlTime < 0)
  {
    UtlTime = millis();
  }
  else
  {
    segundo = int((millis() - UtlTime) / 1000);
  }
  if (segundo > 59)
  {
    segundo = 0;
    minuto++;
    UtlTime = millis();
    if (minuto > 59)
    {
      hora++;
      minuto = 0;
      if (hora > 23)
      {
        dia++;
        hora = 0;
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        {
          if (dia > 31)
          {
            dia = 1;
            mes++;
            if (mes > 12)
            {
              ano++;
              mes = 1;
            }
          }
        }
        else if (mes == 2)
        {
          if (ano % 400 == 0)
          {
            if (dia > 29)
            {
              dia = 1;
              mes++;
            }
          }
          else if ((ano % 4 == 0) && (ano % 100 != 0))
          {
            if (dia > 29)
            {
              dia = 1;
              mes++;
            }
          }
          else
          {
            if (dia > 28)
            {
              dia = 1;
              mes++;
            }
          }
        }
        else
        {
          if (dia > 30)
          {
            dia = 1;
            mes++;
          }
        }
      }
    }
  }

}



void LCDML_BACK_setup(Iniciar_operacao)
{
  // setup
  // is called only if it is started or restartet (reset+start)
}


boolean LCDML_BACK_loop(Iniciar_operacao)
{
    atualizarH(hora, minuto, segundo);
    FuncaoTimer(hora,minuto);
    lcd.setCursor(5, 1);
    lcd.print(hora);
    lcd.print(":");
    lcd.print(minuto);
    lcd.print(":");
    lcd.print(segundo);

    return false;
}

void LCDML_BACK_stable(Iniciar_operacao)
{
}
