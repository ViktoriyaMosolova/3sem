#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
} t_list;

t_list *create_element(int data) {
    t_list *element = (t_list*)malloc(sizeof(t_list));
    element -> data = data;
    element -> next = NULL;
    return element;
}

void add_element(t_list **l, int data) {
    t_list *add_element = create_element(data);
    add_element -> next = *l;
    *l = add_element;
}

int main() {
    t_list *l = create_element(1);
    add_element(&l, 2);
    while(l != NULL) {
        printf("data = %d\n", l -> data);
        l = l -> next;
    }
    return 0;
}