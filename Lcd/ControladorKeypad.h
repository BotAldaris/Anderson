#ifndef ControladorKeypad_h
#define ControladorKeypad_h
#include <Keypad.h>
#include "ControladorDeTemperatura.h"

class ControladorKeypad
{
private:
    Keypad &keypad;
    ControladorDeTemperatura &temp;
    bool ativo = false;
    String novaTemp;
    void outrasTeclas(char key);
    void adicionarNumero(String number);
    Display &display;

public:
    void run();
    ControladorKeypad(ControladorDeTemperatura &controladorDeTemperatura, Keypad &key, Display &disp) : keypad(key), temp(controladorDeTemperatura), display(disp){};
};
#endif
