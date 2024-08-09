#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdlib.h>

int *array = NULL;
int N = 0;
int max_size = 1;

void push(int item);
int pop();
int size();
bool isEmpty();
void resize_array(int new_size);

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
    if (N == 0)
    {
        resize_array(max_size);
    }
    else if (N == max_size)
    {
        resize_array(2 * max_size);
        max_size *= 2;
    }
    array[N++] = item;
}

int pop()
{
    if (isEmpty())
    {
        return INT_MIN;
    }
    int item = array[--N];
    printf("%d \n", item);
    if (size() > 0 && size() == max_size / 4)
    {
        resize_array(max_size / 2);
    }
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

void resize_array(int new_size)
{
    int *new_arr = (int *)malloc(sizeof(int));
    for (int i = 0; i < N; i++)
        new_arr[i] = array[i];

    int *temp = array;
    array = new_arr;
    free(temp);
}