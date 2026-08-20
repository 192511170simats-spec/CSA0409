#include <stdio.h>

int main()
{
    int b[20], p[20], n, m, i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &m);

    printf("Enter process sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &p[i]);

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(b[j] >= p[i])
            {
                printf("Process %d -> Block %d\n", i + 1, j + 1);
                b[j] -= p[i];
                break;
            }
        }

        if(j == n)
            printf("Process %d -> Not Allocated\n", i + 1);
    }

    return 0;
}
