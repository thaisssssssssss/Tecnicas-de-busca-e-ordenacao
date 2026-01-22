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
        bst = insereChaveBST(bst, i, i);
    }

    printf("\n");

    printf("Altura da arvore desbalanceada: %d\n", alturaBST(bst));

    bst = balanciamento(bst);
    printf("Altura da arvore balanceada: %d\n", alturaBST(bst));

    
    liberaBST(bst);

    return 0;
}
