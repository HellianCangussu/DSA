typedef struct stack {
  int top;
  int capacity;
  int *array;
} stack;

stack *createStack(int capacity);
int size(stack **stack);
int empty(stack **stack);
int full(stack **stack);
void push(stack **stack, int value);
int pop(stack **stack);
int peek(stack **stack);
void dispose(stack **stack);