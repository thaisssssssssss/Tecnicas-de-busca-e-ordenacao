#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


void sort(Item *a, int lo, int hi);

void mergeSortCutoff(Item* vet, Item* aux, int lo, int hi);

void mergeSortSkip(Item* vet, Item* aux, int lo, int hi);

void merge(Item* vet, Item* aux, int lo, int mid, int hi);

void insertSort(Item *a, int lo, int hi);

#endif
