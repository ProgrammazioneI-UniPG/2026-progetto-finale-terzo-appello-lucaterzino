#include "gamelib.h"
#include <time.h> // Necessario per time()

int main() {
    // Inizializza il generatore di numeri casuali una sola volta all'avvio del programma
    srand((unsigned) time(NULL)); 

    int scelta = 0;

    do {
        // Stampa del menu principale
        printf("\n--- COSE STRANE: MENU PRINCIPALE ---\n");
        printf("1) Imposta gioco\n");
        printf("2) Gioca\n");
        printf("3) Termina gioco\n");
        printf("4) Visualizza crediti\n");
        printf("------------------------------------\n");
        printf("Inserisci la tua scelta: ");

        // Lettura dell'input con controllo di validità
        // scanf restituisce il numero di elementi letti correttamente.
        if (scanf("%d", &scelta) != 1) {
            // Se l'utente non inserisce un numero (es. lettere), puliamo il buffer
            printf("Errore: Inserisci un numero valido!\n");
            while (getchar() != '\n'); // Svuota il buffer di input
            continue; // Ricomincia il ciclo
        }

        // Switch per eseguire i comandi 
        switch (scelta) {
            case 1:
                imposta_gioco();
                break;
            case 2:
                gioca();
                break;
            case 3:
                termina_gioco();
                // Il ciclo terminerà se verra selezionato 3
                break;
            case 4:
                crediti();
                break;
            default:
                // Gestione comando sbagliato 
                printf("Comando sbagliato (deve essere 1-4). Riprova.\n");
                break;
        }

    } while (scelta != 3); // Condizione di uscita 

    return 0;
}
