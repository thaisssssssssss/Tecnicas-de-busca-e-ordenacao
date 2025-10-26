#include <stdio.h>
#include <stdlib.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    fprintf(stdout, "%d\n", n);
    

    int i, num;

    Item *vet = malloc(sizeof(int) * n);


    FILE* arquivo = fopen("input/in/thaisTeste/sorted.txt", "r");

    for(i = 0; i < n; i++){
        fscanf(arquivo, "%d", &num);
        vet[i] = num;
    }

    fclose(arquivo);

    sort(vet, 0, n);

    for(i = 0; i < n; i++){
        fprintf(stdout, "%d ", vet[i]);
    }
    free(vet);
}