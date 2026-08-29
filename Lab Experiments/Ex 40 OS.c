#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void displayPermissions(mode_t mode)
{
    printf("Permissions: ");

    /* Owner permissions */
    printf("%c",
           (mode & S_IRUSR) ? 'r' : '-');

    printf("%c",
           (mode & S_IWUSR) ? 'w' : '-');

    printf("%c",
           (mode & S_IXUSR) ? 'x' : '-');

    /* Group permissions */
    printf("%c",
           (mode & S_IRGRP) ? 'r' : '-');

    printf("%c",
           (mode & S_IWGRP) ? 'w' : '-');

    printf("%c",
           (mode & S_IXGRP) ? 'x' : '-');

    /* Other users */
    printf("%c",
           (mode & S_IROTH) ? 'r' : '-');

    printf("%c",
           (mode & S_IWOTH) ? 'w' : '-');

    printf("%c\n",
           (mode & S_IXOTH) ? 'x' : '-');
}

int main()
{
    char filename[] = "file.txt";

    /* Create the file */
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        perror("File creation failed");
        return 1;
    }

    fprintf(fp,
            "Operating Systems Lab\n");

    fclose(fp);

    struct stat fileStat;

    /* Get current permissions */
    if (stat(filename, &fileStat) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Current ");
    displayPermissions(fileStat.st_mode);

    /* Change permissions to rw-r--r-- */
    if (chmod(filename, 0644) == -1)
    {
        perror("chmod");
        return 1;
    }

    printf("Permissions changed successfully.\n");

    /* Display updated permissions */
    if (stat(filename, &fileStat) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Updated ");
    displayPermissions(fileStat.st_mode);

    return 0;
}