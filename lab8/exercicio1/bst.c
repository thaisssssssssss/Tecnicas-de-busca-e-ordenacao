#include "bst.h"

struct bst{
    int chave;
    int valor;
    BST* esq;
    BST* dir;
};

BST* criaBST(){
    return NULL;
}

BST* criaNo(int chave, int valor){
    BST* bst = malloc(sizeof(struct bst));
    if(bst == NULL){
        printf("Erro ao alocar memoria para o no da arvore binaria de busca");
        exit(1);
    }

    bst->chave = chave;
    bst->valor = valor;
    bst->esq = NULL;
    bst->dir = NULL;
    return bst;
}

int compara(int c1, int c2){
    return c1 - c2;
}

BST* insereChaveBST(BST* bst, int chave, int valor){
    if(bst == NULL) return criaNo(chave, valor);

    int comp = compara(chave, bst->chave);

    if(comp < 0){
        bst->esq = insereChaveBST(bst->esq, chave, valor);
        bst = rotacaoADireita(bst);
    }
    else if(comp > 0){
        bst->dir = insereChaveBST(bst->dir, chave, valor);
        bst = rotacaoAEsquerda(bst);
    }
    else bst->valor = valor;
    
    return bst;
}

BST* rotacaoADireita(BST* bst){
    BST* novo = bst->esq;

    bst->esq = novo->dir;
    
    novo->dir = bst;
    return novo;
}

BST* rotacaoAEsquerda(BST* bst){
    BST* novo = bst->dir;

    bst->dir = novo->esq;
    
    novo->esq = bst;
    return novo;
}

void liberaBST(BST* bst){
    if(bst == NULL) return;
    else{
        liberaBST(bst->esq);
        liberaBST(bst->dir);
        free(bst);
    }
}

void imprimeBST(BST* bst){
    if(bst == NULL) return;
    else{
        imprimeBST(bst->esq);
        printf("chave: %d ", bst->chave);
        printf("valor: %d\n", bst->valor);
        imprimeBST(bst->dir);
    }
}

int alturaBST(BST* bst){
    if(bst == NULL) return -1;
    else{
        int esq = alturaBST(bst->esq);
        int dir = alturaBST(bst->dir);

        if(esq > dir) return esq + 1;
        else return dir + 1;
    }
}

