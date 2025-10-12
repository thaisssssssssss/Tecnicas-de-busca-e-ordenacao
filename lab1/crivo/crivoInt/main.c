// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "crivo.h"
#include <time.h>

void crivoInt(){
    int n = 100000000;
    int *vetor = inicializaVetor(n);
    marcaPrimos(vetor, n);
    // imprimeVetor(vetor, n); 
    free(vetor);
}

int main(){
    crivoInt();
    return 0;
}