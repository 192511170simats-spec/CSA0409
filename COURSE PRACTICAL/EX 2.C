#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int source, destination, bytesRead;
    char buffer[1024];

    // Open source file in read mode
    source = open("source.txt", O_RDONLY);
    if (source < 0)
    {
        printf("Error opening source file.\n");
        return 1;
    }

    // Create/Open destination file
    destination = open("destination.txt",
                       O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination < 0)
    {
        printf("Error creating destination file.\n");
        close(source);
        return 1;
    }

    // Copy file contents
    while ((bytesRead = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, bytesRead);
    }

    // Close files
    close(source);
    close(destination);

    printf("File copied successfully.\n");

    return 0;
}
