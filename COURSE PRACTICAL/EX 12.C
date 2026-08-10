#include <stdio.h>

int main()
{
    int n, r;
    int allocation[10][10], max[10][10], need[10][10];
    int available[10], work[10], finish[10];
    int safe[10];
    int i, j, k, count = 0, found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (j = 0; j < r; j++)
        scanf("%d", &available[j]);

    /* Calculate Need Matrix */
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    for (j = 0; j < r; j++)
        work[j] = available[j];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    while (count < n)
    {
        found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == r)
                {
                    for (k = 0; k < r; k++)
                        work[k] += allocation[i][k];

                    safe[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    if (count == n)
    {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");

        for (i = 0; i < n; i++)
            printf("P%d ", safe[i]);
    }
    else
    {
        printf("\nSystem is NOT in safe state.\n");
    }

    return 0;
}
