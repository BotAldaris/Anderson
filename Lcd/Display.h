#ifndef Display_h
#define Display_h

#include <LiquidCrystal.h>
class Display
{
private:
    LiquidCrystal lcd = LiquidCrystal(13, 12, 7, 6, 5, 4);
    void limparDisplayLinha(int linha);

public:
    Display();
    void escreverNaTelaTemperatura(String menssagem, float temperatura, int linha);
    void atualizarNaTelaTemperatura(float temperatura, int posicaoDoCursor, int posicao);
};
#endif
