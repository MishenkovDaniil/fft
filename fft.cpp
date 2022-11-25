#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <math.h>

#include "fft.h"
#include "fft_output.h"

static const double PI = 3.1415926535897932384626433832795;

int fft (int *p, int k, double complex *result)
{
    double complex *result_0 = (double complex *)calloc (k, sizeof (double complex));
    double complex *result_1 = (double complex *)calloc (k, sizeof (double complex));

    if (k == 1)
    {
        result[0] = p[0];
        return 0;
    }

    double complex w = cos (2*PI/k) + sin (2*PI/k)*I;

    int *p_0 = (int *)calloc (k/2, sizeof (int));
    int *p_1 = (int *)calloc (k/2, sizeof (int));

    int j = 0;
    for (int i = 0, j = 0; i < k; i+=2)
    {
        p_0[j] = p[i];
        p_1[j++] = p[i + 1];
    }

    fft (p_0, k/2, result_0);
    fft (p_1, k/2, result_1);

    for (int i = 0; i < k; i++)
    {
        int a = i % (k/2);

        result[i] = result_0[a] + cpow (w, i) * result_1[a];
        //result[i] = round (creal (result[i])) + round(cimag (result[i]))*I;

        //print_complex ("result [ii] = ", result [i]);
    }

    free (result_0);
    free (result_1);
    free (p_0);
    free (p_1);

    return 0;
}

int re_fft (double complex *p, int k, double complex  *result)
{
    double complex  result_0[500] = {};
    double complex  result_1[500] = {};

    if (k == 1)
    {
        result[0] = p[0];
        return 0;
    }
    double complex w = cos (-2*PI/k) + sin (-2*PI/k)*I;

    double complex *p_0 = (double complex *)calloc (k/2, sizeof (double complex));
    double complex *p_1 = (double complex *)calloc (k/2, sizeof (double complex));

    int j = 0;
    for (int i = 0; i < k; i++)
    {
        p_0[j] = p[i];
        p_1[j++] = p[++i];
    }

    re_fft (p_0, k/2, result_0);
    re_fft (p_1, k/2, result_1);

    for (int i = 0; i < k; i++)
    {
        int a = i % (k/2);

        result[i] = result_0[a] + cpow (w, i) * result_1[a];

        result[i] = round (creal (result[i])) + round (cimag (result[i]))*I;

        //print_complex ("result [ii] = ", result [i]);
    }

    free (p_0);
    free (p_1);

    return 0;

}
