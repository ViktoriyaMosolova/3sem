import java.io.*;
import java.util.Scanner;

public class lab2_GaussZeidel {
    public static int N = 6;
    public static void main(String[] args) throws Exception {
        double[][] A = new double[N][N];
        double[] old_X = new double[N];
        double[] new_X = new double[N];
        scan(A, old_X, new_X);
        diagonal(A);
        //диагональное преобладание
        //привести к итерационному виду:
        //получить матрицу c
        //получить лямбду для каждой строки
        //получить матрицу d
    }
    public static void scan(double [][] A, double [] old_X, double [] new_X) throws Exception {
        Scanner scanner = new Scanner(new File("data.txt"));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N+1; j++) {
                if(j == N) {
                    new_X[i] = scanner.nextDouble();
                }
                else {
                    A[i][j] = scanner.nextDouble();
                }
            }
        }
        for(int i = 0; i < N; i++){
            old_X[i]= scanner.nextDouble();
        }
    }
    public static int diagonal(double [][] A) {
        double sum = 0;
        int j = 0;
        int k = 1;
        for(int i = 0; i < N; i++){
            sum = 0;
            for(j = 0; j < N; j++) {
                sum += Math.abs(A[i][j]);
            }
            sum -= Math.abs(A[i][i]);
            if(sum > A[i][i]) {
                k = 0;
                System.out.println(A[i][i] + "<" + sum);
            } else {
                System.out.println(A[i][i] + ">" + sum);
            }
        }
        return k;
    }


}
