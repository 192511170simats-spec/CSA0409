#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat file;

    if(stat("student.txt", &file) == 0)
    {
        printf("File Size : %ld bytes\n", file.st_size);
        printf("Permissions : %o\n", file.st_mode & 0777);
        printf("Last Modified : %s", ctime(&file.st_mtime));
    }
    else
    {
        printf("File not found.\n");
    }

    return 0;
}
