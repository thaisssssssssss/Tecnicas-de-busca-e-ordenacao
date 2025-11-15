#include "quick_sort.h"

// int particioning(Item* vet, int lo, int hi){
//     int i = lo + 1;
//     int j = hi;

//     while(i < hi && j > lo){
//         if(vet[i] <= vet[lo]) i++;
//         else if(vet[j] > vet[lo]) j--;
//         else if(i > j) break;
//         else{
//             exch(vet[i], vet[j]);
//         }
//     }
//     exch(vet[lo], vet[j]);
//     return j;
// }

int particioning(Item* vet, int lo, int hi){
    int i = lo;
    int j = hi + 1;

    while(1){
        while(less(vet[++i], vet[lo])){
            if(i == hi) break;
        }
        while(less(vet[lo], vet[--j])){
            if(j == lo) break;
        }
        if(i >= j) break;
        exch(vet[i], vet[j]);
    }

    exch(vet[lo], vet[j]);
    return j;
}

void quickSort(Item* vet, int lo, int hi){
    if(hi <= lo) return;
    int a = particioning(vet, lo, hi);
    quickSort(vet, lo, a-1);
    quickSort(vet, a+1, hi);
}