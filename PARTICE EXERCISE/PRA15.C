#include <stdio.h>
#include <unistd.h>

int main()
{
    char path[1024];

    if(getcwd(path, sizeof(path)) != NULL)
    {
        printf("Current Working Directory:\n%s\n", path);
    }
    else
    {
        printf("Error getting current directory.\n");
    }

    return 0;
}
