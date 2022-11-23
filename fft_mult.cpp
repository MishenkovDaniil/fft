#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

#include "fft.h"
#include "fft_mult.h"

void mult_polynomials (int *poly_1, int *poly_2, int k, int *poly_res)
{
    double complex *result_1 = (double complex *)calloc (k, sizeof (double complex));
    double complex *result_2 = (double complex *)calloc (k, sizeof (double complex));

    fft (poly_1, k, result_1);
    fft (poly_2, k, result_2);

    double complex *poly_complex_values = (double complex *)calloc (k, sizeof (double complex));
    double complex *poly_complex_res    = (double complex *)calloc (k, sizeof (double complex));

    for (int i = 0; i < k; i++)
    {
        poly_complex_values[i] = result_1[i]*result_2[i];
    }

    re_fft (poly_complex_values, k, poly_complex_res);

    for (int i = 0; i < k; i++)
    {
        poly_complex_res[i] = poly_complex_res [i]/k;
        poly_res[i] = round (creal (poly_complex_res[i]));

        printf ("res[i] = %d\n", poly_res[i]);
    }

    free (poly_complex_values);
    free (poly_complex_res);
}

void mult_nums (int base, int *num_1, int *num_2, int k, int *res)
{
    mult_polynomials (num_1, num_2, k, res);

    int carry = 0;

    for (int i = k - 2; i >= 0; i--)
    {
        res[i] += carry;
        carry = res[i] / base;
        res[i] %= base;

        res[i + 1] = res[i];
    }
    res[0] = carry;
    for (int i = 0; i < k; i++)
    {
        printf ("[i] ==== %d", res[i]);
    }
}
