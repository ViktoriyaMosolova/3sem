#include <stdio.h>
#include <stdlib.h>
#define N 4

void reading_data(double a[], double*, double*);

int main() {
    double a[N];
    double x_left, x_right;
    reading_data(a, &x_left, &x_right);
    return 0;
}

void reading_data(double a[], double* x_left, double* x_right) {
    FILE* f = fopen("var.txt", "r"); 
    for(int i = 0; i < N; i++) {
        fscanf(f, "%lf", &a[i]);
        printf("%4.4lf\n", a[i]);
    }
    fscanf(f,"%lf%lf", &x_left, &x_right);
    printf("%4.4lf\n%4.4lf", x_left,x_right);
    fclose(f);
}