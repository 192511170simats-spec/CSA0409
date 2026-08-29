#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char word[50], line[200];

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    printf("\nMatching lines:\n");

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, word) != NULL)
            printf("%s", line);
    }

    fclose(fp);

    return 0;
}
