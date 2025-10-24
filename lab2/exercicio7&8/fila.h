#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

typedef struct fila Fila;

Fila* criaFilaVazia();
void enfileira(Fila* fila, BST* no);
BST* desenfileira(Fila* fila);
int confereFilaVazia(Fila* fila);
void liberaFila(Fila* fila);

#endif