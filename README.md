# fmc_320a - Computador de Caudales.

Instruccion Para Clonar y Version del STM32CubeIDE:
- El proyecto corre en STM32Cube IDE 1.12
- Aunque trabaja con carpetas no absolutas clonar el proyecto en d:\githubs\fm-320a\
- File -> Switch Workspace -> d:\githubs\fmc-320a 
- File -> Open Project From File System -> Directory -> d:\githubs\fmc-320a -> (Se debe desticlear la opción que dice libs/fm_lcd para que no figure como una carpeta externa y aparezca efectivamente dentro de libs/)-> Finish

En este punto debería ver en Project Explorer todos los proyectos relacionados, si no los ve es posible que precionando en el pequeño icono restore, arriba a la izquierda, los muestre.

Configurar el límite de linea par que sea visible en 80 caracteres
- Windows -> Preferences -> General -> Editors -> Text Editors
- Macar Show print margin
- Print margin columm: 80

Configuraciones Code Analysis
  Windows -> Preferenes -> C/C++ -> Code Analysis ->  Seleccionar lodos los items de todos los Names menos Line comments.
 
Para el codigo que no generemos nosotros habra que que incluir excepciones en la herramienta de Code Analysis, las librerias HAL y los archivos del RTOS, es codigo que no estara exluido del Code Analysis. Para un warining o error que nos marque el code analysis, notamos de cual se trata con este dato el procedimiento para exlcuirlo es:
- Windows -> Preferences -> Code Analysis .... de la lista debemos buscar cual es la regla que no se cumple, luego continuamos con:
- Customize Selected -> Scope -> Exclusion patterns Add ... tipicamente se hace Add para dos reglas
Core/
Source/

Configuracion Formato:
- Windows -> Preferences -> C/C++ -> Code Style -> Formatter -> Import... ->  d:\githubs\fm-320a\stm32cubeide_preferences\ide_formatter

Configuracion Diccionario:
- Windows -> Preferences -> General -> Editors -> Text Editors -> Spelling.
- En la sección de Dictionaries -> User defined dictionary: Browse... ->  d:\githubs\fm-320a\stm32cubeide_preferences\user_defined_dictionary_esp -> abrir.
- El diccionario en Español no está completo por lo que se debe actualizar al ver que el IDE subraya en rojo las palabras que están correctamente escritas. Para agregar palabras nuevas se debe apoyar el cursor en la palabra subrayada y seleccionar la opción de "Add PALABRA to dictionary".

Al finalizar darle a la opción de Apply and close del menu Preferences.