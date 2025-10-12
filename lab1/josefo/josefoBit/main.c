// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "josefo.h"

int main(){
    long int n = 100000000;
    int bytes = n / BYTE;
    int m = 10;

    inicializaCirculo(bytes);
    loopPrincipal(n, m);
    encontraLider(n);

    return 0;
}