// Thais Gomes Brandão 
// Matrícula:  2024102657


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

//funcoes de visitar pre, in e pos ordem
void imprimeNoBST(BST* arv);
void iterativa_preorder(BST* arv, void(*visit)(BST*));
void iterativa_inorder(BST* arv, void(*visit)(BST*));
void iterativa_postorder(BST* arv, void(*visit)(BST*));

//funcoes de visitar pre, in e pos ordem
void imprimeNoBST(BST* arv);
void rec_preorder(BST *arv, void (*visit)(BST*));
void rec_inorder(BST *arv, void (*visit)(BST*));
void rec_postorder(BST *arv, void (*visit)(BST*));

#endif