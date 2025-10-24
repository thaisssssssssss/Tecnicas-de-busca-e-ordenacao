#include "bst.h"
#include <time.h>

int main(){
    BST* arv = criaBSTvazia();

    arv = adicionaChaveArvore(arv, 15);
    arv = adicionaChaveArvore(arv, 12);
    arv = adicionaChaveArvore(arv, 10);
    arv = adicionaChaveArvore(arv, 4);
    arv = adicionaChaveArvore(arv, 20);
    arv = adicionaChaveArvore(arv, 22);
    arv = adicionaChaveArvore(arv, 13);
    arv = adicionaChaveArvore(arv, 14);


    // int n = 10000000, i;
    // //scanf("%d", &n);

    // srand(time(NULL)); // should only be called once

    // for(i = 0; i < n; i++){
    //     int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
    //     arv = adicionaChaveArvore(arv, r);
    // }

    // clock_t start = clock ();
    // iterativa_postorder(arv, imprimeNoBST);
    // clock_t end = clock ();

    // double seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    // printf ("%lf\n", seconds);

    levelOrder(arv, imprimeNoBST);
    liberaBST(arv);

    return 0;
}