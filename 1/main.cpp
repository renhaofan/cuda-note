#include "kernel.h"

#include <stdlib.h>
#include <stdio.h>
#define N 64

float scale(int i, int n) {
    return (float)(i)/(n - 1);
}

extern void distanceKernel(float *d_out, float *d_in, float ref);

int main() {
    const float ref = 0.5;

    float *in = (float*)calloc(N, sizeof(float));
    float *out = (float*)calloc(N, sizeof(float));

    for (int i = 0; i < N; i++) {
        in[i] = scale(i, N);
    }

    distanceArray(out, in, ref, N);

    free(in);
    free(out);
    in = out = NULL;
    return 0;
}
