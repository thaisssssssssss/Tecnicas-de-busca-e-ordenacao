#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct bst BST;

BST* criaBST();

BST* criaNo(int chave, int valor);

int compara(int c1, int c2);

BST* insereChaveBST(BST* bst, int chave, int valor);

BST* particionamento(BST* bst, int k);

BST* balanciamento(BST* bst);

BST* rotacaoADireita(BST* bst);

BST* rotacaoAEsquerda(BST* bst);

void liberaBST(BST* bst);

void imprimeBST(BST* bst);

int alturaBST(BST* bst);

int calculaTamanhoBST(BST* bst);

int atualizaTamanhoBST(BST* bst);

#endif