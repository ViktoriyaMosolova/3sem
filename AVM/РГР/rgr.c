#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 7
#define M 6

void input_data(double x[N][M], double Q[N]);
void transp(double x[N][M], double xT[M][N]);
void multi(double x[N][M], double xT[M][N], double F[M][M]);
void invert(double F[M][M], double E[M][M]);
void coefficient_a(double E[M][M], double xT[M][N], double a[M], double Q[N]);
void approxi(double a[M]);

int main() { 
    double x[N][M], xT[M][N], Q[N];
    double a[M]; 
    double E[M][M];
    double F[M][M] = {0};
    input_data(x, Q);
    transp(x, xT);
    multi(x, xT, F);
    invert(F, E);
    coefficient_a(E, xT, a, Q);
    approxi(a);
    return 0;
}

void input_data(double x[N][M], double Q[N]) {
    double B, Zh, U;
    FILE*f=fopen("data.txt", "r");
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

void multi(double x[N][M], double xT[M][N], double F[M][M]){
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            F[i][j] = 0;
            for(int k = 0; k < N;k++){
                F[i][j]+=xT[i][k]*x[k][j];
            }
        }
    }
    printf("F[][]:\n");
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            printf("%-13.3lf", F[i][j]);
        }
        printf("\n");
    }
}

void invert(double F[M][M], double E[M][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++){
            if (i == j) E[i][j] = 1;
            else E[i][j] = 0;
        }
    }
    double temp;
    for (int k = 0; k < M; k++) {
        temp = F[k][k];
        for (int j = 0; j < M; j++) {
            F[k][j] /= temp;
            E[k][j] /= temp;
        }
        for (int i = k + 1; i < M; i++) {
            temp = F[i][k];
            for (int j = 0; j < M; j++) {
                F[i][j] -= F[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    for (int k = M - 1; k > 0; k--) {
        for (int i = k - 1; i >= 0; i--) {
            temp = F[i][k];
            for (int j = 0; j < M; j++)
            {
                F[i][j] -= F[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    printf("invert F:\n");
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            printf("%-15.7lf", E[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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
    for(int i=0; i<M; i++) {
        printf("a[%d]=%-13.3lf\n", i, a[i]);
    }
    printf("\n");
}

void approxi(double a[M]) {
    double B, Zh, U, Q_real[N];
    double R[N] = {0};
    FILE*f=fopen("data.txt", "r");
    if(f==0) printf("error");
    int k = 0;
    printf("\n7 products:\n");
    while(!feof(f)) {
        fscanf(f, "%lf%lf%lf%lf", &B, &Zh, &U, &Q_real[k]);
        double Q = a[0]+a[1]*B+a[2]*Zh+a[3]*U+a[4]*B*B+a[5]*Zh*Zh;
        printf("Q[%d]=%-10.4lf\n", k, Q);
        R[k] = (Q - Q_real[k]) * (Q - Q_real[k]);
        k++;
    }
    double sum = 0;
    for(int i = 0; i < N; i++) {
        sum+=R[i];
        printf("\nR[%d]=%-4.7lf", i, R[i]);
    }
    printf("\n\nE=%-4.10lf\n", sqrt(sum)/N);
    fclose(f);
    printf("\n3 products:\n");
    double R_i[3], Q_i[3]={0};
    FILE*w=fopen("input.txt", "r");
    if(w==0) printf("error");
    int l = 0;
    while(!feof(f)) {
        fscanf(w, "%lf%lf%lf%lf", &B, &Zh, &U, &Q_i[l]);
        double Q = a[0]+a[1]*B+a[2]*Zh+a[3]*U+a[4]*B*B+a[5]*Zh*Zh;
        printf("Q[%d]=%-10.4lf\n", l, Q);
        R_i[l] = (Q - Q_i[l]) * (Q - Q_i[l]);
        l++;
    }
    sum = 0;
    for(int i = 0; i < 3; i++) {
        sum+=R_i[i];
        printf("\nR[%d]=%-4.7lf", i, R_i[i]);
    }
    printf("\n\nE=%-4.10lf\n\n", sqrt(sum)/3);
    fclose(w);
}





