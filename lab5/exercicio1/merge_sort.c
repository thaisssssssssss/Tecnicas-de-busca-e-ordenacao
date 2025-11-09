#include "merge_sort.h"

void sort(Item *a, int lo, int hi) {
    int n = (hi - lo) + 1;
    Item* aux = malloc(n * sizeof(Item));
    mergeSort(a, aux, lo, hi);
    free(aux);
}

void mergeSort(Item* vet, Item* aux, int lo, int hi){
    if(hi <= lo) return;
    else{
        int mid = (lo + hi) / 2;
        mergeSort(vet, aux, lo, mid);
        mergeSort(vet, aux, mid+1, hi);
        merge(vet, aux, lo, mid, hi);
    }
}

void merge(Item* vet, Item* aux, int lo, int mid, int hi){
    int i;
    for(i = lo; i <= hi; i++){
        aux[i] = vet[i];
    }

    int a = lo;
    int b = mid + 1;
    for(i = lo; i <= hi; i++){
        if(a > mid) vet[i] = aux[b++];
        else if(b > hi) vet[i] = aux[a++];
        else if(less(aux[a], aux[b])) vet[i] = aux[a++];
        else vet[i] = vet[b++];
    }
}
