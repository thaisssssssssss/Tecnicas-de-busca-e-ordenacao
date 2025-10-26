#include "item.h"

extern void sort(Item *a, int lo, int hi){
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


// #define key(A) (A)
// #define less(A, B) (key(A) < key(B))
// #define exch(A, B) { Item t = A; A = B; B = t; }
// #define compexch(A, B) if (less(B, A)) exch(A, B)