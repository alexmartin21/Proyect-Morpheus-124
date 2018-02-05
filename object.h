/**
*@brief Manejo de objetos (interfaz)
*
*
*@file object.h
*@author FJNR & AMH
*@version 1.0
*@date 05/02/2018
*@copyright GNU Public License
*/

#ifndef OBJECT_H
#define OBJECT_H
#include "types.h"

typedef struct _Object Object; /*NUEVA / ANTIGUA*/

/**
OBJECT CREATE : CONSTRUCTOR : si objeto == 0 retornara ERROR  guardara memoria dinamica
y asigna valores a los campos de la estructura nueva creada (newObject) retorna el puntero a estructura
*/
Object* object_create (Id id);
/**
OBJECT CREATE : DESTRUCTOR : si objeto == 0 retornara ERROR  liberara memoria y si lo llega a hacer
devolvera un codigo de estado (OK);
*/
STATUS object_destroy (Object);
/**
OBJECT SET NAME: Esta función simplemente establece el nombre copiándolo de name a (*space).name, en el caso de que el destino sea NULL, devuelve Error con el condicional
*/
STATUS object_set_name (Object* , char* name);
/**
OBJECT GET NAME: Si el objeto == 0 retorna NULL si no retorna el nombre del objeto (Object->objeto)
*/
const char * object_get_name(Object* object)
/**
OBJECT SET WEAPON: Si el objeto es NULL o id == (-1) habrá un error , si no , al objeto arma
se le asignará el valor de id
*/
STATUS object_set_weapon(Object* object, Id id);
/**
OBJECT SET TOOL: Si el objeto es NULL o id == (-1) habrá un error , si no , al objeto util
se le asignará el valor de id
*/
STATUS object_set_tool(Object* object, Id id);
/**
OBJECT SET KEY: Si el objeto es NULL o id == (-1) habrá un error , si no , al objeto llave
se le asignará el valor de id
*/
STATUS object_set_key(Object* object, Id id);
/**
OBJECT GET WEAPON: Si el objeto == 0 retorna (-1) si no retorna el id del objeto (Object->id)
*/
Id object_get_weapon(Object* objeto);
/**
OBJECT GET TOOL: Si el objeto == 0 retorna (-1) si no retorna el id del objeto (Object->id)
*/
Id object_get_tool(Object* objeto);
/**
OBJECT GET KEY: Si el objeto == 0 retorna (-1) si no retorna el id del objeto (Object->id)
*/
Id object_get_key(Object* objeto);
/**
OBJECT PRINT: /Si objeto ==0 devuelve ERROR / pone por pantalla el objeto inicial (con Id y Name) /
/Si idaux no esta vacio tras hacer llamadas a object_get_x (x: funcionalidades: N, S, E, W, O) se imprimira por pantallla que el link (conexion)
esta habilitada con el codigo idaux (declarado dentro de la funcion) si idaux = NO_ID (-1) imprime
que no hay conexion./ Tambien lo hace con object_get_object transimitiendo si hay o no objeto en el espacio.
RESUMIENDO: Control de errores Debugging.
*/
/**
COMENTARIO ALTERNATIVO ==> OBJECT PRINT: Control de errores Debugging
*/
STATUS object_print(Object* object);

#endif
