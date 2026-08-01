#include <stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
 key_t key;
 int shmid;
 key=1234;
 char *str;
 shmid=shmget(key,1024,0666|IPC_CREAT);
 str =(char*) shmat(shmid,NULL,0);
  printf("Enter a message: ");
  fgets(str,1024,stdin);
  printf("Data written in shared memory: %s",str);
  shmdt(str);
    return 0;
}