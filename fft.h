#ifndef FFT_H
#define FFT_H

#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

#define complex _Complex

int fft (int *p, int k, double complex *result);
void print_complex (const char *note, double complex z);
int re_fft (double complex *p, int k, double complex  *result);

#endif /* FFT_H */
