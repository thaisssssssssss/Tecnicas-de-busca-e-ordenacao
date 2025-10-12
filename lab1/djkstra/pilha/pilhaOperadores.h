// Thais Gomes Brandão 
// Matrícula:  2024102657


#ifndef PILHA_OPERADORES_H
#define PILHA_OPERADORES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct pilhaOperadores PilhaOperadores;

PilhaOperadores* criaPilhaOperadores();
char retornaOperador(char* op);
double retornaNumero(char* op);
void adicionaOperadorPilha(PilhaOperadores* pilhaOperadores, char* c);
char retornaOperacao(PilhaOperadores* pilha);
void imprimePilhaOperadores(PilhaOperadores* pilha);
void liberaPilhaOperadores(PilhaOperadores* pilha);

#endif