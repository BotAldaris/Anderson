#ifndef ControladorDeTemperatura_h
#define ControladorDeTemperatura_h

#include "Arduino.h"
#include "Display.h"

class ControladorDeTemperatura
{
private:
  float temperatura;
  int temmperaturaSetPoint;
  int temperaturaAjustavel;
  Display &display;

  void controlarTemperatura(bool aumentarTemperatura);

public:
  ControladorDeTemperatura(Display &disp) : display(disp)
  {
    display = disp;
    temperatura = 20;
    temmperaturaSetPoint = 20;
    temperaturaAjustavel = 40;
    display.escreverNaTelaTemperatura("Temp: ", temperatura, 0);
    display.escreverNaTelaTemperatura("Set Temp: ", temmperaturaSetPoint, 1);
  }
  void run(float temp);
  void setTemperaturaSetPoint();
  int getTemperaturaSetPoint();
  int getTemperatura();
  void setTemperatura(String novoSetPointt);
};

#endif
