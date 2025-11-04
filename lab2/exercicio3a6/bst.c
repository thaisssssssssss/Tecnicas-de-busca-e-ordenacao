// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "bst.h"
#include "pilha.h"

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

int alturaBST(BST* arv){
    if(confereBSTvazia(arv)) return -1;
    else{
        int esq = alturaBST(arv->esq);
        int dir = alturaBST(arv->dir);

        if(esq > dir) return esq + 1;
        else return dir + 1;
    }
}

void imprimeNoBST(BST* arv){
    //printf("%d ", arv->valor);
}

void iterativa_preorder(BST* arv, void(*visit)(BST*)){
    Pilha* pilha = criaPilhaVazia();

    while(1){
        if(!confereBSTvazia(arv)){
            pilha = push(pilha, arv->dir);
            visit(arv);
            arv = arv->esq;
        }
        else{
            if(conferePilhaVazia(pilha)) break;
            else arv = pop(pilha);
            pilha = liberaTopo(pilha);
        }
    }
}

void iterativa_inorder(BST* arv, void(*visit)(BST*)){
    Pilha* pilha = criaPilhaVazia();

    while(1){
        if(!confereBSTvazia(arv)){
            pilha = push(pilha, arv);
            arv = arv->esq;
        }
        else{
            if(conferePilhaVazia(pilha)) break;
            else{
                arv = pop(pilha);
                pilha = liberaTopo(pilha);
                visit(arv);
                arv = arv->dir;
            }
        }
    }
}


void iterativa_postorder(BST* arv, void(*visit)(BST*)){
    Pilha* pilhaRaiz = criaPilhaVazia();
    Pilha* pilhaEfetiva = criaPilhaVazia();

    while(1){
        if(!confereBSTvazia(arv)){
            pilhaRaiz = push(pilhaRaiz, arv);
            pilhaEfetiva = push(pilhaEfetiva, arv);
            arv = arv->dir;
        }
        else{
            if(conferePilhaVazia(pilhaRaiz)) break;
            arv = pop(pilhaRaiz);
            pilhaRaiz = liberaTopo(pilhaRaiz);
            arv = arv->esq;
        }
    }

    while(!conferePilhaVazia(pilhaEfetiva)){
        arv = pop(pilhaEfetiva);
        pilhaEfetiva = liberaTopo(pilhaEfetiva);
        //visit(arv);
    }
}

void rec_preorder(BST *arv, void (*visit)(BST*)){
    if(confereBSTvazia(arv)) return;
    else{
        //visit(arv);
        rec_preorder(arv->esq, visit);
        rec_preorder(arv->dir, visit);
    }
}

void rec_inorder(BST *arv, void (*visit)(BST*)){
    if(confereBSTvazia(arv)) return;
    else{
        rec_inorder(arv->esq, visit);
        //visit(arv);
        rec_inorder(arv->dir, visit);
    }
}

void rec_postorder(BST *arv, void (*visit)(BST*)){
    if(confereBSTvazia(arv)) return;
    else{
        rec_postorder(arv->esq, visit);
        rec_postorder(arv->dir, visit);
        //visit(arv);
    }
}
