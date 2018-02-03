/*
*@brief Define la interfaz del juego
*
*
*@file game.h
*@author FJNR & AMH
*@version 1.0
*@date 03/02/2018
*@copyright GNU Public License
*/

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"

typedef struct _Game{
  Id player_location;
  Id object_location;
  Space* spaces[MAX_SPACES + 1];
  T_Command last_cmd;
} Game;
/**
CONSTRUCTOR: Comprueba si se puede puede crear el juego (devuelve OK si ha sido así, de lo contrario ERROR)
*/
STATUS game_create(Game* game);
/**
CONTRUCTOR FROM FILE: Comprueba que el CONSTRUCTOR y el LOAD SPACES funcionan con éxito,
de comprobar que no hay error con el fichero
y de llamar a las funciones que establecen las posiciones del jugador y objeto
*/
STATUS game_create_from_file(Game* game, char* filename);
/**
   GAME UPDATE: OOOOOOOOOOOOOOOOOOOOOOOOOOOJJJJJJJJJJJJJJJJJJJJJJOOOOOOOOOOOOOOOOOOOOOOOOO
*/
STATUS game_update(Game* game, T_Command cmd);
/**
   DESTRUCTOR: Destruye los espacios del array spaces (devuelve OK si ha sido así)
*/
STATUS game_destroy(Game* game);
/**
   GAME OVER: Funcion BOOL que usaremos en otro fichero.c para el final del juego
*/
BOOL   game_is_over(Game* game);
void   game_print_screen(Game* game);
/**
   IMPRIMIR DATOS: Se asegura del error del array "spaces" y imprime las localizaciones de player y object 
*/
void   game_print_data(Game* game);
/**
   TAD (GET): completa el array de space un espacio desde que esta vacio
   -Si los argumentos estan vacios = ERROR 
*/
Space* game_get_space(Game* game, Id id);
/**
   SET PLAYER LOCATION: Comprueba el error comparando la macro y establece la posicion del jugador en el juego
*/
Id     game_get_player_location(Game* game);
/**
   SET OBJECT LOCATION: Comprueba el error comprarando la macro y establece la posicion del objeto en el juego
*/
Id     game_get_object_location(Game* game);
/**
   GET LAST COMMAND: Devuelve el CMD de "last_cmd" al puntero game, como argumento
*/
T_Command game_get_last_command(Game* game);
#endif
