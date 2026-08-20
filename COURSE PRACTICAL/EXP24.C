#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char text[] = "Hello UNIX System Calls";
    char buf[50];

    fd = open("file.txt", O_CREAT | O_RDWR, 0644);

    write(fd, text, sizeof(text));
    lseek(fd, 0, SEEK_SET);

    read(fd, buf, sizeof(text));
    printf("File Content: %s\n", buf);

    close(fd);

    return 0;
}
