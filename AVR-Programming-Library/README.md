Librería de Programación de AVR
===============================

Archivos que son reusados en todo libro *Make: AVR Programming*

* **pinDefines.h**
	Incluye todas las definiciones de los pines para los proyectos en *Make: AVR Programming*. Cuando necesites saber que conectar en dónde, hecha un vistazo aquí.

* **USART.c** y **USART.h**
	ADVERTENCIA! Estos archivos están comentados actualmente ya que el attiny tiene diferente hardware para la comunicación serial. Originalmente estos son los archivos de utilidad principales usados para la entrada/salida serial en el libro. No están particularmente optimizados, pero tienen una pequeña memoria y una recursos marcados y te pondrán en marcha muy rápido.

* **binaryMacro.h**
	If you're using a compiler other than a recent AVR-GCC, it may not support
	native binary digits (e.g. 0b00111010).  If so, this include file has a pre-processor
	macro that will let you enter them similarly: B8(01010101).  

* **macros.h**
	This file includes pre-processor macro definitions for bit-twiddling: 
	set_bit, clear_bit, and toggle_bit.  Useful for those days when you're feeling
	lazy, or have forgotten your bit-wise logic operations.

* **portpins.h**
	This is a recent version of the portpins.h file included with the Arduino environment.
	It includes the AVR pin definitions of the form PB1 and similar.  The version included
	with Arduino is very old -- you'll want to replace it with this one if you want to write
	in C using the Arduino IDE. Or you can include this file directly in your code.

