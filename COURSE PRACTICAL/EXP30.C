#include <stdio.h>

int main()
{
    int block[20], n, i, start;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Enter starting block: ");
    scanf("%d", &start);

    if(start >= 1 && start <= n)
    {
        printf("Linked Blocks: ");

        for(i = start - 1; i < n; i++)
            printf("%d ", block[i]);
    }
    else
        printf("Invalid starting block");

    return 0;
}
