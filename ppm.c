// ppm.c
// Řešení IJC-DU1, příklad b), 18.3.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.4.0
// Modul k nacteni dat z obrazku
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error.h"
#include "ppm.h"

struct ppm * ppm_read(const char * filename)
{
    if(access(filename, F_OK) == -1)
    {
        warning_msg("Soubor neexistuje\n");
        return NULL;
    }
    FILE *input = fopen(filename, "rb");
    if(input == NULL)
    {
        warning_msg("Otevreni souboru se nezdarilo\n");
        fclose(input);        
        return NULL;
    }
    char format[2];
    unsigned rgb;
    unsigned x;
    unsigned y;
    unsigned size;
    if(fscanf(input, "%2s %u %u %u ",format, &x, &y, &rgb) != 4)
    {
        warning_msg("Nacteni hlavicky souboru se nezdarilo\n");
        fclose(input);
        return NULL;
    }
    if(format[0] != 'P' || format[1] !='6')
    {
        warning_msg("Spatny format souboru\n");
        fclose(input);
        return NULL;
    }
    size = 3 * x * y;
    if(size > MAX_SIZE)
    {
        warning_msg("Obrazek je prilis velky\n");
        fclose(input);
        return NULL;
    }
    struct ppm *img = malloc(sizeof(struct ppm) + size);
    img->xsize = x;
    img->ysize = y;
    unsigned value = fread(img->data, sizeof(char), size, input);
    if(value != size)
    {
        warning_msg("Velikost nactenych dat neodpovida hlavicce souboru\n");
        fclose(input);
        ppm_free(img);
        return NULL;
    }
    fclose(input);
    return img;
}

void ppm_free(struct ppm *p)
{
    free(p);
}
