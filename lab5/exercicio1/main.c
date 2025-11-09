#include "merge_sort.h"
#include <time.h>

int main(int argc, char* argv[]){
    srand(time(NULL)); // should only be called once
    
    //int n = atoi(argv[1]);
    int n = 10;
    Item* vet = malloc(sizeof(Item) * (n+1));
    int i;
    for(i = 0; i < n; i++){
        int r = rand() % 100; // returns a pseudo-random integer between 0 and RAND_MAX
        vet[i] = r;
    }
    
    // sort(vet, 0, n);
    // for(i = 0; i < n; i++){
    //     printf("%d ", vet[i]);
    // }

    clock_t start = clock ();
    sort(vet, 0, n);
    clock_t end = clock ();

    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf ("TEMPO: %lf\n\n", seconds);
    
    return 0;
}