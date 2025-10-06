#ifndef CRIVO_H
#define CRIVO_H

#include <stdio.h>
#include <stdlib.h>

// static unsigned char *a;

#define BYTE 8

#define set_bit(n) (a[n/BYTE] |= (1U << n%BYTE)) // setar: a[i] = 1
#define clear_bit(n) (a[n/BYTE] &=  (1U << n%BYTE)) // limpar: a[i] = 0
#define is_set(n) ((a[n/BYTE] >> n%BYTE) & 1U) // testar: a[i] == 1


void inicializaVetor(int n);
void imprimeVetor(int n);
void marcaPrimos(int n);
void saltaMultiplos(int mult, int n);

#endif