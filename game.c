/*
*@brief Implementa la interfaz del juego y todas las llamadas para cada comando
*
*
*@file game.c
*@author FJNR & AMH
*@version 1.0
*@date 03/02/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

#define N_CALLBACK 4

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

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);

/**
   List of callbacks for each command in the game
*/
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_following(Game* game);
void game_callback_previous(Game* game);

/**
Array de punteros a funciones
static = unico en este modulo (evitar que se exponga) (cuidadin)

*/
static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_following,
  game_callback_previous};

/**
   Funciones privadas, las cuales solo se ponen en el fichero.c
*/

STATUS game_load_spaces(Game* game, char* filename);
STATUS game_add_space(Game* game, Space* space);
/*P. F. */
Id     game_get_space_id_at(Game* game, int position);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_object_location(Game* game, Id id);

/**
   Game interface implementation
*/
/**
   CONSTRUCTOR: Comprueba si se puede puede crear el juego (devuelve OK si ha sido así, de lo contrario ERROR)
*/
STATUS game_create(Game* game) {
  int i;

  for (i = 0; i < MAX_SPACES; i++) {/*Vacia el array spaces*/
    game->spaces[i] = NULL;
  }

  game->player_location = NO_ID;
  game->object_location = NO_ID;
  game->last_cmd = NO_CMD;

  return OK;
}
/**
CONTRUCTOR FROM FILE: Comprueba que el CONSTRUCTOR y el LOAD SPACES funcionan con éxito,
de comprobar que no hay error con el fichero
y de llamar a las funciones que establecen las posiciones del jugador y objeto
*/

STATUS game_create_from_file(Game* game, char* filename) {

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_load_spaces(game, filename) == ERROR)
    return ERROR;

  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}
/**
   DESTRUCTOR: Destruye los espacios del array spaces (devuelve OK si ha sido así)
*/

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }

  return OK;
}
/**
   TAD (ESTADO): completa el array de space un espacio desde que esta vacio
   -Si los argumentos estan vacios = ERROR
*/
STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}
/**kajldfkjal;kdjf;lakjdfkajdlkfja;ldjf;lakjdflkjad;lfkja;ldkjfla;kjdf
   TAD (ID): completa el array de space un espacio desde que esta vacio
   -Si los argumentos estan vacios = ERROR
*/

Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}
/**
   TAD (GET): completa el array de space un espacio desde que esta vacio
   -Si los argumentos estan vacios = ERROR
*/

Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}

/**
   SET PLAYER LOCATION: Comprueba el error comparando la macro y establece la posicion del jugador en el juego
*/
/*P. F. */
STATUS game_set_player_location(Game* game, Id id) {

  if (id == NO_ID) {
    return ERROR;
  }

  game->player_location = id;

}

/**
   SET OBJECT LOCATION: Comprueba el error comprarando la macro y establece la posicion del objeto en el juego
*/
/*P. F. */
STATUS game_set_object_location(Game* game, Id id) {

  int i = 0;

  if (id == NO_ID) {
    return ERROR;
  }

  game->object_location = id;

  return OK;
}

/**
   GET PLAYER LOCATION: Devuelve el ID de "player_location" al puntero game, como argumento
*/

Id game_get_player_location(Game* game) {
  return game->player_location;
}

/**
   GET PLAYER LOCATION: Devuelve el ID de "object_location" al puntero game, como argumento
*/

Id game_get_object_location(Game* game) {
  return game->object_location;
}

/**
   GAME UPDATE: OOOOOOOOOOOOOOOOOOOOOOOOOOOJJJJJJJJJJJJJJJJJJJJJJOOOOOOOOOOOOOOOOOOOOOOOOO
*/

STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

/**
   GET LAST COMMAND: Devuelve el CMD de "last_cmd" al puntero game, como argumento
*/

T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}

/**
   IMPRIMIR DATOS: Se asegura del error del array "spaces" y imprime las localizaciones de player y object
*/

void game_print_data(Game* game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int) game->object_location);
  printf("=> Player location: %d\n", (int) game->player_location);
  printf("prompt:> ");
}

/**
   GAME OVER: Funcion BOOL que usaremos en otro fichero.c para el final del juego
*/

BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
   Callbacks implementation for each action
*/

/**

*/

void game_callback_unknown(Game* game) {
}

/**

*/

void game_callback_exit(Game* game) {
}

/**

*/

void game_callback_following(Game* game) {
  int i = 0;
  Id current_id = NO_ID;/*-1*/
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_previous(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
/*P. F. */
STATUS game_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space* space = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
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

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}
