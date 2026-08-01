#include <unistd.h>
#include <string.h>

int main()
{
    char msg[] = "Welcome to Operating System Lab!\n";

    write(1, msg, strlen(msg));

    return 0;
}
