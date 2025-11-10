#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#define BOTTOMUP 1
#define BOTTOMUP_CUTOFF 2
#define BOTTOMUP_SKIP 3
#define BOTTOMUP_COMPLETO 4

#include "merge.h"

void sort(Item *a, int lo, int hi, int TIPO);
void mergeSort_bottomUp(Item* vet, Item* aux, int lo, int hi);
void mergeSortCutoff(Item* vet, Item* aux, int lo, int hi);
void mergeSortSkip(Item* vet, Item* aux, int lo, int hi);
void mergeSortCompleto(Item* vet, Item* aux, int lo, int hi);

#endif
