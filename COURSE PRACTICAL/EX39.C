#include <stdio.h>
#include <pthread.h>

void *work(void *arg)
{
    printf("Thread is running\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, work, NULL);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, work, NULL);

    if (pthread_equal(t1, t2))
        printf("Threads are equal\n");
    else
        printf("Threads are not equal\n");

    pthread_join(t2, NULL);

    printf("Threads completed\n");

    return 0;
}
