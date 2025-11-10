#include "merge_sort.h"
#define SZ2 (sz+sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))


void sort(Item *a, int lo, int hi){
    int n = (hi - lo) + 1;
    Item* aux = malloc(n * sizeof(Item));
    mergeSort(a, aux, lo, hi);
    free(aux);
}

/**VERSAO BOTTOM-UP (ITERATIVA) 
 * PRIMEIRO LOOP DUPLICA AS PASSADAS
 * SEGUNDO ACHA MIN, MID E MAX E CHAMA MERGE
*/
void mergeSort(Item *vet, Item* aux, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;
    for (int sz = 1; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            int mid = lo+sz-1;
            if(!less(vet[mid], vet[mid+1])) merge(vet, aux, lo, mid, MIN(x,y));
        }
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

