#include <stdio.h>

int main()
{
    int index[20], n, i, pos;

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &index[i]);

    printf("Index Block: ");
    for(i = 0; i < n; i++)
        printf("%d ", index[i]);

    printf("\nEnter position to access: ");
    scanf("%d", &pos);

    if(pos >= 1 && pos <= n)
        printf("File Block = %d\n", index[pos - 1]);
    else
        printf("Invalid position\n");

    return 0;
}
