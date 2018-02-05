/*
*@brief Carga de espacios (funcionalidad)
*
*
*@file game_reader.c
*@author FJNR & AMH
*@version 1.0
*@date 05/02/2018
*@copyright GNU Public License
*/

/***************************************************************
/*
Game juego;
Game *pjuego;

if (game_create(juego)==ERROR){
/*Error al cargar el juego*//*
  return ERROR;
}
else {
  if(game_create_from_file(juego,data.dat)==ERROR){
    return ERROR;
  }
  else {
    game_print_screen(juego);
    game_print_data(juego);
  }
}
***************************************************************/

#include <stdio.h>
#include <string.h>
#include "game_reader.h"
#include "types.h"
#include "game.h"

/**
typedef struct _Game{
  Id player_location;
  Id object_location;
  Space* spaces[MAX_SPACES + 1];
  T_Command last_cmd;
} Game;
*/

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
P. F.: Private Function
*/


STATUS game_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space* space = NULL;
  STATUS status = OK;

  /*Comprueba que el nombre del fichero esta libre de error*/
  if (!filename) {
    return ERROR;
  }

 /*Comprueba que el fichero esta libre de error al abrirse*/
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  /**
  line: Es un puntero a un espacio de memoria
  WORD_SIZE: Es el límite de caracteres a leer (macro definida en types.h)
  file: puntero (archivo)
  RESUMIENDO: Este bucle, con "fgets", primero, establece donde se copiará el string leído,
  segundo, establece el numero máximo de caracteres que se pueden leer, la macro
  y por último, el último parámetro hace referencia a donde se obtienen los datos
  */
  while (fgets(line, WORD_SIZE, file)) {
    /**
    int strncmp(const char *s1, const char *s2, size_t n);
    Compara no más de n caracteres (caracteres posteriores al carácter nulo no se tienen en cuenta)
    de la cadena apuntada por s1 con la cadena apuntada por s2. //
    La función retorna un número entero mayor, igual, o menor que cero, apropiadamente
    según la cadena apuntada por s1 es mayor, igual, o menor que la cadena apuntada por s2.
    */
    /*En este caso, no compara más de 3 caracteres*/
    if (strncmp("#s:", line, 3) == 0) {
      /*"strtok" rompe el string "line" en la secuencia del carácter ASCII "|"*/
      toks = strtok(line + 3, "|");
      /*"atol" convierte la porción inicial de la cadena apuntada por "toks" a una representación de "id", y devuelve el valor convertido.
      Por lo tanto, "id" = valor convertido*/
      id = atol(toks);
      /*Continua la partición en segmentos hasta que "strtok" es NULL*/
      toks = strtok(NULL, "|");
      /*Copiamos el array "toks en el destino "name*/
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      /*"atol" convierte la porción inicial de la cadena apuntada por "toks" a una representación de "north", y devuelve el valor convertido.
      Por lo tanto, "north" = valor convertido*/
      north = atol(toks);
      toks = strtok(NULL, "|");
      /*"atol" convierte la porción inicial de la cadena apuntada por "toks" a una representación de "east", y devuelve el valor convertido.
      Por lo tanto, "east" = valor convertido*/
      east = atol(toks);
      toks = strtok(NULL, "|");
      /*"atol" convierte la porción inicial de la cadena apuntada por "toks" a una representación de "south", y devuelve el valor convertido.
      Por lo tanto, "south" = valor convertido*/
      south = atol(toks);
      toks = strtok(NULL, "|");
      /*"atol" convierte la porción inicial de la cadena apuntada por "toks" a una representación de "west", y devuelve el valor convertido.
      Por lo tanto, "west" = valor convertido*/
      west = atol(toks);

    #ifdef DEBUG /*Se ejecuta el código de dentro si debug está definido*/

      printf("Leído: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);

    #endif
    /**
    /Asignacion de un nuevo espacio a space (reserva memoria dinamica) y preparacion para asignar punteros con funciones/
    /Si space_create no devuelve NULL (esta preparado y con memoria dinamica) hara llamadas a las funciones para igualar
    el nombre , north , etc al puntero space->id (devolvera OK si es asi)
    */
    space = space_create(id);
      if (space != NULL) {
	      space_set_name(space, name);
	      space_set_north(space, north);
	      space_set_east(space, east);
	      space_set_south(space, south);
	      space_set_west(space, west);
	      game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {/*Se modifica el estado del código de error "int ferror (FILE* stream) " Devuelve un valor distinto de cero si se detectan errores*/
    status = ERROR;
  }
  /*Se cierra el fichero*/
  fclose(file);

  return status;
}
