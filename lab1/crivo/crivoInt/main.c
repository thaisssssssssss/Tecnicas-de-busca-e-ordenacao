#include "crivo.h"
#include <time.h>

void crivoInt(){
    int n = 100;
    int *vetor = inicializaVetor(n);
    marcaPrimos(vetor, n);
    imprimeVetor(vetor, n); 
}

int main(){
    crivoInt();
    return 0;
}