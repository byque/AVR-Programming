                                                         /* Demo Blink */

// ------- Preambulo -------- //
#include <avr/io.h>                  /* Define los pines, puertos, etc */
#include <util/delay.h>          /* Funciones para desperdiciar tiempo */


int main(void) {

  // --- Inicializaciones --- //
  DDRB |= 0b0000001;            /* Direccion de Datos del Registro B:
                                   escribir un uno al bit
                                   habilita la salida. */

  // --- Bucle de Eventos --- //
  while (1) {

    PORTB = 0b00000001;      /* Prender el primer LED bit/pin en PORTB */
    _delay_ms(1000);                                        /* esperar */

    PORTB = 0b00000000; /* Apagar todos los pines de B, incluyendo al LED */
    _delay_ms(1000);                                        /* esperar */

  }                                       /* Acaba el bucle de eventos */
  return (0);                           /* Nunca se llega a esta linea */
}
