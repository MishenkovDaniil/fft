#include <stdio.h>
#include <complex.h>

#include "fft_output.h"

void print_complex (const char *note, double complex z)
{
    printf ("%s %lf + %lf*i\n", note, creal (z), cimag (z));
}

void print_nums_mult_res (int base, int *res, int k)
{
    long long int result = 0;

    for (int i = 0; i < k; i++)
    {
        result = base*result + res[i];
    }

    printf ("Result is %lld.\n", result);
}

void print_poly_mult_res (int *res, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (i)
        {
            printf (" + %dx^%d", res[i], i);
        }
        else
        {
            printf ("%d", res[i]);
        }
    }
}
