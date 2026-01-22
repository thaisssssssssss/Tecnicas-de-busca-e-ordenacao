// Thais Gomes Brandão 
// Matrícula:  2024102657

#include "bst.h"

int main(int argc, char const *argv[]){
    srand(time(NULL));

    BST* bst = criaBST();

    int n = atoi(argv[1]);
    int i, r;

    for(i = 0; i < n; i++){
        r = rand();
        bst = insereChaveBST(bst, r, i);
    }

    printf("Altura da arvore: %d\n", alturaBST(bst));

    liberaBST(bst);

    return 0;
}
