#include "Temporizador.h"
#include "Arduino.h"
bool Temporizador::tempoPidConcluido()
{
    unsigned long tempo = millis();
    if (tempo >= tempoPid)
    {
        ultimoTempo = tempo;
        return true;
    }
    else
    {
        return false;
    }
}

bool Temporizador::tempoParaDesativarConcluido()
{
    long tempo = millis();
    if (tempo >= tempoParaDesativar && tempoParaDesativarLigado)
    {
        tempoParaDesativarLigado = false;
        return true;
    }
    else
    {
        return false;
    }
}

void Temporizador::configurar(int tempoParaAdicionar)
{
    tempoPid = ultimoTempo + tempoParaAcionarOPidNovamente;
    tempoParaDesativar = ultimoTempo + tempoParaAdicionar;
    tempoParaDesativarLigado = true;
}

Temporizador::Temporizador(int tempo)
{
    tempoParaAcionarOPidNovamente = tempo;
}