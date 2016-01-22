Código y Ejemplos de "Make: AVR Programming"
==============================================

Bienvenidos!
--------

Aquí encontrarás todo el código (y más) para el libro de Maker Media
 [Make: AVR Programming](http://shop.oreilly.com/product/0636920028161.do).

Las diferencias principales entre este repositorio y el original son:

1. El código original está orientado al microcontrolador ATmega168 y sus variantes, mientras que el código en este repositorio está adaptado al attiny45 20PU.
2. Este repositorio está en español.

ADVERTENCIA! Este es un trabajo en proceso y no está terminado.


Para empezar
------------

* Primero, descargar los contenidos de este repositorio en tu disco duro. La manera más fácil es con el botón "Download ZIP" que se encuentra en la parte superior derecha de esta página web. Extrae los contenidos del archivo zip a tu conveniencia. (Eres libre de clonar el repositorio si usas Git.)

* La mayoría de los proyectos comparten un set común de definiciones de pines y una librerial serial USART común y simple en el directorio **AVR-Programing-Library**. Los archivos make que se incluyen dependen por defecto de esta estructura del directorio, por ello no muevas las carpetas a menos que también cambies la ruta hacia los archivos incluídos en el archivo make.
  
* Si estás usando el Arduino IDE, debes copiar el directorio **AVR-Programming-Library** en tu carpeta **sketchbook/libraries**. Si no sabes donde está, puedes encontrarla en opciones en el diálogo de localización dentro del Arduino IDE. Con eso puedes enlazar tu código para que use esta librería usando simplemente "Programa...Incluir Librería" y seleccionando la librería en el menú.

* Ahora estarás listo para abrir el código, editarlo y cargarlo en la memoria flash del AVR siguiendo las direcciones del libro.
  
  
Disposción del Repositorio
--------------------------

Todo el código del proyecto está organizado por los capítulos del libro. Así que si estás buscando un ejemplo de código SPI, mira en la carpeta "Chapter16_SPI" para proyectos relacionados con SPI, a pesar de que suena obvio.

Sin embargo, un montón de proyectos interesantes se encuentran adicionalmente al tema cubierto en el capítulo. Por ejemplo, "Chapter05_Serial-IO" incluye un proyecto que usa la comunicación serial entre tu computadora y el AVR para convertir el teclado de tu computadora en un teclado musical que toca las notas generadas en el AVR, convirtiéndolo en un órgano controlado por un puerto serial. No pensarías buscar en el capítulo de Serial I/O a menos que estuvieras siguiendo el libro.

Por esa razón, para una visión detallada de todos los proyectos, el archivo [allProjectsList](https://github.com/hexagon5un/AVR-Programming/blob/master/allProjectsList) los enlista a todos por nombre.


setupProject
------------

Si quieres una plantilla en blanco para comenzar a escribir tu propio código AVR, hecha un vistazo en el directorio **setupProject** que está incluído aquí. Adentro encontrarás los archivos **main.c** y **main.h** que están esencialmente en blanco y listos para usarse.

**main.c** usa la librería simple de USART, que también está incluída y enlazada por el archivo **Makefile**.

En corto, puedes copiar este directorio, renombrar los archivos y comenzar a usarlo en tus propios proyectos.

Pero no tienes que hacerlo manualmente. Ejecutando *python setuProject.py NombreProyecto* creará un directorio llamado **NombreProyecto** para ti, además copia los archivos main en blanco, renombrándolos apropiadamente y configurando el archivo make respectivamente. Todo lo que te queda por hacer es la parte difícil -- codificar.

Si usas a menudo esta configuración, querrás personalizar el **Makefile** y los dos archivos **main** para que se ajusten a tus preferencias. De esa forma, cuando quieras comenzar un nuevo proyecto, éste incluirá un **Makefile** personalizado que tiene tu programador, tipo de chip y tu velocidad de transmisión ya configurados.

Finalmente, si quieres mapear las definiciones de tus pines en definiciones macro, ejecuta *python createPinDefines.py*. El programa te preguntará cómo quieres llamar a cada macro del pin (ej. "LED0") y luego qué pin en el AVR quieres asociar con ese nombre (ej. "PB1"). Cuando acabes de ingresar la dispocisión de tus pines, el programa creará un archivo "pinDefine.h" con unos macros bellamente nombrados (eso espero). Mueve este archivo en el directorio adecuado e inclúyelo en tu código. Recurrir a LED0_Set_HIGH encenderá al LED.


Más Recursos!
-------------

Has leído el libro, has construído los proyectos, has trabajado el código. Pero aún tienes sed de más proyectos, más ejemplos, más, más, más! Si tuviera que sonar su propio cuerno, deberías visitar [LittleHacks.org](http://littlehacks.org) donde Elliot Williams escribe blogs acerca de cualquier proyecto de microcontroladores en el que se encuentre al momento.

Especialmente, si estás leyendo [Make: AVR Programming](http://shop.oreilly.com/product/0636920028161.do) y estás interesado en versiones completamente elaboradas de los proyectos con más fotos, videos y explicaciones que puedan entrar en un libro, dirígite a [LittleHacks.org's AVR-Programming Section](http://littlehacks.org/AVR-Programming).

Una vez que hayas agotado todos estos recursos, deberías *definitivamente* dirigirte a la página de listados [Proyectos Finales ECE 4760 de la Universidad de Cornell University](http://people.ece.cornell.edu/land/courses/ece4760/FinalProjects/). Es una colección inspiradora y asombrosa de aplicaciones, y de seguro despertará pensamientos creativos. Todo está bien documentado y hay una vasta cantidad de código fuente en C. 

La [Sección de enlaces del Profesor Land]
(http://people.ece.cornell.edu/land/courses/ece4760/#links) también es de primera categoría, y sus clases en YouTube también merecen un vistazo si estás tomándote en serio todo este asunto de AVR.






