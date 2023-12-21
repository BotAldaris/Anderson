#ifndef Macarrao_h
#define Macarrao_h

#include "ControladorDeTemperatura.h"
#include "Temporizador.h"

class Macarrao
{
private:
    float kp = 180;
    float ki = 0;
    float kd = 0;
    float ultimoErro = 0;
    float erroIntegral = 0;
    int pinoRele = 30;
    ControladorDeTemperatura &temp;
    Temporizador temporizador = Temporizador(5000);
    int calculaPid();

public:
    Macarrao(ControladorDeTemperatura &cont, Temporizador tempo) : temp(cont)
    {
        temporizador = tempo;
    };
    void run();
};
#endif
