#include "crivo.h"

int* inicializaVetor(int n){
    int *vetor = calloc((n + 1), sizeof(int));

    return vetor;
}

void imprimeVetor(int *vetor, int n){
    int i;
    for(i = 2; i <= n; i++){
        if(!vetor[i]) {
            printf("Numero %d eh primo\n", i);
        }
        // printf("numero %d: %d\n", i, vetor[i]);
    }
}

void marcaPrimos(int *vetor, int n){
    int i;
    for(i = 2; i <= n; i++){
        if(!vetor[i]){
            saltaMultiplos(vetor, i, n);
        }
    }
}

void saltaMultiplos(int *vetor, int mult, int n){
    int i;
    for(i = mult * 2; i <= n; i += mult){
        vetor[i] = 1;
    }
}