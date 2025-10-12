// Thais Gomes Brandão 
// Matrícula:  2024102657


#ifndef JOSEFO_H
#define JOSEFO_H

#include <stdio.h>
#include <stdlib.h>

#define BYTE 8

#define set_bit(n) (a[n/BYTE] |= (1U << n%BYTE)) // setar: a[i] = 1
#define clear_bit(n) (a[n/BYTE] &=  (1U << n%BYTE)) // limpar: a[i] = 0
#define is_set(n) ((a[n/BYTE] >> n%BYTE) & 1U) // testar: a[i] == 1

void inicializaCirculo(int n);
void loopPrincipal(int n, int m);
int retiraNumero(int ultimo, int m, int n);
void encontraLider(int n);
void imprimeNumeroEliminado(int vez, int num);

#endif