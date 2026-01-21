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

void liberaBST(BST* bst);

void imprimeBST(BST* bst);

int alturaBST(BST* bst);

#endif