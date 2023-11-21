#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    const char *path = argv[1];
    const char *arg = argv[2];
    pid_t child_pid = fork();

    printf("%s : %s", path, arg);

    if (child_pid == -1)
    {

        perror("Process creation unsuccessful");
        exit(1);
    }
    else if (child_pid > 0)
    {
        int status;
        wait(&status);
        printf("\nChild Terminated.\n");
        exit(0);
    }
    else
    {
        printf("Child starts\n");

        if (execl(path, (strlen(arg) == 0 ? NULL : arg), NULL) < 0)
        {
            perror("Exec error");
            exit(1);
        }
    }

    return 0;
}
