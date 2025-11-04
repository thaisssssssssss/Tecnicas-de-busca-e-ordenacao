// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "bst.h"
#include <time.h>

int main(int argc, char* argv[]){
    BST* arv = criaBSTvazia();

    int n = atoi(argv[1]);

    srand(time(NULL)); // should only be called once

    int i;
    for(i = 0; i < n; i++){
        int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
        arv = adicionaChaveArvore(arv, r);
    }

    //RECURSIVA PRE-ORDER
    printf("Recursiva Pre-Order\n");
    clock_t start = clock ();
    rec_preorder(arv, imprimeNoBST);
    clock_t end = clock ();

    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("%lf\n\n", seconds);

    //RECURSIVA IN-ORDER
    printf("Recursiva In-Order\n");
    start = clock ();
    rec_inorder(arv, imprimeNoBST);
    end = clock ();

    seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("%lf\n\n", seconds);

    //RECURSIVA POST-ORDER
    printf("Recursiva Post-Order\n");
    start = clock ();
    rec_inorder(arv, imprimeNoBST);
    end = clock ();

    seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("%lf\n\n", seconds);



    //ITERATIVA PRE-ORDER
    printf("Iterativa Pre-Order\n");
    start = clock ();
    iterativa_preorder(arv, imprimeNoBST);
    end = clock ();

    seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("%lf\n\n", seconds);

    //ITERATIVA IN-ORDER
    printf("Iterativa In-Order\n");
    start = clock ();
    iterativa_inorder(arv, imprimeNoBST);
    end = clock ();

    seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("%lf\n\n", seconds);

    //ITERATIVA POST-ORDER
    printf("Iterativa Post-Order\n");
    start = clock ();
    iterativa_postorder(arv, imprimeNoBST);
    end = clock ();

    seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("%lf\n", seconds);

    
    liberaBST(arv);

    return 0;
}