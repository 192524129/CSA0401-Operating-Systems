#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    int block[n];

    printf("Enter block sizes:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &m);

    int process[m];

    printf("Enter process sizes:\n");

    for (int i = 0; i < m; i++)
        scanf("%d", &process[i]);

    printf("\nWorst Fit Allocation:\n");

    for (int i = 0; i < m; i++)
    {
        int worst = -1;

        for (int j = 0; j < n; j++)
        {
            if (block[j] >= process[i])
            {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            printf("Process %d (%d) -> Block %d (%d)\n",
                   i + 1, process[i],
                   worst + 1, block[worst]);

            block[worst] -= process[i];
        }
        else
        {
            printf("Process %d (%d) -> Not Allocated\n",
                   i + 1, process[i]);
        }
    }

    return 0;
}