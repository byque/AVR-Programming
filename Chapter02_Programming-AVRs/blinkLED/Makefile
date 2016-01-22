# Archivo Make para programar el ATtiny45
# adaptado de http://electronut.in/getting-started-with-attiny85-avr-programming/

##########------------------------------------------------------##########
##########          Detalles especificos del Proyecto		##########
##########  Revisarlos cada vez que comienzas un nuevo proyecto ##########
##########------------------------------------------------------##########

MCU   = attiny45
F_CPU = 8000000
BAUD  = 9600UL
## Tambien intenta BAUD = 19200 o 38400 si te sientes con suerte.

## Un directorio para archivos que se incluyen comunmente y la libreria
## simple USART. Si mueves ya sea la carpeta actual o la carpeta Library,
## debes tambien cambiar esta ruta para que coincida.
LIBDIR = ../../AVR-Programming-Library


##########------------------------------------------------------##########
##########	    Opciones del Programador por Defecto	##########
##########     Configuralas una vez y luego olvidate de ellas	##########
##########      (Se pueden anular. Ver el final del archivo)	##########
##########------------------------------------------------------##########

PROGRAMMER_TYPE = usbasp
# # argumentos extra para avrdude: baud rate, chip type, -F flag, etc.
# PROGRAMMER_ARGS =

OBJECTS	= blinkLED.o

# Para el ATTiny45
# ver http://www.engbedded.com/fusecalc/
FUSES      = -U lfuse:w:0xE2:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m 

# Tune the lines below only if you know what you are doing:
AVRDUDE = avrdude -p $(MCU) -c $(PROGRAMMER_TYPE)
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)

# symbolic targets:
all:	blinkLED.hex

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:blinkLED.hex:i

fuse:
	$(AVRDUDE) $(FUSES)

# Xcode uses the Makefile targets "", "clean" and "install"
install: flash fuse

# if you use a bootloader, change the command below appropriately:
load: all
	bootloadHID blinkLED.hex

clean:
	rm -f blinkLED.hex blinkLED.elf $(OBJECTS)

# file targets:
blinkLED.elf: $(OBJECTS)
	$(COMPILE) -o blinkLED.elf $(OBJECTS)

blinkLED.hex: blinkLED.elf
	rm -f blinkLED.hex
	avr-objcopy -j .text -j .data -O ihex blinkLED.elf blinkLED.hex
	avr-size --format=avr --mcu=$(DEVICE) blinkLED.elf
# If you have an EEPROM section, you must also create a hex file for the
# EEPROM and add it to the "flash" target.

# Targets for code debugging and analysis:
disasm:	blinkLED.elf
	avr-objdump -d blinkLED.elf

cpp:
	$(COMPILE) -E blinkLED.c

