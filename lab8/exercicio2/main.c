#include "bst.h"

int main(int argc, char const *argv[]){
    srand(time(NULL));

    BST* bst = criaBST();

    int n = atoi(argv[1]);
    //int n = 3;
    int i, r;

    for(i = 0; i < n; i++){
        r = rand()/1000000;
        //printf("(%d) ", r);
        bst = insereChaveBST(bst, r, i);
    }

    // bst = insereChaveBST(bst, 34, 0);
    // bst = insereChaveBST(bst, 1626, 1);
    // bst = insereChaveBST(bst, 489, 2);

    printf("\n");

    imprimeBST(bst);
    printf("Altura da arvore: %d\n", alturaBST(bst));

    bst = balanciamento(bst);
    imprimeBST(bst);
    printf("Altura da arvore: %d\n", alturaBST(bst));

    
    liberaBST(bst);

    return 0;
}
