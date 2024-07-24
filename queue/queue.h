typedef struct queue {
  int front, rear;
  int* items;
  int size;
} Queue;

Queue *create(int size);
int empty(Queue **queue);
void enqueue(Queue **queue, int value);
int dequeue(Queue **queue);
