#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst BST;

int confereBSTvazia(BST* arv);
BST* criaBSTvazia();
BST* criaNo(int chave, BST* esq, BST* dir);
BST* adicionaChaveArvore(BST* arv, int chave);
void imprimeBST(BST* arv);
void liberaBST(BST* arv);
int alturaBST(BST* arv);

#endif