using System;
using System.Text;

namespace ConsoleApp
{
    class lab3_N
    {
        const int N = 3;
        const int count = 16;
        static void Main()
        {
            double [] xPoint = {-3, 0.85, 4.70};
            double [] x = {-3, -2.45, -1.90, -1.35, -0.80, -0.25, 0.30, 0.85, 1.40, 1.95, 2.50, 3.05, 3.60, 4.15, 4.70, 5.25};
            double [] yPoint = {-14.92, -6.35, 0.07};
            double [] y = {-14.92, -13.58, -12.3, -11.04, -9.75, -8.60, -7.47, -6.35, -5.30, -4.37, -3.34, -2.45, -1.60, -0.75, 0.07, 0.79};
            double [] f = new double[count];

            double[][] dValues = new double[N][];
            for(int i = 0; i < N; i++){
                dValues[i] = new double[N-i];
                dValues[i][0] = yPoint[i];
            }
            dif(xPoint, yPoint, dValues);
            function_N(f, x, xPoint, dValues);
            print(f);
            //print_dif(dValues);
        }

        static void function_N(double[] f, double[] x, double[] xP, double[][] d) {
            for(int k = 0; k < count; k++) {
                f[k] = d[0][0];
                for(int i = 0; i < N-1; i++) {
                    double a = 1;
                    for(int j = 0; j < N-1; j++) {
                        a *= (x[k]-xP[j]);
                    }
                    f[k] += d[0][i+1]*a;
                }
            }
        }
        static void dif(double[] x, double[] y, double[][] dValues) {
            double [] max = new double[N-1];
            double [] min = new double[N-1];
            double [] d = new double[N-1];
            for(int j = 0; j < N; j++){
                for(int i = 0; i < N-1-j; i++) {
                    dValues[i][j+1] = (dValues[i+1][j] - dValues[i][j])/(x[i+1] - x[i]);
                }
            }
        }
        static void print_dif (double[][] dValues) {
            for(int i = 0; i < N; i++){
                for(int j = 1; j < N-i; j++) {
                    Console.Write("{0,-10:f2}", dValues[i][j]);
                }
                Console.WriteLine();
            }
        }
        static void print(double[] f) {
            for(int i = 0; i < count; i++){
                Console.WriteLine("{0,-7:f2}", f[i]);
            }
        }
    }
}