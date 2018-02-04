/** 
 * @brief It defines a textual graphic engine
 * 
 * @file graphic_engine.h
 *@author FJNR & AMH
 * @version 1.0 
 *@date 05/02/2018
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;
/**
GRAPHIC ENGINE CONSTRUCTOR: Utilizando funciones del módulo screen se generan unos puntos en la pantalla 
(x,y,width,height) todo ello en la pantalla generalizada que es screen_init (se reserva memoria dinamica para "ge" que es un
puntero declarado en esta misma funcion), se devolverá ese mismo puntero.
*/
Graphic_engine* graphic_engine_create();
/**
GRAPHIC ENGINE DESTRUCTOR: Es el encargado de llamar a todas las funciones DESTRUCTOR, para acabar liberando la memoria dinámica reservada en el GRAPHIC ENGINE CONSTRUCTOR
*/
void graphic_engine_destroy(Graphic_engine *ge);
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
