#include "SLList.h"
#include <stdlib.h>
#include <stdio.h>

int _size = 0;
Node *_HEAD = NULL;

Node *create()
{
    _HEAD = malloc(sizeof(Node));
    _HEAD->next = NULL;
    // printf("created list at: %p\n", _HEAD);
    return _HEAD;
}

Node *_seek(int pos)
{
    if (_HEAD == NULL)
    {
        fprintf(stderr, "list does not exist\n");
    }
    if (getSize() < pos)
    {
        fprintf(stderr, "illegal pos %d for size %d\n", pos, getSize());
        return NULL;
    }

    Node *ptr = _HEAD;
    int i = 0;
    while (i < pos && ptr->next != NULL)
    {
        // printf("at pos %i\taddr: %p\n", i, ptr);
        ptr = ptr->next;
        i++;
    }
    return ptr;
}

Node *ins(int item)
{
    // printf("insert at begin\n");
    // Node *newNode = malloc(sizeof(Node));
    // newNode->data = item;
    // newNode->next = _HEAD->next;
    // _HEAD->next = newNode;
    // printf("inserted %d at:\t %p\n", _HEAD->next->data, _HEAD->next);
    // _size += 1;
    // return newNode;
    return insAt(0, item);
}

Node *insAt(int pos, int item)
{
    Node *ptr = _seek(pos);
    Node *newNode = malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    if (ptr->next != NULL)
    {
        newNode->next = ptr->next;
    }
    ptr->next = newNode;
    _size += 1;

    // printf("inserted %d at:\t %p\n", ptr->next->data, ptr->next);

    return newNode;
}

int del()
{
    return delAt(0);
}

int delAt(int pos)
{
    Node *ptr = _seek(pos);

    Node *oldNode = ptr->next;
    // printf("addr to del: %p\n", oldNode);
    // printf("next addr: %p\n", oldNode->next);
    // printf("prev addr: %p\n", ptr);
    ptr->next = oldNode->next;
    oldNode->next = NULL;
    int oldData = oldNode->data;
    _size -= 1;
    free(oldNode);

    return oldData;
}

int getHead()
{
    if (_HEAD == NULL)
    {
        fprintf(stderr, "list does not exist\n");
    }
    return _HEAD->next->data;
}

int getTail()
{
    return get(getSize() - 1);
}

int get(int pos)
{
    Node *ptr = _seek(pos);
    return ptr->next->data;
}
void printList()
{
    printf("\n");
    Node *ptr = _HEAD->next;
    printf("print list at:\t %p\n", ptr);
    if (getSize() >= 1)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    for (int i = 0; i < getSize() - 1; i++)
    {
        printf("--> %d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int getSize()
{
    return _size;
}

bool isEmpty()
{
    return getSize() <= 0;
}

// int main(int argc, char const *argv[])
// {
//     Node *list = create();
//     printf("list should be empty, isEmpty?: %s\n", isEmpty() ? "true" : "false");
//     ins(10);
//     ins(15);
//     ins(25);
//     insAt(0, 78);
//     insAt(1, 7);
//     printList();
//     delAt(2);
//     insAt(2, 78);
//     printf("list should NOT be empty, isEmpty?: %s\n", isEmpty() ? "true" : "false");
//     printList();
//     return 0;
// }
