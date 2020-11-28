// eratosthenes.c
// Řešení IJC-DU1, příklad a), 18.3.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.4.0
// Modul s eratosthenuvym algoritmem pro vypocet prvocisel
#include <math.h>
#include "bitset.h"

void Eratosthenes(bitset_t pole)
{
    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);
    for(bitset_index_t i = 4; i < bitset_size(pole); i+=2)
    {
        bitset_setbit(pole, i, 1);
    }
    for(bitset_index_t i = 3; i < sqrt(bitset_size(pole)); i+=2)
    {
        if(bitset_getbit(pole, i) == 0)
        {
            for(bitset_index_t j = i*i; j < bitset_size(pole); j += 2 * i)
            {
                bitset_setbit(pole, j, 1);
            }
        }
    }
}