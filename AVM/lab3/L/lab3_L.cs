using System;

namespace ConsoleApp
{
    class lab3_L
    {
        const int N = 3, N1 = 4 ,init = 16; // N - число узловых точек, init - кол-во экспериментальных точек
        static void Main()
        {
            double [] x_init = {-3, -2.45, -1.90, -1.35, -0.80, -0.25, 0.30, 0.85, 1.40, 1.95, 2.50, 3.05, 3.60, 4.15, 4.70, 5.25};
            double [] y_init = {-14.92, -13.58, -12.3, -11.04, -9.75, -8.60, -7.47, -6.35, -5.30, -4.37, -3.34, -2.45, -1.60, -0.75, 0.07, 0.79};
            double [] x = {-3, 0.85, 4.70};
            double [] y = {-14.92, -6.35, 0.07};
            double [] x1 = {-3, -0.80, 1.40, 4.70};
            double [] y1 = {-14.92, -9.75, -5.30, 0.07};
            double [] f = new double[init];
            double [][] dValues = new double[init][];
            double [] dif = new double[init-2];
            for(int i = 0; i < init; i++){
                dValues[i] = new double[init-i];
                dValues[i][0] = y_init[i];
            }
            double [][] sep_dif = new double[N1][];
            for(int i = 0; i < N1; i++) {
                sep_dif[i] = new double[N1-i];
                sep_dif[i][0] = y1[i];
            }
            finite_differences(dValues);//конечные разности
            print_finite_differences(x_init, dValues);//вывод таблицы конечных разностей
            dif_finite_differences(dValues, dif); //величина разности между максимальным
            // и минимальным значениями конечных разностей порядков
            optim_dif(dif);//оптимальная степень полинома


            function_L(x_init, x, y, f); //функция метода Лагранжа
            Console.WriteLine("Method L:");
            print(f);//вывод результатов интерполирования Лагранжем
            Console.WriteLine("Error L:");
            error_L(f, y_init);//среднеквадратичная ошибка Лагранжа

            separated_differences(x1, sep_dif);
            Console.Write("{0,-10}{1,-10}", "x", "y");
            for(int i = 1; i < N1; i++){
                Console.Write("q" + "{0,-9}", i);
            }
            Console.WriteLine();
            for(int i = 0; i < N1; i++){
                Console.Write("{0,-10:f2}", x1[i]);
                for(int j = 0; j < N1 - i; j++){
                    Console.Write("{0,-10:f2}", sep_dif[i][j]);
                }
                Console.WriteLine();
            }
            function_N(x_init, x1, f, sep_dif);
            Console.WriteLine("Method N:");
            print(f);//вывод результатов интерполирования Ньютоном
            Console.WriteLine("Error N:");
            error_N(f, y_init);//среднеквадратичная ошибка Ньютона
        }
        static void finite_differences(double[][] d){
            for(int j = 0; j < init; j++){
                for(int i = 0; i < init-1-j; i++){
                    d[i][j+1] = d[i+1][j] - d[i][j];
                }
            }
        }
        static void print_finite_differences(double[] x_init, double[][] d) {
            Console.Write("{0,-10}{1,-10}", "x", "y");
            for(int i = 1; i < init; i++){
                Console.Write("d" + "{0,-9}", i);
            }
            Console.WriteLine();
            for(int i = 0; i < init; i++){
                Console.Write("{0,-10:f2}", x_init[i]);
                for(int j = 0; j < init-i; j++){
                    Console.Write("{0,-10:f2}", d[i][j]);
                }
                Console.WriteLine();
            }
        }
        static void dif_finite_differences (double[][] d, double[] dif) {
            double [] max = new double[init-2];
            double [] min = new double[init-2];
            Console.WriteLine("dm = max(dm) - min(dm) :");
            Console.Write("{0,-10}{0,-10}", "---");
            for(int i = 1; i < init-1; i++){
                max[i-1] = min[i-1] = d[0][i];
                for(int j = 0; j < init-i; j++){
                    if(max[i-1] < d[j][i]) max[i] = d[j][i];
                    else min[i-1] = d[j][i];
                }
                dif[i-1]=max[i-1]-min[i-1];
                Console.Write("{0,-10:f2}", dif[i-1]);
            }
            Console.WriteLine();
        }
        static void optim_dif(double[] dif) {
            double min = dif[0];
            int k = 0;
            for(int i = 0; i < init-2; i++){
                if(dif[i] < min) {
                    min = dif[i];
                    k = i;
                }
            }
            Console.WriteLine("min dm: " + "{0,-10:f2}", min);
            Console.WriteLine("optimum: {0}", k+1);
        }
        static void function_L(double[] x_init, double[] x, double[] y, double[] f) {
            for(int k = 0; k < init; k++) {
                f[k] = 0;
                for(int i = 0; i < N; i++) {
                    double a = 1;
                    for(int j = 0; j < N; j++) {
                        if(j!=i) {
                            a *= (x_init[k]-x[j])/(x[i]-x[j]);
                        }
                    }
                    f[k] += y[i] * a;
                }
            }
        }
        static void separated_differences(double[] x, double[][] sep_dif) {
            for(int j = 0; j < N1; j++){
                for(int i = 0; i < N1-1-j; i++) {
                    sep_dif[i][j+1] = (sep_dif[i+1][j] - sep_dif[i][j])/(x[i+1+j] - x[i]);
                }
            }
        }
        static void function_N(double[] x_init, double[] x, double[] f, double[][] sep_dif) {
            for(int k = 0; k < init; k++) {
                f[k] = sep_dif[0][0];
                for(int i = 0; i < N1-1; i++) {
                    double a = 1;
                    for(int j = 0; j < i+1; j++) {
                        a *= (x_init[k]-x[j]);
                    }
                    f[k] += sep_dif[0][i+1]*a;
                }
            }
        }
        static void print(double[] f) {
            for(int i = 0; i < init; i++){
                Console.WriteLine("{0,-7:f2}", f[i]);
            }
        }
        static void error_L(double[] f, double[] y_init){
            double [] error = new double[init];
            for(int i = 0; i < init; i++) {
                error[i] = Math.Pow(y_init[i]-f[i], 2);
                Console.WriteLine("{0,-7:f4}", error[i]);
            }
            double sum = 0;
            for(int i = 0; i < init; i++) {
                sum += error[i];
            }
            Console.WriteLine("All points:"+"{0,-7:f4}", Math.Sqrt(init+1) * sum);
            sum = 0;
            for(int i = 0; i < init; i++) {
                if(i!=0||i!=7||i!=14){
                    sum += error[i];
                }
            }
            Console.WriteLine("Unused points:"+"{0,-7:f4}", Math.Sqrt(init-2) * sum);
        }
        static void error_N(double[] f, double[] y_init){
            double [] error = new double[init];
            for(int i = 0; i < init; i++) {
                error[i] = Math.Pow(y_init[i]-f[i], 2);
                Console.WriteLine("{0,-7:f4}", error[i]);
            }
            double sum = 0;
            for(int i = 0; i < init; i++) {
                sum += error[i];
            }
            Console.WriteLine("All points:"+"{0,-7:f4}", Math.Sqrt(init+1) * sum);
            sum = 0;
            for(int i = 0; i < init; i++) {
                if(i!=0||i!=4||i!=8||i!=14){
                    sum += error[i];
                }
            }
            Console.WriteLine("Unused points:"+"{0,-7:f4}", Math.Sqrt(init-3) * sum);
        }
    }
}
