#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main()
{
    key_t key;
    int shmid;
    char *str;

    // Generate unique key
    key = ftok("shmfile", 65);

    // Create shared memory
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach shared memory
    str = (char *)shmat(shmid, (void *)0, 0);

    printf("Write Data: ");
    fgets(str, 1024, stdin);

    printf("Data written in shared memory: %s", str);

    printf("\nReading from shared memory: %s", str);

    // Detach shared memory
    shmdt(str);

    // Destroy shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
