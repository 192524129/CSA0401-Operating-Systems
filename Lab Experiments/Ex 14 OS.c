#include <stdio.h>
#include <string.h>

#define MAX_FILES 20
#define MAX_NAME 50

int main()
{
    char files[MAX_FILES][MAX_NAME];
    int count = 0;
    int choice;
    char name[MAX_NAME];

    while (1)
    {
        printf("\n--- SINGLE LEVEL DIRECTORY ---\n");
        printf("1. Create File\n");
        printf("2. List Files\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (count == MAX_FILES)
            {
                printf("Directory is full.\n");
                continue;
            }

            printf("Enter file name: ");
            scanf("%s", name);

            strcpy(files[count], name);
            count++;

            printf("File created successfully.\n");
        }
        else if (choice == 2)
        {
            printf("\nFiles:\n");

            if (count == 0)
                printf("Directory is empty.\n");

            for (int i = 0; i < count; i++)
                printf("%d. %s\n", i + 1, files[i]);
        }
        else if (choice == 3)
        {
            int found = -1;

            printf("Enter file name to delete: ");
            scanf("%s", name);

            for (int i = 0; i < count; i++)
            {
                if (strcmp(files[i], name) == 0)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                printf("File not found.\n");
            }
            else
            {
                for (int i = found; i < count - 1; i++)
                    strcpy(files[i], files[i + 1]);

                count--;
                printf("File deleted successfully.\n");
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}