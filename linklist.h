#ifndef COMP230_LINKLIST_H
#define COMP230_LINKLIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
extern int errno;


typedef struct Node {
    int data; // value stored in this position
    struct Node* next; // pointer to next node in this list
} Node;

typedef struct List {
    size_t length; // the number of nodes in the list
    Node* head;    // the first node in the list (or NULL if empty)
} List;

int init_Node(Node* node, int data);
Node* new_Node(int data);
int delete_Node(Node* node);

int init_List(List* list);
List* new_List();
int delete_List(List* list);

void List_print(List* list);
int List_append(List* list, int data);
int List_prepend(List* list, int data);
int List_extend(List* listA, List* listB);
bool List_contains(List* list, int value);

int List_get(List* list, size_t index);
int List_set(List* list, size_t index, int value);
int List_insert(List* list, size_t index, int value);
int List_remove(List* list, size_t index);
int List_clear(List* list);

#endif /* COMP230_LINKLIST_H */