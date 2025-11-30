💻 so_long (Bonus): Arquitectura 2D en C con Zero Leaks
Este proyecto representa una implementación avanzada del ejercicio so_long de la 42 Network, desarrollado completamente en C y utilizando la librería MiniLibX para el renderizado gráfico. El foco principal fue la ingeniería de software y la gestión de recursos.

🛠️ Logros Técnicos Clave
Zero Leaks: El código fuente garantiza una gestión de memoria manual rigurosa. Pruebas exhaustivas con Valgrind confirman cero bytes perdidos en todas las fases de ejecución, incluido el cierre inesperado de la ventana y la finalización del juego.

Arquitectura Avanzada (Bonus): El diseño modular permitió la implementación eficiente de:

Doble Jugador (Co-op): Manejo simultáneo y diferenciado de la lógica de input para dos entidades de jugador separadas dentro del mismo gamestate.

Sistema de Entidades Enemigas: Implementación de enemigos con pathfinding simple y lógica de colisión específica para el evento Game Over.

Gestión de Eventos: Uso de hooks de MiniLibX (key_hook, loop_hook) para manejar la entrada del usuario (teclado) y mantener un ciclo de renderizado (frame rate) consistente para la animación.

Animación por Frames: Implementación de lógica de timer y contador de frames para ofrecer animaciones fluidas de sprites (jugadores, coleccionables y enemigos).

El proyecto está diseñado para ser compilado y ejecutado en entornos Unix/Linux/macOS que soporten la librería MiniLibX. Sigue estos pasos para poner en marcha el juego:

Para comenzar, clona el repositorio y navega a la carpeta del proyecto. Abre tu terminal y ejecuta: git clone https://github.com/cuadradodev42/so_long_bonus.git seguido de cd so_long_bonus. El siguiente paso es la compilación. Utiliza el Makefile incluido, el cual gestionará la compilación de todos los archivos .c y la vinculación con la librería MiniLibX. Simplemente ejecuta make. Esto generará el ejecutable principal del juego, llamado so_long. Finalmente, la ejecución. El ejecutable requiere exactamente un argumento: la ruta hacia un archivo de mapa válido con la extensión .ber. El proyecto incluye mapas de ejemplo en dos ubicaciones: la carpeta básica maps/ y la carpeta de bonus bonus/maps_bonus/. Puedes usar cualquiera de los archivos map1.ber de ejemplo. La sintaxis general es ./so_long [ruta/al/archivo/mapa.ber].

Ejemplos Prácticos de Ejecución:
Para ejecutar el juego con un mapa simple:

Bash

./so_long maps/map1.ber
Para probar las funcionalidades Bonus con un mapa avanzado:

Bash

./so_long bonus/maps_bonus/map1.ber
Además, puedes validar la excelencia en la gestión de memoria utilizando Valgrind para confirmar los ZERO LEAKS durante la ejecución:

Bash

valgrind --leak-check=full ./so_long maps/map1.ber
