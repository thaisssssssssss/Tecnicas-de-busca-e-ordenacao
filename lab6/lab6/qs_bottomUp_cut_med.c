#include "quick_sort.h"
#include "pilha.h"

#define CUTOFF 32

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
    Pilha* pilha = inicializaPilha();
    
    pilha = push(hi, pilha);
    pilha = push(lo, pilha);

    while(!vazia(pilha)){
        lo = pop(&pilha);
        //pilha = limpa(pilha);
        hi = pop(&pilha);
        //pilha = limpa(pilha);

        if(hi <= lo) continue;

        if(hi <= lo + CUTOFF){
            insertSort(vet, lo, hi);
            continue;
        }

        int med = mediana(vet, lo, hi);
        exch(vet[med], vet[lo]);

        int a = particioning(vet, lo, hi);

        if(a-lo > hi-a){ //ordenar a menor array primeiro
            pilha = push(a-1, pilha); //maior (metade esquerda)
            pilha = push(lo, pilha);  //menor (metade esquerda)

            pilha = push(hi, pilha);  //maior (metade direita)
            pilha = push(a+1, pilha); //menor (metade direita)
        }
        else{
            pilha = push(hi, pilha);  //maior (metade direita)
            pilha = push(a+1, pilha); //menor (metade direita)
            
            pilha = push(a-1, pilha); //maior (metade esquerda)
            pilha = push(lo, pilha);  //menor (metade esquerda)
        }
    }
}