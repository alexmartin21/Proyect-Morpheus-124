/*
*@brief Muestra la funcionalidad de la estructura de datos
*
*@file command.h
*@author FJNR & AMH
*@version 1.0
*@date 01/02/2018
*@copyright GNU Public License
*/

#ifndef COMMAND_H
#define COMMAND_H

typedef enum enum_Command {
  NO_CMD = -1, 
  UNKNOWN, /*0*/
  EXIT, /*1*/
  FOLLOWING, /*etc*/
  PREVIOUS} T_Command;
/*Prototipo de funcion de comandos (se declara una variable estructurada  y se le asigna (NO_CMD = -1)
se inicializa una variable char que tiene de tamano 30 = "" / se inicializa una variable entero 
que obtiene el valor de 0; */
T_Command get_user_input();

#endif
