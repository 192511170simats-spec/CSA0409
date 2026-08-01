#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;

    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if(fd < 0)
    {
        printf("Cannot create file.\n");
        return 1;
    }

    // Redirect stdout to the file
    dup2(fd, STDOUT_FILENO);

    printf("This message is written into output.txt\n");

    close(fd);

    return 0;
}
