// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "item.h"
#include <stdio.h>

void sort(Item *a, int lo, int hi){
    printf("EXECUTANDO BUBBLE SORT\n");
    int i, j;

    for(i = lo; i < hi - 1; i++){
        for(j = lo; j < hi - 1; j++){
           compexch(a[j], a[j + 1]);
        }
    }
}