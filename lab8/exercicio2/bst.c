#include "bst.h"

struct bst{
    int chave;
    int valor;
    int tamanho;
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
    bst->tamanho = 1;
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
    
    // bst->tamanho = calculaTamanhoBST(bst);
    bst->tamanho = atualizaTamanhoBST(bst);
    return bst;
}

BST* particionamento(BST* bst, int k){
    if(bst == NULL) return NULL;

    int t = atualizaTamanhoBST(bst->esq);

    if(t > k){
        bst->esq = particionamento(bst->esq, k);
        bst = rotacaoADireita(bst);
    }
    else if(t < k){
        bst->dir = particionamento(bst->dir, k-t-1);
        bst = rotacaoAEsquerda(bst);
    }

    return bst;
}

BST* balanciamento(BST* bst){
    if(bst == NULL) return NULL;
    if(bst->tamanho < 2) return bst;
    
    bst = particionamento(bst, bst->tamanho / 2);
    bst->esq = balanciamento(bst->esq);
    bst->dir = balanciamento(bst->dir);
    
    bst->tamanho = atualizaTamanhoBST(bst);
    
    return bst;
}

BST* rotacaoADireita(BST* bst){
    BST* novo = bst->esq;

    bst->esq = novo->dir;
    
    novo->dir = bst;

    bst->tamanho = atualizaTamanhoBST(bst);
    novo->tamanho = atualizaTamanhoBST(novo);

    return novo;
}

BST* rotacaoAEsquerda(BST* bst){
    BST* novo = bst->dir;

    bst->dir = novo->esq;
    
    novo->esq = bst;

    bst->tamanho = atualizaTamanhoBST(bst);
    novo->tamanho = atualizaTamanhoBST(novo);

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
        printf("tamanho: %d\n", bst->tamanho);
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

int calculaTamanhoBST(BST* bst){
    if(bst == NULL) return 0;
    else{
        int esq = calculaTamanhoBST(bst->esq);
        int dir = calculaTamanhoBST(bst->dir);
        
        return esq + dir + 1;
    }
}

int atualizaTamanhoBST(BST* bst){
    if(bst == NULL) return 0;
    else{
        if(bst->esq != NULL && bst->dir != NULL) return 1 + bst->esq->tamanho + bst->dir->tamanho;
        else if(bst->esq != NULL) return 1 + bst->esq->tamanho;
        else if(bst->dir != NULL) return 1 + bst->dir->tamanho;
        else return 1;
    }
}