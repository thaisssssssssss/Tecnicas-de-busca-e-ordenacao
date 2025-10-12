// Thais Gomes Brandão 
// Matrícula:  2024102657


#ifndef JOSEFO_H
#define JOSEFO_H

#include <stdio.h>
#include <stdlib.h>

int* criaCirculo(int n);
void loopPrincipal(int* circulo, int n, int m);
int retiraNumero(int* circulo, int ultimo, int m, int n);
void imprimeNumeroEliminado(int vez, int num);
void encontraLider(int* circulo, int n);

#endif