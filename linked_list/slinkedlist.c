#include "slinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int length(node **head) {
  int i = 0;
  node *cursor = *head;
  while (cursor != NULL) {
    i++;
    cursor = cursor->next;
  }
  return i;
}

void prepend(node **head, int value) {
  node *new_node = (node *)malloc(sizeof(node *));
  node *new = (node *)malloc(sizeof(node *));
  if (!new_node) {
    printf("memory error");
    return;
  }

  new_node->value = value;
  new_node->next = (*head);
  (*head) = new_node;
}

void append(node **head, int value) {
  node *new_node = malloc(sizeof(node *));
  new_node->value = value;
  node *cursor = *head;
  if (!new_node) {
    printf("memory error");
    return;
  }
  while (cursor->next != NULL) {
    cursor = cursor->next;
  }
  cursor->next = new_node;
}

void insert_at(node **head, int index, int value) {
  node *new_node = malloc(sizeof(node *));
  node *cursor = *head;
  int size = length(head);
  if (!new_node) {
    printf("memory error");
    return;
  }
  if (index == 0) {
    prepend(head, value);
  } else if (index == size - 1) {
    append(head, value);
  } else if (index > 0 && index < size - 1) {
    for (int i = 0; i < index - 1; i++) {
      cursor = cursor->next;
    }
    new_node->value = value;
    new_node->next = cursor->next;
    cursor->next = new_node;
  }
}

void remove_at(node **head, int index) {
  node *cursor = *head;
  int size = length(head);
  if (index == 0) {
    (*head) = (*head)->next;
  } else if (index == size - 1) {
    for (int i = 0; i < (index - 1); i++) {
      cursor = cursor->next;
    }
    cursor->next = cursor->next->next;
  } else if (index > 0 && index < size - 1) {
    for (int i = 0; i < index - 1; i++) {
      cursor = cursor->next;
    }
    cursor->next = cursor->next->next;
  }
}

void print(node **head) {
  node *cursor = *head;
  while (cursor != NULL) {
    printf("(%d)", cursor->value);
    cursor = cursor->next;
  }
  printf("\n");
}

void reverse(node **head) {
  node *prev, *cursor, *next;
  cursor = *head;
  prev = NULL;
  while (cursor != NULL) {
    next = cursor->next;
    cursor->next = prev;
    prev = cursor;
    cursor = next;
  }
  (*head) = prev;
}

int findCycle(node *head) {
  node *slow, *fast;
  while (fast && fast->next) {
    slow = slow->next;
    fast = slow->next->next;
    if (slow == fast) {
      printf("Cycle detected \n");
    }
    return 1;
  }
  printf("No cycle detected");
  return 0;
}

int main() {
  node *head = NULL;
  prepend(&head, 0);
  prepend(&head, 1);
  append(&head, 2);
  append(&head, 3);
  insert_at(&head, 1, -1);
  // reverse(&head);
  // print(&head);
  head->next->next->next->next = head->next->next;
  printf("\n%d\n", findCycle(head));
}
