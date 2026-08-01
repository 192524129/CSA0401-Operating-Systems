#include<stdio.h>
#include<unistd.h>

int main()
{
    int pid;

    pid = fork();

    if(pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Parent's Parent PID = %d\n", getppid());
    }

    return 0;
}
