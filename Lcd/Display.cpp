#include "Display.h"
#include "Arduino.h"
Display::Display()
{
    lcd.begin(16, 2);
}

void Display::escreverNaTelaTemperatura(String menssagem, float temperatura, int linha)
{
    limparDisplayLinha(linha);
    lcd.print(menssagem);
    lcd.print(temperatura);
    lcd.print("C");
}

void Display::limparDisplayLinha(int linha)
{
    for (int n = 0; n < 16; n++)
    {
        lcd.setCursor(n, linha);
        lcd.print(" ");
    }
    lcd.setCursor(0, linha);
}

void Display::atualizarNaTelaTemperatura(float temperatura, int posicaoDoCursor, int posicao)
{
    lcd.setCursor(posicao, posicaoDoCursor);
    lcd.print(temperatura);
}
