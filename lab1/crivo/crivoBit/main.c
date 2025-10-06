#include "crivoBit.h"
#include <time.h>

void crivoBit(){
    int n = 1000000000;
    int bytes = n / BYTE;
    inicializaVetor(bytes);
    marcaPrimos(n);
    //imprimeVetor(n); 
}

int main(){
    crivoBit();
    return 0;
}