#ifndef QUICK_SORT_H
#define QUICK_SORT_H


#include <stdio.h>
#include <stdlib.h>
#include "item.h"


int particioning(Item* vet, int lo, int hi);

void quickSort(Item* vet, int lo, int hi);

#endif
