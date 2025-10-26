#include "item.h"

extern void sort(Item *a, int lo, int hi){
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


// #define key(A) (A)
// #define less(A, B) (key(A) < key(B))
// #define exch(A, B) { Item t = A; A = B; B = t; }
// #define compexch(A, B) if (less(B, A)) exch(A, B)