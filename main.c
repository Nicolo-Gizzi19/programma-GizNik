//GIZZI NICOLO'  MATRICOLA N°

#include <stdlib.h>
#include <stdio.h>
#include "gamelib.h"


int main(){


  //Creo la variabile menu con la quale effettuare le diverse scelte nel gioco
  int menu=0;
  //Breve presentazione della storia
  printf("          SABBIE: the game        \n");
  printf("La Arvais e la Hartornen sono 2 famiglie che si contendono da anni l'estrazione di una preziosissima sostanza: La MELASSA.\n");
  printf("L'estrazione è ostacolata da moltissimi pericoli come: improvvise frane, imprevisti, e lo scontro con l'acerrima famiglia rivale.\n");
  printf("Quasi dimenticavo. Fate MOLTA ATTENZIONE ai terrificanti Bachi delle Sabbie, che con la loro lunghezza di centinaia di metri vi possono ingoiare in 1 solo boccone.\n");
  printf("Ora che è tutto chiaro, solo voi potete riuscire raccogliere tutta la melassa ed uscire dalle caverne in tempo, prima che il serbatoio di energia si svuoti.\n");
  printf("Buona fortuna giocatori e che il gioco abbia inizio!!!\n");
  do{
    printf("_______________________\n");
    printf("| 1)CREA CUNICOLI      |\n");
    printf("| 2)GIOCA              |\n");
    printf("| 3)TERMINA AVVENTURA  |\n");
    printf("_______________________\n");

    scanf("%d",&menu);
    //controllo input
    for(int i=0;i<1;i++){
    if(menu<1||menu>3)
    {
      printf("Errore nella scelta\n");
      printf("Nuova Scelta\n");
      scanf("%d",&menu);
      --i;

    }
  }
  switch(menu){
    case 1:
    //crea CUNICOLI

  //  crea_cunicoli();
    break;

    case 2:
    //gioca
  //  gioca();
    break;

    case 3:
    //termina partita

  //  termina_gioco();

    default:
    break;

  }

} while(menu!=3);
}
