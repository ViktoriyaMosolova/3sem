#include <stdio.h>
#include <math.h>
#define N 5

void reading_data(double a[], double*, double*, double*, double*);
void write_data(double a[], double, double, double, double);
double method_euler(double a[], double, double, double, double);
double method_modified_euler(double a[], double, double, double, double);
double method_runge_kutta_3(double a[], double, double, double, double);
double method_runge_kutta_4(double a[], double, double, double, double);
double func(double a[], double, double);

int main() {
    double a[N]; //коэф
    double x_init, y_init; //начальная точка
    double step; //шаг
    double x_point; //найти решение диф. уравнения в точке x_point

    double sol[4] = {0};
    
    //считывание и вывод начальных данных
    reading_data(a, &x_init, &y_init, &step, &x_point);
    write_data(a, x_init, y_init, step, x_point);

    //определение знака шага
    if(x_init < x_point) step = fabs(step);
    else if(x_init > x_point) step = -1 * fabs(step);

    sol[0] = method_euler(a, x_init, y_init, step, x_point);//метод эйлера
    sol[1] = method_modified_euler(a, x_init, y_init, step, x_point); //модиф метод эйлера
    sol[2] = method_runge_kutta_3(a, x_init, y_init, step, x_point);//метод РК с step
    sol[3] = method_runge_kutta_4(a, x_init, y_init, step/10, x_point);//метод РК с step/10

    printf("\nerror(E/ME/RK):\n");
    for(int i = 0; i < 3; i++) {
        printf("%.9lf\n", fabs(sol[3] - sol[i]));
    }
    double error[5] = {0};
    error[0] = sol[0];
    printf("\nstep/2=%.6lf\n", step/2);
    error[1] = method_euler(a, x_init, y_init, step/2, x_point);
    printf("\nstep/4=%.6lf\n", step/4);
    error[2] = method_euler(a, x_init, y_init, step/4, x_point);
    printf("\nstep/6=%.6lf\n", step/6);
    error[3] = method_euler(a, x_init, y_init, step/6, x_point);
    printf("\nstep/8=%.6lf\n", step/8);
    error[4] = method_euler(a, x_init, y_init, step/8, x_point);
    
    printf("\nerror(E(dx)/E(dx/2)/E(dx/4)/E(dx/6)/E(dx/8)):\n");
    for(int i = 0; i < 5; i++) {
        printf("%.9lf\n", fabs(sol[3] - error[i]));
    }
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
    printf("method_euler:\n1. x=%.6lf y=%.6lf\n", x, y);
    double s;
    int i = 1;
    double k = fabs((x_point - x)/step);
    while (i <= k) {
        double k1 = step * func(a, x, y);//fabs
        x += step;
        y += k1;
        s = y;
        i++;
        printf("%d. x=%.6lf y=%.6lf\n", i, x, y);
    }
    return s;
}
double method_modified_euler(double a[], double x, double y, double step, double x_point) {
    double s;
    printf("\nmethod_modified_euler:\n1. x=%.6lf y=%.6lf\n", x, y);
    int i = 1;
    while ((x < x_point && step > 0)||(x > x_point && step < 0)) {
        double k1 = (step/2) * func(a, x, y);
        double k2 = step * func(a, x+(step/2), y+k1);
        x += step;
        y += k2;
        s = y;
        i++;
        printf("%d. x=%.6lf y=%.6lf\n",i, x, y);
    }
    return s;
}
double method_runge_kutta_3(double a[], double x, double y, double step, double x_point) {
    double s;
    int i = 1;
    printf("\nmethod_runge_kutta_3:\n1. x=%.6lf y=%.6lf\n", x, y);
    while ((x < x_point && step > 0)||(x > x_point && step < 0)) {
        double k1 = step * func(a, x, y);
        double k2 = step * func(a, x+(step/2), y+(k1/2));
        double k3 = step * func(a, x+(step/2), y+(k2/2));
        double k4 = step * func(a, x+step, y+k3);
        x += step;
        y += (k1+2*k2+2*k3+k4)/6;
        s = y;
        i++;
        printf("%d. x=%.6lf y=%.6lf\n",i, x, y);
    }
    return s;
}
double method_runge_kutta_4(double a[], double x, double y, double step, double x_point) {
    double s;
    int i = 1;
    printf("\nmethod_runge_kutta_4:\n1. x=%.6lf y=%.6lf\n", x, y);
    while ((x + step < x_point && step > 0)||(x + step > x_point && step < 0)) {
        double k1 = step * func(a, x, y);
        double k2 = step * func(a, x+(step/2), y+(k1/2));
        double k3 = step * func(a, x+(step/2), y+(k2/2));
        double k4 = step * func(a, x+step, y+k3);
        x += step;
        y += (k1+2*k2+2*k3+k4)/6;
        s = y;
        i++;
        printf("%d. x=%.6lf y=%.6lf\n", i, x, y);
    }
    return s;
} 

double func(double a[], double x, double y) {
    return (a[0] + a[1]*x + a[2]*x*x + a[3]*y + a[4]*x*y);
}
