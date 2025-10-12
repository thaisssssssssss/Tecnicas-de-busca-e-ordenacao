// Thais Gomes Brandão 
// Matrícula:  2024102657

#include "crivoBit.h"

static unsigned char *a;


void inicializaVetor(int n){
    a = calloc((n + 1), sizeof(unsigned char));
}

void imprimeVetor(int n){
    int i;
    for(i = 2; i <= n; i++){
        if(!is_set(i)){
            printf("Numero %d eh primo\n", i);
        }
    }
}

void marcaPrimos(int n){
    int i;
    for(i = 2; i <= n; i++){
        if(!is_set(i)){
            saltaMultiplos(i, n);
        }
    }
    free(a);
}

void saltaMultiplos(int mult, int n){
    int i;
    for(i = mult * 2; i <= n; i += mult){
        set_bit(i);
    }
}