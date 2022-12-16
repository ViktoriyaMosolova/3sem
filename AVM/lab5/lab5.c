/*
done 0) 3. На Листе 1 привести исходные данные для расчета, указанные в вы-данном варианте задания.
done 1) 4. На Листе 2 построить график оптимизируемой функции и перечислить координаты ее глобальных и 
локальных минимумов и максимумов (с точно-стью до 0,5) в указанном интервале локализации.
done 2) 5. На Листе 3 в табличной форме представить решения задачи оптимиза-ции функции одной переменной 
для всех экстремумов указанного в варианте задания типа с точностью 0,001.
done 3) 6. На Листе 4 в табличной форме представить решения задачи оптимиза-ции функции одной переменной 
для глобального экстремума указанного в ва-рианте задания типа со значениями 
точности 0,1, 0,01, 0,001, 0,0001.
done 4) 7. На Листе 5 построить график зависимости количества шагов расчета координаты глобального оптимума 
от выбранной точности. Для независимой переменной использовать логарифмическую шкалу. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4
#define z 0.382

double f(double);
double the_golden_ratio_min_list3(double, double, double);
double the_golden_ratio_min_list4(double, double, double, int*);
void list2_value_func();

int main() {
    double min[N];
    double e[] = {0.1, 0.01, 0.001, 0.0001};
    //list2_value_func();

    FILE*file=fopen("list3.txt", "w");
    fprintf(file,"2) local min e=0.001\n\n");
    fclose(file);
    FILE*file1=fopen("list3.txt", "a");
    min[0] = the_golden_ratio_min_list3(-8, -6, 0.001);
    min[1] = the_golden_ratio_min_list3(-3, -1, 0.001);
    min[2] = the_golden_ratio_min_list3(3, 5, 0.001);
    min[3] = the_golden_ratio_min_list3(9, 10, 0.001); 
    for(int i=0; i<N;i++) fprintf(file1,"min=%-15.8lf\n", min[i]);
    fprintf(file1,"global_min=%.8lf\n",min[0]);
    fclose(file1);

    FILE*file4=fopen("list4.txt", "w");
    fprintf(file4, "3) global min\n");
    fclose(file4);
    FILE*file5=fopen("list4.txt", "a");
    for(int i = 0; i < N; i++) {
        int count=0;
        min[i]=the_golden_ratio_min_list4(-8, -6, e[i], &count);
        fprintf(file5,"e=%-10.4lfcount=%-5dglobal_min=%.8lf\n", e[i],count,min[i]);
    }
    fclose(file5);
    return 0;
}



double the_golden_ratio_min_list3(double a, double b, double e) {
    FILE*file=fopen("list3.txt", "a");
    double x1=a+z*(b-a);
    double x2=b+z*(a-b);
    fprintf(file, "x=[%.0lf;%.0lf]\n", a,b);
    fprintf(file,"a=%-15.8lf b=%-15.8lf x1=%-19.8lf x2=%-19.8lf ",a,b,x1,x2);
    fprintf(file,"f(x1)=%-15.8lf f(x2)=%-15.8lf end_condition=%-15.8lf\n",f(x1),f(x2),(b-a)/2);
    while((b-a)/2 > e) {
        if(f(x1) < f(x2)) {
            b = x2;
            x2 = x1;
            x1 = a+z*(b-a);
        } else if (f(x1) > f(x2)) {
            a = x1;
            x1 = x2;
            x2 = b+z*(a-b);
        } else if (f(x1) == f(x2)){
            a = x1;
            b = x2;
            x1 = a+z*(b-a);
            x2 = b+z*(a-b);
        }
        fprintf(file,"a=%-15.8lf b=%-15.8lf x1=%-19.8lf x2=%-19.8lf ",a,b,x1,x2);
        fprintf(file,"f(x1)=%-15.8lf f(x2)=%-15.8lf end_condition=%-15.8lf\n",f(x1),f(x2),(b-a)/2);
    }
    double min_c;
    if(f(x1) < f(x2)) min_c=x1;
    else if(f(x1) > f(x2)) min_c=x2;
    fprintf(file,"\n");
    fclose(file);
    return min_c;
}
double the_golden_ratio_min_list4(double a, double b, double e, int* count) {
    FILE*file=fopen("list4.txt", "a");
    double x1=a+z*(b-a);
    double x2=b+z*(a-b);
    *count+=1;
    fprintf(file,"%-3d a=%-15.8lf b=%-15.8lf x1=%-19.8lf x2=%-19.8lf ",*count,a,b,x1,x2);
    fprintf(file,"f(x1)=%-15.8lf f(x2)=%-15.8lf end_condition=%-15.8lf\n",f(x1),f(x2),(b-a)/2);
    while((b-a)/2 > e) {
        *count+=1;
        if(f(x1) < f(x2)) {
            b = x2;
            x2 = x1;
            x1 = a+z*(b-a);
        } else if (f(x1) > f(x2)) {
            a = x1;
            x1 = x2;
            x2 = b+z*(a-b);
        } else if (f(x1) == f(x2)){
            a = x1;
            b = x2;
            x1 = a+z*(b-a);
            x2 = b+z*(a-b);
        }
        fprintf(file,"%-3d a=%-15.8lf b=%-15.8lf x1=%-19.8lf x2=%-19.8lf ",*count, a,b,x1,x2);
        fprintf(file,"f(x1)=%-15.8lf f(x2)=%-15.8lf end_condition=%-15.8lf\n",f(x1),f(x2),(b-a)/2);
    }
    double min_c;
    if(f(x1) < f(x2)) min_c=x1;
    else if(f(x1) > f(x2))  min_c=x2;
    fprintf(file,"\n");
    fclose(file);
    return min_c;
}
double f(double x) {
    return 2.67+0.78*x+2.77*sin(1.12*x);
}

void list2_value_func(){
    FILE* file=fopen("value_func.txt", "w");
    for(double x = -11; x<=12; x+=0.5) {
        fprintf(file,"%4.2lf %4.8lf\n", x, f(x));
    }
    fclose(file);
}