#include <stdio.h>

int main()
{
    int record[20], n, i, pos;

    printf("Enter number of records: ");
    scanf("%d", &n);

    printf("Enter records:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &record[i]);

    printf("Enter record number to access: ");
    scanf("%d", &pos);

    if(pos >= 1 && pos <= n)
    {
        printf("Reading records: ");
        for(i = 0; i < pos; i++)
            printf("%d ", record[i]);

        printf("\nRequired Record = %d\n", record[pos - 1]);
    }
    else
        printf("Invalid record number\n");

    return 0;
}
