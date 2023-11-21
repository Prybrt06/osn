#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msg_buffer
{
    long msg_type;
    char msg[100];
} message;

int main()
{
    key_t my_key;
    int msg_id;
    my_key = ftok("progfile", 65);
    msg_id = msgget(my_key, 0666 | IPC_CREAT);
    if (fork() == 0)
    {

        message.msg_type = 1;
        printf("Write Message : ");
        fgets(message.msg, 100, stdin);
        msgsnd(msg_id, &message, sizeof(message), 0);
        printf("Sent message is : %s \n", message.msg);
        exit(0);
    }

    else
    {
        wait(NULL);
        msgrcv(msg_id, &message, sizeof(message), 1, 0);
        printf("Received Message is : %s \n", message.msg);
        msgctl(msg_id, IPC_RMID, NULL);
        exit(0);
    }
    return 0;
}
