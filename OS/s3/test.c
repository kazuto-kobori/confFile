#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int main()
{
	int filedes[2], pid;
	char buf[5];
	pipe(filedes);
	if ((pid = fork()) == 0) {
		read(filedes[0], buf, 5);
		write(1, buf, 5);
	} else if (pid > 0) {
		close(0);
		dup(filedes[1]);
		close(filedes[1]);
		write(0, "test\n", 5);
		return 0;
	} else {
		perror("fork");
	}
	wait(NULL);
	return 0;
} 
