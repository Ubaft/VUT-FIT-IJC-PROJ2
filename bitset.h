// bitset.h
// Řešení IJC-DU1, příklad a), 18.3.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.4.0
// Modul obsahujici definice maker
#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "error.h"
#ifndef BITSET_H
#define BITSET_H
        typedef unsigned long *bitset_t;
        typedef unsigned long bitset_index_t;

        #define ul_bitsize (sizeof(bitset_index_t)*CHAR_BIT)
        #define real_size(velikost) (1+(velikost/ul_bitsize)+((velikost%ul_bitsize)? 1 : 0))

        #define bitset_create(jmeno_pole,velikost) \
                bitset_index_t jmeno_pole[real_size(velikost)] = {velikost};\
                _Static_assert(velikost>0, "Pole musi byt vetsi 0\n")

        #define bitset_alloc(jmeno_pole,velikost)\
                assert(velikost>0);\
                bitset_t jmeno_pole = calloc(real_size(velikost), sizeof(bitset_index_t));\
                if(jmeno_pole == NULL)\
                {\
                        error_exit("bitset_alloc: Chyba alokace paměti\n");\
                        return 1;\
                }\
                *jmeno_pole = velikost

        #ifndef USE_INLINE
                #define bitset_free(jmeno_pole) free(jmeno_pole)

                #define bitset_size(jmeno_pole) jmeno_pole[0]

                #define bitset_setbit(jmeno_pole,index,vyraz)\
                        if(index >= bitset_size(jmeno_pole))\
                        {\
                                error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole)-1);\
                        }\
                        if(vyraz == 0)\
                        {\
                                jmeno_pole[1 + (index/ul_bitsize)] = ~jmeno_pole[1 + (index/ul_bitsize)];\
                        }\
                        jmeno_pole[1 + (index/ul_bitsize)] |= (1UL << (ul_bitsize-1-(index%ul_bitsize)));\
                        if(vyraz == 0)\
                        {\
                                jmeno_pole[1 + (index/ul_bitsize)] = ~jmeno_pole[1 + (index/ul_bitsize)];\
                        }
                        
                #define bitset_getbit(jmeno_pole,index)\
                        (index >= bitset_size(jmeno_pole))?\
                        (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)(bitset_size(jmeno_pole)-1)), 2):\
                        ((jmeno_pole[1 + (index/ul_bitsize)] >> (ul_bitsize-1-(index%ul_bitsize))) & 1UL)
        #else
                inline void bitset_free(bitset_t jmeno_pole)
                {
                        free(jmeno_pole);
                }
                inline bitset_index_t bitset_size(bitset_t jmeno_pole)
                {
                        return jmeno_pole[0];
                }
                inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz)
                {
                        if(index >= bitset_size(jmeno_pole))
                        {
                                error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole)-1);
                        }
                        if(vyraz == 0)
                        {
                                jmeno_pole[1 + (index/ul_bitsize)] = ~jmeno_pole[1 + (index/ul_bitsize)];
                        }
                        jmeno_pole[1 + (index/ul_bitsize)] |= (1UL << (ul_bitsize-1-(index%ul_bitsize)));
                        if(vyraz == 0)
                        {
                                jmeno_pole[1 + (index/ul_bitsize)] = ~jmeno_pole[1 + (index/ul_bitsize)];
                        }
                        return;
                }
                inline bitset_index_t bitset_getbit(bitset_t jmeno_pole,bitset_index_t index)
                {
                        if(index >= bitset_size(jmeno_pole))
                                error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)(bitset_size(jmeno_pole)-1));
                        return ((jmeno_pole[1 + (index/ul_bitsize)] >> (ul_bitsize-1-(index%ul_bitsize))) & 1UL);
                }
        #endif
#endif