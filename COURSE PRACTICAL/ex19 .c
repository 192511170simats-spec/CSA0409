#include <stdio.h>
#include <string.h>

struct User
{
    char username[20];
    char files[10][20];
    int count;
};

int main()
{
    struct User user[5];
    int users = 0;
    int choice, userNo, i, j;
    char filename[20];

    while (1)
    {
        printf("\n--- TWO LEVEL DIRECTORY ---");
        printf("\n1. Create User");
        printf("\n2. Create File");
        printf("\n3. Display Files");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        /* Create User */
        if (choice == 1)
        {
            if (users >= 5)
            {
                printf("Maximum users reached.\n");
                continue;
            }

            printf("Enter username: ");
            scanf("%s", user[users].username);

            user[users].count = 0;
            users++;

            printf("User created successfully.\n");
        }

        /* Create File */
        else if (choice == 2)
        {
            if (users == 0)
            {
                printf("No users created. Create a user first.\n");
                continue;
            }

            printf("Enter user number (1-%d): ", users);
            scanf("%d", &userNo);

            if (userNo < 1 || userNo > users)
            {
                printf("Invalid user number.\n");
                continue;
            }

            if (user[userNo - 1].count >= 10)
            {
                printf("File limit reached for this user.\n");
                continue;
            }

            printf("Enter file name: ");
            scanf("%s", filename);

            strcpy(user[userNo - 1].files[user[userNo - 1].count],
                   filename);

            user[userNo - 1].count++;

            printf("File created successfully.\n");
        }

        /* Display Files */
        else if (choice == 3)
        {
            if (users == 0)
            {
                printf("No users available.\n");
                continue;
            }

            for (i = 0; i < users; i++)
            {
                printf("\nUser %d: %s\n", i + 1, user[i].username);

                if (user[i].count == 0)
                {
                    printf("No files.\n");
                }
                else
                {
                    for (j = 0; j < user[i].count; j++)
                    {
                        printf("  %s\n", user[i].files[j]);
                    }
                }
            }
        }

        /* Exit */
        else if (choice == 4)
        {
            printf("Program ended.\n");
            break;
        }

        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
