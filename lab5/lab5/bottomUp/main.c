#include "mergeSort_bottomUp.h"
#include <time.h>

int main(int argc, char* argv[]){
    srand(time(NULL)); // should only be called once
    
    //int n = atoi(argv[1]);
    int n = 100;
    Item* vet = malloc(sizeof(Item) * (n+1));
    int i;
    for(i = 0; i < n; i++){
        int r = rand()%1000; // returns a pseudo-random integer between 0 and RAND_MAX
        vet[i] = r;
    }
    

    printf("\n\nMERGE BOTTOM-UP SEM ALTERACOES:\n");
    clock_t start = clock ();
    sort(vet, 0, n, BOTTOMUP);
    clock_t end = clock ();
    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);

    for(i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }


    printf("\n\nMERGE BOTTOM-UP COM CUTOFF:\n");
    start = clock ();
    sort(vet, 0, n, BOTTOMUP_CUTOFF);
    end = clock ();
    seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);

    for(i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }

    printf("\n\nMERGE BOTTOM-UP COM SKIP:\n");
    start = clock ();
    sort(vet, 0, n, BOTTOMUP_SKIP);
    end = clock ();
    seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);
    
    for(i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }

    printf("\n\nMERGE BOTTOM-UP COM CUTOFF E SKIP:\n");
    start = clock ();
    sort(vet, 0, n, BOTTOMUP_COMPLETO);
    end = clock ();
    seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);

    for(i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}