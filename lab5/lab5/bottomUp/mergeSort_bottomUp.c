// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "mergeSort_bottomUp.h"

#define SZ2 (sz+sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))
#define CUTOFF 1

//INSERT SORT PRA VERSAO MERGE SORT COM CUTOFF
static void insertSort(Item *a, int lo, int hi){
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




void sort(Item *a, int lo, int hi, int TIPO) {
    int n = (hi - lo) + 1;
    Item* aux = malloc(n * sizeof(Item));

    if(TIPO == BOTTOMUP) mergeSort_bottomUp(a, aux, lo, hi);
    else if(TIPO == BOTTOMUP_CUTOFF) mergeSortCutoff(a, aux, lo, hi);
    else if(TIPO == BOTTOMUP_SKIP) mergeSortSkip(a, aux, lo, hi);
    else if(TIPO == BOTTOMUP_COMPLETO) mergeSortCompleto(a, aux, lo, hi);

    free(aux);
}

/**VERSAO BOTTOM-UP (ITERATIVA) 
 * PRIMEIRO LOOP DUPLICA AS PASSADAS
 * SEGUNDO ACHA MIN, MID E MAX E CHAMA MERGE
*/
void mergeSort_bottomUp(Item *vet, Item* aux, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;
    for (int sz = 1; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            merge(vet, aux, lo, lo+sz-1, MIN(x,y));
        }
    }
}

void mergeSortCutoff(Item *vet, Item* aux, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;


    for(int i = 0; i <= N; i += CUTOFF){
        hi = MIN(i + CUTOFF - 1, y);
        insertSort(vet, i, hi);
    }

    for (int sz = CUTOFF; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            hi =  MIN(x,y);
            merge(vet, aux, lo, lo+sz-1, hi);
        }
    }
}

/**
 * CASO EM QUE O ULTIMO ELEMENTO DA PRIMEIRA METADE EH MENOR QUE O 
 * PRIMEIRO ELEMENTO DA SEGUNDA METADE (JA ESTA ORDENADO)
 */
void mergeSortSkip(Item *vet, Item* aux, int lo, int hi) {
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

/**CASO EM QUE OS VETORES SAO PEQUENOS, ORDENA-OS COM INSERTION SORT E
 * CONFERE SE JA NAO ESTA PRE ORDENADO ANTES DE CHAMAR MERGE
*/
void mergeSortCompleto(Item* vet, Item* aux, int lo, int hi){
    int N = (hi - lo) + 1;
    int y = N - 1;


    for(int i = 0; i <= N; i += CUTOFF){
        hi = MIN(i + CUTOFF - 1, y);
        insertSort(vet, i, hi);
    }

    for (int sz = CUTOFF; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            hi =  MIN(x,y);
            int mid = lo+sz-1;
            if(!less(vet[mid], vet[mid+1])) merge(vet, aux, lo, mid, MIN(x,y));
        }
    }
}
