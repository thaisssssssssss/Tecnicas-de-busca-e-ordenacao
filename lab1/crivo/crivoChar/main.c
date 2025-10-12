// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "crivoChar.h"
#include <time.h>

void crivoChar(){
    int n = 10000000000;
    char *vetor = inicializaVetor(n);
    marcaPrimos(vetor, n);
    // imprimeVetor(vetor, n); 
    free(vetor);
}

int main(){
    crivoChar();
    return 0;
}