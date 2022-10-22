#define STACK_MAX_SIZE 20
typedef int T;

typedef struct Stack_tag {
    T data[STACK_MAX_SIZE];
    int size;
} Stack_t;

void push(Stack_t *stack, const T value) {
    stack->data[stack->size] = value;
    stack->size++;
}