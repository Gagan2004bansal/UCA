#include <stdio.h>
int solveRec(int n, int counter)
{
    if (n == 0 && counter == 0)
    {
        return 0;
    }
    if (n == counter)
    {
        return 1;
    }
    if (n == -counter)
    {
        return -1;
    }

    return solveRec(n, counter + 1);
}
int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", solveRec(n, 0));

    return 0;
}

// 24 July 2024