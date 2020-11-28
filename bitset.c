// bitset.c
// Řešení IJC-DU1, příklad a), 18.3.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.4.0
// Externi definice inline funkci
#include "bitset.h"
#ifdef USE_INLINE
extern void bitset_free(bitset_t jmeno_pole);
extern bitset_index_t bitset_size(bitset_t jmeno_pole);
extern void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz);
extern bitset_index_t bitset_getbit(bitset_t jmeno_pole,bitset_index_t index);
#endif