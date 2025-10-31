// Thais Gomes Brandão 
// Matrícula:  2024102657


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    fprintf(stdout, "%d\n", n);
    
    char* caminho = strdup(argv[2]);
    int i, num;

    Item *vet = malloc(sizeof(int) * n);

    FILE* arquivo = fopen(caminho, "r");
    for(i = 0; i < n; i++){
        fscanf(arquivo, "%d", &num);
        vet[i] = num;
    }
    fclose(arquivo);

    clock_t start = clock ();
    sort(vet, 0, n);
    clock_t end = clock ();

    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);

    free(vet);
    free(caminho);
}

