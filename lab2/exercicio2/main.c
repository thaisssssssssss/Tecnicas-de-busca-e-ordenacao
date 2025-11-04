// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "bst.h"
#include <time.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    BST* arv = criaBSTvazia();

    srand(time(NULL)); // should only be called once
    
    int n = atoi(argv[1]);
    int i;
    for(i = 0; i < n; i++){
        int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
        arv = adicionaChaveArvore(arv, r);
    }
    
    fprintf(stdout, "Altura arvore: %d\n", alturaBST(arv));
    liberaBST(arv);

    return 0;
}