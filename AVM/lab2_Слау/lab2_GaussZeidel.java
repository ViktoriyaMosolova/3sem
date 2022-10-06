import java.io.*;
import java.util.Scanner;

public class lab2_GaussZeidel {
    public static int N = 2;
    public static double v = 1;
    public static double g = 0.70;
    public static void main(String[] args) throws Exception {
        double[][] a = new double[N][N];
        double[] b = new double[N];
        double[][] c = new double[N][N];
        double[] d = new double[N];
        double[] old_x = new double[N];
        double[] new_x = new double[N];
        double[] error = new double[N];
        scan(a, b, old_x);
        /*if (diagonal(A) == 1) {
            System.out.println("+");
        } else {
            System.out.println("-");
        }*/
        matrix_c_d(a,b,c,d);
        method(c,d,old_x,new_x,error);
        printt(new_x);
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
    static void printt(double [] matrix) {
        for(int i = 0; i < matrix.length; i++){
            System.out.printf("%6.2f", matrix[i]);
            System.out.println();
        }
        System.out.println();
    }
    static void scan(double [][] a, double [] b, double [] old_x) throws Exception {
        Scanner scanner = new Scanner(new File("test.txt"));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N+1; j++) {
                if(j == N) {
                    b[i] = scanner.nextDouble();
                }
                else {
                    a[i][j] = scanner.nextDouble();
                }
            }
        }
        for(int i = 0; i < N; i++){
            old_x[i] = scanner.nextDouble();
        }
    }
    static int diagonal(double [][] a) {
        double sum = 0;
        int k = 1;
        for(int i = 0; i < N; i++){
            sum = 0;
            for(int j = 0; j < N; j++) {
                if(i != j) sum += Math.abs(a[i][j]);
            }
            if(sum > a[i][i]) {
                k = 0;
                System.out.println(a[i][i] + "<" + sum);
                //System.out.println("no");
            } else {
                //System.out.println(a[i][i] + ">" + sum);
                System.out.println("yes");
            }
        }
        return k;
    }
    static void matrix_c_d(double [][] a, double [] b, double [][] c, double [] d) {
        for(int i = 0; i < N; i++) {
            double l = la(a[i][i]);
            for(int j = 0; j < N; j++) {
                if(i == j) {
                    c[i][j] = 1 + a[i][j] * l;
                    d[i]= -l * b[i];
                }
                else {
                    c[i][j] = a[i][j] * l;
                }
            }
        }
    }
    static double la(double a){
        return -(Math.signum(a) * v)/(g + Math.abs(a));
    }
    static void method(double [][] c, double [] d, double [] old_x, double [] new_x, double [] error) {
        double max = 1;
        do{
            for(int i = 0; i < N; i++){
                new_x[i] = 0;
                for(int j = 0; j < N; j++){
                    new_x[i]+=c[i][j]*old_x[j];
                }
                new_x[i] += d[i];
                error[i] = Math.abs(old_x[i]-new_x[i]);
                old_x[i] = new_x[i];
            }
            max = error[0];
            for (int i = 0; i < N; i++) {
                max = Math.max(max, error[i]);
            }
        } while (max >= 0.1);
    }
}
