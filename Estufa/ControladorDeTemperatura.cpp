#include "ControladorDeTemperatura.h"
#include "Arduino.h"

void ControladorDeTemperatura::controlarTemperatura(bool aumentarTemperatura)
{
    if (aumentarTemperatura)
    {
        temperaturaAjustavel++;
    }
    else
    {
        temperaturaAjustavel--;
    }
    display.atualizarNaTelaTemperatura(temperaturaAjustavel, 2, 10);
}

void ControladorDeTemperatura::setTemperaturaSetPoint()
{
    temmperaturaSetPoint = temperaturaAjustavel;
    display.atualizarNaTelaTemperatura(temmperaturaSetPoint, 1, 10);
}

void ControladorDeTemperatura::run(float temp)
{
    if (temperatura != temp)
    {
        temperatura = temp;
        Serial.println(temperatura);
        display.atualizarNaTelaTemperatura(temperatura, 0, 6);
    }
}

int ControladorDeTemperatura::getTemperatura()
{
    return temperatura;
}

int ControladorDeTemperatura::getTemperaturaSetPoint()
{
    return temmperaturaSetPoint;
}
void ControladorDeTemperatura::setTemperatura(String novoSetPointt)
{
    int novoSetPoint = novoSetPointt.toInt();
    if (!(novoSetPoint == 0 && novoSetPointt != "0"))
    {
        if (novoSetPoint > 55)
        {
            temmperaturaSetPoint = 55;
        }
        else if (novoSetPoint < 25)
        {
            temmperaturaSetPoint = 25;
        }
        else
        {
            temmperaturaSetPoint = novoSetPoint;
        }
    }
    Serial.print("Temp trocada com sucesso, nova temp: ");
    Serial.print(temmperaturaSetPoint);
}
ControladorDeTemperatura::ControladorDeTemperatura() {}