#include <stdio.h>
#include <stdlib.h>


typedef struct queue {
  int front, rear;
  int* items;
  int size;
} Queue;

Queue *create(int size) {
  Queue *q = malloc(sizeof(Queue *));
  q->items = malloc(size * sizeof(int));
  q->front = q->rear = 0;
  q->size = size;
  return q;
}

int empty(Queue **queue) { return (*queue)->front == (*queue)->rear; }

void enqueue(Queue **queue, int value) {
  if ((*queue)->front == (*queue)->size) {
    printf("queue is full");
    return;
  }
  (*queue)->items[(*queue)->rear++] = value;
}

int dequeue(Queue **queue) {
  if ((*queue)->front == -1) {
    printf("queue is empty");
    return -1;
  }
  return (*queue)->items[(*queue)->front++];
}

int main() {
  Queue *q = create(4);
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);

  for (int i = 0; i < q->size; i++) {
    printf("%d \n", dequeue(&q));
  }

  return 0;
}