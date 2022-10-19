using System;
 
namespace ConsoleApp
{
    class lab3
    {
        const int N = 16;
        static void Main()
        {
            double [] xValues = {-3, -2.45, -1.90, -1.35, -0.80, -0.25, 0.30, 0.85, 1.40, 1.95, 2.50, 3.05, 3.60, 4.15, 4.70, 5.25};
            double [] yValues = {-14.92, -13.58, -12.3, -11.04, -9.75, -8.60, -7.47, -6.35, -5.30, -4.37, -3.34, -2.45, -1.60, -0.75, 0.07, 0.79};
            double[][] dValues = new double[N][];
            double [] d = new double[N-1];
            for(int i = 0; i < N; i++){
                dValues[i] = new double[N-i];
                dValues[i][0] = yValues[i];
            }
            using (StreamReader sr = new StreamReader("theoria.txt", System.Text.Encoding.Default))
            {
               
               int len = sr.ReadToEnd().Length;
               string[] arrTheoria = new string[len];
               for (int i = 0; i < len; i++)
                {
                    arrTheoria[i] = sr.ReadLine();
                    Console.WriteLine(arrTheoria[i]);
                }
                Console.ReadLine();
            }
           dif(dValues);
           //print_dif(dValues);
           dm(dValues, d);
           optim_d(dValues, d);
        }
        static void print_dif (double[][] dValues)
        {
            for(int i = 0; i < N; i++){
                for(int j = 1; j < N-i; j++){
                    Console.Write("{0,-10:f2}", dValues[i][j]);
                }
                Console.WriteLine();
            }
        }
        static void dif (double[][] dValues)
        {
            for(int j = 0; j < N; j++){
                for(int i = 0; i < N-1-j; i++){
                    dValues[i][j+1] = dValues[i+1][j] - dValues[i][j];
                }
            }
        }
        static void dm (double[][] dValues, double[] d)
        {
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
        static void optim_d(double[][] dValues, double[] d){
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
                
        }

        static double InterpolateLagrangePolynomial (double x, double[] xValues, double[] yValues)
        {
            double lagrangePol = 0;
            for (int i = 0; i < N; i++) {
                    double basicsPol = 1;
                    for (int j = 0; j < N; j++) {
                        if (j != i) {
                            basicsPol *= (x - xValues[j])/(xValues[i] - xValues[j]);   
                        }
                    }
                    Console.WriteLine(basicsPol);
                    lagrangePol += basicsPol * yValues[i];
            }
            return lagrangePol;
        }
    }
}