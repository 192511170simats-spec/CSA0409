#include <stdio.h>

int main()
{
    FILE *fp;
    char data[100];

    // Create and write
    fp = fopen("file.txt", "w");
    printf("Enter data: ");
    scanf(" %[^\n]", data);
    fprintf(fp, "%s\n", data);
    fclose(fp);

    // Read
    fp = fopen("file.txt", "r");
    printf("\nFile contents:\n");
    while (fgets(data, sizeof(data), fp))
        printf("%s", data);
    fclose(fp);

    // Append
    fp = fopen("file.txt", "a");
    printf("\nEnter data to append: ");
    scanf(" %[^\n]", data);
    fprintf(fp, "%s\n", data);
    fclose(fp);

    // Display updated file
    fp = fopen("file.txt", "r");
    printf("\nUpdated file contents:\n");
    while (fgets(data, sizeof(data), fp))
        printf("%s", data);
    fclose(fp);

    return 0;
}
