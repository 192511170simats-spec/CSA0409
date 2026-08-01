#include <stdio.h>
#include <unistd.h>

int main()
{
    char name[100];

    printf("Enter your name: ");

    read(0, name, sizeof(name));

    printf("You entered: %s", name);

    return 0;
}