# ##########------------------------------------------------------##########
# ##########                Ubicacion del Programa		        ##########
# ##########        No debes cambiarla si esta en tu ruta		    ##########
# ##########------------------------------------------------------##########
#
# CC = avr-gcc
# OBJCOPY = avr-objcopy
# OBJDUMP = avr-objdump
# AVRSIZE = avr-size
# AVRDUDE = avrdude	
# ##########------------------------------------------------------##########
# ##########                   Magia del archivo Make	            ##########
# ##########         Resumen:                                     ##########
# ##########             Queremos un archivo .hex					##########
# ##########        Compilar los archivos fuente en .elf          ##########
# ##########        Convertir el archivo .elf en .hex             ##########
# ##########        No deberias necesitar editar abajo			##########
# ##########------------------------------------------------------##########
#
# ## El nombre de tu proyecto (sin .c)
# # TARGET = blinkLED
# ## O nombralo automaticamente en base al directorio que lo abarca
# TARGET = $(lastword $(subst /, ,$(CURDIR)))
#
# # Archivos de objeto: encontraran cualquier archivo .c/.h files
# #  en el directorio actual y en LIBDIR. Si tienes otro (sub)directorio
# #  con codigo, puedes anadirlos en los SOURCES de abajo en la declaracion
# #  comodin.
#
# SOURCES=$(wildcard *.c $(LIBDIR)/*.c)
# OBJECTS=$(SOURCES:.c=.o)
# HEADERS=$(SOURCES:.c=.h)
#
# ## Opciones de compilacion, escribe man avr-gcc si eres curioso.
# CPPFLAGS = -DF_CPU=$(F_CPU) -DBAUD=$(BAUD) -I. -I$(LIBDIR)
# CFLAGS = -Os -g -std=gnu99 -Wall
# ## Usar tipos de datos cortos (8-bit)
# CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
# ## Separa los archivos de objeto por funcion
# CFLAGS += -ffunction-sections -fdata-sections
# LDFLAGS = -Wl,-Map,$(TARGET).map
# ## Opcional, pero a menudo acaba con menor codigo
# LDFLAGS += -Wl,--gc-sections
# ## Relax reduce el codigo aun mas, pero hace el desamblaje confuso
# ## LDFLAGS += -Wl,--relax
# ## LDFLAGS += -Wl,-u,vfprintf -lprintf_flt -lm  ## for floating-point printf
# ## LDFLAGS += -Wl,-u,vfprintf -lprintf_min      ## for smaller printf
# TARGET_ARCH = -mmcu=$(MCU)
#
# ## Reglas explicitas de patron:
# ##  Para hacer archivos .o a partir de .c files
# %.o: %.c $(HEADERS) Makefile
# 	 $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<;
#
# $(TARGET).elf: $(OBJECTS)
# 	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@
#
# %.hex: %.elf
# 	 $(OBJCOPY) -j .text -j .data -O ihex $< $@
#
# %.eeprom: %.elf
# 	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@
#
# %.lst: %.elf
# 	$(OBJDUMP) -S $< > $@
#
# ## Estos archivos de destino no tienen archivos nombrados a partir de ellos
# .PHONY: all disassemble disasm eeprom size clean squeaky_clean flash fuses
#
# all: $(TARGET).hex
#
# debug:
# 	@echo
# 	@echo "Source files:"   $(SOURCES)
# 	@echo "MCU, F_CPU, BAUD:"  $(MCU), $(F_CPU), $(BAUD)
# 	@echo
#
# # Optionally create listing file from .elf
# # This creates approximate assembly-language equivalent of your code.
# # Useful for debugging time-sensitive bits,
# # or making sure the compiler does what you want.
# disassemble: $(TARGET).lst
#
# disasm: disassemble
#
# # Optionally show how big the resulting program is
# size:  $(TARGET).elf
# 	$(AVRSIZE) -C --mcu=$(MCU) $(TARGET).elf
#
# clean:
# 	rm -f $(TARGET).elf $(TARGET).hex $(TARGET).obj \
# 	$(TARGET).o $(TARGET).d $(TARGET).eep $(TARGET).lst \
# 	$(TARGET).lss $(TARGET).sym $(TARGET).map $(TARGET)~ \
# 	$(TARGET).eeprom
#
# squeaky_clean:
# 	rm -f *.elf *.hex *.obj *.o *.d *.eep *.lst *.lss *.sym *.map *~ *.eeprom
#
# ##########------------------------------------------------------##########
# ##########              Programmer-specific details             ##########
# ##########           Flashing code to AVR using avrdude         ##########
# ##########------------------------------------------------------##########
#
# flash: $(TARGET).hex
# 	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -U flash:w:$<
#
# ## An alias
# program: flash
#
# flash_eeprom: $(TARGET).eeprom
# 	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -U eeprom:w:$<
#
# avrdude_terminal:
# 	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -nt
#
# ## If you've got multiple programmers that you use,
# ## you can define them here so that it's easy to switch.
# ## To invoke, use something like `make flash_arduinoISP`
# flash_usbtiny: PROGRAMMER_TYPE = usbtiny
# flash_usbtiny: PROGRAMMER_ARGS =  # USBTiny works with no further arguments
# flash_usbtiny: flash
#
# flash_usbasp: PROGRAMMER_TYPE = usbasp
# flash_usbasp: PROGRAMMER_ARGS =  # USBasp works with no further arguments
# flash_usbasp: flash
#
# flash_arduinoISP: PROGRAMMER_TYPE = avrisp
# flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P /dev/ttyACM0
# ## (for windows) flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P com5
# flash_arduinoISP: flash
#
# flash_109: PROGRAMMER_TYPE = avr109
# flash_109: PROGRAMMER_ARGS = -b 9600 -P /dev/ttyUSB0
# flash_109: flash
#
# ##########------------------------------------------------------##########
# ##########       Fuse settings and suitable defaults            ##########
# ##########------------------------------------------------------##########
#
# ## Valores por defecto para el ATTiny45
# LFUSE = 0x62
# HFUSE = 0xdf
# EFUSE = 0xff
#
# ## Generic
# FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m
#
# fuses:
# 	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) \
# 	           $(PROGRAMMER_ARGS) $(FUSE_STRING)
# show_fuses:
# 	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -nv
#
# ## Called with no extra definitions, sets to defaults
# set_default_fuses:  FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m
# set_default_fuses:  fuses
#
# ## Set the fuse byte for full-speed mode
# ## Note: can also be set in firmware for modern chips
# set_fast_fuse: LFUSE = 0xE2
# set_fast_fuse: FUSE_STRING = -U lfuse:w:$(LFUSE):m
# set_fast_fuse: fuses
#
# ## Set the EESAVE fuse byte to preserve EEPROM across flashes
# set_eeprom_save_fuse: HFUSE = 0xD7
# set_eeprom_save_fuse: FUSE_STRING = -U hfuse:w:$(HFUSE):m
# set_eeprom_save_fuse: fuses
#
# ## Clear the EESAVE fuse byte
# clear_eeprom_save_fuse: FUSE_STRING = -U hfuse:w:$(HFUSE):m
# clear_eeprom_save_fuse: fuses
