#include <stdio.h>
#include <stdlib.h>

void push(int x, int *, int stack[]);
void pop(int *, int *);
int main() {
    int stack[10]={0,1,2,3,4,5,6,7,8,9};
    int tos = 0;
    push(5, &tos, stack);
    pop(&tos, stack);
    return 0;
}

void push(int x, int *tos, int stack[]) {
    if(*tos >= 10) {
        printf("full");
    } else {
        stack[*tos] = x;
        *tos+=1;
    }
}

void pop(int *tos, int *stack) {
    if(*tos == 0) {
        printf("0");
    } else {
        *tos-=1;
        printf("%d\n", stack[*tos]);
    }
}