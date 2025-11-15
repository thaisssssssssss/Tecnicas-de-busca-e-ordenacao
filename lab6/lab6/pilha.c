#include "pilha.h"

struct pilha{
    Item num;
    Pilha* prox;
};

Pilha* inicializaPilha(){
    return NULL;
}

Pilha* push(Item a, Pilha* pilha){
    Pilha* nova = malloc(sizeof(struct pilha));
    nova->num = a;
    nova->prox = pilha;
    return nova;
}

Item pop(Pilha** pilha){
    if(pilha){
        Item a = (*pilha)->num;
        Pilha* aux = (*pilha);
        (*pilha) = (*pilha)->prox;
        free(aux);
        return a;
    }
    return -1;
}

Pilha* limpa(Pilha* pilha){
    if(pilha){
        Pilha* aux = pilha;
        pilha = pilha->prox;
        free(aux);
        return pilha;
    }
    return NULL;
}

int vazia(Pilha* pilha){
    return (pilha == NULL);
}
