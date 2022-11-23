#include <stdio.h>
#include <complex.h>
#include <cmath>

#include "fft.h"
#include "fft_mult.h"
#include "fft_output.h"

int main ()
{
    int p_1[8] = {0xF, 3};
    int p_2[8] = {1, 0xC};
    int p_res[8] = {};

    mult_polynomials (p_1, p_2, 4, p_res);
    //mult_nums (10, p_1, p_2, 8, p_res);
    print_poly_mult_res (p_res, 4);
    //print_nums_mult_res (10, p_res, 8);

    return 0;
}
