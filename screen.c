/**
*@brief Implementa la pantalla
*
*
*@file screen.c
*@author FJNR & AMH
*@version 1.0
*@date 04/02/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#pragma GCC diagnostic ignored "-Wpedantic"

#define ROWS 23
#define COLUMNS 80
#define TOTAL_DATA (ROWS * COLUMNS) + 1

#define BG_CHAR '~'
#define FG_CHAR ' '
#define PROMPT " prompt:> "

#define ACCESS(d, x, y) (d + ((y) * COLUMNS) + (x)) /*puntero a void */
/**                 Definidos en:
                        ||
                        ||
                        V
WORD_SIZE = 1000 <==types.h
MAX_SPACES = 100 <==space.h
FIRST_SPACE = 1 <==space.h
NO_ID = -1 <==types.h
NO_CMD = -1 <==command.h
UNKNOWN = 0 <==command.h
EXIT = 1 <==command.h
FOLLOWING = 2 <==command.h
PREVIOUS = 3 <==command.h
SCREEN_MAX_STR = 80 <==screen.h
P.F.: Private Function
*/
struct _Area{
  int x, y, width, height;
  char *cursor;
};

char *__data;

/****************************/
/*     Private functions    */
/****************************/
int  screen_area_cursor_is_out_of_bounds(Area* area);
void screen_area_scroll_up(Area* area);
void screen_utils_replaces_special_chars(char* str);

/****************************/
/* Functions implementation */
/****************************/
/**
SCREEN CONSTRUCTOR: Reserva memoria dinamica ((ROWS *COLUMNS )+1)
Funciones utilizadas : *memset(void *str, int c, size_t n) copia el caracter c a los primeros n
caracteres de str ==>En este caso el numero que representa BG_CHAR en ASCII (126).
*/
void screen_init(){
  screen_destroy(); /* Dispose if previously initialized */
  __data = (char *) malloc(sizeof(char) * TOTAL_DATA);

  if (__data){
    memset(__data, (int) BG_CHAR, TOTAL_DATA); /*Fill the background*/
    *(__data + TOTAL_DATA - 1) = '\0';         /*NULL-terminated string*/
  }
}

/**
SCREEN DESTRUCTOR: Libera la memoria de la variable "__data" con el condicional "__data != 0"
*/

void screen_destroy(){
  if (__data)
    free(__data);
}

/**
SCREEN PAINT: Encargada de asociar los códigos de los colores guardados en el array "dest"
*/

void screen_paint(){
  char *src = NULL;
  char dest[COLUMNS + 1];
  int i=0;

  memset(dest, 0, COLUMNS + 1);

  if (__data){
    /* puts(__data); */ /*Dump data directly to the terminal*/
    /*It works fine if the terminal window has the right size*/

    puts("\033[2J"); /*Clear the terminal*/
    for (src=__data; src < (__data + TOTAL_DATA - 1); src+=COLUMNS){
      memcpy(dest, src, COLUMNS);
      /* printf("%s\n", dest); */
      for (i=0; i<COLUMNS; i++){
	if (dest[i] == BG_CHAR){
	  printf("\033[0;34;44m%c\033[0m", dest[i]); /* fg:blue(34);bg:blue(44) */
	}else{
	  printf("\033[0;30;47m%c\033[0m", dest[i]); /* fg:black(30);bg:white(47)*/
	}
      }
      printf("\n");
    }
  }
}
/**
SCREEN GET: Saca por pantalla prompt>:
stdin	  | Entrada estándar ==>Descriptor de archivo = 2
stdout	| Salida estándar ==>Descriptor de archivo = 1
stderr	| Error típico
*/
void screen_gets(char *str){
  fprintf(stdout, PROMPT);
  if (fgets(str, COLUMNS, stdin))
    *(str + strlen(str) - 1) = 0; /* Replaces newline character with '\0' */
}

