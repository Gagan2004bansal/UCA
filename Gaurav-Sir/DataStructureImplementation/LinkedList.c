#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
    int item;
    struct Node *next;
};

typedef struct Node Node;

Node *head = NULL;
int N = 0;

void push(int item);
int pop();
int size();
bool isEmpty();

int main()
{
    push(3);
    push(10);
    push(19);

    assert(isEmpty() == false);
    assert(size() == 3);
    assert(pop() == 19);
    assert(size() == 2);
    assert(pop() == 10);
    assert(size() == 1);
    assert(pop() == 3);
    assert(size() == 0);
    assert(isEmpty());
    return 0;
}

void push(int item)
{
    Node *oldHead = head;
    head = (Node *)malloc(sizeof(Node));
    head->item = item;
    head->next = oldHead;
    N++;
}

int pop()
{
    if (N == 0)
    {
        return INT_MIN;
    }
    int item = head->item;
    printf("%d \n", item);
    Node *temp = head;
    head = head->next;
    N--;
    free(temp);
    return item;
}

int size()
{
    return N;
}

bool isEmpty()
{
    return N == 0;
}
