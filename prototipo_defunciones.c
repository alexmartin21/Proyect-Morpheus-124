#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define OBJECT_NAME 100

enum Armas_fuego {Escopeta, Revolver, Granada_de_Mano, Fusil_de_Asalto, SMG, Ametralladora_Pesada, Fusil_de_Francotirador};
enum Armas_mano {Bate_de_Baseball, Hacha, Pala, Punio_Americano, Machete};
enum Herramientas {Llave, Mapa, Bebida_Energetica, Linterna, Antorcha, Camara, Pilas, Mochila};

int main (){
  char objeto[OBJECT_NAME];
  int porcentaje;

  time_t t;
  time_t t2;

  srand((unsigned) time(&t));
  porcentaje = (rand() %100);

  if (porcentaje > 50){
    srand((unsigned) time(&t2));
    enum Armas_fuego fuego = (rand() %6);
    switch (fuego) {
      case Escopeta: strcpy(objeto,"Escopeta");goto PRINT;break;
      case Revolver: strcpy(objeto,"Revólver");goto PRINT;break;
      case Granada_de_Mano: strcpy(objeto,"Granada de Mano");goto PRINT;break;
      case Fusil_de_Asalto: strcpy(objeto,"Fusil de Asalto");goto PRINT;break;
      case SMG: strcpy(objeto,"SMG");goto PRINT;break;
      case Ametralladora_Pesada: strcpy(objeto,"Ametralladora Pesada");goto PRINT;break;
      case Fusil_de_Francotirador:strcpy(objeto,"Fusil de Francotirador");goto PRINT; break;
    }
  }

  else if(porcentaje<50 && porcentaje > 30){
    srand((unsigned) time(&t2));
    enum Armas_mano mano= (rand() %4);
    switch (mano) {
      case Bate_de_Baseball: strcpy(objeto,"Bate de Baseball");goto PRINT;break;
      case Hacha: strcpy(objeto,"Hacha");goto PRINT;break;
      case Pala: strcpy(objeto,"Pala");goto PRINT;break;
      case Punio_Americano: strcpy(objeto,"Puño Americano");goto PRINT;break;
      case Machete: strcpy(objeto,"Machete");goto PRINT;break;
    }
  }

  else {
    srand((unsigned) time(&t2));
    enum Herramientas herra= (rand() %7);
    switch (herra) {
      case Llave: strcpy(objeto,"Llave");goto PRINT; break;
      case Mapa: strcpy(objeto,"Mapa");goto PRINT; break;
      case Bebida_Energetica: strcpy(objeto,"Bebida Energética");goto PRINT; break;
      case Linterna: strcpy(objeto,"Linterna");goto PRINT; break;
      case Antorcha: strcpy(objeto,"Antorcha");goto PRINT; break;
      case Camara: strcpy(objeto,"Cámara");goto PRINT; break;
      case Pilas: strcpy(objeto,"Pilas");goto PRINT; break;
      case Mochila: strcpy(objeto,"Mochila");goto PRINT; break;
      }
  }

  PRINT: printf("%s",objeto);

  return 0;
}
