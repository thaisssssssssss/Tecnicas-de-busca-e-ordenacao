#include "mergeSort_topDown.h"

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

    if(TIPO == TOPDOWN) mergeSort_topDown(a, aux, lo, hi);
    else if(TIPO == TOPDOWN_CUTOFF) mergeSortCutoff(a, aux, lo, hi);
    else if(TIPO == TOPDOWN_SKIP) mergeSortSkip(a, aux, lo, hi);
    else if(TIPO == TOPDOWN_COMPLETO) mergeSortCompleto(a, aux, lo, hi);

    free(aux);
}

void mergeSort_topDown(Item* vet, Item* aux, int lo, int hi){
    if(hi <= lo) return;
    else{
        int mid = (lo + hi) / 2;
        mergeSort_topDown(vet, aux, lo, mid);
        mergeSort_topDown(vet, aux, mid+1, hi);
        merge(vet, aux, lo, mid, hi);
    }
}

/**CASO EM QUE OS VETORES SAO PEQUENOS, ORDENA-OS COM INSERTION SORT*/
void mergeSortCutoff(Item* vet, Item* aux, int lo, int hi){
    if(hi <= lo + CUTOFF){
        insertSort(vet, lo, hi);
        return;
    }
    if(hi <= lo) return;
    else{
        int mid = (lo + hi) / 2;
        mergeSortCutoff(vet, aux, lo, mid);
        mergeSortCutoff(vet, aux, mid+1, hi);
        merge(vet, aux, lo, mid, hi);
    }
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
        if(less(vet[mid], vet[mid+1])) return;
        merge(vet, aux, lo, mid, hi);
    }
}

/**CASO EM QUE OS VETORES SAO PEQUENOS, ORDENA-OS COM INSERTION SORT E
 * CONFERE SE JA NAO ESTA PRE ORDENADO ANTES DE CHAMAR MERGE
*/
void mergeSortCompleto(Item* vet, Item* aux, int lo, int hi){
    if(hi <= lo + CUTOFF){
        insertSort(vet, lo, hi);
        return;
    }
    if(hi <= lo) return;
    else{
        int mid = (lo + hi) / 2;
        mergeSortCompleto(vet, aux, lo, mid);
        mergeSortCompleto(vet, aux, mid+1, hi);
        if(less(vet[mid+1], vet[mid])) return;
        merge(vet, aux, lo, mid, hi);
    }
}
