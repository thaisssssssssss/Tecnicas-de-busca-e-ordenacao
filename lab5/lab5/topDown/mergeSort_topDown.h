#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#define TOPDOWN 1
#define TOPDOWN_CUTOFF 2
#define TOPDOWN_SKIP 3
#define TOPDOWN_COMPLETO 4

#include "merge.h"

void sort(Item *a, int lo, int hi, int TIPO);
void mergeSort_topDown(Item* vet, Item* aux, int lo, int hi);
void mergeSortCutoff(Item* vet, Item* aux, int lo, int hi);
void mergeSortSkip(Item* vet, Item* aux, int lo, int hi);
void mergeSortCompleto(Item* vet, Item* aux, int lo, int hi);

#endif
