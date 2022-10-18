#include <stdio.h>
#include <stdlib.h>

int stack[10];
void push(int x, int *);
void pop(int *);
int main() {
    int stack[10];
    int tos = 0;
    push(1, &tos);
    push(2, &tos);
    push(3, &tos);
    pop(&tos);
    pop(&tos);
    return 0;
}

void push(int x, int *tos) {
    if(*tos >= 10) {
        printf("full");
    } else {
        stack[*tos] = x;
        *tos+=1;
    }
}

void pop(int *tos) {
    if(*tos == 0) {
        printf("0");
    } else {
        *tos-=1;
        printf("%d\n", stack[*tos]);
    }
}