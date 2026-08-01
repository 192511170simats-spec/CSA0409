#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20], pr[20];
    int wt[20], tat[20];
    int highest, minPriority;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time and Priority:\n");
    for(i = 0; i < n; i++)
    {
        printf("\nP%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        printf("P%d Priority: ", i + 1);
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    while(completed != n)
    {
        highest = -1;
        minPriority = 9999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(pr[i] < minPriority)
                {
                    minPriority = pr[i];
                    highest = i;
                }
            }
        }

        if(highest == -1)
        {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0)
        {
            completed++;

            tat[highest] = time - at[highest];
            wt[highest] = tat[highest] - bt[highest];

            if(wt[highest] < 0)
                wt[highest] = 0;
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
