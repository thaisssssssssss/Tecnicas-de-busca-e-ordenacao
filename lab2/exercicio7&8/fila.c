#include "fila.h"

typedef struct celula Celula;

struct celula{
    BST* no;
    Celula* prox;
};

struct fila{
    Celula* prim;
    Celula* ult;
};

Fila* criaFilaVazia(){
    Fila* fila = malloc(sizeof(struct fila));
    fila->prim = NULL;
    fila->ult = NULL;
    return fila;
}

void enfileira(Fila* fila, BST* no){
    if(no){
        Celula* nova = malloc(sizeof(struct celula));
        nova->no = no;
        nova->prox = NULL;


        if(fila->prim == NULL){
            fila->prim = nova;
            fila->ult = nova;
        }
        else{
            fila->ult->prox = nova;
            fila->ult = nova;
        }
    }
}

BST* desenfileira(Fila* fila){
    BST* no = fila->prim->no;

    Celula* aux = fila->prim;
    fila->prim = fila->prim->prox;

    if(fila->prim == NULL) fila->ult = NULL;

    free(aux);

    return no;
}

int confereFilaVazia(Fila* fila){
    return(fila->prim == NULL && fila->ult == NULL);
}

void liberaFila(Fila* fila){
    Celula* atual = fila->prim;
    Celula* seguinte;

    while(atual){
        seguinte = atual->prox;
        free(atual);
        atual = seguinte;
    }
    free(fila);
}