#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int i;
	
	for (i = 0; i < 20; i++) {
		pid = getpid();
		printf("pid: %d\n", pid);
	}	

	return 0;
}
