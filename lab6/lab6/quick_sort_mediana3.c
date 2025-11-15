#include "quick_sort.h"

static int mediana(Item* vet, int lo, int hi){
    int mid = (hi + lo) / 2;
    //printf("lo: %d, mid: %d, hi: %d\n", vet[lo], vet[mid], vet[hi]);
    if(less(vet[lo], vet[mid])){
        if(less(vet[mid], vet[hi])) return mid;
        else{
            if(less(vet[lo], vet[hi])) return hi;
            else return lo;
        }
    }
    else{
        if(less(vet[hi], vet[mid])) return mid;
        else{
            if(less(vet[lo], vet[hi])) return lo;
            else return hi;
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

    int medi = mediana(vet, lo, hi);
    exch(vet[medi], vet[lo]);
    
    int a = particioning(vet, lo, hi);
    quickSort(vet, lo, a-1);
    quickSort(vet, a+1, hi);
}