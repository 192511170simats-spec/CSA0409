#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20], n, head, i, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Seek Sequence: %d ", head);

    for(i = 0; i < n; i++)
    {
        total += abs(head - a[i]);
        head = a[i];
        printf("-> %d ", head);
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
