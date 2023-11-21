#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<sys/wait.h>
#define SHM_SIZE 1024

int main() {
    key_t key = 1234;
    char message[SHM_SIZE];

    int shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
   
    char *shm_ptr = (char *)shmat(shm_id, NULL, 0);
    if(fork()==0)
    {
        
        printf("Enter a message to write to shared memory: ");
        fgets(message, SHM_SIZE, stdin);
        strncpy(shm_ptr, message, SHM_SIZE);
        
    }
    else
    {
         wait(NULL);
        printf("Data read from shared memory: %s\n", shm_ptr);

    }
    
    shmdt(shm_ptr);

    return 0;
}
