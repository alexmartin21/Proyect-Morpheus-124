/*
*@brief Implementa los comandos 
*
*@file command.c
*@author FJNR & AMH
*@version 1.0
*@date 01/02/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <strings.h>
#include "command.h"

/*
Definimos 2 macros: 
CMD_LENGHT para determinar el tamaño del array "input", de tipo char.
N_CMD para determinar el tamaño de los punteros "cmd_to_str" y "short_cmd_to_str" a los array de tipo char.
*/
#define CMD_LENGHT 30
#define N_CMD 5
/*Declaramos este puntero a char, que será el que después se usará para comparalo con el contenido de "input"*/
char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Following", "Previous"};
/*Ahora este puntero que lo compararemos también con el contenido de "input", para ver cual es el valor de "i", el entero que devuelve "srtcasecmp"*/
char *short_cmd_to_str[N_CMD] = {"","","e","f","p"};

/*Recoge el "input", y devuelve el "cmd", (mejor explicado en el fichero.h)*/
T_Command get_user_input(){
  T_Command cmd = NO_CMD;/*-1*/
  char input[CMD_LENGHT] = "";
  int i=UNKNOWN - NO_CMD + 1; /*2*/
  
  if (scanf("%s", input) > 0){    
    cmd = UNKNOWN; /*cmd=0 siempre*/
    while (cmd == UNKNOWN && i /*=2*/ < N_CMD /*=5*/){ /*UNKNOWN = 0 , N_CMD = 5*/
/*
La función "strcasecmp": 
Compares two strings irrespective of the case of characters.
Por ejemplo:
int strcasecmp(const char *f1, const char *f2);
This function returns an integer i:
i > 0, if lowercase(f1) is greater than lowercase(f2)
i < 0, if lowercase(f1) is found less than string lowercase(f2)
i = 0, if lowercase(f1) is equal to lowercase(f2).<=====ESTO ES LO QUE SE COMPRUEBA EN EL CONDICIONAL DE JUSTO DEBAJO
*/

/*IF <=== Si las cadenas son iguales ("input" y "short_cmd_to_str") el comando sera "e", de lo contrario se va sumando
hasta llegar a la "p", es decir, i = 5;*/

      if (!strcasecmp(input,short_cmd_to_str[i])){
        cmd = i /*=2*/ + NO_CMD/*=-1*/;
      }
      else{
	      i++;
      }
    }
  }
  /*Hay cuatro posibles cmd: "", "e", "f", "p" */
  return cmd;
}
