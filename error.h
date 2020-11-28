// error.h
// Řešení IJC-DU1, příklad b), 18.3.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.4.0
// Hlavickovy soubor pro modul error.c
#ifndef ERROR_H
#define ERROR_H
void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);
#endif