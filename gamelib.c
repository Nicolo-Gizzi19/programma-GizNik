//GIZZI NICOLO'

#include "gamelib.h"

static enum Tipo_imprevisto p_imprevisto(enum Tipo_caverna caverna, int probabilita);
//puntatori
static struct Caverna* primo_cunicolo_arvais = NULL;
static struct Caverna* primo_cunicolo_hartornen = NULL;
//giocatori
static struct Scavatrice arvais = {NULL,4,0};
static struct Scavatrice hartornen = {NULL,4,0};

static int numerocunicoli=0;
static int numerocunicoli2=0;
static const int mat[4][3]={{50,30,20},{50,30,20},{50,30,20},{50,30,20}};

//funzioni necessarie
//crea mappa
void crea_cunicoli();
static void ins_caverna();
static void canc_caverna();
static void stampa_cunicolo();
static void chiudi_cunicoli();
//gioca
static void turnoarvais();
static void turnohartornen();
static void avanza();
static void aggira();
static void abbatti();
static void esci();

//svolgimento termina gioco
void termina_gioco(){
  while(primo_cunicolo_arvais!=NULL){
    while(primo_cunicolo_hartornen!=NULL){
      free(primo_cunicolo_hartornen);
      free(primo_cunicolo_arvais);
    }
  }
}

//svolgimento giocatori




//svolgimento crea cunicolo
void crea_cunicoli(){
  int scelta=0;
  do{
    printf("Crea un nuovo cunicolo.....SFIDA LA SORTE, FAI LA TUA SCELTA\n");
    printf("1)INSERISCI CAVERNA.... \n2)CANCELLA CAVERNA.... \n3)STAMPA CUNICOLO.... \n4)CHIUDI CUNICOLO....\n5)CHIUDI....\n");
    while(scanf("%d",&scelta) !=1 || scelta >5 || scelta<1){
      printf("SCELTA NON CONSENTITA! Inserisci un nuovo valore:");
      while(getchar() != '\n');
    }
    switch(scelta){
      case 1:
      ins_caverna();
      break;
      case 2:
      canc_caverna();
      break;
      case 3:
      stampa_cunicolo();
      break;
      case 4:
      chiudi_cunicoli();
      break;
      case 5:
      printf("CHIUSURA MENU");
      break;
      default:
      printf("LA SCELTA NON È ANCORA VALIDA. PROVA DI NUOVO\n");
      break;
    }
  }while(scelta!=5);
}

static void canc_caverna(){
  int a=0;
  printf("Inserisci 1 per il primo giocatore e 2 per il secondo\n ");
  scanf("%d",&a);
  for(int i=0; i<1; i++){
    if(a<1||a>2){
      printf("valore inserito non valido. scegli nuovo valore\n");
        scanf("%d",&a);
        i--;
    }
  }
  if(a==1){
  struct Caverna *inizio=NULL;
  inizio=primo_cunicolo_arvais;
  if(primo_cunicolo_arvais==NULL){
    printf("NON VI È NESSUNA CAVERNA\n");
  }
  else if(inizio->avanti == NULL){
    printf("NON PUOI ELIMINARE LA PRIMA CAVERNA!\n");
  }
  else{
    while(inizio->avanti !=NULL){
      primo_cunicolo_arvais=inizio;
      inizio=inizio->avanti;
    }
    free(inizio);
    primo_cunicolo_arvais->avanti=NULL;
    printf("CAVERNA CANCELLATA CORRETTAMENTE!\n");
  }}
  else{
  struct Caverna *inizio2=NULL;
  inizio2=primo_cunicolo_hartornen;
  if(primo_cunicolo_hartornen==NULL){
    printf("NON VI È NESSUNA CAVERNA\n");
  }
  else if(inizio2->avanti == NULL){
    printf("NON PUOI ELIMINARE LA PRIMA CAVERNA!\n");
  }
    else{
      while(inizio2->avanti !=NULL){
        primo_cunicolo_hartornen=inizio2;
        inizio2=inizio2->avanti;
      }
      free(inizio2);
      primo_cunicolo_hartornen->avanti=NULL;
      printf("CAVERNA CANCELLATA CORRETTAMENTE!\n");
    }
  }
}



