#include "bst.h"
#include <time.h>
#include <stdlib.h>


int main(){
    BST* arv = criaBSTvazia();

    srand(time(NULL)); // should only be called once
    
    int n, i;
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
        // printf("%d\n", r);
        arv = adicionaChaveArvore(arv, r);
    }
    
    printf("Altura arvore: %d\n", alturaBST(arv));
    
    liberaBST(arv);

    return 0;
}