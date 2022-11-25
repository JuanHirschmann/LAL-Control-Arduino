# LAL Control
## Sistema de control de procedimiento y monitoreo para un láser de ablación pulsada.

[![FIUBA](https://campus.fi.uba.ar/pluginfile.php/263695/course/section/26610/banner-fiuba.jpg)](https://www.fi.uba.ar/)

[![LSA](https://es.expensereduction.com/wp-content/uploads/2018/02/logo-placeholder.png)](https://www.fi.uba.ar/investigacion/areas-de-investigacion/materiales-y-nanotecnologia/laboratorio-de-solidos-amorfos)

LAL Control es un sistema para el control del procedimiento para operar el láser de ablación pulsada del laboratorio de Sólidos amorfos de la facultad de ingeniería de la UBA. Esta versión del sistema se encuentra desarrollada en el entorno Arduino para ser implementada en una placa basada en el microcontrolador Atmega328p o equivalentes.

## Características del sistema

- Sensado de temperatura en motor extractor.
- Control de temperatura mediante dos coolers.
- Interfaz con el usuario mediante LCD.
- Sistema de alarmas para alertar por exceso de temperatura, humedad en el recinto o fallas en los sensores.

## Instalación
Para ser cargado en Arduino, el sistema requiere utilizar el plugin de Visual Studio Code [PlatformIO](https://platformio.org/).

## Licencia

MIT

