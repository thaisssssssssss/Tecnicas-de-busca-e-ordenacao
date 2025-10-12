// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "crivoChar.h"

char* inicializaVetor(int n){
    char *vetor = calloc((n + 1), sizeof(char));

    return vetor;
}

void imprimeVetor(char *vetor, int n){
    int i;
    for(i = 2; i <= n; i++){
        if(!vetor[i]) {
            printf("Numero %d eh primo\n", i);
        }
        // printf("numero %d: %d\n", i, vetor[i]);
    }
}

void marcaPrimos(char *vetor, int n){
    int i;
    for(i = 2; i <= n; i++){
        if(!vetor[i]){
            saltaMultiplos(vetor, i, n);
        }
    }
}

void saltaMultiplos(char *vetor, int mult, int n){
    int i;
    for(i = mult * 2; i <= n; i += mult){
        vetor[i] = '1';
    }
}