#include "bst.h"

int main(){
    BST* arv = criaBSTvazia();

    arv = adicionaChaveArvore(arv, 15);
    arv = adicionaChaveArvore(arv, 12);
    arv = adicionaChaveArvore(arv, 10);
    arv = adicionaChaveArvore(arv, 4);
    arv = adicionaChaveArvore(arv, 20);
    arv = adicionaChaveArvore(arv, 22);
    arv = adicionaChaveArvore(arv, 13);
    arv = adicionaChaveArvore(arv, 13);

    iterativa_preorder(arv, imprimeNoBST);
    printf("\n");
    iterativa_inorder(arv, imprimeNoBST);
    printf("\n");

    liberaBST(arv);

    return 0;
}