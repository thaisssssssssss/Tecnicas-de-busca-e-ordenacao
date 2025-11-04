// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "bst.h"
#include <time.h>

int main(int argc, char* argv[]){
    BST* arv = criaBSTvazia();

    int i;
    int n = atoi(argv[1]);

    srand(time(NULL)); // should only be called once

    for(i = 0; i < n; i++){
        int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
        arv = adicionaChaveArvore(arv, r);
    }

    levelOrder(arv, imprimeNoBST);
    liberaBST(arv);

    return 0;
}