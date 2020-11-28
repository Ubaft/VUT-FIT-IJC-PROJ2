// ppm.h
// Řešení IJC-DU1, příklad b), 18.3.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.4.0
// Hlavickovy soubor pro modul ppm.c
#ifndef PPM_H
#define PPM_H
#define MAX_SIZE 8000*8000*3
struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];
};
struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);
#endif