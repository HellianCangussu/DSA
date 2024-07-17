#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int front, rear;
  int items[10];
} Queue;

Queue *create() {
  Queue *q = malloc(sizeof(Queue *));
  q->front = q->rear = 0;
  return q;
}

int empty(Queue** queue) {
    return (*queue)->front == (*queue)->rear;
}

int full(Queue** queue, int size) {
    return (*queue)->rear == size;
}

void enqueue(Queue** queue, int value) {
    (*queue)->items[(*queue)->rear++] = value;
}

int dequeue(Queue** queue) {
    return (*queue)->items[(*queue)->front++];
}


int main() { 
    Queue *q = create();
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    int deq = dequeue(&q);
    printf("%d\n", empty(&q));
    return 0;
}