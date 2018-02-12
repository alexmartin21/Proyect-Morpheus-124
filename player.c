/**
*@brief Manejo de jugadores (funcionalidad)
*
*
*@file player.c
*@author FJNR & AMH
*@version 1.0
*@date 06/02/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "player.h"
#include "space.h"
#include "object.h"

/*Estrucura que para las caracteristicas de player*/
struct _Player {
  Id id;
  char name[WORD_SIZE+1];
  Object inventory_item;/*objeto del inventario*/
  Space location;/*localicación*/
};

/*
 * @brief Se encarga de crear el jugador,
   y poner el caracter fin de cadena al final del nombre de este
 * @param id, de tipo Id
 * @return newPlayer, que es el puntero a la estructura
 */
Player* player_create (Id id){
  Player *newPlayer = NULL;
  if (id == NO_ID){
    return NULL
  }
  newPlayer = (Player*)malloc(sizeof(Player))

  if (newPlayer==NULL){
    return NULL;
  }
  newPlayer->id
  newPlayer->name[0] = '\0';

  return newPlayer;
}

/*
 * @brief Libera memoria para player.
 * @param Player: puntero a Player .
 * @return status OK o ERROR.
 */
STATUS player_destroy (Player* player){
  if(!player){
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}

/*
 * @brief Pone o cambia el nombre del jugador
 * @param objeto: puntero a Objeto.
 * @param name: puntero a char.
 * @return status OK o ERROR.
 */
STATUS player_set_name (Player* player, char* name){
  if (!player || !name){
    return ERROR;
  }
  if (!strcpy(player->name,name)){
    return ERROR;
  }

  return OK;
}

/*
 * @brief Devuelve el nombre asignado a un jugador
 * @param jugador: puntero a Jugador.
 * @return name, el nombre que asignamos al jugador
 */
const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}

/*
 * @brief Pone o cambia el objeto del inventario
 * @param player: puntero a Player.
 * @param objeto: campo de Objeto.
 * @return status OK o ERROR.
 */
STATUS player_set_inventory_item(Player* player,Object object) {
  if (!player || !object) {
    return ERROR;
  }
  player->inventory_item = object;
  return OK;
}

/*
 * @brief Pone o cambia la localizacion de player
 * @param player: puntero a Player.
 * @param location: campo de Space.
 * @return status OK o ERROR.
 */
STATUS player_set_location(Player* player,Space location) {
  if (!player || !location) {
    return ERROR;
  }
  player->location = location;
  return OK;
}

/*
 * @brief Devuelve la inventory_item
 * @param jugador: puntero a Jugador.
 * @return player->inventory_item (objeto)
 */
Id player_get_inventory_item(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->inventory_item;
}

/*
 * @brief Devuelve la location
 * @param jugador: puntero a Jugador.
 * @return player->location(localizacion)
 */
Id player_get_location(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->location;
}

/*
 * @brief Muestra por la pantalla de salida, tanto el id, como el nombre del jugador
 * @param jugador: puntero a Jugador.
 * @return status, OK o ERROR
 */
 /**
 COMENTARIO ALTERNATIVO ==> PLAYER PRINT: Control de errores Debugging
 */
STATUS player_print(Player* player) {
  Id idaux = NO_ID;

  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

  idaux = player_get_inventory_item(player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> inventory_item: %ld.\n", idaux);
  }else {
    fprintf(stdout, "---> No inventory_item.\n");
  }
  idaux = player_get_location(player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Location: %ld.\n", idaux);
  }else {
    fprintf(stdout, "---> No location.\n");
  }

  return OK;
}

