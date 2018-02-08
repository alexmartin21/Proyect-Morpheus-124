/*
*@brief Carga de espacios (interfaz)
*
*
*@file game_reader.h
*@author FJNR & AMH
*@version 1.0
*@date 05/02/2018
*@copyright GNU Public License
*/
#ifndef GAME_READ
#define GAME_READ

#include "game.h"
#include "command.h"
#include "space.h"

typedef struct _Game{
  Id player_location;
  Id object_location;
  Space* spaces[MAX_SPACES + 1];
  T_Command last_cmd;
} Game;

/*
 * @brief funcionalidad de carga de espacios
 * @param game, es el string destino, en el que se copia el puntero al string de tipo char, "toks" 
 * @param filename, puntero a char, que es el nombre del fichero que estamos accediendo
 * @return status, OK O ERROR
 */
STATUS game_load_spaces(Game* game, char* filename);
/*
 * @brief funcionalidad de añadir espacios
 * @param game, puntero a estructura Game (direccion)
 * @param space , puntero a estructura Space (direccion)
 * @return status, OK O ERROR
 */
STATUS game_add_space(Game* game, Space* space);
/*
 * @brief funcionalidad leer el id de un espacio
 * @param game, puntero a estructura,(direccion)
 * @param position, posicion del espacio (en el array de punteros a Space)
 * @return NO_ID (si la posicion se sale de limites), space_get_id (la posicion)
 */
Id game_get_space_id_at(Game* game, int position);
/*
 * @brief funcionalidad de modificar la localizacion del jugador
 * @param game, puntero a Game (direccion)
 * @param id, que nos sirve para asginar el id de la nueva localizacion
 * @return ERROR, en el caso de que lo hubiera
 */
STATUS game_set_player_location(Game* game, Id id);
/*
 * @brief funcionalidad de carga de espacios
 * @param game,puntero a la estructura Game 
 * @param id, campo de la estructura Id
 * @return status, OK O ERROR
 */
STATUS game_set_object_location(Game* game, Id id);

#endif
