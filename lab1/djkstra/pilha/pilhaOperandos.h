// Thais Gomes Brandão 
// Matrícula:  2024102657


#ifndef PILHA_OPERANDOS_H
#define PILHA_OPERANDOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CHAR 1
#define DOUBLE 2

typedef struct pilhaOperandos PilhaOperandos;

PilhaOperandos* criaPilhaOperandos();
void adicionaValorPilha(PilhaOperandos* pilhaOperandos, char* c, double n, int OPCAO);
double retornaNumero(char* op);
void imprimePilha(PilhaOperandos* pilha);
double retornaValor(PilhaOperandos* pilha);
void liberaPilhaOperandos(PilhaOperandos* pilha);

#endif