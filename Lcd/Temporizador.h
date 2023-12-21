#ifndef Temporizador_h
#define Temporizador_h
#include "Arduino.h"
class Temporizador
{
private:
    unsigned long ultimoTempo = 0;
    int tempoParaAcionarOPidNovamente = 5000;
    unsigned long tempoPid = 5000;
    unsigned long tempoParaDesativar = 5000;
    bool tempoParaDesativarLigado = true;

public:
    bool tempoPidConcluido();
    bool tempoParaDesativarConcluido();
    void configurar(int tempoParaAdicionar);
    Temporizador(int tempo);
};
#endif