#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Tipo de módulo (puede ser FC16_HW o PAROLA_HW según tu módulo)
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

// Número de matrices conectadas
#define MAX_DEVICES 2

// Pines SPI por hardware
#define DATA_PIN 11
#define CLK_PIN  13
#define CS_PIN   10

// Inicialización del objeto Parola (SPI por hardware)
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Configuración de texto
uint8_t scrollSpeed = 100;
textEffect_t scrollEffect = PA_SCROLL_LEFT;
textPosition_t scrollAlign = PA_LEFT;
uint16_t scrollPause = 0;

// Mensaje a mostrar
char mensaje[] = "UCSE-DASS";

void setup()
{
  P.begin();
  P.displayText(mensaje, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
}

void loop()
{
  if (P.displayAnimate())
  {
    P.displayReset();
  }
}
