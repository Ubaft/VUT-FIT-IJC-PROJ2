# Makefile
# Řešení IJC-DU1, příklad a), 18.3.2020
# Autor: Filip Osvald, FIT
# Přeloženo: gcc 7.4.0
# Makefile pro prelozeni projektu prikazem make
CC = gcc
CFLAGS= -g -O2 -std=c11 -pedantic -Wall -Wextra
all: primes primes-i steg-decode


primes: primes.o eratosthenes.o bitset.o error.o
	$(CC) $(CFLAGS) -o primes primes.o eratosthenes.o bitset.o error.o -lm

primes.o: primes.c
	$(CC) $(CFLAGS) -c primes.c -o primes.o
eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o
bitset.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -c bitset.c -o bitset.o
error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c -o error.o


primes-i: primes-i.o eratosthenes-i.o bitset-i.o error.o
	$(CC) $(CFLAGS) -o primes-i primes-i.o eratosthenes-i.o bitset-i.o error.o -lm
primes-i.o: primes.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o
eratosthenes-i.o: eratosthenes.c eratosthenes.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o
bitset-i.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset-i.o


steg-decode: steg-decode.o eratosthenes.o bitset.o error.o ppm.o
	$(CC) $(CFLAGS) -o steg-decode steg-decode.o eratosthenes.o bitset.o error.o ppm.o -lm
steg-decode.o: steg-decode.c
	$(CC) $(CFLAGS) -c steg-decode.c -o steg-decode.o

ppm.o: ppm.c ppm.h
	$(CC) $(CFLAGS) -c ppm.c -o ppm.o
run: primes primes-i
	./primes
	./primes-i