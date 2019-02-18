#include "kernel.h"
#include <stdio.h>
#define TPB 32

__device__
float distance(float x1, float x2) {
    return sqrt((x2 - x1) * (x2 - x1));
}

__global__
void distanceKernel(float *d_out, float *d_in, float ref) {
    const int i = blockIdx.x*blocckDim.x + threadIdx.x;
    const float x = d_in[i];
    d_out[i] = distance(x, ref);
    printf(" i = %2d: dist from %f to %f is %f. \n", i, ref, x, d_out[i]);
}

void distanceArray(float *out, float *in, float ref)