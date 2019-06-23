#include "SLList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define DETERMINISTIC true

void show_help_message()
{
    printf("%s\n", "Usage: test_sllist NUM_SAMPLES");
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        show_help_message();
        return -1;
    }
    int NUM = atoi(argv[1]);

    if (DETERMINISTIC)
    {
        srand(42);
    }
    else
    {
        srand(time(0));
    }

    // Create SLList
    Node *list = create();

    //Test 1: list should be empty
    assert(isEmpty());

    // Test 2: insertion at HEAD
    int items[NUM];
    for (int i = 0; i < NUM; i++)
    {
        int item = rand();
        items[i] = item;
        ins(item);
        assert(getHead() == item);
    }

    //Test 2: list should not be empty
    assert(!isEmpty());

    //Test 3: check size
    assert(getSize() == NUM);

    //Test 5: insert and get
    for (int i = 0; i < NUM; i++)
    {
        int item = rand();
        int pos = rand() % NUM;
        insAt(pos, item);
        assert(get(pos) == item);
        assert(delAt(pos) == item);
    }

    //Test 4: check deletion
    for (int i = 0; i < NUM; i++)
    {
        int item = del();
        assert(items[NUM - i - 1] == item);
    }

    // Test 6: Insert after delete
    for (int i = 0; i < NUM; i++)
    {
        int item = rand();
        items[i] = item;
        ins(item);
        assert(getHead() == item);
    }

    // printList();

    return 0;
}
