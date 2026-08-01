#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i;
    int bt[20], rt[20], pr[20];
    int wt[20], tat[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Priority of P%d: ", i + 1);
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    int complete = 0, time = 0;

    while(complete < n)
    {
        int highest = -1;
        int best = INT_MAX;

        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0 && pr[i] < best)
            {
                best = pr[i];
                highest = i;
            }
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0)
        {
            complete++;
            tat[highest] = time;
            wt[highest] = tat[highest] - bt[highest];
        }
    }

    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t%d\t%d\n", i + 1, pr[i], bt[i], wt[i], tat[i]);

    return 0;
}