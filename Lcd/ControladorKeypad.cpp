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
            adicionarNumero("1");
            break;
        case '2':
            adicionarNumero("2");
            break;
        case '3':
            adicionarNumero("3");
            break;
        case '4':
            adicionarNumero("4");
            break;
        case '5':
            adicionarNumero("5");
            break;
        case '6':
            adicionarNumero("6");
            break;
        case '7':
            adicionarNumero("7");
            break;
        case '8':
            adicionarNumero("8");
            break;
        case '9':
            adicionarNumero("9");
            break;
        case '0':
            adicionarNumero("0");
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
        display.escreverNaTelaTemperatura("Set Temp: ", temp.getTemperaturaSetPoint(), 1);
        break;
    default:
        break;
    }
}

void ControladorKeypad::adicionarNumero(String number)
{
    novaTemp += number;
    display.escreverNaTelaTemperatura("Set Temp: ", novaTemp.toFloat(), 1);
}