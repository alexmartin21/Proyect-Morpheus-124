/**
*@brief Manejo de jugadores (funcionalidad)
*
*
*@file player.h
*@author FJNR & AMH
*@version 1.0
*@date 06/02/2018
*@copyright GNU Public License
*/

#ifndef PLAYER_H
#define PLAYER_H
#include "types.h"

typedef struct _Player Player; /*NUEVA / ANTIGUA*/

/**
PLAYER CREATE : CONSTRUCTOR : si player == 0 retornara ERROR  guardara memoria dinamica
y asigna valores a los campos de la estructura nueva creada (newPlayer) retorna el puntero a estructura
*/
Player* player_create (Id id);
/**
PLAYER CREATE : DESTRUCTOR : si player == 0 retornara ERROR  liberara memoria dinamica y si lo llega a hacer
devolvera un codigo de estado (OK);
*/
STATUS player_destroy (Player);
/**
PLAYER SET NAME: Esta función simplemente establece el nombre copiándolo de name a (*Player).name, en el caso de que el destino sea NULL, devuelve Error con el condicional
*/
STATUS player_set_name (Player* , char* name);
/**
PLAYER GET NAME: Si el player == 0 retorna NULL si no retorna el nombre del player (Player->player)
*/
const char * player_get_name(Player* player)
/**
PLAYER SET INVENTORY ITEM: Si el player es NULL o id == (-1) habrá un error , si no , al player arma
se le asignará el valor de id
*/
STATUS player_set_inventory_item(Player* player, Id id);
/**
PLAYER SET LOCATION: Si el player es NULL o id == (-1) habrá un error , si no , al player util
se le asignará el valor de id
*/
STATUS player_set_location(Player* player, Id id);
/**
PLAYER GET INVENTORY ITEM: Si el player == 0 retorna (-1) si no retorna el id del player (Player->id)
*/
Id player_get_inventory_item(Player* player);
/**
PLAYER GET LOCATION: Si el player == 0 retorna (-1) si no retorna el id del player (Player->id)
*/
Id player_get_location(Player* player);
/**
PLAYER PRINT: /Si player ==0 devuelve ERROR / pone por pantalla el player inicial (con Id y Name) /
/Si idaux no esta vacio tras hacer llamadas a player_get_x (x: funcionalidades: N, S, E, W, O) se imprimira por pantallla que el link (conexion)
esta habilitada con el codigo idaux (declarado dentro de la funcion) si idaux = NO_ID (-1) imprime
que no hay conexion./ Tambien lo hace con player_get_player transimitiendo si hay o no player en el espacio.
RESUMIENDO: Control de errores Debugging.
*/
/**
COMENTARIO ALTERNATIVO ==> PLAYER PRINT: Control de errores Debugging
*/
STATUS player_print(Player* player);

#endif
