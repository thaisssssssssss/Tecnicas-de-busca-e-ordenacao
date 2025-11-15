#include "quick_sort.h"
#include <time.h>


int main(int argc, char const *argv[]){
    //int n = atoi(argv[1]);
    int n = 10000000;
    Item* vet = malloc(sizeof(Item) * n);

    int i;
    for(i = 0; i < n; i++){
        vet[i] = rand() % 100;
    }

    __clock_t inicio = clock();
    quickSort(vet, 0, n-1);
    __clock_t final = clock();
    double tempo = (double)(final - inicio) / CLOCKS_PER_SEC;
    printf("TEMPO: %lf", tempo);

    for(i = 0; i < n; i += 1000000){
        printf("%d ", vet[i]);
    }

    free(vet);
    return 0;
}
