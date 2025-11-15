#include "quick_sort.h"
#include "pilha.h"

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
        hi = pop(&pilha);

        if(hi <= lo) continue;

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