#include "Macarrao.h"

int Macarrao::calculaPid()
{
    float erro = temp.getTemperaturaSetPoint() - temp.getTemperatura();
    float proporcional = kp * erro;

    erroIntegral += erro;
    float integral = ki * erroIntegral;

    float erroDerivado = erro - ultimoErro;
    float derivado = kd * erroDerivado;

    float soma = proporcional + integral + derivado;
    int valorPid = constrain((int)soma, 0, 255);

    ultimoErro = erro;
    int tempoDesativado = map(valorPid, 0, 255, 0, 5000);
    return tempoDesativado;
}

void Macarrao::run()
{
    if (temporizador.tempoParaDesativarConcluido())
    {
        digitalWrite(pinoRele, HIGH);
    }
    if (temporizador.tempoPidConcluido())
    {
        int tempoDesativado = calculaPid();
        if (tempoDesativado > 1)
        {
            digitalWrite(pinoRele, LOW);
        }
        temporizador.configurar(tempoDesativado);
    }
}
