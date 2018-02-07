#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define OBJECT_NAME 100
#include <time.h>
/*
int aleatorio(int a, int b) {
return (int) (a + (double) rand() / (RAND_MAX-1) * (b - a + 1));
}
*/

int main (){
  int i;
  char objeto[OBJECT_NAME];
  int numero;
  int numero2;
  int porcentaje;
  int bucle;
  bucle = 100;

  time_t t;
  time_t t2;

  srand((unsigned) time(&t));
  numero = (rand() %100);


  if (numero > 50){
    srand((unsigned) time(&t2));
    numero2= (rand() %6);


    if (numero2 == 0){
      goto OBJECT_ESCOPETA;
    }
    else if (numero2 == 1){
      goto OBJECT_GRANADA;
    }
    else if (numero2 == 2){
      goto OBJECT_REVOLVER;
    }
    else if (numero2 == 3){
      goto OBJECT_FUSILASALTO;
    }
    else if (numero2 == 4){
      goto OBJECT_SMG;
    }
    else if (numero2 == 5){
      goto OBJECT_PESADA;
    }
    else{
      goto OBJECT_FRANCOTIRADOR;
    }
  }

  else if(numero<50 && numero > 30){
    srand((unsigned) time(&t2));
    numero2= (rand() %4);



    if (numero2 == 0){
      goto OBJECT_BEISBOL;
    }
    else if (numero2 == 1){
      goto OBJECT_HACHA;
    }
    else if (numero2 == 2){
      goto OBJECT_PALA;
    }
    else if (numero2 == 3){
      goto OBJECT_PUNIOAMERICANO;
    }
    else {
      goto OBJECT_MACHETE;
    }
  }

  else {
    srand((unsigned) time(&t2));
    numero2= (rand() %7);


    if (numero2 == 0){
      goto OBJECT_LLAVE;
    }
    else if (numero2 == 1){
      goto OBJECT_MAPA;
    }
    else if (numero2 == 2){
      goto OBJECT_BEBIDA;
    }
    else if (numero2 == 3){
      goto OBJECT_LINTERNA;
    }
    else if (numero2 == 4){
      goto OBJECT_ANTORCHA;
    }
    else if (numero2 == 5){
      goto OBJECT_CAMARA;
    }
    else if (numero2 == 6){
      goto OBJECT_BATERIA;
    }

  }
  OBJECT_ESCOPETA: strcpy(objeto,"Escopeta");goto PRINT;
  OBJECT_REVOLVER: strcpy(objeto,"Revolver");goto PRINT;
  OBJECT_GRANADA: strcpy(objeto,"Granada de mano");goto PRINT;
  OBJECT_FUSILASALTO: strcpy(objeto,"Fusil de asalto");goto PRINT;
  OBJECT_SMG: strcpy(objeto,"SMG");goto PRINT;
  OBJECT_PESADA: strcpy(objeto,"Ametralladora pesada");goto PRINT;
  OBJECT_FRANCOTIRADOR: strcpy(objeto,"Fusil de francotirador");goto PRINT;
  OBJECT_BEISBOL: strcpy(objeto,"Bate de baseball");goto PRINT;
  OBJECT_HACHA: strcpy(objeto,"Hacha");goto PRINT;
  OBJECT_PALA: strcpy(objeto,"Pala");goto PRINT;
  OBJECT_PUNIOAMERICANO: strcpy(objeto,"Punio Americano");goto PRINT;
  OBJECT_MACHETE:  strcpy(objeto,"Machete");goto PRINT;
  OBJECT_LLAVE: strcpy(objeto,"Llave");goto PRINT;
  OBJECT_MAPA: strcpy(objeto,"Mapa");goto PRINT;
  OBJECT_BEBIDA: strcpy(objeto,"Bebida energetica");goto PRINT;
  OBJECT_LINTERNA: strcpy(objeto,"linterna");goto PRINT;
  OBJECT_ANTORCHA: strcpy(objeto,"Antorcha");goto PRINT;
  OBJECT_CAMARA: strcpy(objeto,"Camara");goto PRINT;
  OBJECT_BATERIA:strcpy(objeto,"Pilas");goto PRINT;
  OBJECT_MOCHILA:strcpy(objeto,"Mochila");goto PRINT;
  PRINT: printf("%s",objeto);

  return 0;
}
