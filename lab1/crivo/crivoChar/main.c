#include "crivoChar.h"
#include <time.h>

void crivoChar(){
    int n = 1000000000;
    char *vetor = inicializaVetor(n);
    marcaPrimos(vetor, n);
    //imprimeVetor(vetor, n); 
}

int main(){
    crivoChar();
    return 0;
}