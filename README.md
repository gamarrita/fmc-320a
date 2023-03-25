# fmc_320a - Computador de Caudales.

Instruccion Para Clonar y Version del STM32CubeIDE:
- El proyecto corre en STM32Cube IDE 1.12
- Aunque trabaja con carpetas no absolutas clonar el proyecto en d:\githubs\fm-320a\
- File -> Switch Workspace -> d:\githubs\fmc-320a
- File -> Open Project From File System -> Directory -> d:\githubs\fmc-320a -> Select All -> Finish

En este punto deberia ver en Project Explorer todos los protyectos relacionado, si no los ve es posible que precionand en el pequeño icono restore, arriba a la izquierda los muestre.

Configurar el limite de linea par que sea visible en 80 caracteres
- Windows -> Preferences -> General -> Editors -> Text Editors
- Macar Show print margin
- Print margin columm: 80

Configuraciones Code Analysis
  Windows -> Preferenes -> C/C++ -> Code Analysis ->  Seleccionar lodos los items de todos los Names menos Line comments.
 
Para el codigo que no generemos nosotros habra que que incluir excepciones en la erramienta de Code Analysis, las librerias HAL y los archivos del RTOS, es codigo que no estara exluido del Code Analysis. Para un warining o error que nos marque el code analysis, notamos de cual se trata con este dato el procedimiento para exlcuirlo es:
- Windows -> Preferences -> Code Analysis .... de la lista debemos buscar cual es la regla que no se cumple, luego continuamos con:
- Customize Selected -> Scope -> Exclusion patterns Add ... tipidamente se hace Add para dos reglas
Core/
Source/

Configuracion Formato:

Configuracion Diccionario:

