#include <stdio.h>

int main()
{
    int n, i, time = 0, remain;
    int bt[20], rt[20], wt[20], tat[20];
    int quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++)
    {
        printf("Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    while(remain != 0)
    {
        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0)
            {
                if(rt[i] <= quantum)
                {
                    time += rt[i];
                    rt[i] = 0;
                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];
                    remain--;
                }
                else
                {
                    rt[i] -= quantum;
                    time += quantum;
                }
            }
        }
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    return 0;
}