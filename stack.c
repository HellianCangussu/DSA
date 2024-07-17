#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int top;
  int capacity;
  int *array;
} stack;

stack *createStack(int capacity) {
  stack *new = malloc(sizeof(stack *));
  if (!new)
    return NULL;
  new->capacity = capacity;
  new->top = -1;
  new->array = malloc(new->capacity * sizeof(int));
  if (!new->array)
    return NULL;
  return new;
}

int size(stack **stack) { return (*stack)->top + 1; }

int empty(stack **stack) { return (*stack)->top == -1; }

int full(stack **stack) { return (*stack)->top == ((*stack)->capacity - 1); }

void push(stack **stack, int value) {
  if (full(&(*stack))) {
    printf("stack overflow");
  } else {
    (*stack)->array[++(*stack)->top] = value;
  }
}

int pop(stack **stack) {
  if (empty(&(*stack))) {
    printf("stack empty");
    return INT_MIN;
  } else {
    return (*stack)->array[(*stack)->top--];
  }
}

int peek(stack **stack) {
  if (empty(&(*stack))) {
    printf("stack empty");
    return INT_MIN;
  } else {
    return (*stack)->array[(*stack)->top];
  }
}

void dispose(stack **stack) {
  if ((*stack)) {
    if ((*stack)->array) {
      free((*stack)->array);
      free((*stack));
    }
  }
}

int main() {
  stack *stck = createStack(4);
  push(&stck, 1);
  push(&stck, 2);
  push(&stck, 3);
  printf("%d", peek(&stck));
  push(&stck, 4);
  printf("%d", peek(&stck));
  printf("%d", pop(&stck));
  dispose(&stck);
}