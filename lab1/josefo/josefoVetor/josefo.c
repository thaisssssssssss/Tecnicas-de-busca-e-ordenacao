// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "josefo.h"

int* criaCirculo(int n){
    int* circulo = calloc((n + 1), sizeof(int));
    return circulo;
}

void loopPrincipal(int* circulo, int n, int m){
    int i, ultimo = 0;
    for(i = 1; i < n; i++){
        ultimo = retiraNumero(circulo, ultimo, m, n);
        //imprimeNumeroEliminado(i, ultimo);
    }
}

int retiraNumero(int* circulo, int ultimo, int m, int n){
    int posicao = (ultimo + m) % n;
    ultimo = (ultimo + 1) % n;

    while(1){
        if(posicao == 0) posicao = n;
        if(ultimo == 0) ultimo = n;

        if(!circulo[ultimo]){
            if(ultimo == posicao){
                circulo[posicao] = 1;
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

void encontraLider(int* circulo, int n){
    int i;
    for(i = 1; i <= n; i++){
        if(!circulo[i]){
            printf("%d eh o lider\n", i);
            break;
        }
    }
}

void imprimeNumeroEliminado(int vez, int num){
    printf("Numero %d for o %d eliminado\n", num, vez);
}