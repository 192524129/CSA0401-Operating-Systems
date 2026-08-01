#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, time = 0, complete = 0;
    int bt[20], rt[20], wt[20], tat[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while(complete != n)
    {
        int shortest = -1;
        int min = INT_MAX;

        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0 && rt[i] < min)
            {
                min = rt[i];
                shortest = i;
            }
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0)
        {
            complete++;
            tat[shortest] = time;
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    return 0;
}