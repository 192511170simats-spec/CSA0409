#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    int fd;
    struct stat s;
    DIR *d;
    struct dirent *file;

    fd = open("test.txt", O_CREAT | O_RDWR, 0644);

    if (fd < 0)
    {
        printf("File cannot be opened\n");
        return 0;
    }

    printf("File opened successfully\n");

    lseek(fd, 0, SEEK_END);
    printf("File pointer moved to end\n");

    stat("test.txt", &s);
    printf("File size: %ld bytes\n", s.st_size);

    close(fd);

    d = opendir(".");
    if (d == NULL)
    {
        printf("Directory cannot be opened\n");
        return 0;
    }

    printf("\nFiles in current directory:\n");

    while ((file = readdir(d)) != NULL)
        printf("%s\n", file->d_name);

    closedir(d);

    return 0;
}
