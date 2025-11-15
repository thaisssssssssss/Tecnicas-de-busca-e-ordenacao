#include "quick_sort.h"

#define CUTOFF 32
// void insertSort(Item* vet, int lo, int hi){
//     int i, j, posicao;
//     for(i = lo + 1; i <= hi; i++){
//         posicao = i;
//         for(j = i-1; j > 0; j--){
//             if(less(vet[posicao], vet[j])){
//                 exch(vet[j], vet[posicao]);
//                 posicao = j;
//             }
//             else break;
//         }
//     }
// }
static void insertSort(Item *vet, int lo, int hi){
    int i, j, posicao;

    for(i = lo + 1; i <= hi; i++){
        posicao = i;
        for(j = i - 1; j >= lo; j--){
            if(less(vet[posicao], vet[j])){
                exch(vet[posicao], vet[j]);
                posicao = j;
            }
            else break;
        }
    }
}

int particioning(Item* vet, int lo, int hi){
    int i = lo;
    int j = hi + 1;


    while(1){
        while(less(vet[++i], vet[lo])){
            if(i == hi) break;
        }
        while(less(vet[lo], vet[--j])){
            if(j == lo) break;
        }
        if(i >= j) break;
        exch(vet[i], vet[j]);
    }

    exch(vet[lo], vet[j]);
    return j;
}

void quickSort(Item* vet, int lo, int hi){
    if(hi <= lo) return;

    if(hi <= lo + CUTOFF){
        insertSort(vet, lo, hi);
        return;
    }
    
    int a = particioning(vet, lo, hi);
    quickSort(vet, lo, a-1);
    quickSort(vet, a+1, hi);
}