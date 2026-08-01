#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i;

    for(i = 0; i < 3; i++)
    {
        pid_t pid = fork();

        if(pid == 0)
        {
            printf("Child %d\n", i + 1);
            printf("PID  = %d\n", getpid());
            printf("PPID = %d\n\n", getppid());
            return 0;
        }
    }

    for(i = 0; i < 3; i++)
        wait(NULL);

    printf("Parent Process Completed.\n");

    return 0;
}
