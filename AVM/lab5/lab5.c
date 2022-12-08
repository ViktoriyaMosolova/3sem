#include <stdio.h>
#include <stdlib.h>
#define N 4
#define z 0.382

void reading_data(double a[], double*, double*);
double f(double a[], double);
void the_golden_ratio(double a[], double, double, double);
void condition(double, double, double);

int main() {
    double a[N];
    double x_left, x_right;
    double e;
    reading_data(a, &x_left, &x_right);
    the_golden_ratio(a, x_left, x_right, e);
    return 0;
}

void reading_data(double a[], double* x_left, double* x_right) {
    FILE* f = fopen("var.txt", "r"); 
    for(int i = 0; i < N; i++) {
        fscanf(f, "%lf", &a[i]);
        printf("%4.4lf\n", a[i]);
    }
    fscanf(f,"%lf%lf", x_left, x_right);
    printf("%4.4lf\n%4.4lf", *x_left, *x_right);
    fclose(f);
}

void the_golden_ratio_max(double a[], double x_left, double x_right, double e) {
    double x1=x_left+z*(x_right-x_left);
    double x2=x_left+(1-z)*(x_right-x_left);
    double func;
    if(f(a, x1) >= f(a, x2)) func = f(a, x1);
    condition(x_left, x_right, e);
}

void condition(double a, double b, double e) {
    int flag = 0;
    if (b-a/2<=e) flag = 1;
    return flag;
}

double f(double a[], double x) {
    return a[0]+a[1]*x+a[2]*sin(a[3]*x);
}