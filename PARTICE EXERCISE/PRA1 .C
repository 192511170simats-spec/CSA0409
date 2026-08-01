#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        // Child Process
        printf("Child Process\n");
        printf("Child PID : %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else if (pid > 0)
    {
        // Parent Process
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID : %d\n", pid);
    }
    else
    {
        printf("Fork Failed!\n");
    }

    return 0;
}
