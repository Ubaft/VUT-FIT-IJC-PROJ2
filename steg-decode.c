// steg-decode.c
// Řešení IJC-DU1, příklad b), 18.3.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.4.0
// Program dekodujici zpravu v obrazku typu ppm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "ppm.h" 
#include "eratosthenes.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        error_exit("Nespravny pocet argumentu\n");
    }
    struct ppm *image;
    image = ppm_read(argv[1]);
    if(image == NULL)
    {
        error_exit("Nacteni souboru se nezdarilo\n");
    }

    bitset_alloc(primes, (image->xsize * image->ysize *3));
    Eratosthenes(primes);
    char messageLetter = 0;
    int bit;
    unsigned j = 8;

    for(unsigned i = 23; i < (image->xsize * image->ysize *3); i++)
    {
        if(bitset_getbit(primes, i) == 0)
        {
            bit = image->data[i] & 1;
            messageLetter += bit*(pow(2, (8-j)));
            j--;
            if(j==0)
            {
                if(messageLetter == '\0')
                {
                    printf("\n");
                    ppm_free(image);
                    bitset_free(primes);
                    return 0;
                }
                putchar(messageLetter);
                messageLetter = 0;
                j = 8;
            }
        }
    }
    
    ppm_free(image);
    bitset_free(primes);
}