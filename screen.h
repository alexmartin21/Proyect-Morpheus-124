/** 
 * @brief It defines a screen
 * 
 * @file screen.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 11-01-2017
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80

typedef struct _Area Area;

void  screen_init();
void  screen_destroy();
void  screen_paint();
void  screen_gets(char *str);

Area* screen_area_init(int x, int y, int width, int height);
void  screen_area_destroy(Area* area);
void  screen_area_clear(Area* area);
void  screen_area_reset_cursor(Area* area);
void  screen_area_puts(Area* area, char *str);

#endif
/**
 * @brief Define la pantalla
 *
 *
 * @file screen.h
 * @author FJNR & AMH
 * @version 1.0
 * @date 04/02/2018
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80

typedef struct _Area Area;

/**
SCREEN CONSTRUCTOR: Reserva memoria dinamica ((ROWS *COLUMNS )+1)
Funciones utilizadas : *memset(void *str, int c, size_t n) copia el caracter c a los primeros n
caracteres de str ==>En este caso el numero que representa BG_CHAR en ASCII (126).
*/
void  screen_init();
/**
SCREEN DESTRUCTOR: Libera la memoria de la variable "__data" con el condicional "__data != 0"
*/
void  screen_destroy();
/**
SCREEN PAINT: Encargada de asociar los códigos de los colores guardados en el array "dest"
*/
void  screen_paint();
/**
SCREEN GET: Saca por pantalla prompt>:
stdin	  | Entrada estándar ==>Descriptor de archivo = 2
stdout	| Salida estándar ==>Descriptor de archivo = 1
stderr	| Error típico
*/
void  screen_gets(char *str);
/**
SCREEN AREA CONTRUCTOR: Libera la memoria de la variable "area" con el condicional "area != 0"
ACCESS(d, x, y) == (d + ((y) * COLUMNS) + (x)) // d ,x , y hacen de "parametros" de la MACRO
Si la reserva dinamica de memoria de "area" =! 0
Funciones utilizadas : *memset(void *str, int c, size_t n) copia el caracter c a los primeros n
caracteres de str /// anchura = width / altura = height .
*/

Area* screen_area_init(int x, int y, int width, int height);
/**
SCREEN AREA DESTROY: Libera la memoria de la variable area "area != 0"
*/
void  screen_area_destroy(Area* area);
/**
SCREEN AREA CLEAR: Si area != NULL (Si "i" es menor que altura se copia FG_CHAR = ' ' tantas veces como
width casteando con size_t que es un unsigned integer type de al menos 16 bits) en el array que deja ACCESS
*/
void  screen_area_clear(Area* area);
/**
SCREEN AREA RESET CURSOR: Con el condicional "area != 0", el cursor se incluye como tipo del puntero area
Se sumaria __data con (y * filas(ROWS)) + (x *columnas(COLUMNS)) (reset del cursor )
*/
void  screen_area_reset_cursor(Area* area);
/**
SCREEN AREA PUTS: Si la pantalla se va del limite la sube / Se remplazan los caracteres especiales/
El bucle : Le dice al cursor la anchura con la que tiene que inicializarse y a continuación se encarga de seguirlo
Teniendo en cuenta que:
void *memset(void *s, int c, size_t n);
Copia el valor de c (convertido a unsigned char) en cada uno de los primeros n caracteres en el objeto apuntado por s.
La función retorna el valor de s.
/////
void *memcpy(void *s1, const void *s2, size_t n);
Copia los primeros n caracteres del objeto apuntado por s2 al objeto apuntado por s1.
La función retorna el valor de s1. Si al copiar un objeto al otro se superponen, entonces el comportamiento no está definido.
*/
void  screen_area_puts(Area* area, char *str);

#endif
