/**
*@brief It defines a space
*
*
*@file space.h
*@author FJNR & AMH
*@version 1.0
*@date 05/02/2018
*@copyright GNU Public License
*/

#ifndef SPACE_H
#define SPACE_H

#include "types.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1
/**
SPACE_CREATE : CONSTRUCTOR : reserva memoria dinamica para la estructura Space 
y asigna valores a los campos de la estructura nueva creada (newSpace) retorna el puntero a estructura
*/
Space* space_create(Id id);
/**
SPACE_CREATE : DESTRUCTOR : si space == 0 retornara ERROR  liberara memoria y si lo llega a hacer
devolvera un codigo de estado (OK);
*/
STATUS space_destroy(Space* space);
/**
SPACE GET ID: Si el espacio == 0 retorna (-1) si no retorna el nombre del espacio (Space->id)
*/
Id space_get_id(Space* space);
/**
SPACE SET NAME: Esta función simplemente establece el nombre copiándolo de name a (*space).name, en el caso de que el destino sea NULL, devuelve Error con el condicional
*/
STATUS space_set_name(Space* space, char* name);
/**
SPACE GET NAME: Si el espacio == 0 retorna NULL si no retorna el nombre del espacio (Space->name)
*/
const char* space_get_name(Space* space);
/**
SPACE SET NORTH: Si el espacio es NULL o id == (-1) habrá un error , si no , al espacio norte
se le asignará el valor de id 
*/
STATUS space_set_north(Space* space, Id id);
/**
SPACE SET NORTH: Si el espacio ==0 retornara (-1) si no retornara espace->north
*/
Id space_get_north(Space* space);
/**
SPACE SET SOUTH: Si el espacio es NULL o id == (-1) habrá un error , si no , al espacio sur
se le asignará el valor de id 
*/
STATUS space_set_south(Space* space, Id id);
/**
SPACE SET SOUTH:Si el espacio ==0 retornara (-1) si no retornara espace->south
*/
Id space_get_south(Space* space);
/**
SPACE SET EAST:Si el espacio es NULL o id == (-1) habrá un error , si no , al espacio este
se le asignará el valor de id y retornara el codigo OK
*/
STATUS space_set_east(Space* space, Id id);
/**
SPACE GET EAST:Si el espacio ==0 retornara (-1) si no retornara espace->east
*/
Id space_get_east(Space* space);
/**
SPACE SET WEST: Si el espacio es NULL o id == (-1) habrá un error , si no , al espacio oeste
se le asignará el valor de id y retornara el codigo OK
*/
STATUS space_set_west(Space* space, Id id);
/**
SPACE GET WEST:Si el espacio ==0 retornara (-1) si no retornara espace->west
*/
Id space_get_west(Space* space);
/**
SPACE SET OBJECT: Se encarga de establecer el espacio objeto, asignándolo a value y devolviendo el error si lo hubiera, es decir, si no existiera space
*/
STATUS space_set_object(Space* space, BOOL value);
/**
SPACE GET OBJECT: Esta función es similar a space_set_object pero en vez de asginar a value, devuelve el atributo objeto, y False, si no existiera space 
*/
BOOL space_get_object(Space* space);
/**
SPACE PRINT: /Si space ==0 devuelve ERROR / pone por pantalla el espacio inicial (con Id y Name) / 
/Si idaux no esta vacio tras hacer llamadas a space_get_x (x: funcionalidades: N, S, E, W, O) se imprimira por pantallla que el link (conexion)
esta habilitada con el codigo idaux (declarado dentro de la funcion) si idaux = NO_ID (-1) imprime 
que no hay conexion./ Tambien lo hace con space_get_object transimitiendo si hay o no objeto en el espacio.
*/
STATUS space_print(Space* space);

#endif
