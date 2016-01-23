
##########------------------------------------------------------##########
##########          Detalles especificos del Proyecto		##########
##########  Revisarlos cada vez que comienzas un nuevo proyecto ##########
##########------------------------------------------------------##########

MCU   = attiny45
F_CPU = 8000000UL
BAUD  = 9600UL
## Tambien intenta BAUD = 19200 o 38400 si te sientes con suerte.

## Un directorio para archivos que se incluyen comunmente y la libreria
##  simple USART. Si mueves ya sea la carpeta actual o la carpeta Library,
##  debes tambien cambiar esta ruta para que coincida.
LIBDIR = ../../AVR-Programming-Library

##########------------------------------------------------------##########
##########	    Opciones del Programador por Defecto	##########
##########     Configuralas una vez y luego olvidate de ellas	##########
##########      (Se pueden anular. Ver el final del archivo)	##########
##########------------------------------------------------------##########

PROGRAMMER_TYPE = usbasp
# argumentos extra para avrdude: baud rate, chip type, -F flag, etc.
PROGRAMMER_ARGS =

##########------------------------------------------------------##########
##########                Ubicacion del Programa		##########
##########        No debes cambiarla si esta en tu ruta		##########
##########------------------------------------------------------##########

CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude	

##########------------------------------------------------------##########
##########                   Magia del archivo Make	        ##########
##########         Resumen:                                     ##########
##########             Queremos un archivo .hex			##########
##########        Compilar los archivos fuente en .elf          ##########
##########        Convertir el archivo .elf en .hex             ##########
##########        No deberias necesitar editar abajo		##########
##########------------------------------------------------------##########

## El nombre de tu proyecto (sin .c)
# TARGET = blinkLED
## O nombralo automaticamente en base al directorio que lo abarca
TARGET = $(lastword $(subst /, ,$(CURDIR)))

