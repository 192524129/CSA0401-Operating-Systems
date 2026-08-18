#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m];
    int maximum[n][m];
    int need[n][m];
    int available[m];
    int finish[n];

    printf("\nEnter Allocation Matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("\nEnter Maximum Matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &maximum[i][j]);

    printf("\nEnter Available Resources:\n");

    for (int j = 0; j < m; j++)
        scanf("%d", &available[j]);

    for (int i = 0; i < n; i++)
    {
        finish[i] = 0;

        for (int j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
    }

    int safeSequence[n];
    int count = 0;

    while (count < n)
    {
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int possible = 1;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if (possible)
                {
                    for (int j = 0; j < m; j++)
                        available[j] += allocation[i][j];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == n)
    {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe sequence: ");

        for (int i = 0; i < n; i++)
            printf("P%d ", safeSequence[i]);

        printf("\n");
    }
    else
    {
        printf("\nSystem is in UNSAFE state.\n");
    }

    return 0;
}