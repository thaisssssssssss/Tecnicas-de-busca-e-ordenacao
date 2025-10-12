// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "josefo.h"

int main(){
    int n = 100000;
    int m = 10;
    int* circulo = criaCirculo(n);
    loopPrincipal(circulo, n, m);
    encontraLider(circulo, n);
    free(circulo);
    return 0;
}