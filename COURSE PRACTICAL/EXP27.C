#include <stdio.h>

int main()
{
    int p[20], f[10];
    int n, nf, i, j, k, pos, far, next, fault = 0, found;

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
                found = 1;

        if(!found)
        {
            pos = -1;

            for(j = 0; j < nf; j++)
                if(f[j] == -1)
                {
                    pos = j;
                    break;
                }

            if(pos == -1)
            {
                far = -1;

                for(j = 0; j < nf; j++)
                {
                    next = n + 1;

                    for(k = i + 1; k < n; k++)
                        if(f[j] == p[k])
                        {
                            next = k;
                            break;
                        }

                    if(next > far)
                    {
                        far = next;
                        pos = j;
                    }
                }
            }

            f[pos] = p[i];
            fault++;
        }

        printf("\nPage %d: ", p[i]);
        for(j = 0; j < nf; j++)
            printf("%d ", f[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", fault);

    return 0;
}
