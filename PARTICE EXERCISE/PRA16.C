#include <stdio.h>
#include <time.h>

int main()
{
    time_t currentTime;

    time(&currentTime);

    printf("Current System Time:\n");
    printf("%s", ctime(&currentTime));

    return 0;
}
