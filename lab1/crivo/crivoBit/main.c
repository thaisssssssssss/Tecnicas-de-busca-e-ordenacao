// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "crivoBit.h"
#include <time.h>

void crivoBit(){
    long int n = 100000;
    int bytes = n / BYTE;
    inicializaVetor(bytes);
    marcaPrimos(n);
    // imprimeVetor(n); 
}

int main(){
    crivoBit();
    return 0;
}