#include "item.h"

extern void sort(Item *a, int lo, int hi){
    int i, j, posicao;

    for(i = lo; i < hi - 1; i++){
        for(j = lo; j < hi - 1; j++){
           compexch(a[j], a[j + 1]);
        }
    }
}


// #define key(A) (A)
// #define less(A, B) (key(A) < key(B))
// #define exch(A, B) { Item t = A; A = B; B = t; }
// #define compexch(A, B) if (less(B, A)) exch(A, B)