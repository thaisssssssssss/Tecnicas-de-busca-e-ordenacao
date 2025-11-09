#include "merge_sort.h"

#define CUTOFF 1

void sort(Item *a, int lo, int hi){
    int n = (hi - lo) + 1;
    Item* aux = malloc(n * sizeof(Item));
    mergeSortCutoff(a, aux, lo, hi);
    free(aux);
}

/**
 * CASO EM QUE O ULTIMO ELEMENTO DA PRIMEIRA METADE EH MENOR QUE O 
 * PRIMEIRO ELEMENTO DA SEGUNDA METADE (JA ESTA ORDENADO)
 */
void mergeSortSkip(Item* vet, Item* aux, int lo, int hi){
    if(hi <= lo) return;
    else{
        int mid = (lo + hi) / 2;
        mergeSortSkip(vet, aux, lo, mid);
        mergeSortSkip(vet, aux, mid+1, hi);
        if(less(vet[mid+1], vet[mid])) return;
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
        else vet[i] = aux[b++];
    }
}


void insertSort(Item *a, int lo, int hi){
    //printf("EXECUTANDO INSERTION SORT\n");
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