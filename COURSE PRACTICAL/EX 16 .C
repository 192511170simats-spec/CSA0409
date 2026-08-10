#include <stdio.h>

int main()
{
    int i;

    printf("Dining Philosophers Problem\n");

    for (i = 1; i <= 5; i++)
    {
        printf("Philosopher %d is thinking\n", i);
        printf("Philosopher %d is eating\n", i);
        printf("Philosopher %d finished eating\n\n", i);
    }

    return 0;
}
