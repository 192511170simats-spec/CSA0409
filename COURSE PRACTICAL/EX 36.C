#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *file;

    dir = opendir(".");

    if (dir == NULL)
    {
        printf("Cannot open directory\n");
        return 0;
    }

    printf("Files and directories:\n");

    while ((file = readdir(dir)) != NULL)
    {
        printf("%s\n", file->d_name);
    }

    closedir(dir);

    return 0;
}
