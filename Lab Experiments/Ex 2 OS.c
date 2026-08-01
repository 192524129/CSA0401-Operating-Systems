#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, destination;
    char buffer[100];
    int bytes;

    source = open("source.txt", O_RDONLY);

    if (source < 0)
    {
        printf("Cannot open source file.\n");
        return 1;
    }

    destination = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (destination < 0)
    {
        printf("Cannot create destination file.\n");
        close(source);
        return 1;
    }

    while ((bytes = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, bytes);
    }

    printf("File copied successfully.\n");

    close(source);
    close(destination);

    return 0;
}