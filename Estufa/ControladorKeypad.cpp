#include "ControladorKeypad.h"
#include "ControladorDeTemperatura.h"

void ControladorKeypad::run()
{
    char key = keypad.getKey();
    if (2 > novaTemp.length() && key)
    {
        switch (key)
        {
        case '1':
            novaTemp += "1";
            break;
        case '2':
            novaTemp += "2";
            break;
        case '3':
            novaTemp += "3";
            break;
        case '4':
            novaTemp += "4";
            break;
        case '5':
            novaTemp += "5";
            break;
        case '6':
            novaTemp += "6";
            break;
        case '7':
            novaTemp += "7";
            break;
        case '8':
            novaTemp += "8";
            break;
        case '9':
            novaTemp += "9";
            break;
        case '0':
            novaTemp += " 0";
            break;
        case 'B':
            novaTemp.remove(novaTemp.length() - 1);
            break;
        default:
            outrasTeclas(key);
            break;
        }
    }
    else
    {
        outrasTeclas(key);
    }
    Serial.print(key);
}

void ControladorKeypad::outrasTeclas(char key)
{
    switch (key)
    {
    case 'A':
        ativo = true;
        break;
    case '*':
        ativo = false;
        temp.setTemperatura(novaTemp);
        novaTemp = "";
        break;
    case '#':
        ativo = false;
        novaTemp = "";
        break;
    default:
        break;
    }
}
