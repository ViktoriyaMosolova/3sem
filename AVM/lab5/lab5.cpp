#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#define N 4
#define z 0.382

using namespace std;
double f(double);
double the_golden_ratio_min_list3(double, double, double);
double the_golden_ratio_min_list4(double, double, double, int i);
void list2_value_func();
int count[N]={0};

int main() {
    double min[N];
    double e[] = {0.1, 0.01, 0.001, 0.0001};
    list2_value_func();
    ofstream file ("list3pp.txt", ios_base::out); 
    file << "2) local min e=0.001\n" << endl;
    file.close();
    min[0] = the_golden_ratio_min_list3(-8, -6, 0.001);
    min[1] = the_golden_ratio_min_list3(-3, -1, 0.001);
    min[2] = the_golden_ratio_min_list3(3, 5, 0.001);
    min[3] = the_golden_ratio_min_list3(9, 10, 0.001); 
    ofstream file1 ("list3pp.txt", ios_base::app); 
    for(int i=0; i<N;i++) 
        file1 << "min=" << left << setw(20) << min[i] << endl;
    file1 << "global_min=" << left << setw(20) << min[0] << endl;
    file1.close();

    ofstream file2 ("list4pp.txt", ios_base::out); 
    file2 << "3) global min\n";
    file2.close();
    for(int i = 0; i < N; i++) {
        min[i]=the_golden_ratio_min_list4(-8, -6, e[i], i);
    }
    ofstream file3 ("list4pp.txt", ios_base::app); 
    for(int i = 0; i < N; i++) {
        file3 << "e=" << left << setw(10) << e[i] <<"count=" << left << setw(5) << count[i]
        << "global_min=" << left << setw(10) << min[i] <<endl;
    }
    file3.close();
 return 0;
}
double the_golden_ratio_min_list3(double a, double b, double e) {
    ofstream file ("list3pp.txt", ios_base::app); 
    double x1=a+z*(b-a);
    double x2=b+z*(a-b);
    file << "x=[" << a << ";" << b << "]"<< endl;
    file << "a=" << left << setw(10) << a << " b=" << left << setw(10) << b
    << "x1=" << left << setw(10) << x1 << "x2=" << left << setw(10) << x2
    << "f(x1)=" << left << setw(15) << f(x1) << "f(x2)=" << 
    left << setw(15) << f(x2) << "end_condition="<< left << setw(15) << (b-a)/2 << endl;
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
        file << "a=" << left << setw(10) << a << " b=" << left << setw(10) << b
        << "x1=" << left << setw(10) << x1 << "x2=" << left << setw(10) << x2
        << "f(x1)=" << left << setw(15) << f(x1) << "f(x2)=" << 
        left << setw(15) << f(x2) << "end_condition="<< left << setw(15) << (b-a)/2 << endl;
    }
    double min_c;
    if(f(x1) < f(x2)) min_c=x1;
    else if(f(x1) > f(x2)) min_c=x2;
    file << "\n";
    file.close();
    return min_c;
}

double the_golden_ratio_min_list4(double a, double b, double e, int i) {
    ofstream file ("list4pp.txt", ios_base::app); 
    double x1=a+z*(b-a);
    double x2=b+z*(a-b);
    count[i]+=1;
    file << "count=" << left << setw(3) << count[i] << "a=" << left << setw(10) << a << " b=" << left << setw(10) << b
    << "x1=" << left << setw(10) << x1 << "x2=" << left << setw(10) << x2
    << "f(x1)=" << left << setw(15) << f(x1) << "f(x2)=" << 
    left << setw(15) << f(x2) << "end_condition="<< left << setw(15) << (b-a)/2 << endl;
    while((b-a)/2 > e) {
        count[i]+=1;
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
        file << "count=" << left << setw(3) << count[i] << "a=" << left << setw(10) << a << " b=" << left << setw(10) << b
        << "x1=" << left << setw(10) << x1 << "x2=" << left << setw(10) << x2
        << "f(x1)=" << left << setw(15) << f(x1) << "f(x2)=" << 
        left << setw(15) << f(x2) << "end_condition="<< left << setw(15) << (b-a)/2 << endl;
    }
    double min_c;
    if(f(x1) < f(x2)) min_c=x1;
    else if(f(x1) > f(x2))  min_c=x2;
    file << "\n";
    file.close();
    return min_c;
}

double f(double x) {
    return 2.67+0.78*x+2.77*sin(1.12*x);
}

void list2_value_func(){
    ofstream file ("value_func.txt");
    for(double x = -11; x<=12; x+=0.5) {
        file << left << setw(10) << x << left << setw(4) << f(x) <<endl;
    }
    file.close();
}