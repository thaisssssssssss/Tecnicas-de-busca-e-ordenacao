#include "bst.h"

int main(int argc, char const *argv[]){
    srand(time(NULL));

    BST* bst = criaBST();

    int n = atoi(argv[1]);
    //int n = 10;
    int i, r;

    for(i = 0; i < n; i++){
        r = rand();
        bst = insereChaveBST(bst, r/1000000, i);
    }

    //imprimeBST(bst);
    printf("Altura da arvore: %d\n", alturaBST(bst));

    liberaBST(bst);

    return 0;
}
