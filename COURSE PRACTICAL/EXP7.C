#include <stdio.h>

int main()
{
    int n, i, j;
    int at[20], bt[20], wt[20], tat[20], ct[20];
    int completed[20] = {0};
    int time = 0, count = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++)
    {
        printf("\nP%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    while(count < n)
    {
        int shortest = -1;
        int minBT = 9999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0)
            {
                if(bt[i] < minBT)
                {
                    minBT = bt[i];
                    shortest = i;
                }
            }
        }

        if(shortest == -1)
        {
            time++;
            continue;
        }

        time += bt[shortest];
        ct[shortest] = time;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];

        completed[shortest] = 1;
        count++;
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
