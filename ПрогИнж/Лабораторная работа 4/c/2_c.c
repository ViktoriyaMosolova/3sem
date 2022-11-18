#include <stdio.h>
#include <math.h>

int main() {
    double x;
    printf("x: ");
    scanf("%lf", &x);
    printf("z = %lf", sin(x*x) - cos(x*x));
    return 0;
}