#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t lock;

void *increment(void *arg)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&lock);

        count++;
        printf("Thread %d: Count = %d\n",
               *(int *)arg, count);

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int n1 = 1, n2 = 2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, &n1);
    pthread_create(&t2, NULL, increment, &n2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("\nFinal Count = %d\n", count);

    return 0;
}
