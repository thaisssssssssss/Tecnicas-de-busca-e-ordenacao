#include "bst.h"

struct bst{
    int valor;
    BST* esq;
    BST* dir;
};

int confereBSTvazia(BST* arv){
    return (arv == NULL);
}

BST* criaBSTvazia(){
    return NULL;
}

BST* criaNo(int chave, BST* esq, BST* dir){
    BST* no = malloc(sizeof(struct bst));
    no->valor = chave;
    no->esq = esq;
    no->dir = dir;
    return no;
}

BST* adicionaChaveArvore(BST* arv, int chave){
    if(confereBSTvazia(arv)){
        arv = criaNo(chave, NULL, NULL);
    }
    else{
        if(arv->valor > chave) arv->esq = adicionaChaveArvore(arv->esq, chave);
        else if(arv->valor < chave) arv->dir = adicionaChaveArvore(arv->dir, chave);
    }

    return arv;
}

void imprimeBST(BST* arv){
    if(confereBSTvazia(arv)) return;
    else{
        imprimeBST(arv->esq);
        printf("%d ", arv->valor);
        imprimeBST(arv->dir);
    }
}

void liberaBST(BST* arv){
    if(confereBSTvazia(arv)) return;
    else{
        liberaBST(arv->esq);
        liberaBST(arv->dir);
        free(arv);
    }
}