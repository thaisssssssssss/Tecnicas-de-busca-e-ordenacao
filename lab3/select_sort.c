// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "item.h"
#include <stdio.h>

extern void sort(Item *a, int lo, int hi){
    printf("EXECUTANDO SELECTION SORT\n");
    int i, j, posicao;
    Item menor;

    for(i = lo; i < hi - 1; i++){
        menor = a[i];
        posicao = i;

        for(j = i + 1; j < hi; j++){
            if(less(a[j], menor)){
                menor = a[j];
                posicao = j;
            }
        }

        if(posicao != i) exch(a[i], a[posicao]);
    }
}

