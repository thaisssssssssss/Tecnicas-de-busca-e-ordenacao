// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "josefo.h"

static unsigned char *a;

void inicializaCirculo(int n){
    a = calloc((n + 1), sizeof(unsigned char));
}

void loopPrincipal(int n, int m){
    int i, ultimo = 0;
    for(i = 1; i < n; i++){
        ultimo = retiraNumero(ultimo, m, n);
    }
}

int retiraNumero(int ultimo, int m, int n){
    int posicao = (ultimo + m) % n;
    ultimo = (ultimo + 1) % n;

    while(1){
        if(posicao == 0) posicao = n;
        if(ultimo == 0) ultimo = n;

        if(!is_set(ultimo)){
            if(ultimo == posicao){
                set_bit(posicao);
                return posicao;
            }
            ultimo = (ultimo + 1) % n;
        }
        else{
            ultimo = (ultimo + 1) % n;
            posicao = (posicao + 1) % n;
        }
    }
}

void encontraLider(int n){
    int i;
    for(i = 1; i <= n; i++){
        if(!is_set(i)){
            printf("%d eh o lider\n", i);
            break;
        }
    }
    free(a);
}

void imprimeNumeroEliminado(int vez, int num){
    printf("Numero %d for o %d eliminado\n", num, vez);
}