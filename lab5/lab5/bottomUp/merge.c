// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "merge.h"

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
        else if(less(aux[b], aux[a])) vet[i] = aux[b++];
        else vet[i] = aux[a++];
    }
}
