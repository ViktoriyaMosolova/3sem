#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 7
#define M 6

void input_data(double x[N][M], double Q[N]);
void transp(double x[N][M], double xT[M][N]);
void multi(double x[N][M], double xT[M][N], double mul[M][M]);
void invert(double mul[M][M], double E[M][M]);
void coefficient_a(double E[M][M], double xT[M][N], double a[M], double Q[N]);
void approxi(double a[M]);

int main() { 
    double x[N][M], xT[M][N], Q[N];
    double a[M]; 
    double E[M][M];
    double mul[M][M] = {0};
    input_data(x, Q);
    transp(x, xT);
    multi(x, xT, mul);
    invert(mul, E);
    coefficient_a(E, xT, a, Q);
    approxi(a);
    return 0;
}

void input_data(double x[N][M], double Q[N]) {
    double B, Zh, U;
    FILE*f=fopen("data_set.txt", "r");
    if(f==0) printf("error");
    for(int i = 0; i < N; i++) {
        fscanf(f, "%lf%lf%lf%lf", &B, &Zh, &U, &Q[i]);
        x[i][0]= 1;
        x[i][1]= B;
        x[i][2]= Zh;
        x[i][3]= U;
        x[i][4]= B*B;
        x[i][5]= Zh*Zh;
    }
    printf("x[][]:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            printf("%-10.3lf", x[i][j]);
        }
        printf("\n");
    }
    fclose(f);
}

void transp(double x[N][M], double xT[M][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            xT[j][i]=x[i][j];
        }
    }
    printf("xT[][]:\n");
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            printf("%-10.3lf", xT[i][j]);
        }
        printf("\n");
    }
}

void multi(double x[N][M], double xT[M][N], double mul[M][M]){
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            mul[i][j] = 0;
            for(int k = 0; k < N;k++){
                mul[i][j]+=xT[i][k]*x[k][j];
            }
        }
    }
    printf("mul[][]:\n");
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            printf("%-13.3lf", mul[i][j]);
        }
        printf("\n");
    }
}

void invert(double mul[M][M], double E[M][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++){
            if (i == j) E[i][j] = 1;
            else E[i][j] = 0;
        }
    }
    double temp;
    for (int k = 0; k < M; k++) {
        temp = mul[k][k];
        for (int j = 0; j < M; j++) {
            mul[k][j] /= temp;
            E[k][j] /= temp;
        }
        for (int i = k + 1; i < M; i++) {
            temp = mul[i][k];
            for (int j = 0; j < M; j++) {
                mul[i][j] -= mul[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    for (int k = M - 1; k > 0; k--){
        for (int i = k - 1; i >= 0; i--)
        {
            temp = mul[i][k];
            for (int j = 0; j < M; j++)
            {
                mul[i][j] -= mul[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    printf("invert:\n");
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            printf("%-15.7lf", E[i][j]);
        }
        printf("\n");
    }
}

void coefficient_a(double E[M][M], double xT[M][N], double a[M], double Q[N]) {
    double c[M][N];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            c[i][j] = 0;
            for(int k = 0; k < M;k++){
                c[i][j]+=E[i][k]*xT[k][j];
            }
        }
    }
    for (int i = 0; i < M; i++) {
        a[i] = 0;
        for (int j = 0; j < N; j++) {
            a[i]+= c[i][j]*Q[j];
        }
    }
    printf("a[]:\n");
    for(int i=0; i<M; i++) {
        printf("%-13.3lf\n", a[i]);
    }
    printf("\n");
}

void approxi(double a[M]) {
    double B, Zh, U;
    FILE*f=fopen("input.txt", "r");
    if(f==0) printf("error");
    //printf("data:\n");
    int i = 0;
    while(!feof(f)) {
        i++;
        fscanf(f, "%lf%lf%lf", &B, &Zh, &U);
        double Q = a[0]+a[1]*B+a[2]*Zh+a[3]*U+a[4]*B*B+a[5]*Zh*Zh;
        printf("Q[%d]=%-10.4lf\n", i, Q);
    }
    fclose(f);
}



