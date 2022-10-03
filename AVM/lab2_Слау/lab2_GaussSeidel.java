import java.io.*;
import java.util.Scanner;

public class lab2_GaussSeidel {
    public static int N = 6;
    public static void main(String[] args) throws Exception {
        double[][] A = new double[N][N];
        double[] new_X = new double[N];
        double[] old_X = new double[N];
        scan(A, old_X, new_X);
        gauss_zen_method(A, old_X, new_X);
        print(A);
        printt(old_X);
        printt(new_X);
    }
    static void scan(double [][] A, double [] old_X, double [] new_X) throws Exception {
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
    static void print(double [][] matrix) {
        for(int i = 0; i < matrix.length; i++){
            for (int j = 0; j < matrix.length; j++) {
                System.out.printf("%6.2f", matrix[i][j]);
                if(j < matrix.length - 1) System.out.printf(" ");
            }
            System.out.println();
            if (i == matrix.length - 1) System.out.println();
        }
    }
    static void printt(double [] matrix){
            for (int j = 0; j < matrix.length; j++) {
                System.out.printf("%6.2f", matrix[j]);
                System.out.println();
                if (j == matrix.length - 1) System.out.println();
            }
    }
    static void gauss_zen_method(double [][] A, double [] old_X, double [] new_X) {
        int flag = 1;
        do{
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(j != i){
                        new_X[i] -= A[i][j] * old_X[j];
                    }
                }
                printt(new_X);
                new_X[i] /= A[i][i];
            }
            for(int i = 1; i < N-1; i++){
                if(Math.abs(new_X[i]-new_X[i+1]) < Math.abs(new_X[i-1]-new_X[i])){
                    flag = 0;
                }
            }
            for(int k = 0; k < N; k++){
                old_X[k] = new_X[k];
            } 
        } while(flag == 1);        
    } 
}

