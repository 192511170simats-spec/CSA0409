#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function executed by each thread
void *thread_function(void *arg)
{
    int thread_id = *(int *)arg;

    printf("Thread %d is running.\n", thread_id);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[5];
    int thread_id[5];
    int i;

    // Create 5 threads
    for(i = 0; i < 5; i++)
    {
        thread_id[i] = i + 1;

        if(pthread_create(&threads[i], NULL, thread_function, &thread_id[i]) != 0)
        {
            printf("Error creating thread %d\n", i + 1);
            return 1;
        }
    }

    // Wait for all threads to finish
    for(i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished execution.\n");

    return 0;
}
