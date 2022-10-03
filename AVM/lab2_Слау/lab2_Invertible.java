import java.io.*;
import java.util.Scanner;

public class lab2_Invertible {
    public static int N = 6;
    public static void main(String[] args) throws Exception {
        double[][] A = new double[N][N];
        double[][] B = new double[N][1];
        double[][] E = new double[N][N];
        double[][] X = new double[N][1];
        scan(A, B);
        matrix_E(E); 
        step(A, E);
        multi(B, E, X);
    }
    static void scan(double [][] A, double [][] B) throws Exception {
        Scanner scanner = new Scanner(new File("data.txt"));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N+1; j++) {
                if(j == N) {
                    B[i][0] = scanner.nextDouble();
                }
                else {
                    A[i][j] = scanner.nextDouble();
                }
            }
        }
    }
    static void print(double [][] matrix) {
        for(int i = 0; i < matrix.length; i++){
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.printf("%6.2f", matrix[i][j]);
                if(j < matrix[i].length - 1) System.out.printf(" ");
            }
            System.out.println();
            if (i == matrix.length - 1) System.out.println();
        }
    }
    static void matrix_E(double [][] E) {
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++){
            if (i == j) E[i][j] = 1;
            else E[i][j] = 0;
         }
      }
    }
    static void step(double [][] A, double [][] E) {
      double temp;
      for (int k = 0; k < N; k++) {
          temp = A[k][k];
          for (int j = 0; j < N; j++) {
              A[k][j] /= temp;
              E[k][j] /= temp;
          }
          for (int i = k + 1; i < N; i++) {
              temp = A[i][k];
              for (int j = 0; j < N; j++) {
                  A[i][j] -= A[k][j] * temp;
                  E[i][j] -= E[k][j] * temp;
              }
          }
       }
         for (int k = N - 1; k > 0; k--)
        {
            for (int i = k - 1; i >= 0; i--)
            {
                temp = A[i][k];
 
                for (int j = 0; j < N; j++)
                {
                    A[i][j] -= A[k][j] * temp;
                    E[i][j] -= E[k][j] * temp;
                }
            }
        }
    }
    static void multi(double [][] B, double [][] E, double [][] X) {
        for (int i = 0; i < N; i++) {
            X[i][0] = 0;
        }
         for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
               X[i][0] += E[i][j]*B[j][0];
            }
         }
        print(E);
        print(B);
        print(X);
    }
}
