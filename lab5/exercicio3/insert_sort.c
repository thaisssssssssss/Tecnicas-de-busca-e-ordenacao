// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "item.h"
#include <stdio.h>

void sort(Item *a, int lo, int hi){
    printf("EXECUTANDO INSERTION SORT\n");
    int i, j, posicao;

    for(i = lo + 1; i < hi; i++){
        posicao = i;
        for(j = i - 1; j >= lo; j--){
            if(less(a[posicao], a[j])){
                exch(a[posicao], a[j]);
                posicao = j;
            }
            else break;
        }
    }
}
