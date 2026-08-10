#include <stdio.h>
#include <string.h>

int main()
{
    char files[10][20];
    char name[20];
    int count = 0, choice, i, found;

    while (1)
    {
        printf("\n1. Create File");
        printf("\n2. Search File");
        printf("\n3. Delete File");
        printf("\n4. Display Files");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter file name: ");
            scanf("%s", name);

            strcpy(files[count], name);
            count++;

            printf("File created successfully.\n");
        }
        else if (choice == 2)
        {
            printf("Enter file name: ");
            scanf("%s", name);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (strcmp(files[i], name) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("File found.\n");
            else
                printf("File not found.\n");
        }
        else if (choice == 3)
        {
            printf("Enter file name: ");
            scanf("%s", name);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (strcmp(files[i], name) == 0)
                {
                    for (; i < count - 1; i++)
                        strcpy(files[i], files[i + 1]);

                    count--;
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("File deleted.\n");
            else
                printf("File not found.\n");
        }
        else if (choice == 4)
        {
            printf("Files in directory:\n");

            for (i = 0; i < count; i++)
                printf("%s\n", files[i]);
        }
        else
        {
            break;
        }
    }

    return 0;
}
