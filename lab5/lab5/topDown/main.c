#include "mergeSort_topDown.h"
#include <time.h>

int main(int argc, char* argv[]){
    srand(time(NULL)); // should only be called once
    
    //int n = atoi(argv[1]);
    int n = 10000;
    Item* vet = malloc(sizeof(Item) * (n+1));
    int i;
    for(i = 0; i < n; i++){
        int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
        vet[i] = r;
    }
    

    printf("\n\nMERGE TOP-DOWN SEM ALTERACOES:\n");
    clock_t start = clock ();
    sort(vet, 0, n, TOPDOWN);
    clock_t end = clock ();
    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);

    // for(i = 0; i < n; i++){
    //     printf("%d ", vet[i]);
    // }


    printf("\n\nMERGE TOP-DOWN COM CUTOFF:\n");
    start = clock ();
    sort(vet, 0, n, TOPDOWN_CUTOFF);
    end = clock ();
    seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);

    // for(i = 0; i < n; i++){
    //     printf("%d ", vet[i]);
    // }

    printf("\n\nMERGE TOP-DOWN COM SKIP:\n");
    start = clock ();
    sort(vet, 0, n, TOPDOWN_SKIP);
    end = clock ();
    seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);
    
    // for(i = 0; i < n; i++){
    //     printf("%d ", vet[i]);
    // }

    printf("\n\nMERGE TOP-DOWN COM CUTOFF E SKIP:\n");
    start = clock ();
    sort(vet, 0, n, TOPDOWN_COMPLETO);
    end = clock ();
    seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);

    // for(i = 0; i < n; i++){
    //     printf("%d ", vet[i]);
    // }

    return 0;
}