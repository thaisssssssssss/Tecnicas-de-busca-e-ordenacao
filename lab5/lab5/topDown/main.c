// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "mergeSort_topDown.h"
#include <time.h>

int main(int argc, char* argv[]){
    srand(time(NULL)); // should only be called once
    
    int n = atoi(argv[1]);
    char* caminho = strdup(argv[2]);

    FILE* arq = fopen(caminho, "r");

    Item* vet = malloc(sizeof(Item) * (n+1));
    int i, r;
    for(i = 0; i < n; i++){
        fscanf(arq, "%d", &r);
        vet[i] = r;
    }
    
    vet[n] = 0;
    fclose(arq);

    printf("\n\nMERGE TOP-DOWN SEM ALTERACOES:\n");
    clock_t start = clock ();
    sort(vet, 0, n, TOPDOWN);
    clock_t end = clock ();
    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);



    printf("\n\nMERGE TOP-DOWN COM CUTOFF:\n");
    start = clock ();
    sort(vet, 0, n, TOPDOWN_CUTOFF);
    end = clock ();
    seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);

    

    printf("\n\nMERGE TOP-DOWN COM SKIP:\n");
    start = clock ();
    sort(vet, 0, n, TOPDOWN_SKIP);
    end = clock ();
    seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);
    
    

    printf("\n\nMERGE TOP-DOWN COM CUTOFF E SKIP:\n");
    start = clock ();
    sort(vet, 0, n, TOPDOWN_COMPLETO);
    end = clock ();
    seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);


    free(caminho);
    free(vet);

    return 0;
}