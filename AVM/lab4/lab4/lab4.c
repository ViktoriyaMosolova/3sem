#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5

void method_euler(double, double, double a[], double, double);
void method_modified_euler(double, double, double a[], double, double);   
void reading_data(double*, double*, double*, double*, double a[]);
double f(double, double, double a[]);
double f1(double, double, double a[]);
int main() {
    double a[N], x_init, y_init, dx, x_point;
    reading_data(&x_init, &y_init, &dx, &x_point, a);
    method_euler(x_init, y_init, a, dx, x_point);
    method_modified_euler(x_init, y_init, a, dx, x_point);
    return 0;
}
void reading_data(double *x, double *y, double *dx, double *x_p, double a[]) {
    FILE* f = fopen("data.txt", "r");
    for(int i = 0; i < N; i++) {
        fscanf(f, "%lf", &a[i]);
    }
    fscanf(f,"%lf%lf%lf%lf", x, y, dx, x_p);
    fclose(f);
}
void method_euler(double x_init, double y_init, double a[], double dx, double x_point) {
    printf("y_e: \n");
    while (x_init >= x_point) {
        y_init += dx * f(x_init, y_init, a);
        printf("f(%.2lf)=%-10.2lf\n", x_init,y_init);
        x_init -= dx;
    }
}
void method_modified_euler(double x_init, double y_init, double a[], double dx, double x_point) {
    printf("y_em: \n");
    while (x_init >= x_point) {
        printf("f(%.2lf)=%-10.2lf\n", x_init,y_init);
        x_init -= dx;
        y_init += dx * f((x_init + dx / 2), (y_init + (dx / 2) * f(x_init, y_init, a)), a);
    }
}
double f(double x, double y, double a[]) {
    return a[0] + a[1] * x + a[2] * x * x + a[3] * y + a[4] * x * y;
    //return (exp(x) * (1 + (1 / x))) - (y / x) - 1;
}
double f1(double x, double y, double a[]) {
    return a[1] + a[2] * 2 * x + a[3] * f(x,y,a) + a[4] * (x * f(x,y,a) + y);
    //return (exp(x) * (pow(x, 2) + x - 1) + f(x,y)) / pow(x, 2);
}