/**
SCREEN AREA CONTRUCTOR: Libera la memoria de la variable "area" con el condicional "area != 0"
ACCESS(d, x, y) == (d + ((y) * COLUMNS) + (x)) // d ,x , y hacen de "parametros" de la MACRO
Si la reserva dinamica de memoria de "area" =! 0
Funciones utilizadas : *memset(void *str, int c, size_t n) copia el caracter c a los primeros n
caracteres de str /// anchura = width / altura = height .
*/

Area* screen_area_init(int x, int y, int width, int height){
  int i = 0;
  Area* area = NULL;

  if ( (area  = (Area*) malloc (sizeof(struct _Area))) ){
    *area = (struct _Area) {x, y, width, height, ACCESS(__data, x, y)};  /*XXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

    for (i=0; i < area->height; i++) /*Si i es menor que la altura  se copia el caracter ' ' que equivale a 32 en ASCII a el string
    que genera ACCESS tantas veces como lo indique la anchura */
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);/*XXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
  }

  return area;
}

/**
SCREEN AREA DESTROY: Libera la memoria de la variable area "area != 0"
*/

void screen_area_destroy(Area* area){
  if(area)
    free(area);
}

/**
SCREEN AREA CLEAR: Si area != NULL (Si "i" es menor que altura se copia FG_CHAR = ' ' tantas veces como
width casteando con size_t que es un unsigned integer type de al menos 16 bits) en el array que deja ACCESS
*/

void screen_area_clear(Area* area){
  int i = 0;

  if (area){
    screen_area_reset_cursor(area);

    for (i=0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width); 
  }
}

/**
SCREEN AREA RESET CURSOR: Con el condicional "area != 0", el cursor se incluye como tipo del puntero area
Se sumaria __data con (y * filas(ROWS)) + (x *columnas(COLUMNS)) (reset del cursor )
*/

void screen_area_reset_cursor(Area* area){
  if (area)
    area->cursor = ACCESS(__data, area->x, area->y);
}

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

void screen_area_puts(Area* area, char *str){
  int len = 0;
  char *ptr = NULL;

  if (screen_area_cursor_is_out_of_bounds(area))
    screen_area_scroll_up(area);

  screen_utils_replaces_special_chars(str);

  for (ptr = str; ptr < (str + strlen(str)); ptr+=area->width){
    memset(area->cursor, FG_CHAR, area->width);
    len = (strlen(ptr) < area->width)? strlen(ptr) : area->width; /*variable = condición ? valor si cierto : valor si falso*/
    memcpy(area->cursor, ptr, len);
    area->cursor += COLUMNS; /*cursor += height*/
  }
}

/**
P.F. SCREEN AREA CURSOR IS OUT OF BOUNDS: Devuelve el atributo cursor cuando se sitúa en la esquina superior derecha (sumando la altura y achura), es decir, cuado se sale de límites
*/

int screen_area_cursor_is_out_of_bounds(Area* area){
  return area->cursor > ACCESS(__data,
			       area->x + area->width,
			       area->y + area->height - 1);
}

/**
P.F. SCREEN AREA SCROLL UP: Esta función es la encargada de sumar en el atributo cursor con un "for", las columnas que tenía, mas las que añade el jugador cada vez que aumenta la altura (height, COLUMNS), con el cursor 
*/

void screen_area_scroll_up(Area* area){
  for(area->cursor = ACCESS(__data, area->x, area->y);
      area->cursor < ACCESS(__data, area->x + area->width, area->y + area->height - 2);
      area->cursor += COLUMNS){
    memcpy(area->cursor, area->cursor+COLUMNS, area->width);
  }
}

/**
P.F. SCREEN UTILS REPLACES SPECIAL CHARS: 
char *strpbrk(const char *s1, const char *s2); Localiza la primera aparición de la cadena apuntada por s1 de cualquier carácter de la cadena apuntada por s2.
La función retorna un puntero al carácter, o un puntero nulo si ningún carácter de s2 apareció en s1
*/

void screen_utils_replaces_special_chars(char* str){
  char *pch = NULL;

  /* Replaces acutes and tilde with '??' */
  while ((pch = strpbrk (str, "ÁÉÍÓÚÑáéíóúñ")))
    memcpy(pch, "??", 2);
}
