/**
*@brief It defines a space
*
*
*@file space.c
*@author FJNR & AMH
*@version 1.0
*@date 05/02/2018
*@copyright GNU Public License
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"

struct _Space {
  Id id;
  char name[WORD_SIZE + 1];
  Id north;
  Id south;
  Id east;
  Id west;
  BOOL object;
};
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
SCREEN_MAX_STR = 80 <==screen.h
P.F.: Private Function
*/
/**
SPACE_CREATE : CONSTRUCTOR : reserva memoria dinamica para la estructura Space 
y asigna valores a los campos de la estructura nueva creada (newSpace) retorna el puntero a estructura
*/
Space* space_create(Id id) {

  Space *newSpace = NULL;

  if (id == NO_ID)
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));

  if (newSpace == NULL) {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;

  newSpace->object = FALSE;

  return newSpace;
}

/**
SPACE_CREATE : DESTRUCTOR : si space == 0 retornara ERROR  liberara memoria y si lo llega a hacer
devolvera un codigo de estado (OK);
*/

STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

  free(space);
  space = NULL;

  return OK;
}

/**
SPACE SET NAME: Esta función simplemente establece el nombre copiándolo de name a (*space).name, en el caso de que el destino sea NULL, devuelve Error con el condicional
*/

STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

/**
SPACE SET NORTH: Si el espacio es NULL o id == (-1) habrá un error , si no , al espacio norte
se le asignará el valor de id 
*/

STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

/**
SPACE SET SOUTH: Si el espacio es NULL o id == (-1) habrá un error , si no , al espacio sur
se le asignará el valor de id 
*/

STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

/**
SPACE SET EAST:Si el espacio es NULL o id == (-1) habrá un error , si no , al espacio este
se le asignará el valor de id y retornara el codigo OK
*/

STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

/**
SPACE SET WEST: Si el espacio es NULL o id == (-1) habrá un error , si no , al espacio oeste
se le asignará el valor de id y retornara el codigo OK
*/

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

/**
SPACE SET OBJECT: Se encarga de establecer el espacio objeto, asignándolo a value y devolviendo el error si lo hubiera, es decir, si no existiera space
*/

STATUS space_set_object(Space* space, BOOL value) {
  if (!space) {
    return ERROR;
  }
  space->object = value;
  return OK;
}
/**
SPACE GET NAME: Si el espacio == 0 retorna NULL si no retorna el nombre del espacio (Space->name)
*/

const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}
/**
SPACE GET ID: Si el espacio == 0 retorna (-1) si no retorna el nombre del espacio (Space->id)
*/
Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

/**
SPACE SET NORTH: Si el espacio ==0 retornara (-1) si no retornara espace->north
*/

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

/**
SPACE SET SOUTH:Si el espacio ==0 retornara (-1) si no retornara espace->south
*/

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

/**
SPACE GET EAST:Si el espacio ==0 retornara (-1) si no retornara espace->east
*/

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

/**
SPACE GET WEST:Si el espacio ==0 retornara (-1) si no retornara espace->west
*/

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

/**
SPACE GET OBJECT: Esta función es similar a space_set_object pero en vez de asginar a value, devuelve el atributo objeto, y False, si no existiera space 
*/

BOOL space_get_object(Space* space) {
  if (!space) {
    return FALSE;
  }
  return space->object;
}

/**
SPACE PRINT: /Si space ==0 devuelve ERROR / pone por pantalla el espacio inicial (con Id y Name) / 
/Si idaux no esta vacio tras hacer llamadas a space_get_x (x: funcionalidades: N, S, E, W, O) se imprimira por pantallla que el link (conexion)
esta habilitada con el codigo idaux (declarado dentro de la funcion) si idaux = NO_ID (-1) imprime 
que no hay conexion./ Tambien lo hace con space_get_object transimitiendo si hay o no objeto en el espacio.
*/

STATUS space_print(Space* space) {
  Id idaux = NO_ID;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  if (space_get_object(space)) {
    fprintf(stdout, "---> Object in the space.\n");
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  return OK;
}



