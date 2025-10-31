// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "item.h"
#include <stdio.h>

extern void sort(Item *a, int lo, int hi){
    printf("EXECUTANDO SHAKER SORT\n");
    int i, j;
    int trocou;

    for(i = lo; i < hi; i++){     
        trocou = 0;   

        //esquerda pra direita
        for(j = lo; j < hi - 1; j++){
            if(less(a[j + 1], a[j])){
                exch(a[j + 1], a[j]);
                trocou = 1;
            }
        }
        hi--;

        if(!trocou) break;
        trocou = 0;
        
        //direita pra esquerda
        for(j = hi - 1; j > lo; j--){
            if(less(a[j], a[j - 1])){
                exch(a[j], a[j - 1]);
                trocou = 1;
            }
        }
        lo++;

        if(!trocou) break;
        
    }
}
