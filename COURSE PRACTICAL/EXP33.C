#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, size, i, j, temp, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    // Sort requests
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    printf("\nHead movement: %d", head);

    // Move right
    for(i = 0; i < n; i++)
    {
        if(a[i] >= head)
        {
            total += abs(head - a[i]);
            head = a[i];
            printf(" -> %d", head);
        }
    }

    // Move to end
    total += abs(head - (size - 1));
    head = size - 1;
    printf(" -> %d", head);

    // Jump to beginning
    total += head;
    head = 0;
    printf(" -> %d", head);

    // Service remaining requests
    for(i = 0; i < n; i++)
    {
        if(a[i] < head)
            continue;

        if(a[i] < size - 1)
        {
            total += abs(head - a[i]);
            head = a[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal head movement = %d\n", total);

    return 0;
}
