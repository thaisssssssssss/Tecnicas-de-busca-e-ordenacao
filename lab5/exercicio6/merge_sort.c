#include "merge_sort.h"
#define SZ2 (sz+sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))
#define CUTOFF 10

static void insertSort(Item *a, int lo, int hi){
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
// void mergeSort(Item *a, Item* aux, int lo, int hi) {
//     int N = (hi - lo) + 1;
//     int y = N - 1;

//     for (int sz = 1; sz < N; sz = SZ2) {
//         for (int lo = 0; lo < N-sz; lo += SZ2) {
//             int x = lo + SZ2 - 1;
//             hi =  MIN(x,y);
//             if(hi <= lo + CUTOFF){
//                 insertSort(a, hi, lo);
//             }
//             else merge(a, aux, lo, lo+sz-1, hi);
//         }
//     }
// }


void mergeSort(Item *a, Item* aux, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;


    for(int i = 0; i <= N; i += CUTOFF){
        hi = MIN(i + CUTOFF - 1, y);
        insertSort(a, i, hi);
    }

    for (int sz = CUTOFF; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            hi =  MIN(x,y);
            merge(a, aux, lo, lo+sz-1, hi);
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

