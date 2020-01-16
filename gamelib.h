//GIZZI NICOLO'

#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

//gestisce i turni dei giocatori
void gioca();
//consente la creazione della caverna
void crea_cunicoli();
//chiude l'esecuzione del gioco liberando la memoria
void termina_gioco();

enum Tipo_imprevisto {
  nessun_imprevisto,
  crollo,
  baco
};

enum Quantita_melassa {
  nessuna,
  poca,
  molta
};

enum Tipo_caverna {
  normale,
  speciale,
  accidentata,
  uscita
};

struct Scavatrice {
  struct Caverna* posizione;
  int serbatoio;
  int magazzino;
};

struct Caverna {
  struct Caverna* sinistra;
  struct Caverna* avanti;
  struct Caverna* destra;
  enum Quantita_melassa melassa;
  enum Tipo_imprevisto imprevisto;
  enum Tipo_caverna stato;
};
