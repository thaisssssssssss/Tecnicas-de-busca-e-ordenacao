#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include "item.h"

typedef struct pilha Pilha;

Pilha* inicializaPilha();
Pilha* push(Item a, Pilha* pilha);
Item pop(Pilha** pilha);
Pilha* limpa(Pilha* pilha);
int vazia(Pilha* pilha);

#endif