# Archivos de objeto: encontraran cualquier archivo .c/.h en el directorio
#  actual y en LIBDIR. Si tienes otro (sub)directorio con codigo, puedes
#  anadirlos en los SOURCES de abajo en la declaracion wildcard.
SOURCES=$(wildcard *.c $(LIBDIR)/*.c)
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(SOURCES:.c=.h)

## Opciones de compilacion, escribe man avr-gcc si eres curioso.
CPPFLAGS = -DF_CPU=$(F_CPU) -DBAUD=$(BAUD) -I. -I$(LIBDIR)
CFLAGS = -Os -g -std=gnu99 -Wall
## Usar tipos de datos cortos (8-bit)
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
## Separa los archivos de destino por funcion
CFLAGS += -ffunction-sections -fdata-sections
LDFLAGS = -Wl,-Map,$(TARGET).map
## Opcional, pero a menudo termina en menor codigo
LDFLAGS += -Wl,--gc-sections
## Relax reduce el codigo aun mas, pero hace el desamblaje confuso
## LDFLAGS += -Wl,--relax
## LDFLAGS += -Wl,-u,vfprintf -lprintf_flt -lm  ## para printf de punto flotante
## LDFLAGS += -Wl,-u,vfprintf -lprintf_min      ## para printf mas pequeno
TARGET_ARCH = -mmcu=$(MCU)

## Reglas explicitas de patron:
##  Para hacer archivos .o a partir de .c files
%.o: %.c $(HEADERS) Makefile
	 $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<;

$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

%.hex: %.elf
	 $(OBJCOPY) -j .text -j .data -O ihex $< $@

%.eeprom: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@

%.lst: %.elf
	$(OBJDUMP) -S $< > $@

## Estos archivos de destino no tienen archivos nombrados a partir de ellos
.PHONY: all disassemble disasm eeprom size clean squeaky_clean flash fuses

all: $(TARGET).hex

debug:
	@echo
	@echo "Source files:"   $(SOURCES)
	@echo "MCU, F_CPU, BAUD:"  $(MCU), $(F_CPU), $(BAUD)
	@echo

# Opcionalmente crea un archivo de listado a partir de .elf
# Esto crea un equivalente aproximado de lenguaje de ensamblador de tu codigo.
# Util para depurar bits sensibles al tiempo,
# o para asegurar que el compilador haga lo que tu quieres.
disassemble: $(TARGET).lst

disasm: disassemble

# Opcionalmente muestra lo grande que es el programa resultante
size:  $(TARGET).elf
	$(AVRSIZE) -C --mcu=$(MCU) $(TARGET).elf

clean:
	rm -f $(TARGET).elf $(TARGET).hex $(TARGET).obj \
	$(TARGET).o $(TARGET).d $(TARGET).eep $(TARGET).lst \
	$(TARGET).lss $(TARGET).sym $(TARGET).map $(TARGET)~ \
	$(TARGET).eeprom

squeaky_clean:
	rm -f *.elf *.hex *.obj *.o *.d *.eep *.lst *.lss *.sym *.map *~ *.eeprom

#####--------------------------------------------------------------#######
#####           Detalles especificos del programador		   #######
#####  Cargar el codigo a la memoria flash del AVR usando avrdude  #######
#####--------------------------------------------------------------#######

flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -U flash:w:$<

## Un alias
program: flash

flash_eeprom: $(TARGET).eeprom
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -U eeprom:w:$<

avrdude_terminal:
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -nt

## Si usas multiples programadores
## puedes definirlos aqui para que sea facil cambiarlos.
## Para llamar al programador, usar algo como 'make flash_arduinoISP'
flash_usbtiny: PROGRAMMER_TYPE = usbtiny
flash_usbtiny: PROGRAMMER_ARGS =  # USBTiny works with no further arguments
flash_usbtiny: flash

flash_usbasp: PROGRAMMER_TYPE = usbasp
flash_usbasp: PROGRAMMER_ARGS =  # USBasp works with no further arguments
flash_usbasp: flash

flash_arduinoISP: PROGRAMMER_TYPE = avrisp
flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P /dev/ttyACM0
## (para windows) flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P com5
flash_arduinoISP: flash

flash_109: PROGRAMMER_TYPE = avr109
flash_109: PROGRAMMER_ARGS = -b 9600 -P /dev/ttyUSB0
flash_109: flash

##########------------------------------------------------------##########
##########   Configuraciones de fusibles y valores adecuados    ##########
##########------------------------------------------------------##########

# Valores para que el ATTiny45 use 8 MHz, mas informacion al final del documento.
LFUSE = 0xE2
HFUSE = 0xdf
EFUSE = 0xff

## Generico
FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m

fuses:
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) \
	           $(PROGRAMMER_ARGS) $(FUSE_STRING)
show_fuses:
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -nv

## Llamado sin definiciones extra, configura los valores por defecto
set_default_fuses:  FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m
set_default_fuses:  fuses

## Configura el byte de fusible para modo de maxima velocidad
## Nota: tambien puede ser configurado en el firmware para chips modernos
set_fast_fuse: LFUSE = 0xE2
set_fast_fuse: FUSE_STRING = -U lfuse:w:$(LFUSE):m
set_fast_fuse: fuses

## Configura el byte de fusible EESAVE para preservar la EEPROM entre programaciones del chip
set_eeprom_save_fuse: HFUSE = 0xD7
set_eeprom_save_fuse: FUSE_STRING = -U hfuse:w:$(HFUSE):m
set_eeprom_save_fuse: fuses

## Quita el byte de fusible EESAVE
clear_eeprom_save_fuse: FUSE_STRING = -U hfuse:w:$(HFUSE):m
clear_eeprom_save_fuse: fuses


#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
# Archivo Make simple para programar el ATtiny45 ver
#  http://electronut.in/getting-started-with-attiny85-avr-programming/
# Calculadora de fusibles, hay que desactivar el divisor de reloj ver
#  http://www.engbedded.com/fusecalc/
