// develop application using inter process communication(using shared memoery, pipes or message queue)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 1024

int main()
{

	int p[2];
	pipe(p);

	if (fork() == 0)
	{
		char message[MSGSIZE];
		printf("Enter a message to write: ");
		fgets(message, MSGSIZE, stdin);
		write(p[1], message, MSGSIZE);
		close(p[1]);
		exit(0);
	}

	else
	{
		wait(NULL);
		char inbuf[MSGSIZE];
		read(p[0], inbuf, MSGSIZE);
		printf("Recieved message: ");
		printf("%s", inbuf);
		close(p[0]);
		exit(0);
	}
	return 0;
}
