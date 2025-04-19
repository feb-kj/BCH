/*
______________________________

Data di creazione:	02/06/2024
Ultima modifica:	19/04/2025
______________________________

======================================================================================================================================================

 ___  ___  ________  _____ ______   _____ ______   ___  ________   ________          _______   ________  _________  _______   ________  ________     
|\  \|\  \|\   __  \|\   _ \  _   \|\   _ \  _   \|\  \|\   ___  \|\   ____\        |\  ___ \ |\   ____\|\___   ___\\  ___ \ |\   ____\|\   __  \    
\ \  \\\  \ \  \|\  \ \  \\\__\ \  \ \  \\\__\ \  \ \  \ \  \\ \  \ \  \___|        \ \   __/|\ \  \___|\|___ \  \_\ \   __/|\ \  \___|\ \  \|\  \   
 \ \   __  \ \   __  \ \  \\|__| \  \ \  \\|__| \  \ \  \ \  \\ \  \ \  \  ___       \ \  \_|/_\ \_____  \   \ \  \ \ \  \_|/_\ \_____  \ \  \\\  \  
  \ \  \ \  \ \  \ \  \ \  \    \ \  \ \  \    \ \  \ \  \ \  \\ \  \ \  \|\  \       \ \  \_|\ \|____|\  \   \ \  \ \ \  \_|\ \|____|\  \ \  \\\  \ 
   \ \__\ \__\ \__\ \__\ \__\    \ \__\ \__\    \ \__\ \__\ \__\\ \__\ \_______\       \ \_______\____\_\  \   \ \__\ \ \_______\____\_\  \ \_______\
    \|__|\|__|\|__|\|__|\|__|     \|__|\|__|     \|__|\|__|\|__| \|__|\|_______|        \|_______|\_________\   \|__|  \|_______|\_________\|_______|
                                                                                                 \|_________|                   \|_________|         
				 	   	 ________  ________  ___  ___     
						|\   __  \|\   ____\|\  \|\  \    
						\ \  \|\ /\ \  \___|\ \  \\\  \   
						 \ \   __  \ \  \    \ \   __  \  
						  \ \  \|\  \ \  \____\ \  \ \  \ 
						   \ \_______\ \_______\ \__\ \__\
						    \|_______|\|_______|\|__|\|__|
          	                                                                                                                                                                             
======================================================================================================================================================
*/
//dichiaro le librerie necessarie per l'esecuzione del programma
#include <stdio.h>		//finzioni lettura e scrittua "printf" "scanf"
#include <iostream>		//funzioni "system" prompt dei comandi cmd
#include <stdlib.h>		//funzioni per gestione della memoria e generazione di numeri casuali "srand"
#include <time.h>		//funzioni per la generazione di numeri casuali tenendo conto del giorno, mese, anno, ora, secondi, minuti. (generazione causale)
//dichiaro le costanti globali del programma
const int M = 15;		//numero massimo di colonne della matrice (indice di j); o anche il numero massimo di bit
const int N = 8;		//numero massimo di righe della matrice (indice di i)
const int B = 7;		//numero massimo di bit che si possono inserire in input
//dichiaro le variabili globali del programma
int i, j;		//variabili per la posizione di arrey
//dichiaro un arrey bidimensionale per salvare una matrice "H"
//inizio dichiarazione matrice H per BCH(15,7)
//con H = Hij oppure Hnm. dove i/n = indice righa; j/m = indice colonna
//Matrice default 8*15 composta da bit_controllo + bit_parita + bit_dadti
int H[8][15] =
{
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1}
};
//procedura per calcolare la syndrome "S"
//inizio procedura calcsyn
void calcsyn(int codeword[], int syndrome[], int H[][M])	//calcolo somma XOR
{
    for (i=0; i<N; i++)
	{
        syndrome[i]=0;										//inizia a calcolare la syndrome "S" a 0 nella righa 0
        for (j=0; j<M; j++)
			syndrome[i] ^= (codeword[j] & H[i][j]);			//comando " ^=" operazione ci somma XOR bit a bit; "&" e l'operazione AND bit a bit
    }
}
//procedura per generare la codeword (BCH encoding)
//inizio procedura gene_codeword
void gene_codeword(int bitdati[], int codeword[])
{
	//copio i bit_dati iniziali nella codeword
    for (i=0; i<B; i++)
        codeword[i]=bitdati[i];
	//genero i bit di controllo
    for (i=B; i<M; i++)
    {
        codeword[i]=0;										//primo bit di controllo
        for (j=0; j<B; j++)
			codeword[i] ^= (bitdati[j] & H[i-B][j]);		//operazione XOR e AND  	
    }
}
//procedura per simulare due errori nella codeword
void error_sim(int codeword[], int M, int perror[])
{
    perror[0]=rand() % M;									//genero gli indici degli errori con la funzione rand (limitandola "%" a M-1)
    perror[1]=rand() % M;									//genero gli indici degli errori con la funzione rand (limitandola "%" a M-1)
    while (perror[0]==perror[1])							//controllo dei due indici di errore, finche non saranno diversi, li continuera a ri-generare
        perror[1]=rand() % M;								//genero nuovamente (per il controllo) gli indici degli errori con la funzione rand (limitandola "%" a M-1)
    codeword[perror[0]] ^= 1; 								//inverto il "perror", l'indice di errore generato a 0 o 1, della codeword
    codeword[perror[1]] ^= 1; 								//inverto il "perror", l'indice di errore generato a 0 o 1, della codeword
}
//inizio programma
int main()
{
	//inizio il programma richiamando la funzione per la gestione di numeri casuali in base ai parametri giornalieri
	srand(time(NULL));
	//dichiaro le variabili locali del programma
    int bitdati[B];
    int codeword[M];
    int syndrome[N];
    int perror[2];
	//cambio colore del prompt
	system("color f0");
	//cambio titolo
	system("title codice Hamming - BCH");
    //input dei 7 bit da inserire
    printf("\n | Inserire 7 bit di dati (uno alla volta): \n");
    for (i=0; i<B; i++)
    {
    	printf(" > ");
        scanf("%d", &bitdati[i]);
	}
    //richiamo procedura per calcolare la codeword
    gene_codeword(bitdati, codeword);
	//stampo le posizioni
	printf("\n \t\t\t\t                 012345|");
	printf("\n \t\t\t\t       |123456789111111|");
    //stampo la codeword calcolata
    printf("\n | Codeword calcolata: \t\t\t");
    for (i=0; i<M; i++)
        printf("%d", codeword[i]);
    //richiamo procedura per simulare i 2 errori nella codeword
    error_sim(codeword, M, perror);
    //stampo la codeword con i 2 errori generati
    printf("\n | Codeword con errori simulati: \t");
    for (i=0; i<M; i++)
        printf("%d", codeword[i]);
    //richiamo procedura per calcolare la sindrome "S"
    calcsyn(codeword, syndrome, H);
    //satmpo la syndrome "S" calcolata
    printf("\n - Syndrome: ");
    for (i=0; i<8; i++)
        printf("%d", syndrome[i]);
    //trova e stampa la posizione degli errori
    printf("\n + Errore 1 in posizione: %d", perror[0] + 1);
    printf("\n + Errore 2 in posizione: %d\n\n", perror[1] + 1);
	//metto in pausa il programma
    system("pause");
}
//fine programma
