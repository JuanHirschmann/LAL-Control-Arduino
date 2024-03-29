![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)![image](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)

<a href="https://www.fi.uba.ar/investigacion/areas-de-investigacion/materiales-y-nanotecnologia/laboratorio-de-solidos-amorfos"><img src="https://confedi.org.ar/wp-content/uploads/2020/09/fiuba_logo.jpg" width="600" height="173" align="center">
</a>
# LAL Control
Laboratorio de sólidos amorfos - FIUBA

## Sistema de control de procedimiento y monitoreo para un láser de ablación pulsada.

LAL Control es un sistema para el control del procedimiento para operar el láser de ablación pulsada del laboratorio de Sólidos amorfos de la facultad de ingeniería de la UBA. Esta versión del sistema se encuentra desarrollada en el entorno Arduino para ser implementada en una placa basada en el microcontrolador Atmega328p o equivalentes.

## Características del sistema

- Sensado de temperatura en motor extractor.
- Control de temperatura mediante dos coolers.
- Interfaz con el usuario mediante LCD.
- Sistema de alarmas para alertar por exceso de temperatura, humedad en el recinto o fallas en los sensores.

## Instalación
Para ser cargado en la placa de desarrollo el sistema requiere utilizar el plugin de Visual Studio Code [PlatformIO](https://platformio.org/). Una vez instalado PlatfomIO se debe abrir la carpeta con el sistema como un proyecto e instalarlo en la placa objetivo.

## Documentación
Toda la documentación del código está disponible en este [enlace](https://juanhirschmann.github.io/LAL-Control-Arduino/).

El manual del equipo está disponible en este [enlace](https://juanhirschmann.github.io/LAL-Control-Arduino/Manual.html)


## Licencia
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

