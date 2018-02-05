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

struct _Player {
  Id id;
  char name[WORD_SIZE+1];
  Id inventory_item;/*objeto del inventario*/
  Id location;/*localicación*/
};

/**
PLAYER CREATE : CONSTRUCTOR : si player == 0 retornara ERROR  guardara memoria dinamica
y asigna valores a los campos de la estructura nueva creada (newPlayer) retorna el puntero a estructura
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
/**
PLAYER CREATE : DESTRUCTOR : si player == 0 retornara ERROR  liberara memoria y si lo llega a hacer
devolvera un codigo de estado (OK);
*/
STATUS player_destroy (Player* player){
  if(!player){
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}
/**
PLAYER SET NAME: Esta función simplemente establece el nombre copiándolo de player a (*player).name, en el caso de que el destino sea NULL, devuelve Error con el condicional
*/
STATUS player_set_name (Player* , char* name){
  if (!player || !name){
    return ERROR;
  }
  if (!strcpy(player->name,name)){
    return ERROR;
  }

  return OK;
}
/**
PLAYER GET NAME: Si el player == 0 retorna NULL si no retorna el nombre del player (Player->player)
*/
const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}
/**
PLAYER SET INVENTORY ITEM: Si el player es NULL o id == (-1) habrá un error , si no , al player arma
se le asignará el valor de id
*/
STATUS player_set_inventory_item(Player* player, Id id) {
  if (!player || id == NO_ID) {
    return ERROR;
  }
  player->inventory_item = id;
  return OK;
}
/**
PLAYER SET LOCATION: Si el player es NULL o id == (-1) habrá un error , si no , al player util
se le asignará el valor de id
*/
STATUS player_set_location(Player* player, Id id) {
  if (!player || id == NO_ID) {
    return ERROR;
  }
  player->location = id;
  return OK;
}
/**
PLAYER GET INVENTORY ITEM: Si el player == 0 retorna (-1) si no retorna el id del player (Player->id)
*/
Id player_get_inventory_item(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->inventory_item;
}
/**
PLAYER GET LOCATION: Si el player == 0 retorna (-1) si no retorna el id del player (Player->id)
*/
Id player_get_location(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->location;
}
/**
PLAYER PRINT: Control de errores Debugging
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
