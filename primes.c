// primes.c
// Řešení IJC-DU1, příklad a), 18.3.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.4.0
// Program pro vypocitani prvocisel
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

#define target 500000000
int main()
{
    clock_t start = clock();
    bitset_alloc(pole, target);
    Eratosthenes(pole);

    bitset_index_t i = bitset_size(pole) - 1;
    bitset_index_t j = 0UL;
    bitset_index_t results[10];

    while(j < 10UL)
    {
        if(bitset_getbit(pole, i) == 0UL)
        {
            results[j] = i;
            j++;
        }
        i--;
    }

    for(int j = 9; j >= 0; j--)
    {
        printf("%lu\n", results[j]);
    }
    
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}