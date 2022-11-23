#ifndef FFT_OUTPUT_H
#define FFT_OUTPUT_H

#define complex _Complex

void print_complex (const char *note, double complex z);
void print_nums_mult_res (int base, int *res, int k);
void print_poly_mult_res (int *res, int k);

#endif /* FFT_OUTPUT_H */
