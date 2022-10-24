using System;
using System.Text;

namespace ConsoleApp
{
    class lab3_L
    {
        const int N = 3;
        const int count = 16;
        static void Main()
        {
            double [] xPoint = {-3, 0.85, 4.70};
            double [] yPoint = {-14.92, -6.35, 0.07};
            double [] f = new double[count];
            /*double[][] dValues = new double[N][];
            double [] d = new double[N-1];
            for(int i = 0; i < N; i++){
                dValues[i] = new double[N-i];
                dValues[i][0] = yValues[i];
            }
            dif(dValues);
            print_dif(dValues);
            dm(dValues, d);
            optim_d(dValues, d);*/
            function_L(xPoint, yPoint, f);
            print(f);
        }

        static void function_L(double[] xP, double[] yP, double[] f) {
            double [] x = {-3, -2.45, -1.90, -1.35, -0.80, -0.25, 0.30, 0.85, 1.40, 1.95, 2.50, 3.05, 3.60, 4.15, 4.70, 5.25};
            for(int k = 0; k < count; k++) {
                f[k] = 0;
                for(int i = 0; i < N; i++) {
                    double a = 1;
                    for(int j = 0; j < N; j++) {
                        if(j!=i) {
                            a *= (x[k]-xP[j])/(xP[i]-xP[j]);
                        }
                    }
                    f[k] += yP[i] * a;
                }
            }
        }
        static void print(double[] f) {
            for(int i = 0; i < count; i++){
                Console.WriteLine("{0,-7:f2}", f[i]);
            }
        }

        /*static void print_dif (double[][] dValues) {
            for(int i = 0; i < N; i++){
                for(int j = 1; j < N-i; j++){
                    Console.Write("{0,-10:f2}", dValues[i][j]);
                }
                Console.WriteLine();
            }
        }
        static void dif (double[][] dValues) {
            for(int j = 0; j < N; j++){
                for(int i = 0; i < N-1-j; i++){
                    dValues[i][j+1] = dValues[i+1][j] - dValues[i][j];
                }
            }
        }
        static void dm (double[][] dValues, double[] d) {
            double [] max = new double[N-1];
            double [] min = new double[N-1];
            
            for(int i = 1; i < N; i++){
                max[i-1] = min[i-1] = dValues[0][i];
                for(int j = 0; j < N-i; j++){
                    if(max[i-1] < dValues[j][i]) max[i] = dValues[j][i];
                    else min[i-1] = dValues[j][i];
                }
                d[i-1]=max[i-1]-min[i-1];
                //Console.Write("{0,-10:f2}", d[i-1]);
            }
            //Console.WriteLine();
        }
        static void optim_d(double[][] dValues, double[] d) {
            double min = d[0];
            int k = 0;
            for(int i = 0; i < N-2; i++){
                if(d[i] < min) {
                    min = d[i];
                    k = i;
                }
            }
            Console.WriteLine("{0,-10:f2}", min);
            Console.WriteLine("optimum: {0}", k+1);
        }
        static void del(double[] xValues, double[] yValues){
                
        }*/
    }
}
