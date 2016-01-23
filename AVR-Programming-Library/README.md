Librería de Programación de AVR
===============================

Archivos que son reusados en todo el libro *Make: AVR Programming*

* **pinDefines.h**
	Incluye todas las definiciones de los pines para los proyectos en *Make: AVR Programming*. Cuando necesites saber qué conectar y en dónde, hecha un vistazo aquí.

* **USART.c** y **USART.h**
	ADVERTENCIA! Estos archivos están comentados actualmente ya que el attiny tiene diferente hardware para la comunicación serial. Originalmente estos son los archivos principales de utilidad usados para la entrada/salida serial en el libro. No están particularmente optimizados, pero tienen una pequeña memoria y recursos marcados que te pondrán en marcha muy rápido.

* **binaryMacro.h**
	Si estás usando un compilador que no sea un AVR-GCC reciente, puede que no admita dígitos binarios nativos (ej. 0b00111010). Si es así, este archivo include tiene un macro de pre-procesador que te permitirá ingresarlos de manera similar: B8(01010101).

* **macros.h**
	Este archivo incluye definiciones macro de pre-procesador para bit-twiddling: set_bit, clear_bit y toggle_bit. Útiles para esos días cuando sientes pereza, o has olvidado las operaciones lógicas de bit a bit.

* **portpins.h**
	Es una versión reciente del archivo portpins.h incluido en el entorno Arduino. Incluye las deficiniciones AVR de pines de la forma PB1 y similares. La versión incluida con Arduino es muy antigua -- querrás remplazarla con ésta si quieres escribir en C usando el Arduino IDE. O puedes incluir este archivo directamente en tu código.
