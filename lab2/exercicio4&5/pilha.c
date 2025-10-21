#include "pilha.h"

struct pilha{
    BST* no;
    Pilha* prox; 
};

Pilha* criaPilhaVazia(){
    return NULL;
}

Pilha* push(Pilha* pilha, BST* no){
    if(no){
        Pilha* nova = malloc(sizeof(struct pilha));
        nova->no = no;
        nova->prox = NULL;
    
        if(pilha) nova->prox = pilha;
    
        return nova;
    }
    return pilha;
}

BST* pop(Pilha* pilha){
    return pilha->no;
}

int conferePilhaVazia(Pilha* pilha){
    return (pilha == NULL);
}

Pilha* liberaTopo(Pilha* pilha){
    Pilha* aux = pilha;
    pilha = pilha->prox;
    free(aux);
    return pilha;
}