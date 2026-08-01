#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, destination;
    char buffer[1024];
    int bytesRead;

    source = open("student.txt", O_RDONLY);

    if(source < 0)
    {
        printf("Cannot open source file.\n");
        return 1;
    }

    destination = open("copy.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if(destination < 0)
    {
        printf("Cannot create destination file.\n");
        close(source);
        return 1;
    }

    while((bytesRead = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, bytesRead);
    }

    printf("File copied successfully.\n");

    close(source);
    close(destination);

    return 0;
}
