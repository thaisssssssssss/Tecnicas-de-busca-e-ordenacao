#include "quick_sort.h"

void quickSort(Item* vet, int lo, int hi){
    if(hi <= lo) return;

    int i = lo + 1;
    int lt = lo;
    int gt = hi;

    while(i <= gt){
        if(less(vet[i], vet[lt])){
            exch(vet[i], vet[lt]);
            i++;
            lt++;
        }
        else if(less(vet[lt], vet[i])){
            exch(vet[i], vet[gt]);
            gt--;
        }
        else i++;
    }

    quickSort(vet, lo, lt-1);
    quickSort(vet, gt+1, hi);
}