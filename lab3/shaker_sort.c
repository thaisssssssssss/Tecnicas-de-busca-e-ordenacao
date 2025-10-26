#include "item.h"
#include <stdio.h>

extern void sort(Item *a, int lo, int hi){
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

// extern void sort(Item *a, int lo, int hi){
//     int i, j, posicao;

//     for(i = lo; i < (hi / 2); i++){
        
//         //esquerda pra direita
//         for(j = lo; j < hi - 1; j++){
//            compexch(a[j], a[j + 1]);
//         }

//         //direita pra esquerda
//         for(j = hi - 1; j >= lo; j--){
//            compexch(a[j - 1], a[j]);
//         }
//     }
// }

// #define key(A) (A)
// #define less(A, B) (key(A) < key(B))
// #define exch(A, B) { Item t = A; A = B; B = t; }
// #define compexch(A, B) if (less(B, A)) exch(A, B)