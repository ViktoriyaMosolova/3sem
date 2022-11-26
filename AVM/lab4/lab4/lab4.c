#include <stdio.h>
#include <math.h>
#define N 5

void reading_data(double a[], double*, double*, double*, double*);
void write_data(double a[], double, double, double, double);
double method_euler(double a[], double, double, double, double);
double method_modified_euler(double a[], double, double, double, double);
double method_runge_kutta_3(double a[], double, double, double, double);
double method_runge_kutta_4(double a[], double, double, double, double);
void error(double err[], double err_E[]);
double func(double a[], double, double);

int main() {
    double a[N]; //коэф
    double x_init, y_init; //начальная точка
    double step; //шаг
    double x_point; //найти решение диф. уравнения в точке x_point

    double err[4] = {0};
    
    //считывание и вывод начальных данных
    reading_data(a, &x_init, &y_init, &step, &x_point);
    write_data(a, x_init, y_init, step, x_point);

    //определение знака шага
    if(x_init < x_point) step = fabs(step);
    else if(x_init > x_point) step = -1 * fabs(step);

    err[0] = method_euler(a, x_init, y_init, step, x_point);//метод эйлера
    err[1] = method_modified_euler(a, x_init, y_init, step, x_point); //модиф метод эйлера
    err[2] = method_runge_kutta_3(a, x_init, y_init, step, x_point);//метод РК с step
    err[3] = method_runge_kutta_4(a, x_init, y_init, step/10, x_point);//метод РК с step/10

    double err_E[5] = {0};
    err_E[0] = err[0];
    err_E[1] = method_euler(a, x_init, y_init, step/2, x_point);
    err_E[2] = method_euler(a, x_init, y_init, step/4, x_point);
    err_E[3] = method_euler(a, x_init, y_init, step/6, x_point);
    err_E[4] = method_euler(a, x_init, y_init, step/8, x_point);
    
    error(err, err_E);
    return 0;
}

void reading_data(double a[], double* x_init, double* y_init, double* step, double* x_point) {
    FILE* f = fopen("data.txt", "r"); 
    for(int i = 0; i < N; i++) {
        fscanf(f, "%lf", &a[i]);
    }
    fscanf(f,"%lf%lf%lf%lf", x_init, y_init, step, x_point);
    fclose(f);
}
void write_data(double a[], double x_init, double y_init, double step, double x_point) {
    for(int i = 0; i < N; i++) {
        printf("a%d=%.3lf ", i, a[i]);
    }
    printf("\nx0=%.3lf y0=%.3lf\ndx=%.3lf\nx=%.3lf\n\n", x_init, y_init, step, x_point);
}

double method_euler(double a[], double x, double y, double step, double x_point) {
    printf("\nstep=%.6lf\n", step);
    printf("method_euler:\n1. x=%.6lf y=%.6lf\n", x, y);
    int i = 1;
    double k = fabs((x_point - x)/step);
    while (i <= k) {
        double k1 = step * func(a, x, y);
        x += step;
        y += k1;
        i++;
        printf("%d. x=%.6lf y=%.6lf\n", i, x, y);
    }
    return y;
}
double method_modified_euler(double a[], double x, double y, double step, double x_point) {
    printf("\nmethod_modified_euler:\n1. x=%.6lf y=%6lf\n", x, y);
    int i = 1;
    double k = fabs((x_point - x)/step);
    while (i <= k) {
        double k1 = (step/2) * func(a, x, y);
        double k2 = step * func(a, x+(step/2), y+k1);
        x += step;
        y += k2;
        i++;
        printf("%d. x=%.6lf y=%.6lf\n",i, x, y);
    }
    return y;
}
double method_runge_kutta_3(double a[], double x, double y, double step, double x_point) {
    int i = 1;
    printf("\nmethod_runge_kutta_3:\n1. x=%.6lf y=%.6lf\n", x, y);
    double k = fabs((x_point - x)/step);
    while (i <= k) {
        double k1 = step * func(a, x, y);
        double k2 = step * func(a, x+(step/2), y+(k1/2));
        double k3 = step * func(a, x+(step/2), y+(k2/2));
        double k4 = step * func(a, x+step, y+k3);
        x += step;
        y += (k1+2*k2+2*k3+k4)/6;
        i++;
        printf("%d. x=%.6lf y=%.6lf\n",i, x, y);
    }
    return y;
}
double method_runge_kutta_4(double a[], double x, double y, double step, double x_point) {
    int i = 1;
    printf("\nmethod_runge_kutta_4:\n1. x=%.6lf y=%.6lf\n", x, y);
    double k = fabs((x_point - x)/step);
    while (i <= k) {
        double k1 = step * func(a, x, y);
        double k2 = step * func(a, x+(step/2), y+(k1/2));
        double k3 = step * func(a, x+(step/2), y+(k2/2));
        double k4 = step * func(a, x+step, y+k3);
        x += step;
        y += (k1+2*k2+2*k3+k4)/6;
        i++;
        printf("%d. x=%.6lf y=%.6lf\n", i, x, y);
    }
    return y;
} 

void error(double err[], double err_E[]) {
    printf("\nerror(E/ME/RK):\n");
    for(int i = 0; i < 3; i++) {
        printf("%.9lf\n", fabs(err[3] - err[i]));
    }
    printf("\nerror(E(dx)/E(dx/2)/E(dx/4)/E(dx/6)/E(dx/8)):\n");
    for(int i = 0; i < 5; i++) {
        printf("%.9lf\n", fabs(err[3] - err_E[i]));
    }
}

double func(double a[], double x, double y) {
    return (a[0] + a[1]*x + a[2]*x*x + a[3]*y + a[4]*x*y);
}
