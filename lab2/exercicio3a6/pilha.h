// Thais Gomes Brandão 
// Matrícula:  2024102657


#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

typedef struct pilha Pilha;

Pilha* criaPilhaVazia();
Pilha* push(Pilha* pilha, BST* no);
BST* pop(Pilha* pilha);
int conferePilhaVazia(Pilha* pilha);
Pilha* liberaTopo(Pilha* pilha);

#endif