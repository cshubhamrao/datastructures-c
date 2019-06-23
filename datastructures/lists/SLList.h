#include <stdbool.h>

typedef struct NodeDef
{
    int data;
    struct NodeDef *next;
} Node;

Node *create();

Node *ins(int item);
Node *insAt(int pos, int item);

int del();
int delAt(int pos);

int getHead();
int getTail();
int get(int pos);

bool isEmpty();
int getSize();

void printList();
