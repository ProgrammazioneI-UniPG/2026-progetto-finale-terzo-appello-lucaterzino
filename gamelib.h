#ifndef GAMELIB_H
#define GAMELIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definizioni Enum per Tipo Zona, Nemico e Oggetto
typedef enum {
    bosco, scuola, laboratorio, caverna, strada, giardino, 
    supermercato, centrale_elettrica, deposito_abbandonato, stazione_polizia
} Tipo_zona;

typedef enum {
    nessun_nemico, billi, democane, demotorzone
} Tipo_nemico;

typedef enum {
    nessun_oggetto, bicicletta, maglietta_fuocoinferno, bussola, schitarrata_metallica
} Tipo_oggetto;

// Forward declaration per permettere i puntatori incrociati tra le struct
struct Zona_soprasotto; 
struct Zona_mondoreale;

// Struttura Zona Mondo Reale 
typedef struct Zona_mondoreale {
    Tipo_zona tipo;                 
    Tipo_nemico nemico;            
    Tipo_oggetto oggetto;          
    struct Zona_mondoreale* avanti; 
    struct Zona_mondoreale* indietro; 
    struct Zona_soprasotto* link_soprasotto; 
} Zona_mondoreale;

// Struttura Zona Soprasotto 
typedef struct Zona_soprasotto {
    Tipo_zona tipo;                 
    Tipo_nemico nemico;            
    // NON è presente il campo oggetto 
    struct Zona_soprasotto* avanti; 
    struct Zona_soprasotto* indietro; 
    struct Zona_mondoreale* link_mondoreale; 
} Zona_soprasotto;

// Struttura Giocatore 
typedef struct Giocatore {
    char nome[100]; // Dimensione arbitraria sicura per il nome
    int mondo; // 0 = Mondo Reale, 1 = Soprasotto 
    Zona_mondoreale* pos_mondoreale; 
    Zona_soprasotto* pos_soprasotto; 
    int attacco_pischico; // Valore 1-20 
    int difesa_pischica;  // Valore 1-20 
    int fortuna;          // Valore 1-20 
    Tipo_oggetto zaino[3]; // Array di 3 oggetti 
} Giocatore;

// Prototipi delle funzioni pubbliche 
void imposta_gioco();
void gioca();
void termina_gioco();
void crediti();

#endif
