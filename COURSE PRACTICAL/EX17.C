#include <stdio.h>

int main()
{
    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 417, 112, 426};
    int i, j, choice, allocated;

    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    for (i = 0; i < 4; i++)
    {
        allocated = -1;

        if (choice == 1)
        {
            for (j = 0; j < 5; j++)
            {
                if (block[j] >= process[i])
                {
                    allocated = j;
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            int best = -1;

            for (j = 0; j < 5; j++)
            {
                if (block[j] >= process[i])
                {
                    if (best == -1 || block[j] < block[best])
                        best = j;
                }
            }
            allocated = best;
        }
        else if (choice == 3)
        {
            int worst = -1;

            for (j = 0; j < 5; j++)
            {
                if (block[j] >= process[i])
                {
                    if (worst == -1 || block[j] > block[worst])
                        worst = j;
                }
            }
            allocated = worst;
        }

        if (allocated != -1)
        {
            printf("Process %d (%d KB) -> Block %d\n",
                   i + 1, process[i], allocated + 1);
            block[allocated] -= process[i];
        }
        else
        {
            printf("Process %d (%d KB) -> Not Allocated\n",
                   i + 1, process[i]);
        }
    }

    return 0;
}
