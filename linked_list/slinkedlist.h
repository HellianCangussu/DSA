typedef struct node {
  int value;
  struct node *next;
} node;


int length(node **head);
void prepend(node **head, int value);
void append(node **head, int value);
void insert_at(node **head, int index, int value);
void remove_at(node **head, int index);
void print(node **head);
void reverse(node **head);
int findCycle(node *head);