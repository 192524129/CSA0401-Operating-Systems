#include <stdio.h>

void firstFit(int blocks[], int m, int processes[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blocks[j] >= processes[i])
            {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    printf("\nFirst Fit:\n");

    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n",
                   i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

void bestFit(int blocks[], int m, int processes[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int best = -1;

        for (int j = 0; j < m; j++)
        {
            if (blocks[j] >= processes[i])
            {
                if (best == -1 || blocks[j] < blocks[best])
                    best = j;
            }
        }

        if (best != -1)
        {
            allocation[i] = best;
            blocks[best] -= processes[i];
        }
    }

    printf("\nBest Fit:\n");

    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n",
                   i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

void worstFit(int blocks[], int m, int processes[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int worst = -1;

        for (int j = 0; j < m; j++)
        {
            if (blocks[j] >= processes[i])
            {
                if (worst == -1 || blocks[j] > blocks[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            allocation[i] = worst;
            blocks[worst] -= processes[i];
        }
    }

    printf("\nWorst Fit:\n");

    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n",
                   i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

int main()
{
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};

    int m = 5;
    int n = 4;

    int b1[] = {100, 500, 200, 300, 600};
    int b2[] = {100, 500, 200, 300, 600};
    int b3[] = {100, 500, 200, 300, 600};

    firstFit(b1, m, processes, n);
    bestFit(b2, m, processes, n);
    worstFit(b3, m, processes, n);

    return 0;
}