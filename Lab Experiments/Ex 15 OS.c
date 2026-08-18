#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_FILES 10
#define NAME 50

struct User
{
    char username[NAME];
    char files[MAX_FILES][NAME];
    int fileCount;
};

int main()
{
    struct User users[MAX_USERS];
    int userCount = 0;
    int choice;
    char username[NAME], filename[NAME];

    while (1)
    {
        printf("\n--- TWO LEVEL DIRECTORY ---\n");
        printf("1. Create User\n");
        printf("2. Create File\n");
        printf("3. List Files\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (userCount == MAX_USERS)
            {
                printf("Maximum users reached.\n");
                continue;
            }

            printf("Enter username: ");
            scanf("%s", username);

            strcpy(users[userCount].username, username);
            users[userCount].fileCount = 0;
            userCount++;

            printf("User created.\n");
        }

        else if (choice == 2)
        {
            int found = -1;

            printf("Enter username: ");
            scanf("%s", username);

            for (int i = 0; i < userCount; i++)
            {
                if (strcmp(users[i].username, username) == 0)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                printf("User not found.\n");
                continue;
            }

            printf("Enter file name: ");
            scanf("%s", filename);

            strcpy(users[found].files[users[found].fileCount],
                   filename);

            users[found].fileCount++;

            printf("File created.\n");
        }

        else if (choice == 3)
        {
            printf("Enter username: ");
            scanf("%s", username);

            int found = -1;

            for (int i = 0; i < userCount; i++)
            {
                if (strcmp(users[i].username, username) == 0)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                printf("User not found.\n");
            }
            else
            {
                printf("Files of %s:\n", username);

                for (int i = 0; i < users[found].fileCount; i++)
                    printf("%s\n", users[found].files[i]);
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