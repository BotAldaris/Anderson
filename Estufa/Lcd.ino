#include "Display.h"
#include "ControladorDeTemperatura.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Temporizador.h"
#include <Keypad.h>
#include "ControladorKeypad.h"
#include "Macarrao.h"
long randNumber;
long TEMPOMAXIMOATIVOEMMS = 5000;

const byte ROWS = 4; // the four rows of the keypad
const byte COLS = 4; // the four columns of the keypad

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {53, 52, 51, 50}; // to connect to the row pins of the keypad
byte colPins[COLS] = {49, 48, 47, 46}; // to connect to the column pins of the keypad

// Create the keypad as an object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
OneWire pino(2);
DallasTemperature barramento(&pino);
DeviceAddress sensor;
Display display;
Temporizador temporizador(5000);
ControladorDeTemperatura controladorDeTemperatura(display);
ControladorKeypad controladorKeypad(controladorDeTemperatura, keypad);
Macarrao macarrao(controladorDeTemperatura, temporizador);
void setup()
{
  randomSeed(analogRead(0));
  Serial.begin(9600);
  barramento.begin();
  barramento.getAddress(sensor, 0);
  pinMode(30, OUTPUT);
  digitalWrite(30, HIGH);
}

void loop()
{
  barramento.requestTemperatures();
  float temperatura = barramento.getTempC(sensor);
  // int buttonValue = button.getState();

  controladorDeTemperatura.run(temperatura);
  controladorKeypad.run();
  macarrao.run();
}
