#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("student.txt", O_CREAT | O_WRONLY, 0644);

    if(fd < 0)
    {
        printf("File creation failed.\n");
    }
    else
    {
        printf("File 'student.txt' created successfully.\n");
        close(fd);
    }

    return 0;
}