static void ins_caverna(){

  do{
    time_t t;
    srand( (unsigned) time(&t));
    int b=0;
    printf("Inserisci 1 per il primo giocatore e 2 per il secondo \n");
    scanf("%d",&b);
  } while((b < 1) || (b > 2));

  struct Caverna* pApp = NULL;

  if(b == 1){
    if(primo_cunicolo_arvais != NULL){
      primo_cunicolo_arvais = (struct Caverna*) malloc (sizeof(struct Caverna));
      primo_cunicolo_arvais -> sinistra = NULL;
      primo_cunicolo_arvais -> avanti = NULL;
      primo_cunicolo_arvais -> destra = NULL;
    }
    else{
      pApp = primo_cunicolo_arvais;
    }

  if(b==2){
    if(primo_cunicolo_hartornen != NULL){
      primo_cunicolo_hartornen = (struct Caverna*) malloc (sizeof(struct Caverna));
      primo_cunicolo_hartornen -> sinistra = NULL;
      primo_cunicolo_hartornen -> avanti = NULL;
      primo_cunicolo_hartornen -> destra = NULL;
      }
    else{
      pApp = primo_cunicolo_hartornen;
    }
  }

  if(pApp != NULL){
    do{
      if(pApp -> sinistra != NULL){
        pApp = pApp -> sinistra;
      }
      if(pApp -> avanti != NULL){
        pApp = pApp -> avanti;
      }
      if(pApp -> destra != NULL){
        pApp = pApp -> destra;
      }
    } while(1);

    int var = 0;

    do{
      printf(" in quale direzione si vuole procedere? (1. (sinistra) 2. (avanti), 3. (destra))\n");
      scanf("%d",&var);
    }while((var < 1) || (var > 3));

    if(var == 1){
      pApp -> sinistra = (struct Caverna*) malloc (sizeof(struct Caverna));
      pApp = pApp -> sinistra;
    }
    if(var == 2){
      pApp -> avanti = (struct Caverna*) malloc (sizeof(struct Caverna));
      pApp = pApp -> avanti;
    }
    if(var == 3){
      pApp -> destra = (struct Caverna*) malloc (sizeof(struct Caverna));
      pApp = pApp -> destra;
    }

    pApp -> sinistra = NULL;
    pApp -> avanti = NULL;
    pApp -> destra = NULL;

  }

  //  probabilita=1+(rand()%100);
      //  printf("SCEGLI IL TIPO DELLA CAVERNA: 0)NORMALE,1)ACCIDENTATA,2)SPECIALE\n
while(continua!=1);
if(numero_caverne>=10){
  numero_caverne++;
  uscita1->caverna=uscita;
  uscita1->imprevisto=p_imprevisto(uscita,probabilita);
  primo_cunicolo_arvais->avanti=uscita1;
  primo_cunicolo_arvais=uscita1;
}
    printf("cunicoli modificati\n");
  else{
    printf("IL NUMERO MINIMO DI CAVERNE È 10 E L'USCITA VIENE INSERITA IN AUTOMATICO. QUANTE CAVERNE VUOI CREARE\n ");
    while(scanf("%d",&numero_caverne) numero_caverne<9){
      printf("scelta non corretta. Riprovare\n");
      while(getchar() != '\n');

    }
    for(int i=0;i<numero_caverne;i++){
      numerocunicoli++;
      nuovacaverna=(struct Caverna*)malloc (sizeof(struct Caverna));
      probabilita= 1+(rand()%100);
        printf("SCEGLI IL TIPO DELLA CAVERNA: 0)NORMALE,1)ACCIDENTATA,2)SPECIALE\n");
        while (scanf("%d", nuovacaverna->caverna>2||nuovacaverna->caverna<0){
          printf("scelta non valida.Nuova scelta\n");
          while(getchar()!= '\n');

        }
        nuovacaverna->imprevisto=p_imprevisto(nuovacaverna->caverna,probabilita);
        nuovacaverna->avanti=NULL;
        if(primo_cunicolo_arvais==NULL){
          primo_cunicolo_arvais=nuovacaverna;
        arvais.posizione=primo_cunicolo_arvais;
        }
        else{
          primo_cunicolo_arvais->avanti=nuovacaverna;
        }
    }
    numerocunicoli++;
    uscita1->caverna=uscita;
    uscita->imprevisto=p_imprevisto(uscita,probabilita);
    printf("percorso creato\n");
  }
}
else{
  int numero_caverne=0;
  int probabilita=0;
  int continua=0;
  struct Caverna *new=NULL, *uscita1=NULL;
  uscita1= (struct Caverna*) malloc (sizeof(struct Caverna));
  uscita1->avanti=NULL;
  if(primo_cunicolo_arvais != NULL){
    do{
      struct Caverna *singolacaverna=NULL;
      singolacaverna= (struct Caverna*) malloc (sizeof(struct Caverna));
      singolacaverna->avanti=NULL;
      probabilita=1+(rand()%100);
      printf("SCEGLI IL TIPO DELLA CAVERNA: 0)NORMALE,1)ACCIDENTATA,2)SPECIALE\n");
while (scanf("%d", singolacaverna->caverna>2||singolacaverna->caverna<0){
  printf("scelta non valida.Nuova scelta\n");
  while(getchar()!= '\n');

}
singolacaverna->imprevisto=p_imprevisto(singolacaverna->caverna,probabilita);
primo_cunicolo_hartornen->avanti=singolacaverna;
primo_cunicolo_hartornen=singolacaverna;
numerocunicoli2++;
printf("DIGITA 1 PER USCIRE O UN ALTRO NUMERO PER CONTINUARE\n");
scanf("%d",&continua);
}while(continua!=1);
if(numero_caverne>=10){
  numero_caverne++;
  uscita1->caverna=uscita;
  uscita1->imprevisto=p_imprevisto(uscita,probabilita);
  primo_cunicolo_hartornen->avanti=uscita1;
  primo_cunicolo_hartornen=uscita1;
}
    printf("cunicoli modificati\n");
  }
  else{
    printf("IL NUMERO MINIMO DI CAVERNE È 10 E L'USCITA VIENE INSERITA IN AUTOMATICO. QUANTE CAVERNE VUOI CREARE\n ");
    while(scanf("%d",&numero_caverne) numero_caverne<9){
      printf("scelta non corretta. Riprovare\n");
      while(getchar() != '\n');

    }
    for(int i=0;i<numero_caverne;i++){
      numerocunicoli2++;
      nuovacaverna=(struct Caverna*)malloc (sizeof(struct Caverna));
      probabilita= 1+(rand()%100);
        printf("SCEGLI IL TIPO DELLA CAVERNA: 0)NORMALE,1)ACCIDENTATA,2)SPECIALE\n");
        while (scanf("%d", nuovacaverna->caverna>2||nuovacaverna->caverna<0){
          printf("scelta non valida.Nuova scelta\n");
          while(getchar()!= '\n');

        }
        nuovacaverna->imprevisto=p_imprevisto(nuovacaverna->caverna,probabilita);
        nuovacaverna->avanti=NULL;
        if(primo_cunicolo_hartornen==NULL){
          primo_cunicolo_hartornen=nuovacaverna;
        hartornen.posizione=primo_cunicolo_hartornen;
        }
        else{
          primo_cunicolo_hartornen->avanti=nuovacaverna;
        }
    }
    numerocunicoli2++;
    uscita1->caverna=uscita;
    uscita->imprevisto=p_imprevisto(uscita,probabilita);
    printf("percorso creato\n");
}


}
static void stampa_cunicolo()
{
  int a=0;
  printf("Inserisci 1 per il primo giocatore e 2 per il secondo \n");
  scanf("%d",&a);
  for(int i=0; i<1; i++){
    if(a<1||a>2){
      printf("valore inserito non valido. scegli nuovo valore\n");
        scanf("%d",&a);
        i--;
    }
  }
  if(a==1){
  char tipoc[20]={0};
  char tipoi[20]={0};
  if(primo_cunicolo_arvais == NULL){
    printf("il percoso è vuoto\n");


  }
  else{
    struct Caverna *temp = primo_cunicolo_arvais;
    printf("|   caverna   |   imprevisto   |");
    while(temp!=NULL){
      switch(temp->caverna){
        case 0:
        strcpy(tipoc,"normale   |");
        break;
        case 1:
        strcpy(tipoc,"speciale   |");
        break;
        case 2:
        strcpy(tipoc,"accidentata   |");
        break;
        case 3:
        strcpy(tipoc,"uscita   |");
        break;
        default;
        break;

      }
      switch(temp->imprevisto){
        case 0:
        strcpy(tipoi,"nessuno   |");
        break;
        case 1:
        strcpy(tipoi,"crollo  |");
        break;
        case 2:
        strcpy(tipoi,"baco  |");
        break;
        default;
        break;
    }
    printf("|   %s %s\n",tipoc,tipoi);
    temp=temp->avanti;

  }
}
else{
  char tipoc[20]={0};
  char tipoi[20]={0};
  if(primo_cunicolo_hartornen == NULL){
    printf("il percoso è vuoto\n");


  }
  else{
    struct Caverna *temp = primo_cunicolo_hartornen;
    printf("|   caverna   |   imprevisto   |");
    while(temp!=NULL){
      switch(temp->caverna){
        case 0:
        strcpy(tipoc,"normale   |");
        break;
        case 1:
        strcpy(tipoc,"speciale   |");
        break;
        case 2:
        strcpy(tipoc,"accidentata   |");
        break;
        case 3:
        strcpy(tipoc,"uscita   |");
        break;
        default;
        break;

      }
      switch(temp->imprevisto){
        case 0:
        strcpy(tipoi,"nessuno   |");
        break;
        case 1:
        strcpy(tipoi,"crollo  |");
        break;
        case 2:
        strcpy(tipoi,"baco  |");
        break;
        default;
        break;
    }
    printf("|   %s %s\n",tipoc,tipoi);
    temp=temp->avanti;

  }
}
}


static void chiudi_cunicoli(){
  int a=0;
  printf("Inserisci 1 per il primo giocatore e 2 per il secondo \n");
  scanf("%d",&a);
  for(int i=0; i<1; i++){
    if(a<1||a>2){
      printf("valore inserito non valido. scegli nuovo valore\n");
        scanf("%d",&a);
        i--;
    }
  }
  if(a==1){
    if(primo_cunicolo_arvais==NULL){
      printf("il percorso è vuoto\n");

    }
    else if(numerocunicoli<10){
      printf("Non puoi chiudere con meno di 10 caverne");
    }
    else{
      printf("mappa chiusa");
    }
  }
  else{
    if(primo_cunicolo_hartornen==NULL){
      printf("il percorso è vuoto\n");

    }
    else if(numerocunicoli2<10){
      printf("Non puoi chiudere con meno di 10 caverne");
    }
    else{
      printf("mappa chiusa");
  }
}
}
