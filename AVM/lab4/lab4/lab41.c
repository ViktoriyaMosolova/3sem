#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5

void reading_data(double a[], double*, double*, double*, double*);
void write_data(double a[], double x_init, double y_init, 
                  double step, double x_point);
void method_euler();
void method_modified_euler();
void method_runge_kutta();

int main() {
    double a[N]; //коэф
    double x_init, y_init; //начальная точка
    double step; //шаг
    double x_point; //найти решение диф. уравнения в точке x_point
    
    //считывание и вывод начальных данных
    reading_data(a, &x_init, &y_init, &step, &x_point);
    write_data(a, x_init, y_init, step, x_point);

    //метод эйлера
    method_euler();

    //модиф метод эйлера
    method_modified_euler();

    //метод РК с step/10
    method_runge_kutta();

    return 0;
}

void reading_data(double a[], double* x_init, double* y_init, 
                  double* step, double* x_point) {
    FILE* f = fopen("data.txt", "r"); 
    for(int i = 0; i < N; i++) {
        fscanf(f, "%lf", &a[i]);
    }
    fscanf(f,"%lf%lf%lf%lf", x_init, y_init, step, x_point);
    fclose(f);
}

void write_data(double a[], double x_init, double y_init, 
                  double step, double x_point) {
    for(int i = 0; i < N; i++) {
        printf("a%d=%.3lf ", i, a[i]);
    }
    printf("\nx0=%.3lf y0=%.3lf\ndx=%.3lf\nx=%.3lf", x_init, y_init, step, x_point);
}


void method_euler() {

}

void method_modified_euler() {

}

void method_runge_kutta() {

}