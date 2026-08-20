#include <stdio.h>

int main()
{
    int p[20], f[10], time[10];
    int n, nf, i, j, k, pos, fault = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter number of frames: ");
    scanf("%d", &nf);

    for(i = 0; i < nf; i++)
        f[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < nf; j++)
            if(f[j] == p[i])
            {
                found = 1;
                time[j] = i;
            }

        if(!found)
        {
            pos = 0;

            for(j = 0; j < nf; j++)
                if(f[j] == -1)
                {
                    pos = j;
                    break;
                }

            if(j == nf)
            {
                pos = 0;
                for(k = 1; k < nf; k++)
                    if(time[k] < time[pos])
                        pos = k;
            }

            f[pos] = p[i];
            time[pos] = i;
            fault++;
        }

        printf("\nPage %d: ", p[i]);
        for(j = 0; j < nf; j++)
            printf("%d ", f[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", fault);

    return 0;
}
