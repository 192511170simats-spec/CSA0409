#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char name[100];

    fd = open("student.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if(fd < 0)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);

    write(fd, name, strlen(name));

    printf("Data written successfully.\n");

    close(fd);

    return 0;
}
