#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


void sort(Item *a, int lo, int hi);

void mergeSort(Item* vet, Item* aux, int lo, int hi);

void merge(Item* vet, Item* aux, int lo, int mid, int hi);


#endif
