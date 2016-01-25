                                                    /* Demo Blink II */

#include <avr/io.h>
#include <util/delay.h>

#define LED      PB0
#define LED_DDR  DDRB
#define LED_PORT PORTB

#define DELAYTIME 200			/* tiempo de demora */

#define setBit(sfr, bit)     (_SFR_BYTE(sfr) |= (1 << bit))
#define clearBit(sfr, bit)   (_SFR_BYTE(sfr) &= ~(1 << bit))
#define toggleBit(sfr, bit)  (_SFR_BYTE(sfr) ^= (1 << bit))

int main(void) {

  // Inicializacion
  setBit(LED_DDR, LED);                  /* configurar el pin LED como salida */

  // Bucle principal
  while (1) {

    setBit(LED_PORT, LED);
    _delay_ms(DELAYTIME);

    clearBit(LED_PORT, LED);
    _delay_ms(DELAYTIME);

  }
  return (0);                                     /* terminar bucle princpal */
}
