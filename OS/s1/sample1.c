#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

const int rchar_size = 94;

void usage(char *cmd)
{
	printf("usage: %s filename filesize[KB]\n", cmd);
	exit(-1);
}

void init_rand_char(char *array)
{
	char c;	int  i = 0;
	for (c = '!'; c <= '~'; c++) array[i++] = c;

	return ;
}

int main(int argc, char **argv)
{
	int  fd, size, i;
	char rchar[rchar_size];

	if (argc != 3) usage(argv[0]);

	if ((fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) < 0) {
		perror("open");
		exit(-1);
	}

	size = atoi(argv[2]);
	init_rand_char(rchar);
	srand((unsigned int)time(NULL));

	for (i = 0; i < 1024 * size; i++) {
		write(fd, &rchar[rand()%(rchar_size+1)], 1);
		
	}

	close(fd);

	return 0;
}
