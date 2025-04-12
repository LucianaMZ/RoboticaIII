#include <MatrizLed.h>
/*
 * Texto que aparece por la derecha y sale por la izquierda
 */
MatrizLed pantalla;

void setup() {
  pantalla.begin(13, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
  pantalla.rotar(false);
}

void loop() {
   pantalla.borrar();
  pantalla.escribirFraseScroll("UCSE ", 100); // Texto, milisegundos entre frames
}
 