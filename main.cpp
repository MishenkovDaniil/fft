#include <stdio.h>
#include <complex.h>
#include <cmath>

#include "fft.h"
#include "fft_mult.h"
#include "fft_output.h"

int main ()
{
    int num_1[16] = {3, 4, 5, 7, 8, 9, 9, 5};
    int num_2[16] = {9, 8, 7, 7, 7, 6, 9, 9};
    int num_res[16] = {};

    mult_nums (10, num_1, num_2, 16, num_res);
    print_nums_mult_res (10, num_res, 16);

    int p_1[16] = {3, 4, 5, 7, 8, 9, 9, 5};
    int p_2[16] = {9, 8, 7, 7, 7, 6, 9, 9};
    int p_res[16] = {};
    mult_polynomials (p_1, p_2, 16, p_res);
    print_poly_mult_res (p_res, 16);

    return 0;
}
