/**
*@brief Manejo de objetos (funcionalidad)
*
*
*@file object.c
*@author FJNR & AMH
*@version 1.0
*@date 05/02/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "object.h"

struct _Object {
  Id id;
  char name[WORD_SIZE+1];
  Id object_weapon;/*armas*/
  Id object_tool;/*utiles*/
  Id object_key;/*llaves*/
};
/**
OBJECT CREATE : CONSTRUCTOR : si objeto == 0 retornara ERROR  guardara memoria dinamica
y asigna valores a los campos de la estructura nueva creada (newObject) retorna el puntero a estructura
*/
Object* object_create (Id id){
  Object *newObject = NULL;
  if (id == NO_ID){
    return NULL
  }
  newObject = (Object*)malloc(sizeof(Object))

  if (newObject==NULL){
    return NULL;
  }
  newObject->id
  newObject->name[0] = '\0';

  return newObject;
}
/**
OBJECT CREATE : DESTRUCTOR : si objeto == 0 retornara ERROR  liberara memoria y si lo llega a hacer
devolvera un codigo de estado (OK);
*/
STATUS object_destroy (Object* object){
  if(!object){
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}
/**
OBJECT SET NAME: Esta función simplemente establece el nombre copiándolo de objeto a (*objeto).name, en el caso de que el destino sea NULL, devuelve Error con el condicional
*/
STATUS object_set_name (Object* , char* name){
  if (!object || !name){
    return ERROR;
  }
  if (!strcpy(object->name,name)){
    return ERROR;
  }

  return OK;
}
/**
OBJECT GET NAME: Si el objeto == 0 retorna NULL si no retorna el nombre del objeto (Object->objeto)
*/
const char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}
/**
OBJECT SET WEAPON: Si el objeto es NULL o id == (-1) habrá un error , si no , al objeto arma
se le asignará el valor de id
*/
STATUS object_set_weapon(Object* object, Id id) {
  if (!object || id == NO_ID) {
    return ERROR;
  }
  object->object_weapon = id;
  return OK;
}
/**
OBJECT SET TOOL: Si el objeto es NULL o id == (-1) habrá un error , si no , al objeto util
se le asignará el valor de id
*/
STATUS object_set_tool(Object* object, Id id) {
  if (!object || id == NO_ID) {
    return ERROR;
  }
  object->object_tool = id;
  return OK;
}
/**
OBJECT SET KEY: Si el objeto es NULL o id == (-1) habrá un error , si no , al objeto llave
se le asignará el valor de id
*/
STATUS object_set_key(Object* object, Id id) {
  if (!object || id == NO_ID) {
    return ERROR;
  }
  object->object_tool = id;
  return OK;
}
/**
OBJECT GET WEAPON: Si el objeto == 0 retorna (-1) si no retorna el id del objeto (Object->id)
*/
Id object_get_weapon(Object* objeto) {
  if (!objeto) {
    return NO_ID;
  }
  return objeto->object_weapon;
}
/**
OBJECT GET TOOL: Si el objeto == 0 retorna (-1) si no retorna el id del objeto (Object->id)
*/
Id object_get_tool(Object* objeto) {
  if (!objeto) {
    return NO_ID;
  }
  return objeto->object_tool;
}
/**
OBJECT GET KEY: Si el objeto == 0 retorna (-1) si no retorna el id del objeto (Object->id)
*/
Id object_get_key(Object* objeto) {
  if (!objeto) {
    return NO_ID;
  }
  return objeto->object_key;
}
/**
OBJECT PRINT: Control de errores Debugging
*/
STATUS object_print(Object* object) {
  Id idaux = NO_ID;

  if (!objeto) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", objeto->id, objeto->name);

  idaux = object_get_weapon(object);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Weapon: %ld.\n", idaux);
  }else {
    fprintf(stdout, "---> No weapon.\n");
  }
  idaux = object_get_tool(object);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Tool: %ld.\n", idaux);
  }else {
    fprintf(stdout, "---> No tool.\n");
  }

  idaux = object_get_key(object);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Key: %ld.\n", idaux);
  }else {
    fprintf(stdout, "---> No key.\n");
  }

  return OK;
}
