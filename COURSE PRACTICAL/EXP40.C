#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat s;

    if (stat("test.txt", &s) == -1)
    {
        printf("File not found\n");
        return 0;
    }

    printf("File Permissions: ");

    printf((s.st_mode & S_IRUSR) ? "r" : "-");
    printf((s.st_mode & S_IWUSR) ? "w" : "-");
    printf((s.st_mode & S_IXUSR) ? "x" : "-");

    printf((s.st_mode & S_IRGRP) ? "r" : "-");
    printf((s.st_mode & S_IWGRP) ? "w" : "-");
    printf((s.st_mode & S_IXGRP) ? "x" : "-");

    printf((s.st_mode & S_IROTH) ? "r" : "-");
    printf((s.st_mode & S_IWOTH) ? "w" : "-");
    printf((s.st_mode & S_IXOTH) ? "x" : "-");

    printf("\n");

    printf("Owner : Read, Write, Execute\n");
    printf("Group : Read, Write, Execute\n");
    printf("Others: Read, Write, Execute\n");

    return 0;
}
