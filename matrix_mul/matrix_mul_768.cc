#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 768
int main(int argc, char* argv[]) {
    srand(42);
    int A[N][N];
    int B[N][N];
    int C[N][N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (i+j)%(N+1);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = (i-j)%(N+1);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    printf("%d\n", C[rand()%N][rand()%N]);
    return 0;
}